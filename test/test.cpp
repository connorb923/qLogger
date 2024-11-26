#include "../src/logger.hpp"

int main() {
    qLogger log("tests.html");

    bool Test = log.Log("DEBUG", "Test", "Test", true);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("DEBUG", "Test", "Test", false);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("INFO", "Test", "Test", true);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("INFO", "Test", "Test", false);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("WARN", "Test", "Test", true);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("WARN", "Test", "Test", false);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("ERROR", "Test", "Test", true);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("ERROR", "Test", "Test", false);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("FATAL", "Test", "Test", true);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }
    Test = log.Log("FATAL", "Test", "Test", false);
    if (!Test) {
        std::cout << "Test Fail" << std::endl;
    }   
}