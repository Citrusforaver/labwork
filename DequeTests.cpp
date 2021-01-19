#include "DequeTests.h"
#include "../LongDouble/LongDouble.h"
#include "../UnsignedLongInt/UnsignedLongInt.h"

void DequeTests::pushPop()
{
	LongInt value1(-123);
	LongDouble value2(789, 012);
	UnsignedLongInt value3(456);

	Deque d;

	d.pushBack(value1);
	d.pushBack(value2);
	d.pushBack(value3);

	if (d.getLength() != 3)
		throw exception("Error in push-pop operations!");

	LongInt& receivedFront = d.popFront();
	LongInt& receivedBack = d.popBack();

	if((receivedFront.compare(value1) != 0) || (typeid(receivedFront) != typeid(value1)))
		throw exception("Error in push-pop operations!");

	if ((receivedBack.compare(value3) != 0) || (typeid(receivedBack) != typeid(value3)))
		throw exception("Error in push-pop operations!");
}

void DequeTests::pushPopIndex()
{
	LongInt value1(-123);
	LongDouble value2(789, 012);
	UnsignedLongInt value3(456);

	Deque d;

	d.push(value3,0);
	d.push(value1,0);
	d.push(value2, 1);

	if (d.getLength() != 3)
		throw exception("Error in push-pop with index operations!");

	LongInt& receivedFront = d.pop(0);
	LongInt& receivedBack = d.pop(1);

	if ((receivedFront.compare(value1) != 0) || (typeid(receivedFront) != typeid(value1)))
		throw exception("Error in push-pop with index operations!");

	if ((receivedBack.compare(value3) != 0) || (typeid(receivedBack) != typeid(value3)))
		throw exception("Error in push-pop with index operations!");
}



void DequeTests::search()
{
	LongInt value1(-123);
	LongDouble value2(789, 012);
	UnsignedLongInt value3(456);

	Deque d;

	d.pushBack(value1);
	d.pushBack(value2);
	d.pushBack(value3);

	int search1 = d.search(value1);
	int search2 = d.search(value2);
	int search3 = d.search(value3);

	if(search1 != 0)
		throw exception("Error in search!");

	if (search2 != 1)
		throw exception("Error in search!");

	if (search3 != 2)
		throw exception("Error in search!");
}

void DequeTests::polymorphism()
{
	cout << "Polymorphism test:" << endl;

	LongInt value1(-123);
	LongDouble value2(789, 012);
	UnsignedLongInt value3(456);

	Deque d;

	d.pushBack(value1);
	d.pushBack(value2);
	d.pushBack(value3);

	cout << "value1 type: " << typeid(d.getData(0)).name() << endl;
	cout << "value2 type: " << typeid(d.getData(1)).name() << endl;
	cout << "value3 type: " << typeid(d.getData(2)).name() << endl;

	LongInt& received1 = d.popFront();
	LongInt& received2 = d.popFront();
	LongInt& received3 = d.popFront();

	if (typeid(received1) != typeid(value1))
		throw exception("Error in polymorphism!");

	if (typeid(received2) != typeid(value2))
		throw exception("Error in polymorphism!");

	if (typeid(received3) != typeid(value3))
		throw exception("Error in polymorphism!");
}
