#include "SensorReading.h"
#include "SensorLog.h"
#include <chrono>    // for system_clock
#include <iostream>  // for std::cout

int main() {
    // Capture current time
    auto now = std::chrono::system_clock::now();

    // SensorReading with sample value and current timestamp
    std::cout <<"\nREAL TIME CAPTURE AND DEFAULT TEST VALUE\n"<<std::endl;
    SensorReading reading(42.5, now);
    std::cout << reading << std::endl;

    // SensorLog test
    SensorLog log;
    log.addReading(SensorReading(23.5, std::chrono::system_clock::now()));
    log.addReading(SensorReading(27.8, std::chrono::system_clock::now()));

    std::cout << "\nBASIC ANALYSIS OF SENSOR LOG DATA\n"<<std::endl;
    std::cout << "Average: " << log.computeAverage() << std::endl;
    std::cout << "Min: " << log.findMin() << std::endl;
    std::cout << "Max: " << log.findMax() << std::endl;

    // Save to CSV (adjust path depending on build folder)
    log.saveToFile("../data/sensorlog.csv");

    return 0;
}
