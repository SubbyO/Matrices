#include <iostream>
using namespace std;

//Create the Matrix class
class Matrix
{
	public:
//Create a constructor to initialize the variables of Matrix objects
		Matrix(int len, int wid, int nums[10][10])
		{
			setLength(len);
			setWidth(wid);
			setNumbers(nums);
		}
//Setter methods
		void setLength(int len)
		{
			length = len;
			return;
		}
		void setWidth(int wid)
		{
			width = wid;
			return;
		}
		void setNumbers(int nums[10][10])
		{
			for(int i = 0; i < length; i++)
			{
				for(int j = 0; j < width; j++)
				{
					numbers[i][j] = nums[i][j];
				}
			}
			return;
		}
//Getters
		int getLength()
		{
			return length;
		}
		int getWidth()
		{
			return width;
		}
		int getValue(int len, int wid)
		{
			return numbers[len][wid];
		}
//Print method to display Matrix values
		void print()
		{
			for(int i = 0; i < length; i++)
			{
				cout<<"\n";
				for(int j = 0; j < width; j++)
				{
					cout<< numbers[i][j] << "\t";
				}
			}
			cout<<"\n";
			return;
		}
//Mathematical operation class methods
		static Matrix Add(Matrix mat1, Matrix mat2)
		{
			int rnums[10][10] = {0};
			for(int i = 0; i < mat1.getLength(); i++)
			{
				for(int j = 0; j < mat1.getWidth(); j++)
				{
					rnums[i][j] = mat1.getValue(i, j) + mat2.getValue(i, j);
				}
			}
			Matrix resultant(mat1.getLength(), mat1.getWidth(), rnums);
			return resultant;
		}
		static Matrix Subtract(Matrix mat1, Matrix mat2)
		{
			int rnums[10][10] = {0};
			for(int i = 0; i < mat1.getLength(); i++)
			{
				for(int j = 0; j < mat1.getWidth(); j++)
				{
					rnums[i][j] = mat1.getValue(i, j) - mat2.getValue(i, j);
				}
			}
			Matrix resultant(mat1.getLength(), mat1.getWidth(), rnums);
			return resultant;
		}
		static Matrix Multiply(Matrix mat1, Matrix mat2)
		{
			int rnums[10][10];
			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < 10; j++)
				{
					rnums[i][j] = 0;
				}
			}
			for(int i = 0; i < mat1.getLength(); i++)
			{
				for(int j = 0; j < mat2.getWidth(); j++)
				{
					for(int k = 0; k < mat1.getWidth(); k++)
					{
						rnums[i][j] += mat1.getValue(i, k) * mat2.getValue(k, j);
					}
				}
			}
			Matrix resultant(mat1.getLength(), mat2.getWidth(), rnums);
			return resultant;
		}
//Instance Variables
	private:
		int length, width;
		int numbers[10][10];
};