#pragma once

#include <fstream>
#include <filesystem>
#include <string>
#include <ctime>

class qLogger {
public:
    qLogger(const std::filesystem::path& logFilePath);
    ~qLogger();

    void Clear();
    bool Log(const std::string& level, const std::string& location, const std::string& msg);

private:
    std::filesystem::path logFilePath;
    std::ofstream logStream;
    std::string GetTimestamp() const;
    
    void InitializeHtmlLogFile();
};