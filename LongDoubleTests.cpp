#include "LongDoubleTests.h"
#include <exception>

#include <iostream>

using namespace std;

void LongDoubleTests::setValueWithValue()
{
	//под конструктором с параметром скрывается вызов метода setValue(int)
	//устанавливаем положительное значение
	LongDouble value(123,45678);

	//если объект поставил отрицательное значение
	//то выбрасываем исключение
	if (value.getIsNegative())
		throw exception("Bad sign");

	//если длина числа не равна 3 (т.к. в числе 123 3 цифры)
	//то выбрасываем исключение
	if (value.getLength() != 3)
		throw exception("Bad length");

	if (value.getFractionLength() != 5)
		throw exception("Bad length");

	//считываем цифры из объекта и сравниваем их с настоящими цифрами
	//если хоть одна не совпадает, то выкидываем исключение
	int real_nums[] = {1,2,3}, *nums = value.getNumbers();
	int real_fraction[] = { 4,5,6,7,8 }, * fraction = value.getFraction();
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	for(int i =0;i<5;i++)
		if(real_fraction[i] != fraction[i])
			throw exception("Bad fraction");

	delete[] nums;
	delete[] fraction;

}


void LongDoubleTests::setValueWithArray()
{
	//аналогичные действия проделываем с числом, представленным в массиве
	int valueNums[] = { 1,2,3 };
	int fractionNums[] = { 4,5,6,7,8 };

	LongDouble value(3,valueNums, 5,fractionNums,false);

	//если длина числа не равна 3 (т.к. в числе 123 3 цифры)
	//то выбрасываем исключение
	if (value.getLength() != 3)
		throw exception("Bad length");

	if (value.getFractionLength() != 5)
		throw exception("Bad length");

	//считываем цифры из объекта и сравниваем их с настоящими цифрами
	//если хоть одна не совпадает, то выкидываем исключение
	int real_nums[] = { 1,2,3 }, * nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	int real_fraction[] = { 4,5,6,7,8 }, * fraction = value.getFraction();
	for (int i = 0; i < 5; i++)
		if (real_fraction[i] != fraction[i])
			throw exception("Bad fraction");
}

void LongDoubleTests::fileInputOutput()
{
	int valueNums[] = { 1,2,3 };
	int fractionNums[] = { 4,5,6,7,8 };

	LongDouble value(3, valueNums,5,fractionNums, true), value2;

	ofstream output("test.txt");
	output << value;
	output.close();

	ifstream input("test.txt");
	input >> value2;
	input.close();

	if(value.getIsNegative() != value2.getIsNegative())
		throw exception("Bad sign");

	if (value2.getLength() != 3)
		throw exception("Bad length");

	if (value2.getFractionLength() != 5)
		throw exception("Bad length");

	//считываем цифры из объекта и сравниваем их с настоящими цифрами
	//если хоть одна не совпадает, то выкидываем исключение
	int * nums = value2.getNumbers();
	int * fraction = value2.getFraction();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");

	for (int i = 0; i < 5; i++)
		if (fractionNums[i] != fraction[i])
			throw exception("Bad fraction");

	delete[] nums;
	delete[] fraction;
}

void LongDoubleTests::binaryInputOutput()
{
	int valueNums[] = { 1,2,3 };
	int fractionNums[] = { 4,5,6,7,8 };

	LongDouble value(3, valueNums, 5, fractionNums, true), value2;

	fstream output("test.bin", ios::out | ios::trunc | ios::binary);
	value.write(output);
	output.close();

	fstream input("test.bin", ios::in | ios::binary);
	value2.read(input);
	input.close();

	if (value.getIsNegative() != value2.getIsNegative())
		throw exception("Bad sign");

	if (value2.getLength() != 3)
		throw exception("Bad length");

	if (value2.getFractionLength() != 5)
		throw exception("Bad length");

	//считываем цифры из объекта и сравниваем их с настоящими цифрами
	//если хоть одна не совпадает, то выкидываем исключение
	int* nums = value2.getNumbers();
	int* fraction = value2.getFraction();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");

	for (int i = 0; i < 5; i++)
		if (fractionNums[i] != fraction[i])
			throw exception("Bad fraction");

	delete[] nums;
	delete[] fraction;
}
