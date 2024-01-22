//Moath Samara, 314630153.
//Rashad Altouri, 209424340.

#pragma once
#include "Matrix.h"

#define DOUBLE 2
#define DOUBLECRETERIA 4

template<int row = 3, int col = 3, typename T = int>
class MatrixContainer
{
    int arrSize;
    int matricesNumber;
    Matrix<row, col, T>* dynamicArray;   // this is a matrices list. 


    void updateAfterAddDelete() 
    {
        Matrix<row, col, T>* newArray = new Matrix<row, col, T>[arrSize];
        for (int i = 0; i < matricesNumber; i++)
        {
            newArray[i] = dynamicArray[i];
        }
        delete[] dynamicArray;
        dynamicArray = newArray;
    }

public:
    MatrixContainer()    //// default constructor
    {
        arrSize = 1;
        matricesNumber = 0;
        dynamicArray = new Matrix<row,col,T>[1];
    }
    ~MatrixContainer()   // Destructor.
    {
        delete[] dynamicArray;
    }

    void addMatrix(Matrix<row, col, T> newMatrix) /// add matrix to tail of container
    {
        dynamicArray[matricesNumber] = newMatrix;
        matricesNumber++;

        if (matricesNumber >= arrSize)
        {
            arrSize = arrSize * DOUBLE;
            this->updateAfterAddDelete();
        }
    } 

    void removeLastMatrix() /// removes last matrix at container
    {
        matricesNumber--;
        if (matricesNumber * DOUBLECRETERIA <= arrSize)
        {
            arrSize = arrSize / DOUBLE;
            this->updateAfterAddDelete();
        }
    }

    Matrix<row, col, T>& operator[](const int& index)   // return matrix at container[index]
    {
        return dynamicArray[index];
    }

    friend ostream& operator<<(ostream& os, const MatrixContainer<row, col, T>& container) /// print all matrices
    {
        os << "There are " << container.matricesNumber << " matrices in the container. The matrices:" << endl;
        for (int i = 0;i < container.matricesNumber;i++)
        {
            os << container.dynamicArray[i] << endl;
        }
        return os;
    }

    int size() const /// return num of matrices in the container
    {
        return this->matricesNumber;
    }

    int capacity() const /// return the capacity of cantainer
    {
        return this->arrSize;
    }
  
};