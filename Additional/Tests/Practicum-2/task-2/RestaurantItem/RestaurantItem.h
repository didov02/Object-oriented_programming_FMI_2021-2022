#pragma once

class RestaurantItem
{
protected:
	enum TypeOfItem
	{
	Food,
	Drink,
	Unknown
	} type;
	size_t quantity;
	double price;
public:
	RestaurantItem();
	RestaurantItem(size_t, double);
	RestaurantItem(const RestaurantItem&) = default;
	RestaurantItem& operator=(const RestaurantItem&) = default;
	virtual ~RestaurantItem() = default;

	//Accesors
	virtual TypeOfItem getType() const;
	size_t getQuantity() const;
	double getPrice() const;

	//Mutators
	void setQuantity(size_t);
	void setPrice(double);

	virtual const char* typeToStr() const;
	virtual void print() const;

	virtual void changeName(const char*) = 0;
	virtual RestaurantItem* clone() const = 0;
};