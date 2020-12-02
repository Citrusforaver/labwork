#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class LongInt//класс длинный целых
{

public:

	LongInt();

	LongInt(long long int value);

	LongInt(int length, int* numbers, bool isNegative);

	LongInt(const LongInt& value);

	~LongInt();

	int* getNumbers();

	int getLength();

	bool getIsNegative();

	void setValue(long long int value);

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

	//Лабораторная работа 3

	friend ostream& operator<<(ostream& stream, LongInt& value);//оператор вывода в поток (обычный)

	friend istream& operator>>(istream& stream, LongInt& value);//оператор чтения с потока (обычный)

	void write(fstream& file);//запись в бинарный файл

	void read(fstream& file);//чтение из бинарного файла


private:

	int* _numbers;	//массив цифр числа

	int _length;

	bool _isNegative;

	int* intToArray(long long int value);

	int* normalize(int& length, int* numbers);
};

