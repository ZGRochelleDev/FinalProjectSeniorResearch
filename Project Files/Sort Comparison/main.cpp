
/*
* Final Project for Senior Research - Fall 2017 CSC-450-02
* Objective:
*	Test edge cases and averages of three popular sorting methods.
*	Make a prediction based on what you know.
*	Graph results
*	Present findings to class
*	
*	C++ program for QuickSort | insertion sort | BubbleSort
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

//QuickSort class instantiate object QuickSort
class QuickSort {

	public:
		int n;
		int list[];

		void read()
		{
			std::ifstream fin("numbersToSort.txt", std::ios::binary);
			for (long i = 0; i < n; i++)
			{
				fin.read((char*)&list[i], sizeof(int));
			}
			fin.close();
		}

		long partition(long left, long right)
		{
			int pivot_element = list[left];
			int lb = left, ub = right;
			int temp;

			while (left < right)
			{
				while (list[left] <= pivot_element)
					left++;
				while (list[right] > pivot_element)
					right--;
				if (left < right)
				{
					temp = list[left];
					list[left] = list[right];
					list[right] = temp;
				}
			}
			list[lb] = list[right];
			list[right] = pivot_element;
			return right;
		}

		void quickSort(long left, long right)
		{
			if (left < right)
			{
				long pivot = partition(left, right);
				quickSort(left, pivot - 1);
				quickSort(pivot + 1, right);
			}
		}
};

// Insertion sort function to sort array
void insertionSort(int list[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = list[n];
		j = i - 1;
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

//generic swap for BubbleSort
template<typename T>  
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}


// BubbleSort sort function to sort array
void bubbleSort(int list[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (list[j] > list[j - 1])
				swap(list[j], list[j - 1]);
}

//Driver program to compare sorts
int main() {
	const int n = 100;
	int list[n];
	//std::ifstream ifs("numbersToSort.txt");
	std::fstream myfile("numbersToSort.txt", std::ios_base::in);

	double t1, t2;
	//bubbleSort
	t1 = clock();
	bubbleSort(list, n);
	t2 = clock();
	std::cout << "BubbleSort sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

	//run insertion sort
	t1 = clock();
	insertionSort(list, n);
	t2 = clock();
	std::cout << "Insertion sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

	//run Quicksort
	QuickSort QuickSort_obj;
	QuickSort_obj.read();
	t1 = clock();
	QuickSort_obj.quickSort(0, n - 1);
	t2 = clock();
	std::cout << "Quicksort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

}