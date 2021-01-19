#include "UnsignedLongInt.h"

//конструктор по умолчанию
UnsignedLongInt::UnsignedLongInt()
{
	//устанавливаем нулевой указатель вместо массива для того, чтобы в сеттере не было проблем с очисткой памяти
	_numbers = nullptr;
	//устанавливаем нулевое значение в объект
	setValue(0);
}

//конструктор с параметром
UnsignedLongInt::UnsignedLongInt(long long int value)
{
	//аналогично конструктору по умолчанию
	_numbers = nullptr;
	setValue(value);
}

//конструктор с двумя параметрами
UnsignedLongInt::UnsignedLongInt(int length, int* numbers)
{
	//аналогично конструктору по умолчанию
	_numbers = nullptr;
	setValue(length, numbers, false);
}

//конструктор копирования
UnsignedLongInt::UnsignedLongInt(const UnsignedLongInt& value)
{
	_numbers = nullptr;
	setValue(value._length, value._numbers, value._isNegative);
}

//оператор присваивания
UnsignedLongInt& UnsignedLongInt::operator=(const UnsignedLongInt& value)
{
	setValue(value._length, value._numbers, value._isNegative);

	return *this;
}

//оператор присваивания
UnsignedLongInt& UnsignedLongInt::operator=(LongInt value)
{
	setValue(value.getLength(), value.getNumbers(), false);

	return *this;
}


//изменение числа
void UnsignedLongInt::setValue(long long int value)
{
	delete[] _numbers;

	//переводим число в массив цифр
	_numbers = intToArray(value);
	_length = 0;

	//считаем длину числа
	for (int i = 0; _numbers[i] != -1; i++)
		_length++;

	_isNegative = false;		
}

//изменение числа
void UnsignedLongInt::setValue(int length, int* numbers, bool isNegative)
{
	//длина числа не может быть отрицательной
	if (length < 0)
		throw exception("Bad length of numbers array!");

	//массив не может быть нулевым указателем
	if (!numbers)
		throw exception("Array of numbers is null!");

	//массив не может начинаться с нуля, если он не состоит из одного нуля
	if (!numbers[0] && (length != 1))
		throw exception("First element of numbers array is 0!");

	//все цифры массива не должны быть отрицательными или превышать 9
	for (int i = 0; i < length; i++)
		if ((numbers[i] < 0) || (numbers[i] > 9))
			throw exception("Bad format of numbers array!");

	delete[] _numbers;

	//копируем содержимое массива
	_length = length;
	_numbers = new int[length];
	for (int i = 0; i < length; i++)
		_numbers[i] = numbers[i];

	_isNegative = false;
}

//изменение знака числа
void UnsignedLongInt::setIsNegative(bool is_negative)
{
	_isNegative = false;
}
