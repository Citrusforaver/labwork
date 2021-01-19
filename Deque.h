#pragma once

#include "../LongInt/LongInt.h"

//Класс деки
class Deque
{

public:
	
	
	Deque();

	~Deque();


	int getLength();

	LongInt& getData(int index);


	void pushBack(LongInt& value);

	
	void push(LongInt& value, int index);

	LongInt& popFront();

	LongInt& pop(int index);

	LongInt& popBack();


	int search(LongInt& value);

	void print();

private:

	//класс узла
	class Node
	{
	public:

		//ссылка на данные
		LongInt& _data;

		//указатели на следующий и предыдущий элементы
		Node* _next, * _prev;

		Node(LongInt& value);

		~Node();
	};

	//длина очереди
	int _length;

	//указатели на начало и конец очереди
	Node* _head, * _tail;
};


