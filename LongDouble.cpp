#include "LongDouble.h"

//конструктор по умолчанию
LongDouble::LongDouble()
{
	//устанавливаем нулевой указатель вместо массива для того, чтобы в сеттере не было проблем с очисткой памяти
	_numbers = nullptr;
	_fractionNumbers = nullptr;
	//устанавливаем нулевое значение в объект
	setValue(0);
	setFraction(0);
}

//конструктор с параметрами
LongDouble::LongDouble(long long int value, long long int fraction)
{
	//устанавливаем нулевой указатель вместо массива для того, чтобы в сеттере не было проблем с очисткой памяти
	_numbers = nullptr;
	_fractionNumbers = nullptr;
	//устанавливаем нулевое значение в объект
	setValue(value);
	setFraction(fraction);
}

//конструктор с параметрами
LongDouble::LongDouble(int length, int* numbers, int fractionLength, int* fraction, bool isNegative)
{
	//аналогично конструктору по умолчанию
	_numbers = nullptr;
	_fractionNumbers = nullptr;
	setValue(length, numbers, isNegative);
	setFraction(fractionLength, fraction);
}

//конструктор копирования
LongDouble::LongDouble(const LongDouble& value)
{
	_numbers = nullptr;
	_fractionNumbers = nullptr;
	setValue(value._length, value._numbers, value._isNegative);
	setFraction(value._fractionLength, value._fractionNumbers);
}

//оператор присваивания
LongDouble& LongDouble::operator=(const LongDouble& value)
{
	setValue(value._length, value._numbers, value._isNegative);
	setFraction(value._fractionLength, value._fractionNumbers);

	return *this;
}

//оператор присваивания
LongDouble& LongDouble::operator=(LongInt value)
{
	setValue(value.getLength(), value.getNumbers(), value.getIsNegative());
	setFraction(0);

	return *this;
}

LongDouble::~LongDouble()
{
	delete[] _fractionNumbers;
}



//геттер для цифр дробной части
int* LongDouble::getFraction()
{
	//создаем копию массива цифр числа
	int* numbersCopy = new int[_fractionLength];
	for (int i = 0; i < _fractionLength; i++)
		numbersCopy[i] = _fractionNumbers[i];

	return numbersCopy;
}

//геттер для длины дробной части
int LongDouble::getFractionLength()
{
	return _fractionLength;
}


//сеттер для дробной части из числа
void LongDouble::setFraction(long long int value)
{
	delete[] _fractionNumbers;

	//переводим число в массив цифр
	_fractionNumbers = intToArray(value);
	_fractionLength = 0;

	//считаем длину числа
	for (int i = 0; _fractionNumbers[i] != -1; i++)
		_fractionLength++;
}

//сеттер для дробной части из массива
void LongDouble::setFraction(int length, int* numbers)
{
	//длина числа не может быть отрицательной
	if (length < 0)
		throw exception("Bad length of numbers array!");

	//массив не может быть нулевым указателем
	if (!numbers)
		throw exception("Array of numbers is null!");

	//все цифры массива не должны быть отрицательными или превышать 9
	for (int i = 0; i < length; i++)
		if ((numbers[i] < 0) || (numbers[i] > 9))
			throw exception("Bad format of numbers array!");

	delete[] _fractionNumbers;

	//копируем содержимое массива
	_fractionLength = length;
	_fractionNumbers = new int[length];
	for (int i = 0; i < length; i++)
		_fractionNumbers[i] = numbers[i];
}


//запись в бинарный файл
void LongDouble::write(fstream& file)
{
	if (!file.is_open())
		throw exception("File is closed!");

	file.write((char*)&_isNegative, sizeof(bool));
	
	file.write((char*)&_length, sizeof(int));
	for (int i = 0; i < _length; i++)
		file.write((char*)&_numbers[i], sizeof(int));

	file.write((char*)&_fractionLength, sizeof(int));
	for (int i = 0; i < _fractionLength; i++)
		file.write((char*)&_fractionNumbers[i], sizeof(int));
}

//чтение из бинарного файла
void LongDouble::read(fstream& file)
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

	int fractionLength;
	int * fractionNumbers;

	file.read((char*)&fractionLength, sizeof(int));
	fractionNumbers = new int[fractionLength];
	for (int i = 0; i < fractionLength; i++)
		file.read((char*)&fractionNumbers[i], sizeof(int));

	setFraction(fractionLength, fractionNumbers);
}

//оператор вывода в поток
ostream& operator<<(ostream& stream, LongDouble& value)
{
	if (value._isNegative)
		stream << '-';

	//выводим в поток строковое представление числа
	for (int i = 0; i < value._length; i++)
		stream << value._numbers[i];

	stream << '.';

	for (int i = 0; i < value._fractionLength; i++)
		stream << value._fractionNumbers[i];

	return stream;
}

//оператор чтения с потока
istream& operator>>(istream& stream, LongDouble& value)
{
	int length;
	int* numbers;
	bool isNegative;

	int fractionLength;
	int* fractionNumbers;

	//считываем из потока строковое представление числа
	char* numberStr = new char[1024];
	stream.getline(numberStr, 1024);
	
	int pointPosition = -1;
	int j;
	for (j = 0; j < strlen(numberStr); j++)
		if (numberStr[j] == '.')
			pointPosition = j;

	if (pointPosition == -1)
		throw exception("Bad format of number!");

	//если считывается отрицательное число
	if (numberStr[0] == '-')
	{
		isNegative = true;

		fractionLength = strlen(numberStr) - pointPosition- 1;
		length = strlen(numberStr) -fractionLength - 2;

		numbers = new int[length];
		for (int i = 0; i < length; i++)
			numbers[i] = numberStr[i+1] - '0';

		fractionNumbers = new int[fractionLength];
		for(int i =0;i<fractionLength;i++)
			fractionNumbers[i] = numberStr[i+1+pointPosition] - '0';
	}
	else
	{
		isNegative = false;

		fractionLength = strlen(numberStr) - pointPosition - 1;
		length = strlen(numberStr) - fractionLength - 1;

		numbers = new int[length];
		for (int i = 0; i < length; i++)
			numbers[i] = numberStr[i] - '0';

		fractionNumbers = new int[fractionLength];
		for (int i = 0; i < fractionLength; i++)
			fractionNumbers[i] = numberStr[i + 1 + pointPosition] - '0';
	}

	value.setValue(length, numbers, isNegative);
	value.setFraction(fractionLength, fractionNumbers);

	delete[] numbers;

	return stream;
}
