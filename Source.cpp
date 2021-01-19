
#include <iostream>
#include "LongIntTests\LongIntTests.h"
#include "LongDoubleTests/LongDoubleTests.h"
#include "UnsignedLongIntTests/UnsignedLongIntTests.h"
#include "DequeTests/DequeTests.h"

using namespace std;

int main()
{

	{
		cout << "LongInt tests:" << endl;

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
		cout << endl;
	}

	cout << "UnsignedLongInt Tests:" << endl;
	{
	UnsignedLongIntTests tester;

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

	cout << endl;
}

	{
	cout << "LongDouble tests:" << endl;

	LongDoubleTests tester;

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
	
	cout << endl;
	
}

	{
		cout << "Deque tests:" << endl;

		DequeTests tester;

		try
		{
			tester.pushPop();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.pushPopIndex();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.search();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}

		try
		{
			tester.polymorphism();
		}
		catch (const std::exception& exc)
		{
			cout << exc.what() << endl;
		}
		cout << endl;
	}

	cout << "Press any key" << endl;
	char c;
	cin >> c;

	return 0;
}
