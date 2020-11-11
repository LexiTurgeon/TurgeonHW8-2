#include <iostream>
#include <sstream>
#include <fstream>
#include "AnalogIn.h"

using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

int main(int argc, char* argv[]){
	AnalogIn createdObject;
	createdObject.setNumber(0);

	createdObject.getNumber();

	int storeNumber = createdObject.readADCsample();
	cout << "The value of the ADC is: " <<  storeNumber << endl; 

	float analogVoltage = 1.8 / 4096; //Constant Value
	float Vo = analogVoltage * storeNumber;

	float valueOfResistor = (Vo * 10000) / (1.8 - Vo);
	//cout << "The Value of the Resistor is: " << valueOfResistor << endl;

	if (valueOfResistor > 1000){
		cout << "The Value of the Resistor is: " << valueOfResistor << " K Ohms" << endl;
	}else{
		cout << "The Value of the Resistor is: " << valueOfResistor << " Ohms" << endl;
	}
}


