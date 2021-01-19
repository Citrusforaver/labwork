#pragma once

#include "../LongInt/LongInt.h"

//класс длинный целых
class LongDouble: public LongInt
{
public:

	LongDouble();


	LongDouble(long long int value, long long int fraction);

	LongDouble(int length, int* numbers, int fractionLength, int * fraction, bool isNegative);

	LongDouble(const LongDouble& value);

	LongDouble& operator=(const LongDouble& value);

	LongDouble& operator=(LongInt value);

	~LongDouble();

	int* getFraction();

	int getFractionLength();

	void setFraction(long long int value);

	void setFraction(int length, int* numbers);

	friend ostream& operator<<(ostream& stream, LongDouble& value);

	friend istream& operator>>(istream& stream, LongDouble& value);


	virtual void write(fstream& file) override;
	
	virtual void read(fstream& file) override;

protected:

	//массив цифр дробной части числа
	int* _fractionNumbers;

	//длина массива цифр дробной части числа
	int _fractionLength;
};

