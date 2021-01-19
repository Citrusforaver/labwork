#include "UnsignedLongIntTests.h"
#include <exception>

#include <iostream>

using namespace std;

//тестирование метода setValue(int)
void UnsignedLongIntTests::setValueWithValue()
{
	//под конструктором с параметром скрывается вызов метода setValue(int)
	//устанавливаем положительное значение
	UnsignedLongInt value(123);

	//если объект поставил отрицательное значение
	//то выбрасываем исключение
	if (value.getIsNegative())
		throw exception("Bad sign");

	//если длина числа не равна 3 (т.к. в числе 123 3 цифры)
	//то выбрасываем исключение
	if (value.getLength() != 3)
		throw exception("Bad length");

	//считываем цифры из объекта и сравниваем их с настоящими цифрами
	//если хоть одна не совпадает, то выкидываем исключение
	int real_nums[] = {1,2,3}, *nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;

	//аналогичные действия проделываем с отрицательным числом
	value.setValue(-123);

	if (value.getIsNegative())
		throw exception("Bad sign");

	if (value.getLength() != 3)
		throw exception("Bad length");

	nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;

}

//тестирование метода setValue(int,int*)
void UnsignedLongIntTests::setValueWithArray()
{
	//аналогичные действия проделываем с числом, представленным в массиве
	int valueNums[] = { 1,2,3 };

	UnsignedLongInt value(3,valueNums);

	if (value.getIsNegative())
		throw exception("Bad sign");

	if (value.getLength() != 3)
		throw exception("Bad length");

	int  * nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;

	value.setValue(3, valueNums,true);

	if (value.getIsNegative())
		throw exception("Bad sign");

	if (value.getLength() != 3)
		throw exception("Bad length");

	nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");
}

//тестирование метода compare()
void UnsignedLongIntTests::compare()
{
	UnsignedLongInt value1(100), value2(10);

	if (value1.compare(value2) != 1)
		throw exception("Bad compare");

	if (value2.compare(value1) != -1)
		throw exception("Bad compare");

	value2.setValue(100);

	if (value1.compare(value2) != 0)
		throw exception("Bad compare");
}

//тестирование сложения чисел
void UnsignedLongIntTests::add()
{
	//для данного метода необходимо протестировать только сумму чисел с одинаковыми знаками
	//т.к. при вызове метода для разных знаков вызывается вычитание
	
	UnsignedLongInt value1(100), value2(100);

	UnsignedLongInt result, excpectation;

	excpectation.setValue(200);
	result = value1.add(value2);

	//если сумма 100+100 не равна 200
	if (result.compare(excpectation) != 0)
		throw exception("Bad add");

}

//тестирование вычитания чисел
void UnsignedLongIntTests::sub()
{
	//для данного метода необходимо протестировать только вычитание чисел с одинаковыми знаками
	//т.к. при вызове метода для разных знаков вызывается сумма

	UnsignedLongInt value1(100), value2(100);

	UnsignedLongInt result, excpectation;

	excpectation.setValue(0);
	result = value1.sub(value2);

	//если 100-100 не равно 0
	if (result.compare(excpectation) != 0)
		throw exception("Bad sub");
}

//тестирование умножения чисел
void UnsignedLongIntTests::mult()
{
	UnsignedLongInt value1(100), value2(100);

	UnsignedLongInt result, excpectation;

	excpectation.setValue(10000);
	result = value1.mult(value2);

	//если 100*100 не равно 10000
	if (result.compare(excpectation) != 0)
		throw exception("Bad mult");

}

void UnsignedLongIntTests::div()
{
	UnsignedLongInt value1(100), value2(100);

	UnsignedLongInt result, excpectation;

	excpectation.setValue(1);
	result = value1.div(value2);

	//если 100/100 не равно 1
	if (result.compare(excpectation) != 0)
		throw exception("Bad div");
}

void UnsignedLongIntTests::multByTenInPowerOperator()
{
	UnsignedLongInt value(123);
	int n = 4;

	UnsignedLongInt result, excpectation;

	excpectation.setValue(1230000);
	result = value*n;

	//если 123*(10^4) не равно 1230000
	if (result.compare(excpectation) != 0)
		throw exception("Bad multiply operator");

	//пробуем поменять местами операнды
	result = n * value;

	//если 123*(10^4) не равно 1230000
	if (result.compare(excpectation) != 0)
		throw exception("Bad multiply operator");
}

void UnsignedLongIntTests::divByTenInPowerOperator()
{
	UnsignedLongInt value(12345);
	int n = 5;

	UnsignedLongInt result, excpectation;

	excpectation.setValue(0);
	result = value / n;

	//если 12345/(10^5) не равно 0
	if (result.compare(excpectation) != 0)
		throw exception("Bad div operator");

	n = 3;
	excpectation.setValue(12);
	result = value / n;

	//если 12345/(10^3) не равно 12
	if (result.compare(excpectation) != 0)
		throw exception("Bad div operator");
}

void UnsignedLongIntTests::assignmentOperator()
{
	UnsignedLongInt value(123);

	UnsignedLongInt result, excpectation;

	excpectation.setValue(123);
	result = value;

	//если числа не равны
	if (result.compare(excpectation) != 0)
		throw exception("Bad assignment operator");

}

void UnsignedLongIntTests::staticCastOperator()
{
	LongInt value(123);

	unsigned long int excpectation = 123;
	unsigned long int result = static_cast<unsigned long int>(value);

	if (excpectation != result)
		throw exception("Bad cast operator");
}

void UnsignedLongIntTests::fileInputOutput()
{
	int valueNums[] = { 1,2,3 };

	UnsignedLongInt value(3, valueNums), value2;

	ofstream output("test.txt");
	output << value;
	output.close();

	ifstream input("test.txt");
	input >> value2;
	input.close();

	if (value2.getIsNegative())
		throw exception("Bad sign");

	if (value2.getLength() != 3)
		throw exception("Bad length");

	int* nums = value2.getNumbers();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;
}

void UnsignedLongIntTests::binaryInputOutput()
{
	int valueNums[] = { 1,2,3 };

	UnsignedLongInt value(3, valueNums), value2;

	fstream output("test.bin",ios::out | ios::trunc | ios::binary);
	value.write(output);
	output.close();

	fstream input("test.bin",ios::in | ios::binary);
	value2.read(input);
	input.close();

	if (value2.getIsNegative())
		throw exception("Bad sign");

	if (value2.getLength() != 3)
		throw exception("Bad length");

	int* nums = value2.getNumbers();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;
}
