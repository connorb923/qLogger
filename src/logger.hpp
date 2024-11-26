#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <ctime>

class qLogger {
public:
    qLogger(const std::filesystem::path& logFilePath);
    ~qLogger();

    void Clear();
    bool Log(const std::string& level, const std::string& location, const std::string& msg, bool doCout);

private:
    std::filesystem::path logFilePath;
    std::ofstream logStream;
    std::string GetTimestamp() const;
    
    void InitializeHtmlLogFile();
};