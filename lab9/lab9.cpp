/*
Alex Roeum
4/7/2015
Section 003

Lab 9

Description: Create a program that will output data from a file in the form of a 2d array and 
	calculate the product of each row.
input: the file
processing: using nested for loops to input and output the array and find the product of each
output: the output of the array and the product of each
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(double array[][100], int &row, int &col);
void outputArray(double array[][100], int row, int col);
void getRow(double productRay[100], double array[][100], int row, int col);

int main()
{
	int row, col;
	double array[100][100];
	double productRay[100];
	readFile(array, row, col);
	outputArray(array, row, col);
	getRow(productRay, array, row, col);

	for (int i = 0; i < row; i++)
	{
		cout << "The product of row "<< i << " is " <<productRay[i]<<"."<<endl;

	}

	return 0;
}

/*
Description: Reads the file and adds the values to a 2d array
*/
void readFile(double array[][100], int &row, int &col)
{
	fstream filein;
	filein.open("Lab93.dat");

	if (!filein.fail())
	{

		filein >> row;
		filein >> col;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				filein >> array[i][j];
			}
		}
	}//if the file does not fail

	else
	{
		cout << "Error reading the file" << endl;
	}
	filein.close();
}

/*
Description: outputs the array
*/
void outputArray(double array[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(5)<< array[i][j] << " ";
		}
		cout << endl;
	}
}

/*
Description: Gets the product of a certain row
*/
void getRow(double productRay[12], double array[][12], int row, int col)
{


	for (int i = 0; i < 100; i++)
	{
		productRay[i] = 1;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			productRay[i] = productRay[i] * array[i][j];
		}
	}
}