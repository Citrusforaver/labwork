#include "LongIntTests.h"
#include <exception>

#include <iostream>

using namespace std;

void LongIntTests::setValueWithValue()//������������ ������ setValue(int)

{
	LongInt value(123);//��� ������������� � ���������� ���������� ����� ������ setValue(int)

	if (value.getIsNegative())//���� ������ �������� ������������� ��������
		throw exception("Bad sign");

	if (value.getLength() != 3)//���� ����� ����� �� ����� 3 (�.�. � ����� 123 3 �����)
		throw exception("Bad length");

	int real_nums[] = {1,2,3}, *nums = value.getNumbers();//��������� ����� �� ������� � ���������� �� � ���������� �������
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;

	//����������� �������� ����������� � ������������� ������
	value.setValue(-123);

	if (!value.getIsNegative())
		throw exception("Bad sign");

	if (value.getLength() != 3)
		throw exception("Bad length");

	nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (real_nums[i] != nums[i])
			throw exception("Bad nums");

	delete[] nums;

}

//������������ ������ setValue(int,int*,bool)
void LongIntTests::setValueWithArray()
{
	//����������� �������� ����������� � ������, �������������� � �������
	int valueNums[] = { 1,2,3 };

	LongInt value(3,valueNums,false);

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

	if (!value.getIsNegative())
		throw exception("Bad sign");

	if (value.getLength() != 3)
		throw exception("Bad length");

	nums = value.getNumbers();
	for (int i = 0; i < 3; i++)
		if (valueNums[i] != nums[i])
			throw exception("Bad nums");
}

//������������ ������ setValue(LongInt)
void LongIntTests::setValueWithLongInt()
{
	LongInt value1(123), value2;
	value2.setValue(value1);

	if (value1.getIsNegative() != value2.getIsNegative())
		throw exception("Bad sign");

	if (value1.getLength() != value2.getLength())
		throw exception("Bad length");

	int* nums1 = value1.getNumbers(), * nums2 = value2.getNumbers();
	for (int i = 0; i < 3; i++)
		if (nums1[i] != nums2[i])
			throw exception("Bad numbers");

	delete[] nums1;
	delete[] nums2;
}

//������������ ������ toString()
void LongIntTests::toString()
{
	LongInt value(123);

	char* str = value.toString();
	char real_str[] = { "123" };

	for (int i = 0; i < value.getLength(); i++)
		if (real_str[i] != str[i])
			throw exception("Bad string");

	delete[] str;

	value.setValue(-123);

	str = value.toString();
	char real_str2[] = { "-123" };

	for (int i = 0; i < value.getLength()+1; i++)
		if (real_str2[i] != str[i])
			throw exception("Bad string");

	delete[] str;
}

void LongIntTests::compare()//������������ ������ compare()
{
	LongInt value1(100), value2(-100);

	if (value1.compare(value2) != 1)
		throw exception("Bad compare");

	if (value2.compare(value1) != -1)
		throw exception("Bad compare");

	value2.setValue(100);

	if (value1.compare(value2) != 0)
		throw exception("Bad compare");

	value2.setValue(10);

	if (value1.compare(value2) != 1)
		throw exception("Bad compare");

	if (value2.compare(value1) != -1)
		throw exception("Bad compare");

	value2.setValue(-100);
	value1.setValue(-10);

	if (value1.compare(value2) != 1)
		throw exception("Bad compare");

	if (value2.compare(value1) != -1)
		throw exception("Bad compare");
}


void LongIntTests::add()//������������ �������� �����
{
	
	LongInt value1(100), value2(100);//��� ������� ������ ���������� �������������� ������ ����� ����� � ����������� �������

	LongInt result, excpectation;

	excpectation.setValue(200);
	result.setValue(value1.add(value2));

	if (result.compare(excpectation) != 0) // ���� ����� 100 + 100 �� ����� 200
		throw exception("Bad addition");

	value1.setValue(-100);
	value2.setValue(-100);
	excpectation.setValue(-200);
	result.setValue(value1.add(value2));

	if (result.compare(excpectation) != 0)//���� ����� (-100)+(-100) �� ����� -200
		throw exception("Bad addition");

}

