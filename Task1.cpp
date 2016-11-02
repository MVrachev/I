#include <iostream>

using namespace std;

/*

Task 1
Create a function: 
char* generateLookAndSay(int level);

which generate the line look-and-say from a row level and returns it as a string
with dynamic memory allocation.

The row starts from 1(row 1) and every next row is created by "reading" of the last row.
Here are the first few rows:

1, 11 (one 1), 21 (two 1), 1211 (one 2, one 1), 111221 (one 1, one 2, two 1), 312211 (three
1, two 2, one 1), 13112221, .....

Example: 
Input:
7

Output (result):
13112221

*/


int countEqualDigits(char *temp, int index, char currDigit);

int convertDigit(int digit)
{
	if (digit <= 9 && digit > 0)
	{
		switch (digit)
		{
		case(1) : return '1';
		case(2) : return '2';
		case(3) : return '3';
		case(4) : return '4';
		case(5) : return '5';
		case(6) : return '6';
		case(7) : return '7';
		case(8) : return '8';
		case(9) : return '9';
		default:
			cerr << "Uknown problem!\n";
			return '0';
		}
	}
	else
	{
		cerr << "This number is  more than 9 or its below 0! Problem!\n";
		return '0';
	}
}

char* generateLookAndSay(int level)
{
	char tempArr[256];
	int common = 1;
	char tempDigit = '\0'; 
	int oldIndex;
	int newIndex;
	for (int i = 0; i < level; ++i)
	{
		oldIndex = 0;
		newIndex = 0;
		if (i == 0)
		{
			tempArr[i] = '1';
			tempArr[i + 1] = '\0';
			oldIndex = 2;
			continue;
		}
		char *oldArray = new(nothrow) char[strlen(tempArr) + 1];
		if (!oldArray)
		{
			cerr << "Problem creating the oldArray array!\n";
			return nullptr;
		}
		strcpy_s(oldArray, strlen(tempArr) + 1, tempArr);
		int oldArrLenght = strlen(tempArr);
		while (oldIndex != oldArrLenght)
		{
			tempDigit = oldArray[oldIndex];
			common = countEqualDigits(oldArray, oldIndex, oldArray[oldIndex]);
			if (convertDigit(common) == '0')
				return nullptr;
			else
				tempArr[newIndex] = convertDigit(common);
			tempArr[newIndex + 1] = tempDigit;
			oldIndex += common;
			newIndex += 2;
		}
		tempArr[newIndex] = '\0';
		delete[]oldArray;
	}
	char *result = new(nothrow)char[newIndex + 1];
	if (!result)
	{
		cerr << "Problem allocating the result char array!\n";
	}
	strcpy_s(result, newIndex + 1, tempArr);
	return result;
}



int countEqualDigits(char *temp, int index, char currDigit)
{
	int amountEqual = 0;
	while (temp[index] != '\0' && temp[index] == currDigit)
	{
		++amountEqual;
		++index;
	}
	return amountEqual;
	return 0;
}

int main(){
	
	int level = 1;
	int rightLevel = -1;
	do
	{
		if (rightLevel == -1)
			cout << "Input the level of the sequence you want to see.\n";
		else
			cout << "The level shoud be a positive number!\n";
		++rightLevel;
		cin >> level;
	} while (level <= 0);
	
	char *temp = generateLookAndSay(level);
	if (!temp)
	{ 
		cerr << "Problem with the program!\n";
		return -1;
	}
	cout << "result:\n" << temp << endl;
	delete[] temp;
	return 0;
}
