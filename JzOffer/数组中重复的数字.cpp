#include<iostream>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		// first check input
		if (length < 2)
			return false;
		for (int i = 0; i<length; i++)
			if (numbers[i] >= length || numbers[i] < 0)
				return false;
		int i = 0;
		while (i < length)
		{
			if (numbers[i] == i)
			{
				i++;
				continue;

			}
			if (numbers[numbers[i]] == numbers[i])
			{
				*duplication = numbers[i];
				return true;
			}
			else
			{
				swap(numbers, i, numbers[i]);
			}
		}

		return false;
	}


	void swap(int data[], int i, int j)
	{
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
};