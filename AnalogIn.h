#ifndef ANALOGIN_H_
#define ANALOGIN_H_

using std::string;

class AnalogIn{
	private:
		unsigned int number;

	public:
		AnalogIn();
		AnalogIn(unsigned int n);
		virtual unsigned int getNumber(){return number;}
		virtual void setNumber(unsigned int n);
		virtual int readADCsample();
		virtual ~AnalogIn();
};

#endif 
