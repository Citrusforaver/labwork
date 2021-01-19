#include "LongInt.h"
#include <exception>
#include <iostream>

using namespace std;

LongInt::LongInt()
{
	_numbers = nullptr;//устанавливаем нулевой указатель вместо массива для того, чтобы в сеттере не было проблем с очисткой памяти

	setValue(0);
}

LongInt::LongInt(int value)
{
	_numbers = nullptr;
	setValue(value);
}

LongInt::LongInt(int length, int* numbers, bool isNegative)
{
	_numbers = nullptr;
	setValue(length, numbers, isNegative);
}

LongInt::LongInt(const LongInt& value)
{
	_numbers = nullptr;
	setValue(value);
}

LongInt::~LongInt()
{
	delete[] _numbers;
}

int* LongInt::getNumbers()//геттер для получения массива цифр числа
{
	int* numbersCopy = new int[_length];//создаем копию массива цифр числа
	for (int i = 0; i < _length; i++)
		numbersCopy[i] = _numbers[i];

	return numbersCopy;
}

int LongInt::getLength()//геттер для получения длины числа
{
	return _length;
}

bool LongInt::getIsNegative()//геттер для того, чтобы узнать, является ли число отрицательным
{
	return _isNegative;
}


void LongInt::setValue(int value)//сеттер для числа
{
	delete[] _numbers;

	_numbers = intToArray(value);
	_length = 0;

	for (int i = 0; _numbers[i] != -1; i++)
		_length++;
	if (value < 0)
		_isNegative = true;
	else
		_isNegative = false;
}

void LongInt::setValue(int length, int* numbers, bool isNegative)//сеттер для массива
{
	if (length < 0)
		throw exception("Bad length of numbers array!");

	if (!numbers)
		throw exception("Array of numbers is null!");

	if (!numbers[0] && (length != 1))
		throw exception("First element of numbers array is 0!");

	for (int i = 0; i < length; i++)
		if ((numbers[i] < 0) || (numbers[i] > 9))
			throw exception("Bad format of numbers array!");

	delete[] _numbers;

	_length = length;
	_numbers = new int[length];
	for (int i = 0; i < length; i++)
		_numbers[i] = numbers[i];

	_isNegative = isNegative;
}

void LongInt::setValue(const LongInt& value)//сеттер для копирования объекта
{
	_length = value._length;
	_isNegative = value._isNegative;

	_numbers = new int[_length];
	for (int i = 0; i < _length; i++)
		_numbers[i] = value._numbers[i];
}

void LongInt::setIsNegative(bool is_negative)//изменение знака числа
{
	_isNegative = is_negative;
}


LongInt LongInt::add(LongInt& value)//сложение
{
	if (!_isNegative && value._isNegative)
	{
		LongInt obj(value);
		obj.setIsNegative(false);

		return subtract(obj);
	}

	if (_isNegative && !value._isNegative)
	{
		LongInt obj(*this);
		obj.setIsNegative(false);

		return value.subtract(obj);
	}

	int* numbers;
	int length;

	if (_length >= value._length)
	{
		length = _length;
		numbers = new int[_length];
		for (int i = 0; i < _length; i++)
			numbers[i] = _numbers[i];

		int  i = _length - 1;
		for (int j = value._length - 1; j >= 0; j--)
			numbers[i--] += value._numbers[j];
	}
	else
	{
		length = value._length;
		numbers = new int[value._length];
		for (int i = 0; i < value._length; i++)
			numbers[i] = value._numbers[i];

		int  i = value._length - 1;
		for (int j = _length - 1; j >= 0; j--)
			numbers[i--] += _numbers[j];
	}

	int* norm_numbers = normalize(length, numbers);
	LongInt result(length, norm_numbers, _isNegative);

	delete[] norm_numbers;
	delete[] numbers;

	return result;
}

LongInt LongInt::subtract(LongInt& value)//вычитание
{
	if (!compare(value))
		return LongInt();

	if (!_isNegative && value._isNegative)
	{
		LongInt obj(value);
		obj.setIsNegative(false);

		return add(obj);
	}

	if (_isNegative && !value._isNegative)
	{
		LongInt obj(value);
		obj.setIsNegative(true);

		return add(obj);
	}

	if (compare(value) < 0)
	{
		LongInt result(value.subtract(*this));

		result.setIsNegative(!result.getIsNegative());

		return result;
	}

	int* numbers;
	int length;

	if (_length >= value._length)
	{
		length = _length;
		numbers = new int[_length];
		for (int i = 0; i < _length; i++)
			numbers[i] = _numbers[i];

		int  i = _length - 1;
		for (int j = value._length - 1; j >= 0; j--)
			numbers[i--] -= value._numbers[j];
	}
	else
	{
		length = value._length;
		numbers = new int[value._length];
		for (int i = 0; i < value._length; i++)
			numbers[i] = value._numbers[i];

		int  i = value._length - 1;
		for (int j = _length - 1; j >= 0; j--)
			numbers[i--] -= _numbers[j];
	}

	int* norm_numbers = normalize(length, numbers);
	LongInt result(length, norm_numbers, false);

	delete[] norm_numbers;
	delete[] numbers;

	return result;
}

