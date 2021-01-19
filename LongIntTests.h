#pragma once

#include "../LongInt/LongInt.h"

class LongIntTests
{
public:

	void setValueWithValue();

	void setValueWithArray();

	void setValueWithLongInt();

	void toString();

	void compare();

	void add();

	void subtract();

	void multiplicate();

	void div();

//лабораторная работа 2:

	//тестировать операторы сложения и вычитания нет смысла, т.к. они основаны на соответствующих арифметических операциях

	//тестирование *
	void multByTenInPowerOperator();

	//тестирование /
	void divByTenInPowerOperator();

	//тестирование =
	void assignmentOperator();

	//тестирование приведения к unsigned long int
	void staticCastOperator();



	//лабораторная работа 3:

	void fileInputOutput();

	void binaryInputOutput();

};





