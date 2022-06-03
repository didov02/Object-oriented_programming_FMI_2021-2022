#include "Shop.h"

Shop::Shop()
{
	capacity = 2;
	size = 0;

	list = new StoreItem * [capacity];
}
Shop::Shop(const Shop& other)
{
	copy(other);
}
Shop& Shop::operator=(const Shop& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
Shop::~Shop()
{
	free();
}

void Shop::addItem(const StoreItem& item)
{
	if (size >= capacity)
		resize();

	list[size++] = item.clone();
}

bool Shop::deleteItem(size_t index)
{
	if (index >= size)
		return false;
	
	delete list[index]; //delete element @index
	list[index] = list[size-1]; //adjust pointer to last element <-> swap
	list[size-1] = nullptr; //nulify pointer
	size--; //decrement size
	
	return true;
}

bool Shop::changePrice(size_t index, double price)
{
	if (index >= size)
		return false;

	list[index]->setPrice(price);
	return true;
}

void Shop::print() const
{
	for (size_t i = 0; i < size; i++)
		list[i]->print();
}


void Shop::copy(const Shop& other)
{
	capacity = other.capacity;
	size = other.size;

	list = new StoreItem * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		list[i] = other.list[i]->clone();
	}
}
void Shop::free()
{
	for (size_t i = 0; i < size; i++)
		delete list[i];

	delete[] list;
}
void Shop::resize()
{
	StoreItem** temp = new StoreItem * [capacity *= 2];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	delete[] list;
	list = temp;
	temp = nullptr;
}