LongInt LongInt::multiplicate(LongInt& value)//умножение
{
	LongInt result;

	int multiplier = 1;
	for (int i = value._length - 1; i >= 0; i--)
	{
		LongInt temp(*this);
		temp.setIsNegative(false);

		for (int j = 0; j < value._numbers[i] * multiplier; j++)
			result.setValue(result.add(temp));

		multiplier *= 10;
	}

	if ((_isNegative && !value._isNegative) || (!_isNegative && value._isNegative))
		result.setIsNegative(true);

	return result;
}

LongInt LongInt::div(LongInt& value)//деление
{

	LongInt divider(0);
	if (!value.compare(divider))
		throw exception("Division by zero!");

	divider.setValue(value);
	divider.setIsNegative(false);

	LongInt dividend;
	dividend.setValue(*this);
	dividend.setIsNegative(false);

	int result_number = 0;
	while (dividend.compare(divider) >= 0)
	{
		dividend.setValue(dividend.subtract(divider));
		result_number++;
	}

	if ((_isNegative && !value._isNegative) || (!_isNegative && value._isNegative))
		result_number *= -1;

	return LongInt(result_number);
}


int LongInt::compare(LongInt& value)//сравнение
{
	if (_isNegative && !value._isNegative)
		return -1;

	if (!_isNegative && value._isNegative)
		return 1;

	if (_length > value._length)
		if (_isNegative)
			return -1;
		else
			return 1;

	if (_length < value._length)
		if (_isNegative)
			return 1;
		else
			return -1;

	for (int i = 0; i < _length; i++)
		if (_numbers[i] > value._numbers[i])
			if (!_isNegative)
				return 1;
			else
				return -1;
		else
			if (_numbers[i] < value._numbers[i])
				if (!_isNegative)
					return -1;
				else
					return 1;

	return 0;
}


char* LongInt::toString()//получение стрового представления
{
	char* str;

	if (_isNegative)
	{
		str = new char[_length + 2];
		str[0] = '-';
		int i;
		for (i = 0; i < _length; i++)
			str[i + 1] = _numbers[i] + '0';
		str[++i] = '\0';
	}
	else
	{
		str = new char[_length + 1];
		int i;
		for (i = 0; i < _length; i++)
			str[i] = _numbers[i] + '0';
		str[i] = '\0';
	}

	return str;
}


int* LongInt::intToArray(int value)//перевод числа в массив цифр
{
	if (value < 0)
		value *= -1;

	if (!value)
	{
		int* numbers = new int[2];
		numbers[0] = 0;
		numbers[1] = -1;

		return numbers;
	}

	int temp = value;
	int count = 0;

	while (temp)
	{
		temp /= 10;
		count++;
	}

	int* numbers = new int[count + 1];
	temp = value;
	for (int i = 0; i < count; i++)
	{
		numbers[count - i - 1] = temp % 10;
		temp /= 10;
	}
	numbers[count] = -1;

	return numbers;
}

int* LongInt::normalize(int& length, int* numbers)//нормализация массива
{
	int* result = new int[length];
	for (int i = 0; i < length; i++)
		result[i] = numbers[i];

	for (int i = length - 1; i >= 1; i--)
		if (result[i] < 0)
		{
			result[i - 1]--;
			result[i] += 10;
		}

	while (!result[0] && (length != 1))
	{
		int* new_result = new int[length - 1];
		for (int i = 1; i < length; i++)
			new_result[i - 1] = result[i];

		length--;
		delete[] result;
		result = new_result;
	}

	for (int i = length - 1; i >= 1; i--)
	{
		result[i - 1] += result[i] / 10;
		result[i] %= 10;
	}

	while (result[0] >= 10)
	{
		int* new_result = new int[length + 1];
		for (int i = length - 1; i >= 0; i--)
			new_result[i + 1] = result[i];

		new_result[0] = new_result[1] / 10;
		new_result[1] %= 10;
		length++;
		delete[] result;
		result = new_result;
	}

	return result;
}
//Лабораторная работа 2

//оператор сложения чисел
LongInt LongInt::operator+(LongInt value)
{
	return add(value);
}

