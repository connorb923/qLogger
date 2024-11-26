#include "logger.hpp"

qLogger::qLogger(const std::filesystem::path& logFilePath):logFilePath(logFilePath) {
    logStream.open(logFilePath, std::ios::app);
    if (!logStream.is_open()) {
        std::cerr << "[FATAL] Log: Path not found " << logFilePath << std::endl;
        return;
    }

    if (logStream.tellp() == 0) {
        InitializeHtmlLogFile();
    }
}

qLogger::~qLogger() {
    if (logStream.is_open()) {
        logStream.close();
    }
}

void qLogger::Clear() {
    std::ofstream ofs(logFilePath, std::ofstream::trunc);
    ofs << "";
    InitializeHtmlLogFile();
    ofs.close();
}

bool qLogger::Log(const std::string& level, const std::string& location, const std::string& msg, bool doCout) {
    if (!logStream.is_open()) {
        std::cerr << "[FATAL] Log: Not init/open" << std::endl;
        return false;
    }

    if (doCout) {
        std::cout << GetTimestamp() << " [" << level << "] " << location << msg << std::endl;
    }


    logStream << "<div class='log-entry'>\n"
        << "<span class='timestamp'>" << GetTimestamp() << "</span> "
        << "<span class='" << level <<"'>[" << level << "]</span> "
        << "<span class='location'>" << location << "</span>: "
        << "<span class='message'>" << msg << "</span>\n"
        << "</div>\n";

    return true;
}

std::string qLogger::GetTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}

void qLogger::InitializeHtmlLogFile() {
    logStream << "<html>\n<head>\n<title>Log File</title>\n"
        << "<style>\n"
        << "body { background-color: DarkSlateGray; font-family: 'Tahoma', 'Geneva', sans-serif; }\n"
        << ".log-entry { margin: 10px; padding: 5px; border-radius: 3px; background-color: SlateGray }\n"
        << ".timestamp { font-weight: bold; color: #555; }\n"
        << ".debug { font-style: italic; color: #8e1dd3; }\n"
        << ".info { font-style: italic; color: #1dd334; }\n"
        << ".warn { font-style: bold; background-color: #d3931d; }\n"
        << ".error { font-style: bold; background-color: #e83333; }\n"
        << ".fatal { font-style: bold; background-color: #9d0606; }\n"
        << ".location { color: #555; }\n"
        << ".message { color: #000000; }\n"
        << "</style>\n"
        << "</head>\n<body>\n";
}