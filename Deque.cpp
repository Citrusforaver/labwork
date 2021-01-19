
#include "Deque.h"
#include <exception>

using namespace std;

//конструктор
Deque::Deque()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//деструктор
Deque::~Deque()
{
	delete _head;
}

//получение длины очереди
int Deque::getLength()
{
	return _length;
}

//получение данных по индексу
LongInt& Deque::getData(int index)
{
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	Node* temp = _head;
	for (int i = 0; i < index; i++)
		temp = temp->_next;

	return temp->_data;
}

//добавление в конец очереди
void Deque::pushBack(LongInt& value)
{
	if (!_length)
	{
		_head = new Node(value);
		_tail = _head;
	}
	else
	{
		_tail->_next = new Node(value);
		_tail->_next->_prev = _tail;

		_tail = _tail->_next;
	}

	_length++;
}

//добавление по номеру
void Deque::push(LongInt& value, int index)
{

	if ((index < 0) || (index > _length))
		throw exception("Bad index!");

	if (index == _length)
	{
		pushBack(value);

		return;
	}

	if (!index)
	{
		_head->_prev = new Node(value);
		_head->_prev->_next = _head;
		_head = _head->_prev;
	}
	else
	{
		Node * temp = _head;
		for (int i = 0; i < index-1; i++)
			temp = temp->_next;

		Node* next = temp->_next;

		temp->_next = new Node(value);
		temp->_next->_prev = temp;

		temp->_next->_next = next;
		if (next)
			next->_prev = temp->_next;
	}

	_length++;
}

//извлечение из начала очереди
LongInt& Deque::popFront()
{
	if (!_length)
		throw exception("The Deque is empty!");

	LongInt& result = _head->_data;

	if (_length == 1)
	{
		_head->_next = nullptr;
		delete _head;
		_head = _tail = nullptr;
	}
	else
	{
		_head = _head->_next;

		_head->_prev->_next = nullptr;
		delete _head->_prev;

		_head->_prev = nullptr;
	}

	_length--;

	return result;
}

//извлечение по номеру
LongInt& Deque::pop(int index)
{
	if (!_length)
		throw exception("The Deque is empty!");
	
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	if (_length == 1)
	{
		LongInt& result = _head->_data;

		_head->_next = nullptr;
		delete _head;
		_head = _tail = nullptr;

		_length--;

		return result;
	}
	else
	{

		Node * temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		if(temp->_next)
			temp->_next->_prev = temp->_prev;
		if(temp->_prev)
			temp->_prev->_next = temp->_next;

		if (!index)
			_head = _head->_next;

		if (index == _length - 1)
			_tail = _tail->_prev;

		LongInt& result = temp->_data;
		temp->_next = nullptr;
		delete temp;

		_length--;

		return result;
	}
}

//извлечение из конца очереди
LongInt& Deque::popBack()
{
	if (!_length)
		throw exception("The Deque is empty!");

	LongInt& result = _tail->_data;

	if (_length == 1)
	{
		_head->_next = nullptr;
		delete _head;
		_head = _tail = nullptr;
	}
	else
	{
		_tail = _tail->_prev;

		_tail->_next->_next = nullptr;
		delete _tail->_next;

		_tail->_next = nullptr;
	}

	_length--;

	return result;
}


//вывод на консоль
void Deque::print()
{
	Node * temp = _head;

	for (int i = 0; i < _length; i++)
	{
		cout << "Value #" << i << endl;
		cout << "Class: " << typeid(temp->_data).name() << endl;
		cout << "Value: " << temp->_data << endl;
		cout << endl;
		
		temp = temp->_next;
	}
}

//поиск в очереди
int Deque::search(LongInt& value)
{
	Node * temp = _head;

	for (int i = 0; i < _length; i++)
	{
		if (temp->_data.compare(value) == 0)
			return i;

		temp = temp->_next;
	}

	return -1;
}
