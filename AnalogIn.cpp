#include <iostream>
#include <sstream>
#include <fstream>
#include "AnalogIn.h"

using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

AnalogIn::AnalogIn(){

}

AnalogIn::AnalogIn(unsigned int n){
	number = n;
}

void AnalogIn::setNumber(unsigned int n){
	number = n;
}

int AnalogIn::readADCsample(){
   stringstream ss;
   int storeNumber;
   ss << ADC_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> storeNumber;
   fs.close();
   return storeNumber;
}

AnalogIn::~AnalogIn(){

}
