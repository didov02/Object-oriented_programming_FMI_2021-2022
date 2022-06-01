#pragma once

class StoreItem
{
protected:
	enum Type
	{
		FRUIT,
		VEGETABLE,
		UNKNOWN
	} type;
private:
	size_t calories;
	double price;
public:
	StoreItem();
	StoreItem(size_t, double);

	virtual ~StoreItem() = default;

	void setCalories(size_t);
	void setPrice(double);

	size_t getCalories() const;
	double getPrice() const;

	virtual StoreItem* clone() const = 0;

	virtual void print() const;
};