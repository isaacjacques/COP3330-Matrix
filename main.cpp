#include <iostream>
#include "matrix.h"
using namespace std;
using namespace COP3330; 

// *****************************************************************
// * Function Name: PrintMainMenu
// * Description: Main menu
// * Date: 10-19-24
// * Author: Isaac Jacques
// * References: Modified from sieve of eratosethenes assignment's main
// ***************************************************************** 
void PrintMainMenu() {
    cout <<"Matrix Multiplier"<<endl;
    cout <<"________________________________"<<endl;
    cout <<" I -> Input matrix values"<<endl;
    cout <<" R -> Resize a matrix"<<endl;
    cout <<" P -> Print a matrix"<<endl;
    cout <<" M -> Multiply matrices"<<endl;
    cout <<" E -> Exit System"<<endl;
    cout <<"________________________________"<<endl;
    cout <<"Enter option: ";
}

// *****************************************************************
// * Function Name: PrintSelectionMenu
// * Description: Prompts user for a matrix to modify
// * Date: 10-19-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
void PrintSelectionMenu(string m) {
    cout <<m<<endl;
    cout <<"________________________________"<<endl;
    cout <<" 1 -> Matrix 1"<<endl;
    cout <<" 2 -> Matrix 2"<<endl;
    cout <<" E -> Exit"<<endl;
    cout <<"________________________________"<<endl;
    cout <<"Enter option: ";
}

// *****************************************************************
// * Function Name: ResizeMatrix
// * Description: Prompts user for rowsize and colsize for resizing
// * Date: 10-19-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
void ResizeMatrix(Matrix_Class& matrix) {
    int rowsize, colsize;
    cout << "Enter the new number of rows: ";
    cin >> rowsize;
    cout << "Enter the new number of columns: ";
    cin >> colsize;
    matrix.Resize(rowsize, colsize);
}

// *****************************************************************
// * Function Name: Main
// * Description: Interface for testing the matrix class. 
// * Prompts the user to create 2 matrix objects.
// * Then prompts user with a menu for testing different functions on the 2 matrices.
// * Date: 10-17-24
// * Author: Isaac Jacques
// * References:  matrix.h
// ***************************************************************** 
int main() {
    int rowsize = 0;
    int colsize = 0;

   
    cout << "Welcome to the Matrix Multiplier!" <<endl;
    cout << "Enter the number of rows for your first matrix:" <<endl;
    cin >> rowsize;
    cout << "Enter the number of columns for your first matrix:" <<endl;
    cin >> colsize;
    Matrix_Class MyMatrix1(rowsize,colsize);
    MyMatrix1.Input();
    MyMatrix1.Print("Matrix 1");
   
    cout << "Enter the number of rows for your second matrix:" <<endl;
    cin >> rowsize;
    cout << "Enter the number of columns for your second matrix:" <<endl;
    cin >> colsize;
    Matrix_Class MyMatrix2(rowsize,colsize);
    MyMatrix2.Input();
    MyMatrix2.Print("Matrix 2");
    Matrix_Class MyMatrix3;

    char option;
    PrintMainMenu();
    cin>>option;
    while(option != 'E' ||option !='e')
    {
        switch (option) {
            case 'I':
            case 'i':
                PrintSelectionMenu("Select a matrix to Input values");
                cin>>option;
                if(option == '1') {
                    MyMatrix1.Input();
                } else if (option == '2') {
                    MyMatrix2.Input();
                }
                break;
            case 'R':
            case 'r':
                PrintSelectionMenu("Select a matrix to Resize");
                cin>>option;
                if(option == '1') {
                    ResizeMatrix(MyMatrix1);
                } else if (option == '2') {
                    ResizeMatrix(MyMatrix2);
                }
                break;
            case 'P':
            case 'p':
                PrintSelectionMenu("Select a matrix to Print");
                cin>>option;
                if(option == '1') {
                    MyMatrix1.Print("Matrix 1");
                } else if (option == '2') {
                    MyMatrix2.Print("Matrix 2");
                }
                break;
            case 'M':
            case 'm':
                MyMatrix3 = MyMatrix1 * MyMatrix2;
                if(MyMatrix1.Getcolsize() != MyMatrix2.Getrowsize()) {
                    return 0;
                } else {
                    MyMatrix3.Print("Matrix Output Duplicate Multiplication");
                }
                break;
            case 'e':
            case 'E': 
                cout << "I am done Neo! !" <<endl;
                return 0;
            default:
                cout << "Invalid Option" << endl;
        }
        PrintMainMenu();
        cin>>option;
    }

    return 0;
}


