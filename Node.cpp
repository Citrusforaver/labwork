
#include "Deque.h"

//конструктор с параметром и по умолчанию
Deque::Node::Node(LongInt& value) : _data(value)
{
	_next = nullptr;
	_prev = nullptr;
}

//конструктор с параметром и по умолчанию
Deque::Node::~Node() 
{
	delete _next;
}
