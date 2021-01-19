#pragma once

#include <iostream>
#include <exception>

using namespace std;

//Класс деки
template <typename T>
class Deque
{

public:
	
	/*
	конструктор по умолчанию
	*/
	Deque();

	/*
	деструктор
	*/
	~Deque();



	/*
	получение длины деки
	return - значение длины деки
	*/
	int getLength();

	/*
	Получение данных по индексу
	args:
		index - индекс элемента в структуре
	выбрасывает исключение если index выходит за пределы деки
	*/
	T& getData(int index);


	/*
	добавление в конец деки
	args:
		value - ссылка на вставляемое значение
	*/
	void pushBack(T value);

	/*
	добавление по индексу
	args:
		value - ссылка на вставляемое значение
		index - индекс вставки
	Выбрасывает исключение,	если index выходит за пределы деки
	*/
	void push(T value, int index);

	/*
	извлечение из начала деки
	return - первый элемент деки
	выбрасывает исключение если дека уже пуста
	*/
	T popFront();

	/*
	извлечение по индексу
	return - элемент деки под номером index (нумерация с головы)
	выбрасывает исключение, если дека уже пуста или если индекс выходит за пределы деки
	*/
	T pop(int index);

	/*
	извлечение из конца деки
	return - последний элемент деки
	выбрасывает исключение если дека уже пуста
	*/
	T popBack();


	/*
	поиск по структуре
	args:
		value - ссылка на искомый объект
	return - индекс, под которым находится объект value в деку
	*/
	int search(T value);

	/*
	вывод в консоль
	метод демонстрирует динамический полиморфизм
	*/
	void print();

private:

	//класс узла
	class Node
	{
	public:

		//ссылка на данные
		T _data;

		//указатели на следующий и предыдущий элементы
		Node* _next, * _prev;

		/*
		конструктор с параметром
		args:
			value - значение узла
		*/
		Node(T value);

		//деструктор
		~Node();
	};

	//длина очереди
	int _length;

	//указатели на начало и конец очереди
	Node* _head, * _tail;
};


//конструктор с параметром и по умолчанию
template<typename T>
Deque<T>::Node::Node(T value) : _data(value)
{
	_next = nullptr;
	_prev = nullptr;
}

//конструктор с параметром и по умолчанию
template<typename T>
Deque<T>::Node::~Node()
{
	delete _next;
}


//конструктор
template<typename T>
Deque<T>::Deque()
{
	_head = nullptr;
	_tail = nullptr;

	_length = 0;
}

//деструктор
template<typename T>
Deque<T>::~Deque()
{
	delete _head;
}

//получение длины очереди
template<typename T>
int Deque<T>::getLength()
{
	return _length;
}

//получение данных по индексу
template<typename T>
T& Deque<T>::getData(int index)
{
	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	Node* temp = _head;
	for (int i = 0; i < index; i++)
		temp = temp->_next;

	return temp->_data;
}

//добавление в конец очереди
template<typename T>
void Deque<T>::pushBack(T value)
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
template<typename T>
void Deque<T>::push(T value, int index)
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
		Node* temp = _head;
		for (int i = 0; i < index - 1; i++)
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
template<typename T>
T Deque<T>::popFront()
{
	if (!_length)
		throw exception("The Deque is empty!");

	T result = _head->_data;

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
template<typename T>
T Deque<T>::pop(int index)
{
	if (!_length)
		throw exception("The Deque is empty!");

	if ((index < 0) || (index >= _length))
		throw exception("Bad index!");

	if (_length == 1)
	{
		T result = _head->_data;

		_head->_next = nullptr;
		delete _head;
		_head = _tail = nullptr;

		_length--;

		return result;
	}
	else
	{

		Node* temp = _head;

		for (int i = 0; i < index; i++)
			temp = temp->_next;

		if (temp->_next)
			temp->_next->_prev = temp->_prev;
		if (temp->_prev)
			temp->_prev->_next = temp->_next;

		if (!index)
			_head = _head->_next;

		if (index == _length - 1)
			_tail = _tail->_prev;

		T result = temp->_data;
		temp->_next = nullptr;
		delete temp;

		_length--;

		return result;
	}
}

//извлечение из конца очереди
template<typename T>
T Deque<T>::popBack()
{
	if (!_length)
		throw exception("The Deque is empty!");

	T result = _tail->_data;

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
template<typename T>
void Deque<T>::print()
{
	Node* temp = _head;

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
template<typename T>
int Deque<T>::search(T value)
{
	Node* temp = _head;

	for (int i = 0; i < _length; i++)
	{
		if (temp->_data == value)
			return i;

		temp = temp->_next;
	}

	return -1;
}
