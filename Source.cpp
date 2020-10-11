
#include <iostream>
#include "LongIntTests\LongIntTests.h"

using namespace std;

int main()
{
	LongInt obj1(-10230), obj2(133000);

	cout << obj1.addition(obj2).toString() << endl;

	cout << obj1.subtraction(obj2).toString() << endl;

	cout << obj1.multiplication(obj2).toString() << endl;

	cout << obj1.division(obj2).toString() << endl;

	
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
		tester.addition();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.subtraction();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.multiplication();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.division();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}
	



	return 0;
}