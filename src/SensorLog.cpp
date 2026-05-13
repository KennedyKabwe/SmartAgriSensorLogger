#include "SensorLog.h"
#include "sensorReading.h"
#include <fstream>
#include <limits>
#include <stdexcept>

void SensorLog::addReading(const SensorReading& reading) {
    readings.push_back(reading);
}

double SensorLog::computeAverage() const {
    if (readings.empty()) {
        throw std::runtime_error("No readings available to compute average");
    }
    double sum = 0.0;
    for (const auto& r : readings) {
        sum += r.getValue();
    }
    return sum / readings.size();
}

double SensorLog::findMin() const {
    if (readings.empty()) {
        throw std::runtime_error("No readings available to compute minimum");
    }
    double minVal = std::numeric_limits<double>::max();
    for (const auto& r : readings) {
        if (r.getValue() < minVal) {
            minVal = r.getValue();
        }
    }
    return minVal;
}

double SensorLog::findMax() const {
    if (readings.empty()) {
        throw std::runtime_error("No readings available to compute maximum");
    }
    double maxVal = std::numeric_limits<double>::lowest();
    for (const auto& r : readings) {
        if (r.getValue() > maxVal) {
            maxVal = r.getValue();
        }
    }
    return maxVal;
}

void SensorLog::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing");
    }
    ////////////////////////////////////////////////////////////////
    for (const auto& r : readings) {
    outFile << r.toString() << "," << r.getValue() << "\n";
    
    }

}
