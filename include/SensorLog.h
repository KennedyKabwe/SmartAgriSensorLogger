#ifndef  SENSORLOG_H
#define  SENSORLOG_H
#include<iostream>
#include <vector> 
#include "SensorReading.h"

class SensorLog {
    private:
        std::vector<SensorReading> readings; //container for all sensor readings
    public:
        //add a new sensor reading to the log
        void addReading(const SensorReading& reading);

        // Compute average of all values
        double computeAverage() const;

        // Find minimum value
        double findMin() const;

        // Find maximum value
        double findMax() const;

        // Save readings to file (CSV style)
        void saveToFile(const std::string& filename) const;
};

#endif // SENSORLOG_H   