//оператор вычитания чисел
LongInt LongInt::operator-(LongInt value)
{
	return sub(value);
}

//умножение на 10^n
LongInt LongInt::operator*(int n)
{
	if (n < 0)
		throw exception("Bad number!");

	//переносим все цифры из числа в массив цифр результирующего числа
	int newLength = _length + n;
	int* newNumbers = new int[newLength];
	for (int i = 0; i < _length; i++)
		newNumbers[i] = _numbers[i];
	//в конец числа записываем n нулей
	for (int i = _length; i < newLength; i++)
		newNumbers[i] = 0;

	//формируем число из массива цифр и новой длины
	LongInt result(newLength, newNumbers, _isNegative);
	delete[] newNumbers;

	return result;
}

//умножение на 10^n
LongInt operator*(int n, LongInt value)
{
	if (n < 0)
		throw exception("Bad number!");

	//переносим все цифры из числа в массив цифр результирующего числа
	int newLength = value._length + n;
	int* newNumbers = new int[newLength];
	for (int i = 0; i < value._length; i++)
		newNumbers[i] = value._numbers[i];
	//в конец числа записываем n нулей
	for (int i = value._length; i < newLength; i++)
		newNumbers[i] = 0;

	//формируем число из массива цифр и новой длины
	LongInt result(newLength, newNumbers, value._isNegative);
	delete[] newNumbers;

	return result;
}

//деление на 10^n
LongInt LongInt::operator/(int n)
{
	//реализуется ЦЕЛОЧИСЛЕННОЕ деление

	if (n < 0)
		throw exception("Bad number!");

	//если делитель больше самого числа
	if (n >= _length)
		//то возвращаем 0
		return LongInt(0);

	//переносим первые _length-n цифр числа в результат
	int newLength = _length -n;
	int* newNumbers = new int[newLength];
	for (int i = 0; i < newLength; i++)
		newNumbers[i] = _numbers[i];

	//формируем число из массива цифр и новой длины
	LongInt result(newLength, newNumbers, _isNegative);
	delete[] newNumbers;

	return result;
}

//оператор присваивания
LongInt& LongInt::operator=(const LongInt& value)
{
	setValue(value._length, value._numbers, value._isNegative);

	return *this;
}

//оператор приведения типов
LongInt::operator unsigned long int()
{
	//создаем длинное число, равное максимальному числу среди unsigned long int
	LongInt maxULong(ULONG_MAX);

	//если текущее число меньше максимального
	if (compare(maxULong) > 0)
		throw exception("Overflow");

	//то переводим длинное число из массива цифр в числовой формат
	unsigned long int result = 0, tenDegree = pow(10, (_length - 1));
	for (int i = 0; i < _length; i++, tenDegree /= 10)
		result += _numbers[i] * tenDegree;

	//и возвращаем его
	return result;
}

//------Лабораторная работа 3


//данные операторы работают как с обычными потоками, так и с файловыми
//вывод в обычный поток
ostream& operator<<(ostream& stream, LongInt& value)
{
	if (value._isNegative)
		stream << '-';

	//выводим в поток строковое представление числа
	for (int i = 0; i < value._length; i++)
		stream << value._numbers[i];

	return stream;
}

//чтение с обычного потока
istream& operator>>(istream& stream, LongInt& value)
{
	int length;
	int* numbers;
	bool isNegative;

	//считываем из потока строковое представление числа
	char* numberStr = new char[1024];
	stream.getline(numberStr, 1024);

	//если считывается отрицательное число
	if (numberStr[0] == '-')
	{
		isNegative = true;
		length = strlen(numberStr) - 1;
		numbers = new int[length];

		for (int i = 0; i < length; i++)
			numbers[i] = numberStr[i+1] - '0';
	}
	else
	{
		isNegative = false;
		length = strlen(numberStr);
		numbers = new int[length];

		for (int i = 0; i < length; i++)
			numbers[i] = numberStr[i] - '0';
	}

	value.setValue(length, numbers, isNegative);

	delete[] numbers;

	return stream;
}

//запись в бинарный файл
void LongInt::write(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed!");

	file.write((char*)&_isNegative, sizeof(bool));
	file.write((char*)&_length, sizeof(int));
	for (int i = 0; i < _length; i++)
		file.write((char*)&_numbers[i], sizeof(int));
}

//чтение из бинарного файла
void LongInt::read(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed!");

	int length;
	bool isNegative;
	int* numbers;

	file.read((char*)&isNegative, sizeof(bool));
	file.read((char*)&length, sizeof(int));
	numbers = new int[length];
	for (int i = 0; i < length; i++)
		file.read((char*)&numbers[i], sizeof(int));

	setValue(length, numbers, isNegative);
}
