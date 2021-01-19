#include "DequeTests.h"

void DequeTests::pushPop()
{
	int value1(123);
	int value2(456);
	int value3(789);

	Deque<int> d;

	d.pushBack(value1);
	d.pushBack(value2);
	d.pushBack(value3);

	if (d.getLength() != 3)
		throw exception("Error in push-pop operations!");

	int receivedFront = d.popFront();
	int receivedBack = d.popBack();

	if(value1 != receivedFront)
		throw exception("Error in push-pop operations!");

	if (value3 != receivedBack)
		throw exception("Error in push-pop operations!");
}

void DequeTests::pushPopIndex()
{
	int value1(123);
	int value2(456);
	int value3(789);

	Deque<int> d;

	d.push(value3,0);
	d.push(value1,0);
	d.push(value2, 1);

	if (d.getLength() != 3)
		throw exception("Error in push-pop with index operations!");

	int receivedFront = d.pop(0);
	int receivedBack = d.pop(1);

	if (value1 != receivedFront)
		throw exception("Error in push-pop with index operations!");

	if (value3 != receivedBack)
		throw exception("Error in push-pop with index operations!");
}



void DequeTests::search()
{
	int value1(123);
	int value2(456);
	int value3(789);

	Deque<int> d;

	d.push(value3, 0);
	d.push(value1, 0);
	d.push(value2, 1);

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
