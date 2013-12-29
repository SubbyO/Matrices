#include "Matrix.h"

void main()
{
	//Define variables used to create matrices
	int length, width;
	int numbers[10][10] = {0};
	//Ask the user for input to determine the structure of the first matrix
define:cout << "Enter the length of matrix 1 (max. 10) : ";
	cin >> length;
	cout << "\nEnter the width of matrix 1 (max. 10) : ";
	cin >> width;
//Make sure the user's input doesn't exceed the maximum length/width of 10 and prompt for the values in the first matrix
	if(length <= 10 && width <= 10)
	{
		for(int i = 0; i < length; i++)
		{
			for(int j = 0; j < width; j++)
			{
				cout << "\nEnter matrix 1 value for Row [" << i+1 << "] Column [" << j+1 << "] : ";
				cin >> numbers[i][j];
			}
		}
	}
	else
	{
		cout << "Please enter a length/width that is no greater than 10.\n";
		goto define;
	}
	//Create the first matrix according to the data given by the user
	Matrix matrix1(length, width, numbers);
	//Ask the user for input to determine the structure of the second matrix
define2:cout << "\n\nEnter the length of matrix 2 (max. 10) : ";
	cin >> length;
	cout << "\nEnter the width of matrix 2 (max. 10) : ";
	cin >> width;
//Make sure the user's input doesn't exceed the maximum length/width of 10 and prompt for the values in the second matrix
	if(length <= 10 && width <= 10)
	{
		for(int i = 0; i < length; i++)
		{
			for(int j = 0; j < width; j++)
			{
				cout << "\nEnter matrix 2 value for Row [" << i+1 << "] Column [" << j+1 << "] : ";
				cin >> numbers[i][j];
			}
		}
	}
	else
	{
		cout << "Please enter a length/width that is no greater than 10.\n";
		goto define2;
	}
	//Create the 2nd matrix according to the data given by the user
	Matrix matrix2(length, width, numbers);
	//Prompt the user for which mathematical operation they would like to perform on the matrices
select:cout << "\nWhat operation would you like to perform on the two matrices? Enter 'A' for addition, 'S' for subtraction, or 'M' for multiplication : ";
	char input;
	cin >> input;
	//Create a pointer to the matrix that results from the mathematical operation being performed
	Matrix* resultant;
	switch(input)
	{
		//If the user enters 'A,' the program will check if the two matrices are dimensionally alike and add them if they are
		case 'A': if((matrix1.getLength() == matrix2.getLength()) && (matrix1.getWidth() == matrix2.getWidth()))
					  resultant = &Matrix::Add(matrix1, matrix2);
				  else
				  {
					  cout << "The two matrices are unsuitable for addition, please redefine them.\n\n";
					  goto define;
				  }
			break;
		//If the user enters 'S,' the program will check if the two matrices are dimensionally alike and subtract them if they are
		case 'S': if((matrix1.getLength() == matrix2.getLength()) && (matrix1.getWidth() == matrix2.getWidth()))
					  resultant = &Matrix::Subtract(matrix1, matrix2);
				  else
				  {
					  cout << "The two matrices are unsuitable for subtraction, please redefine them.\n\n";
					  goto define;
				  }
				  break;
		//If the user enters 'M,' the program will check if the two matrices are commensurate and multiply them if they are
		case 'M': if(matrix1.getWidth() == matrix2.getLength())
					  resultant = &Matrix::Multiply(matrix1, matrix2);
				  else
				  {
					  cout << "The two matrices are incommensurate, please redefine them.\n\n";
					  goto define;
				  }
				  break;
		//If the user enters anything other than 'A,' 'S,' or 'M,' the program will return to the operation selection menu
		default: cout << "Your selection was invalid, please enter a valid input.\n";
			goto select;
			break;
	}
	//Print out the matrix that results from the mathematical operation the user selected
	cout << "\nThe resultant matrix is : ";
	resultant->print();
	//Wait for user input before closing
	system("pause");
	return;
}