//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#define NEG -1

template<int row = 3, int col = 3, typename T = int>
class Matrix
{
	T** matrixPtr;    // pointer to the beginning of the two dimensional array(matrix).

	void allocateSpace()   // here we allocate space for the two dimensional array(matrix).
	{
		matrixPtr = new T*[row];
		for (int i = 0; i < row;i++)
		{
			matrixPtr[i] = new T[col];
		}
	}

public:
	Matrix(T value = 0)  // default constructor.
	{
		allocateSpace();
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				matrixPtr[i][j] = value;
			}
		}
	}

	Matrix(const Matrix<row, col, T>& other) // copy constructor.
	{
		allocateSpace();
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				matrixPtr[i][j] = other.matrixPtr[i][j];
			}
		}
	}

	~Matrix()  // Destructor.
	{
		for (int i = 0;i < row;i++)
		{
			delete[] matrixPtr[i];
		}
		delete[] matrixPtr;
	}

	void operator=(const Matrix<row, col, T>& other) ///  matrix = matrix
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j] = other.matrixPtr[i][j];
			}
		}
	}

	static Matrix<row,col,T> getIdentityMatrix() /// return the identity matrix of the same size
	{
		int length = std::min(row, col);
		Matrix<row, col, T> newMatrix;
		for (int i = 0; i < length; i++)
		{
			newMatrix(i,i) = 1;
		}
		return newMatrix;
	}

	T* getDiag(int& number) const /// get the main diagonal of this matrix
	{
		number = std::min(row, col);
		T* diagArray = new T[number];
		for (int i = 0; i < number; i++)
		{
			diagArray[i] = matrixPtr[i][i];
		}
		return diagArray;
	}

	T trace() const /// calculate the trace
	{
		int number = std::min(row, col);
		T trace = 0;
		T* diagArray = this->getDiag(number);
		for (int i = 0; i < number; i++)
		{
			trace += diagArray[i];
		}
		delete[] diagArray;
		return trace;
	}

	operator T() const /// casting: (T)matrix
	{
		return this->trace();
	}

	friend ostream& operator<<(ostream& os, const Matrix<row, col, T>& matrix) /// print matrix
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				os << matrix.matrixPtr[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	T& operator()(const int& row, const int& col) /// return reference to matrix[i,j]
	{
		return matrixPtr[row][col];
	}

	bool operator==(const Matrix<row, col, T>& other) const /// this matrix == other
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (abs(other.matrixPtr[i][j] - this->matrixPtr[i][j]) > DBL_EPSILON)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix<row, col, T>& other) const /// this matrix != other
	{
		return !( (*this) == other);
	}

	Matrix<row, col, T> operator+(const Matrix<row, col, T>& other) const /// matrix + matrix.
	{
		Matrix<row, col, T> finalMatrix;
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				finalMatrix.matrixPtr[i][j] = this->matrixPtr[i][j] + other.matrixPtr[i][j];
			}
		}
		return finalMatrix;
	}

	Matrix<row, col, T> operator+(const T& target) const  /// matrix + scalar.
	{
		return (*this) + Matrix<row, col, T>(target);
	}

	friend Matrix<row, col, T> operator+(const T& target,const Matrix<row, col, T>& other) /// scalar + matrix
	{
		return other + (target);
	}

	Matrix<row, col, T>& operator++()  // ++Matrix
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j]++;
			}
		}
		return *this;
	}

	const Matrix<row, col, T> operator++(int) // Matrix++
	{
		Matrix<row, col, T> matrix = *this;
		++(*this);
		return matrix;
	}
	
	Matrix<row, col, T>& operator--() // --Matrix.
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->matrixPtr[i][j]--;
			}
		}
		return *this;
	}

	const Matrix<row, col, T> operator--(int) // Matrix--
	{
		Matrix<row, col, T> matrix = *this;
		--(*this);
		return matrix;
	}
	
	Matrix<row, col, T> operator*(const T& scalar) const /// matrix * scalar.
	{
		Matrix<row, col, T> finalMatrix;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				finalMatrix.matrixPtr[i][j] = this->matrixPtr[i][j] * scalar;
			}
		}
		return finalMatrix;
	}

	friend Matrix<row, col, T> operator*(const T& scalar, const Matrix<row, col, T>& other) // scalar * matrix.
	{
		return other * scalar;
	}
	

	Matrix<row, col, T> operator-(const Matrix<row, col, T>& other) const /// matrix - matrix
	{
		return (*this) + (other.operator*(NEG));
	}

	Matrix<row, col, T> operator-() const // this is for -Matrix.
	{
		return  this->operator*(NEG);
	}

	Matrix<row, col, T> operator-(const T& target) const // matrix - scalar.
	{
		return  (*this) + ((NEG)*target);
	}

	friend Matrix<row, col, T> operator-(const T& target, const Matrix<row, col, T>& other) // scalar - matrix.
	{
		return (-other) + target;
	}

	Matrix<row, col, T> operator*(const Matrix<row, col, T>& other) const // bonus matrix * matrix.
	{
		Matrix<row, col, T> finalMatrix;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				T sum=0;
				for (int x = 0; x < col; x++)
				{
					sum += this->matrixPtr[i][x] * other.matrixPtr[x][j];
				}
				finalMatrix.matrixPtr[i][j] = sum;
			}
		}
		return finalMatrix;
	}
};