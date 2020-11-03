#pragma once


class LongInt//����� ������� �����
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
	
	//������������ ������ 2
	LongInt operator+(LongInt value);//����������� ��������� �������� ������� �����

	LongInt operator-(LongInt value);//���������� ��������� ��������� ������� �����

	LongInt operator*(int n);//��������� �� 10 � ������� n

	friend LongInt operator*(int n, LongInt value);
	
	LongInt operator/(int n);//������� �� 10 � ������� n

	LongInt& operator=(const LongInt& value);

	operator unsigned long int();



private:

	int* _numbers;	//������ ���� �����

	int _length;

	bool _isNegative;

	int* intToArray(int value);

	int* normalize(int& length, int* numbers);
};

