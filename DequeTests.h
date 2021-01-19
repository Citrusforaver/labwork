#pragma once

#include "../Deque/Deque.h"

//класс тестирования очереди
class DequeTests
{
public:

	//тест обычной вставки и извлечения
	void pushPop();

	//тест вставки и извлечения по номеру
	void pushPopIndex();

	//тест поиска 
	void search();

	//тест динамического полиморфизма
	void polymorphism();

};

