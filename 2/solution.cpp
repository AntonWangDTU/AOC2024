#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

bool isSafeReport(const std::vector<int>& report) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];
        
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false; 
        }
        if (diff > 0) {
            isDecreasing = false; 
        } else if (diff < 0) {
            isIncreasing = false; 
        }
    }
    return isIncreasing || isDecreasing;
}
bool isSafeWithDampener(const std::vector<int>& report) {

    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i);

        if (isSafeReport(modifiedReport)) {
            return true; 
        }
    }
    return false; 
}
int main() {
    std::ifstream inputFile("data.txt"); 
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;  
    }
    std::string line;
    int safeReportCount = 0;
    while (std::getline(inputFile, line)) {
        std::vector<int> report;
        std::stringstream ss(line);
        int level;
        while (ss >> level) {
            report.push_back(level);
        }
        if (isSafeReport(report) || isSafeWithDampener(report)) {
            ++safeReportCount;  
        }
    }
    inputFile.close();
    std::cout << "Number of safe reports (with Problem Dampener): " << safeReportCount << std::endl;
    return 0;
}
