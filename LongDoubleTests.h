#pragma once

#include "../LongDouble/LongDouble.h"

class LongDoubleTests
{
public:

	//Конструкторы нет смысла тестировать, т.к. они основаны на методе SetValue() и его перегрузках
	//getter'ы тоже не тестируются, т.к. в них примитивный код, который лишь возвращает значение

	//тестирование метода setValue(int)
	void setValueWithValue();

	//тестирование метода setValue(int,int*,bool)
	void setValueWithArray();


	//лабораторная работа 3:

	void fileInputOutput();

	void binaryInputOutput();

};

