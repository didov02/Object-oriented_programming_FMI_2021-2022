#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Matrix
{
	T** elements;

	size_t rows;
	size_t cols;
public:
	Matrix(); // default constructor
	Matrix(const size_t, const size_t); // constructor with parameters
	Matrix(const Matrix<T>&); // copy constructor
	Matrix<T>& operator=(const Matrix<T>&); // operator =
	~Matrix(); // destructor
	
	const size_t getRows() const;
	const size_t getCols() const;

	bool setAt(const size_t, const size_t, const T&);
	const T& getAt(const size_t, const size_t) const;
	void transpose();

	void print() const;
protected:
	void setRows(const size_t);
	void setCols(const size_t);
private:
	void copy(const Matrix<T>&);
	void free();
	
};

//Private methods:
template<typename T>
void Matrix<T>::copy(const Matrix<T>& other)
{
	//Copy size of rows & columns
	size_t rows = other.rows; 
	size_t cols = other.cols;

	//Set aside memory
	elements = new T* [rows];
	for (size_t i = 0; i < rows; i++)
		elements[i] = new T[cols];

	//Copy data
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			elements[i][j] = other.elements[i][j];
}
template<typename T>
void Matrix<T>::free()
{
	for (size_t i = 0; i < rows; i++)
		delete[] this->elements[i];

	delete[] this->elements;
}

//Big 4:
template<typename T>
Matrix<T>::Matrix()
{
	rows = cols = 2;

	elements = new T* [rows];
	for (size_t i = 0; i < rows; i++)
		this->elements[i] = new T[cols];
}
template<typename T>
Matrix<T>::Matrix(const size_t rows, const size_t cols)
{
	elements = new T* [rows];
	for (size_t i = 0; i < rows; i++)
		elements[i] = new T[cols];

	this->rows = rows;
	this->cols = cols;
}
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	copy(other);
}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
template<typename T>
Matrix<T>::~Matrix()
{
	free();
}

//Mutators:
template<typename T>
void Matrix<T>::setRows(const size_t rows)
{
	this->rows = rows;
}
template<typename T>
void Matrix<T>::setCols(const size_t cols)
{
	this->cols = cols;
}

//Accessors:
template<typename T>
const size_t Matrix<T>::getRows() const
{
	return rows;
}
template<typename T>
const size_t Matrix<T>::getCols() const
{
	return cols;
}

//Methods:
template<typename T>
bool Matrix<T>::setAt(const size_t x, const size_t y, const T& element)
{
	if (x >= rows || y >= cols)
		return false;

	elements[x][y] = element;
	return true;
}
template<typename T>
const T& Matrix<T>::getAt(const size_t x, const size_t y) const
{
	if (x >= rows || y >= cols)
		throw std::out_of_range("Out of range");

	return this->elements[x][y];
}

template<typename T>
void Matrix<T>::transpose()
{
	//Set aside memory
	T** trans = new T* [cols];
	for (size_t i = 0; i < cols; i++)
		trans[i] = new T[rows];

	//Copy transposed data
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			trans[j][i] = this->elements[i][j];

	//Free memory of main matrix
	free();
	
	//Set size of rows & columns
	{
		//swap
		size_t temp = rows;
		rows = cols;
		cols = temp;
	}

	/*
	* Assign elements pointer to point to transposed matrix,
	* in other words, assign transposed matrix to main matrix.
	*/
	elements = trans;
}

template<typename T>
void Matrix<T>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << elements[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
