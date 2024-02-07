#include<iostream>
using namespace std;

void printAvg(int array[], int counter);
void findValue(int array[], int counter);
void findSmall(int (&array)[10], int counter);

int main()
{
	int Table[10] = {};
	int number = 0;
	int counter = 0;

	do
	{
		cout << "There are " << counter << " elements in the array";
		cout << "\n\nEnter at least 5 numbers(Maximum of 10), enter a negative number once you have put in at least 5 numbers: ";
		cin >> number;

		cout << endl;

		if (number < 0 && counter < 5)
		{
			do
			{
				cout << "There are " << counter << " numbers in the array, you need to put at least " << 5 - counter << " more numbers in: ";
				cin >> number;
				cout << endl;
			} while (number < 0);
		}
		else if (number < 0)
		{
			break;
		}
		

		Table[counter] = number;

		counter++;


	} while (counter < 10);

	cout << "\nThere are " << counter << " elements in the array\n\n";

	cout << "The elements are: ";

	for (int i = 0; i < counter; i++)
	{
		cout << Table[i] << " ";
	}

	cout << endl << endl;

	printAvg(Table, counter);
	findValue(Table, counter);
	findSmall(Table, counter);

	return 0;
}

void printAvg(int array[], int counter)
{
	int sum = 0;
	int average = 0;
	int lessThan = 0;
	int equal = 0;
	int greaterThan = 0;

	for (int k = 0; k < counter; k++)
	{
		sum += array[k];
	}

	average = sum / counter;

	for (int j = 0; j < counter; j++)
	{
		if (array[j] < average)
		{
			lessThan++;
		}
		else if (array[j] == average)
		{
			equal++;
		}
		else if (array[j] > average)
		{
			greaterThan++;
		}
	}

	cout << "The average of the array is " << average << endl;
	cout << "The amount of numbers in the array that are less than the average is " << lessThan << endl;
	cout << "The amount of numbers in the array that are equal to the average is " << equal << endl;
	cout << "The amount of numbers in the array that are greater than the average is " << greaterThan << endl << endl;
}
void findValue(int array[], int counter)
{
	char answer = '\0';

	do
	{
		int value = 0;
		int index = -1;
		
		do
		{
			cout << "Enter a value to search for: ";
			cin >> value;

			if (!value)
			{
				cout << "ERROR: Was not a integer\n\n";
			}
			cin.clear();
			cin.ignore();

		} while (!value);

		

		for (int i = 0; i < counter; i++)
		{
			if (array[i] == value)
			{
				index = i;
				break;
			}
		}

		if (index == -1)
		{
			cout << "\nValue not found\n\n";
		}
		else
		{
			cout << "\nValue was found at index " << index << endl << endl;
		}

		cout << "Enter Y to search for another value: ";
		cin >> answer;
		cout << endl;

	} while (toupper(answer) == 'Y');
}

void findSmall(int(&array)[10], int counter)
{
	int smallest = array[0];
	int index = 0;

	for (int i = 0; i < counter; i++)
	{
		if (i + 1 >= counter)
		{
			break;
		}
		else if (smallest > array[i + 1])
		{
			smallest = array[i + 1];
			index = i + 1;
		}
	}

	cout << "The smallest number in the array is " << smallest << " and it is located at index " << index << endl << endl;

	array[index] = array[0];
	array[0] = smallest;

	cout << "This is the array with the first element and smallest value switched: \n\n";

	for (int k = 0; k < counter; k++)
	{
		cout << array[k] << " ";
	}

	cout << endl << endl;
}