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

	LongInt add(LongInt& value);

	LongInt sub(LongInt& value);

	LongInt mult(LongInt& value);

	LongInt div(LongInt& value);

	int compare(LongInt& value);

	char* toString();
	
	//Лабораторная работа 2
	LongInt operator+(LongInt value);//перергрузка оператора сложения длинных чисел

	LongInt operator-(LongInt value);//перегрузка оператора вычитания длинных чисел

	LongInt operator*(int n);//умножение на 10 в степени n

	friend LongInt operator*(int n, LongInt value);
	
	LongInt operator/(int n);//деление на 10 в степени n

	LongInt& operator=(const LongInt& value);

	operator unsigned long int();



private:

	int* _numbers;	//массив цифр числа

	int _length;

	bool _isNegative;

	int* intToArray(int value);

	int* normalize(int& length, int* numbers);
};