void LongIntTests::sub()//������������ ��������� �����
{

	LongInt value1(100), value2(100);

	LongInt result, excpectation;

	excpectation.setValue(0);
	result.setValue(value1.sub(value2));

	if (result.compare(excpectation) != 0)//���� 100-100 �� ����� 0
		throw exception("Bad subtraction");

	value1.setValue(-100);
	value2.setValue(-100);
	excpectation.setValue(0);

	result.setValue(value1.sub(value2));

	if (result.compare(excpectation) != 0)//���� ����� (-100)-(-100) �� ����� 0
		throw exception("Bad subtraction");
}

void LongIntTests::mult()//������������ ��������� �����
{
	LongInt value1(100), value2(100);

	LongInt result, excpectation;

	excpectation.setValue(10000);
	result.setValue(value1.mult(value2));

	if (result.compare(excpectation) != 0)//���� 100*100 �� ����� 10000
		throw exception("Bad multiplication");

	value1.setValue(-100);
	value2.setValue(-100);
	excpectation.setValue(10000);

	result.setValue(value1.mult(value2));

	if (result.compare(excpectation) != 0)//���� (-100)*(-100) �� ����� 10000
		throw exception("Bad multiplication");

	value1.setValue(-100);
	value2.setValue(100);
	excpectation.setValue(-10000);

	result.setValue(value1.mult(value2));

	if (result.compare(excpectation) != 0)//���� (-100)*100 �� ����� -10000
		throw exception("Bad multiplication");

	value1.setValue(100);
	value2.setValue(-100);
	excpectation.setValue(-10000);

	result.setValue(value1.mult(value2));

	if (result.compare(excpectation) != 0)//���� 100*(-100) �� ����� -10000
		throw exception("Bad multiplication");

}

void LongIntTests::div()
{
	LongInt value1(100), value2(100);

	LongInt result, excpectation;

	excpectation.setValue(1);
	result.setValue(value1.div(value2));

	if (result.compare(excpectation) != 0)
		throw exception("Bad division");

	value1.setValue(-100);
	value2.setValue(-100);
	excpectation.setValue(1);

	result.setValue(value1.div(value2));

	if (result.compare(excpectation) != 0)
		throw exception("Bad division");

	value1.setValue(-100);
	value2.setValue(100);
	excpectation.setValue(-1);

	result.setValue(value1.div(value2));

	if (result.compare(excpectation) != 0)
		throw exception("Bad division");

	value1.setValue(100);
	value2.setValue(-100);
	excpectation.setValue(-1);

	result.setValue(value1.div(value2));

	if (result.compare(excpectation) != 0)
		throw exception("Bad division");
}
void LongIntTests::multByTenInPowerOperator()
{
	LongInt value(123);
	int n = 4;

	LongInt result, excpectation;

	excpectation.setValue(1230000);
	result.setValue(value * n);

	//���� 123*(10^4) �� ����� 1230000
	if (result.compare(excpectation) != 0)
		throw exception("Bad multiply operator");

	//������� �������� ������� ��������
	result.setValue(n * value);

	//���� 123*(10^4) �� ����� 1230000
	if (result.compare(excpectation) != 0)
		throw exception("Bad multiply operator");
}

void LongIntTests::divByTenInPowerOperator()
{
	LongInt value(12345);
	int n = 5;

	LongInt result, excpectation;

	excpectation.setValue(0);
	result.setValue(value / n);

	//���� 12345/(10^5) �� ����� 0
	if (result.compare(excpectation) != 0)
		throw exception("Bad div operator");

	n = 3;
	excpectation.setValue(12);
	result.setValue(value / n);

	//���� 12345/(10^3) �� ����� 12
	if (result.compare(excpectation) != 0)
		throw exception("Bad div operator");
}

void LongIntTests::assignmentOperator()
{
	LongInt value(123);

	LongInt result, excpectation;

	excpectation.setValue(123);
	result = value;

	//���� ����� �� �����
	if (result.compare(excpectation) != 0)
		throw exception("Bad assignment operator");

}

void LongIntTests::staticCastOperator()
{
	LongInt value(123);

	unsigned long int excpectation = 123;
	unsigned long int result = static_cast<unsigned long int>(value);

	if (excpectation != result)
		throw exception("Bad cast operator");
}
