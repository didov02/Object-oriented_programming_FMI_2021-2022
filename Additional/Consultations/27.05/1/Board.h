#pragma once

template <typename T>
class Board
{
	T*** elements;
	size_t x, y, z;
public:
	Board() = delete;
	Board(size_t, size_t, size_t);
	Board(const Board<T>&);
	Board& operator=(const Board<T>&);
	~Board();

	bool setAt(size_t, size_t, size_t, const T&);
	T getAt(size_t,size_t,size_t) const;

	void print() const;
private:
	void copy(const Board<T>&);
	void free();
};

template <typename T>
Board<T>::Board(size_t x, size_t y, size_t z)
{
	this->x = x; //dimeons , number of Boards
	this->y = y; //rows
	this->z = z; //col

	//set Aside memory
	elements = new T * *[x];
	for (size_t i = 0; i < x; i++)
	{
		elements[i] = new T * [y];

		for (size_t j = 0; j < y; j++)
		{
			elements[i][j] = new T[z];
		}
	}

	//for (size_t i = 0; i < x; i++)
	//	for (size_t j = 0; j < y; j++)
	//		for (size_t k = 0; k < z; k++)
	//			elements[i][j][k] = T();
}

template <typename T>
Board<T>::Board(const Board& other)
{
	copy(other);
}

template <typename T>
Board<T>& Board<T>::operator=(const Board<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template <typename T>
Board<T>::~Board()
{
	free();
}

template <typename T>
bool Board<T>::setAt(size_t x, size_t y, size_t z, const T& el)
{
	if (x >= this->x || y >= this->y || z >= this->z)
		return false;

	elements[x][y][z] = el;
	return true;
}

template <typename T>
T Board<T>::getAt(size_t x, size_t y, size_t z) const
{
	if (x >= this->x || y >= this->y || z >= this->z)
		throw "Out of range";

	return elements[x][y][z]; 
}

template <typename T>
void Board<T>::print() const
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			for (size_t k = 0; k < z; k++)
				std::cout << elements[i][j][k] << " ";

			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void Board<T>::copy(const Board& other)
{
	x = other.x; //dimeons , number of Boards
	y = other.y; //rows
	z = other.z; //col

	elements = new T * *[x];

	for (size_t i = 0; i < x; i++)
	{
		elements[i] = new T * [y];

		for (size_t j = 0; j < y; j++)
		{
			elements[i][j] = new T[z];
		}
	}

	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < y; j++)
			for (size_t k = 0; k < z; k++)
				elements[i][j][k] = other.elements[i][j][k];
}

template <typename T>
void Board<T>::free()
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++ )
		{
			delete[] elements[i][j]; //delete z
		}
		delete[] elements[i]; //delete y
	}
	delete[] elements; //delete x
}