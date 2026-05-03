#include "SensorReading.h"
#include <chrono>  //for system_clock
#include <iostream>

int main(){
    //capture current time
    auto now=std::chrono::system_clock::now();
    //SensorReading with sample value and current timestamp
    SensorReading reading(42.5, now);

    //Print the reading using overloaded operator<<
    std::cout << reading << std::endl;

    return 0;
}