#pragma once
#include "StoreItem.h"

class Vegetable : public StoreItem
{
private:
	char* sort;
public:
	Vegetable();
	Vegetable(size_t, double, const char*);
	Vegetable(const Vegetable&);
	Vegetable& operator=(const Vegetable&);
	~Vegetable();

	void setSort(const char*);
	const char* getSort() const;

	virtual StoreItem* clone() const override;

	bool operator==(const Vegetable&);

	void print() const;
private:
	void copy(const Vegetable&);
	void free();
};