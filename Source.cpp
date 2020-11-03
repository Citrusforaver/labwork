
#include <iostream>
#include "LongIntTests\LongIntTests.h"

using namespace std;

int main()
{
	LongInt obj1(102), obj2(13300);

	cout << obj1.add(obj2).toString() << endl;

	cout << obj1.sub(obj2).toString() << endl;

	cout << obj1.mult(obj2).toString() << endl;

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
		tester.sub();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.mult();
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

	//Лабораторная работа 2

	try
	{
		tester.multByTenInPowerOperator();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.divByTenInPowerOperator();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.assignmentOperator();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.staticCastOperator();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}


	return 0;
}