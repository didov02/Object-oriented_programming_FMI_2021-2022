#pragma once
#include "StoreItem.h"

class Fruit : public StoreItem
{
private:
	char* name;
public:
	Fruit();
	Fruit(size_t, double, const char*);
	Fruit(const Fruit&);
	Fruit& operator=(const Fruit&);
	~Fruit();

	void setName(const char*);
	const char* getName() const;

	virtual StoreItem* clone() const override;

	friend bool operator>(const Fruit&, const Fruit&);

	virtual void print() const override;
private:
	void copy(const Fruit&);
	void free();
};
