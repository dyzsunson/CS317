#include <iostream>


using namespace std;

//Bubble Sort 

void Bubblesort(int array[], int n)
{
	int i, j, temp;
	for (j = 0; j <n-1; j++)
	{
		for (i = 0; i <n-1-j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
		}
	}
	int k;
	cout << "Bubble sort:    ";
	for (k = 0; k < n; k++)
	{
		cout << array[k] << " ";
	}

	cout << endl;
}


//Insertion Sort 

void Insertionsort(int array[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		int j = i;
		while (j >= 0 && array[j]<array[j-1])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
	int k;
	cout << "Insertion sort: ";
	for (k = 0; k < n; k++)
	{
		cout << array[k] << " ";
	}

	cout << endl;
}


//Recursive Fibonacci Sequence 

int Fibonacci(int n)
{
	if (n <= 0)
		return 0;
	else if (n==1)
		return 1;
	else
	return Fibonacci(n - 1) + Fibonacci(n - 2);
	
}


//Recursive Factorial

int Factorial(int n)
{
	if (n <= 0)
		return 1;
	else
		return n*Factorial(n - 1);
}

int main()
{
	int number[] = {30,15,16,44,89,71,56,48};
	int size = sizeof(number)/sizeof(number[0]);
	int a = 7;
	cout << "The array is {30,15,16,44,89,71,56,48}" << endl << "the given number is " << a << endl<< endl;
	Bubblesort(number, size);
	Insertionsort(number, size);
	cout << "Fibonacci sequence: " << Fibonacci(a) << " " << endl;
	cout << "Factorial: " << Factorial(a) << " " << endl;
	printf("1234567678");
	
}