#include <iostream>
#include "matrix.h"
using namespace std;

namespace COP3330{
    
// *****************************************************************
// * Function Name: Matrix_Class
// * Description: Default Constructor
// * Just sets the row and columns to zero.
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    Matrix_Class::Matrix_Class() {
        rowsize = 0;
        colsize = 0;
        matrix = nullptr;
    }

// *****************************************************************
// * Function Name: Matrix_Class
// * Description: Constructor with two parameters.   
// * The matrix must be between 2 and 6 rows and columns and if a bad value is passed in use the default of 6. 
// * Parameter Description: 
// *    r= matrix rowsize
// *    c= matrix colsize
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    Matrix_Class::Matrix_Class(const int r, const int c) {
        if(r < 2 || r > 6) {
            rowsize = 6;
        } else {
            rowsize = r;
        }

        if(c < 2 || c > 6) {
            colsize = 6;
        } else {
            colsize = c;
        }

        matrix = new int*[rowsize];
        for(int i=0;i < rowsize; i++) {
            matrix[i] = new int[colsize];
        }
        Zero();
    }

// *****************************************************************
// * Function Name: Destructor
// * Description: Calls Clear()
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References: Clear()
// ***************************************************************** 
    Matrix_Class::~Matrix_Class() {
        Clear();
    }

// *****************************************************************
// * Function Name: Clear
// * Description: Deletes the 2d Array and sets colsize and rowsize to zero. 
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    void Matrix_Class::Clear() {
        if (matrix != nullptr) {
            for (int i=0;i < rowsize;i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
        rowsize=0;
        colsize=0;
    }

// *****************************************************************
// * Function Name: Zero
// * Description: Sets all the values in the matrix to zero
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    void Matrix_Class::Zero() {
        for (int i = 0; i < rowsize; i++) {
            for (int j = 0; j < colsize; j++) {
                matrix[i][j] = 0;
            }
        }
    }

// *****************************************************************
// * Function Name: Print
// * Description: Prints the matrix out to standard output along with 
// * a message that is passed in as a parameter. 
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    void Matrix_Class::Print(string msg) const {
        cout << msg << endl;
        cout << " Row Size = " << rowsize << " Column Size = " << colsize << endl;
        for (int i = 0; i < rowsize; i++) {
            for (int j = 0; j < colsize; j++) {
                cout << ' ' << matrix[i][j];
            }
            cout << endl;
        }
    }

// *****************************************************************
// * Function Name: Input
// * Description: Given the size of the row and column, it prompts the user to input the matrix
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    void Matrix_Class::Input() {
        for (int i = 0; i < rowsize; i++) {
            cout << "Enter " << colsize << " numbers for Row" << (i+1) <<":" << endl;
            for (int j = 0; j < colsize; j++) {
                cin >> matrix[i][j];
            }
        }
    }

// *****************************************************************
// * Function Name: Resize
// * Description: Changes the size of the matrix to the row and column passed in. 
// * If either the row or column is invalid..do not make any changes.
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
    void Matrix_Class::Resize(const int r, const int c) {
        if(r < 2 || r > 6) {
            cout << "Row size invalid, no changes made to matrix." << endl;
            return;
        }
        if(c < 2 || c > 6) {
            cout << "Column size invalid, no changes made to matrix." << endl;
            return;
        }
        Clear();
        
        rowsize=r;
        colsize=c;
        matrix = new int*[rowsize];
        for(int i=0;i < rowsize; i++) {
            matrix[i] = new int[colsize];
        }
        Zero();
    }  

// *****************************************************************
// * Function Name:assignment= operator overload
// * Description: Right Hand Side assignment operator.
// *  Designed to be used for values on the right side of the equal sign 
// *  that can be changed such as another Matrix_Class object. 
// * Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
    Matrix_Class& Matrix_Class::operator=(const Matrix_Class& m) {
        if (this == &m) {
            return *this;
        }

        Clear();
        rowsize = m.rowsize;
        colsize = m.colsize;

        matrix = new int*[rowsize];
        for (int i = 0; i < rowsize; i++) {
            matrix[i] = new int[colsize];
            for (int j = 0; j < colsize; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }

        return *this;
    }

// *****************************************************************
// * Function Name: multiplication * operator overload
// * Description: Multiply two matrices and return the results.
// *  If the matrices cannot be multiplied ( i.e. the column size of the first 
// *  does not match the size of the rows and the second ) return *this as a results.  
// *  Parameter Description: 
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References: Based on provided MultArray() function
// * void MultArray(int ** A, int ** B, int **  C, int m, int n, int l)
// * {
// *     int i,j,k;
// *     for (i=0; i<m; i++)
// *       for (j=0; j<l; j++)
// *         {
// *           result[i][j] =. 0; 
// *             for (k=0; k<n; k++) 
// *               { result[i][j] += A[i][k] * B[k][j];  }
// *          }
// * 
// * }
// ***************************************************************** 
    Matrix_Class& Matrix_Class::operator * (Matrix_Class & m1){ 
        if(this->colsize != m1.rowsize) {
            cout << "Matrices are incompatible for multiplication. colsize ["<<this->colsize<<"] != rowsize ["<<m1.rowsize<<"]"<<endl;
            return *this;
        }

        Matrix_Class* result = new Matrix_Class(this->rowsize, m1.colsize);

        for (int i = 0; i < this->rowsize; i++) {
            for (int j = 0; j < m1.colsize; j++) {
                result->matrix[i][j] = 0;

                for (int k = 0; k < this->colsize; k++) {
                    result->matrix[i][j] += (this->matrix[i][k]) * (m1.matrix[k][j]);
                }
            }
        }

        return *result;
    }
}