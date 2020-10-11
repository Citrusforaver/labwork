#pragma once


class LongInt//класс длинный целых
{

public:

	LongInt();

	LongInt(int value);

	LongInt(int length, int* numbers, bool isNegative);

	LongInt(const LongInt& value);

	~LongInt();

	int* getNumbers();

	int getLength();

	bool getIsNegative();

	void setValue(int value);

	void setValue(int length, int* numbers, bool isNegative);

	void setValue(const LongInt& value);

	void setIsNegative(bool is_negative);

	LongInt addition(LongInt& value);

	LongInt subtraction(LongInt& value);

	LongInt multiplication(LongInt& value);

	LongInt division(LongInt& value);

	int compare(LongInt& value);

	char* toString();

private:

	int* _numbers;	//массив цифр числа

	int _length;

	bool _isNegative;

	int* intToArray(int value);

	int* normalize(int& length, int* numbers);
};

