#ifndef SENSORREADING_H
#define SENSORREADING_H

#include <iostream>
#include <string>
#include <chrono>

class SensorReading {
private:
    double value; //measure data
    std::chrono::system_clock::time_point timestamp;
    //raw time object, precise and safe.
public:
    //constructor initializes with value + timestamp
    SensorReading(double V, std::chrono::system_clock::time_point t);
    //Getter for value
    double getvalue() const;
    //Getter for timestamp(raw form)
    std::chrono::system_clock::time_point getTimestamp() const;
    //Helper: converts timestamp to human-readable format
    std::string toString()const;
    //Friend function: allows printing with <<
    friend std::ostream& operator<<(std::ostream& os, const SensorReading& sr);
};

#endif // SENSORREADING_H