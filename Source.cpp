
#include <iostream>
#include "LongIntTests\LongIntTests.h"

using namespace std;

int main()
{
	LongInt obj1(-10230), obj2(133000);

	cout << obj1.add(obj2).toString() << endl;

	cout << obj1.subtract(obj2).toString() << endl;

	cout << obj1.multiplicate(obj2).toString() << endl;

	cout << obj1.div(obj2).toString() << endl;


	LongIntTests tester;


	try
	{
		tester.setValueWithValue();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.setValueWithArray();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.setValueWithLongInt();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.toString();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.compare();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.add();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.subtract();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.multiplicate();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.div();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}




	return 0;
}
