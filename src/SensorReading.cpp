#include"SensorReading.h"
#include <iomanip> // for formating output
#include <sstream> // for bulding string from chrono

//constructor: use initialize list
SensorReading::SensorReading(double V, std::chrono::system_clock::time_point t)
    : value(V), timestamp(t) {}

//Getter for value
double SensorReading::getvalue() const {
    return value;
}

//Getter for timestamp
std::chrono::system_clock::time_point SensorReading::getTimestamp() const {
    return timestamp;
}

//Helper: converts timestamp to human-readable format
std::string SensorReading::toString() const {
    std::time_t timeT = std::chrono::system_clock::to_time_t(timestamp);
    std::tm tm = *std::localtime(&timeT);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

//operator<< overload for easy printing
std::ostream& operator<<(std::ostream& os, const SensorReading& sr) {
    os << "Value: " << sr.value << "| Time: " << sr.toString();
    return os;
}