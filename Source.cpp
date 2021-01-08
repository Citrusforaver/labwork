

#include <iostream>
#include "LongIntTests\LongIntTests.h"

using namespace std;

int main()
{
	
	
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

	//Лабораторная работа 3

	try
	{
		tester.fileInputOutput();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		tester.binaryInputOutput();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}
	
	cout << "Press any key" << endl;
	char c;
	cin >> c;

	return 0;
}
