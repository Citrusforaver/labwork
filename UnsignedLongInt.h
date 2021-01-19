#pragma once

#include "../LongInt/LongInt.h"

//класс беззнаковых длинных целых
//число не имеет знака и всегда положительно
class UnsignedLongInt : public LongInt
{
public:

	
	UnsignedLongInt();

	UnsignedLongInt(long long int value);

	UnsignedLongInt(int length, int* numbers);

	UnsignedLongInt(const UnsignedLongInt& value);

	UnsignedLongInt& operator=(const UnsignedLongInt& value);

	UnsignedLongInt& operator=(LongInt value);

	virtual void setValue(long long int value);

	virtual void setValue(int length, int* numbers, bool isNegative);

	virtual void setIsNegative(bool is_negative);

};

