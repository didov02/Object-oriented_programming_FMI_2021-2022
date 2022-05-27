#pragma once
#include "StoreItem.h"

class Shop
{
private:
	StoreItem** list;
	size_t capacity, size;
public:
	Shop();
	Shop(const Shop&);
	Shop& operator=(const Shop&);
	~Shop();

	void addItem(const StoreItem&);
	bool deleteItem(size_t);
	bool changePrice(size_t, double);

	void print() const;
private:
	void copy(const Shop&);
	void free();
	void resize();
};

//Член - данни:
//o Хетерогенен контейнер за атрикулите в магазина
// Методи :
//o Добавяне на продукт(приема продукта като аргумент)
//o Премахване на продукт(приема индекс)
//o Промяна на цена на продукт(приема индекс и цена)
//o Извежда информация за всички продук