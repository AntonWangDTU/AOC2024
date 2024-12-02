#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

// Function to check if a report is safe
bool isSafeReport(const std::vector<int>& report) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    // Check the differences between adjacent levels and check if the sequence is strictly increasing or decreasing
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];
        
        // Check if the difference is between 1 and 3 (inclusive)
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false; // Unsafe because the difference is out of bounds
        }

        // Check if the sequence is strictly increasing or decreasing
        if (diff > 0) {
            isDecreasing = false; // Not strictly decreasing
        } else if (diff < 0) {
            isIncreasing = false; // Not strictly increasing
        }
    }

    // The report is safe if it is either strictly increasing or strictly decreasing
    return isIncreasing || isDecreasing;
}

// Function to check if a report can be made safe by removing one level
bool isSafeWithDampener(const std::vector<int>& report) {
    // Try removing each level and check if the modified report is safe
    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i); // Remove the i-th level

        if (isSafeReport(modifiedReport)) {
            return true; // Safe after removing one level
        }
    }
    return false; // Cannot be made safe
}

int main() {
    std::ifstream inputFile("data.txt");  // Open the file for reading
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;  // Exit with error code if the file cannot be opened
    }

    std::string line;
    int safeReportCount = 0;

    // Read each line from the file
    while (std::getline(inputFile, line)) {
        std::vector<int> report;
        std::stringstream ss(line);
        int level;

        // Split the line into numbers (levels)
        while (ss >> level) {
            report.push_back(level);
        }

        // Check if the report is safe or can be made safe
        if (isSafeReport(report) || isSafeWithDampener(report)) {
            ++safeReportCount;  // Increment the count of safe reports
        }
    }

    // Close the file
    inputFile.close();

    // Output the result
    std::cout << "Number of safe reports (with Problem Dampener): " << safeReportCount << std::endl;
    return 0;
}
