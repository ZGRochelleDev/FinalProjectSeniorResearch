
/*
* Objective:
*	Many sorting algorthims handle "nearly sorted" lists differently.
*	There is variation in their running times based on the percent of 'sortedness'.
*	Quicksort struggles with nearly sorted lists while insertion performes well.
*
* This code generates a list of numbers that are sorted by a percent.
* Places the sorted data into an array.
* The array will be unsorted by user chosen amount.
* Then, write to file.
*/

#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //find
#include <array>
#include <string>

const long n = 1000;
int my_sorted_array[n];
std::vector<int> used;


void put_data_into_array(std::string file_name) {

	std::ifstream myfile(file_name);
	for (long i = 0; i < n; i++)
	{
		myfile >> my_sorted_array[i];
	}
	myfile.close();

	/*
	std::cout << "check array contents: " << std::endl;
	for (int i = 0; i < n; i++) {
	std::cout << my_sorted_array[i] << std::endl;
	}
	*/
}

template<typename T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

void unsort() {
	int x, y;
	std::vector<int>::iterator find_x;
	std::vector<int>::iterator find_y;
	find_x = find(used.begin(), used.end(), x);
	find_y = find(used.begin(), used.end(), x);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1.0, 1000.0);
	std::cout << "picking random numbers in array: " << std::endl;

	/*Below, "unsortNumber" is the % that will be unsorted.
	* Must be half of desired value. Ex: for 80% sorted you need 20% unsorted.
	* So... 20% = 100,000. 100,000 / 2 = 50,000. Therefore for 20%, unsortNumber = 50000;
	*/
	int unsortNumber = 200000;
	for (int i = 0; i < unsortNumber; ++i) {
		if (find_x != used.end()) {
			x = dist(mt);
			//std::cout << "doing x: " << x << std::endl;
		}
		used.push_back(x);

		if (find_y != used.end()) {
			y = dist(mt);
			//std::cout << "doing y: " << y << std::endl;
		}
		used.push_back(y);

		//std::cout << "swap: " << my_sorted_array[x] << " with: " << my_sorted_array[y] << std::endl;
		swap(my_sorted_array[x], my_sorted_array[y]);
	}

}

int driver() {
	std::string file_name = "sorted.txt";
	put_data_into_array(file_name);

	unsort();

	std::cout << "Writing array contents to file: " << std::endl;
	std::ofstream myfile;
	int percent;
	std::cout << "What percent should the date be sorted: " << std::endl;
	std::cin >> percent;
	myfile.open("20percent.txt"); //Change the file name 20%

	for (int i = 0; i < 1000; ++i) {
		myfile << my_sorted_array[i] << std::endl;
	}

	myfile.close();

	std::cout << "Write to file complete: " << std::endl;
	std::cout << "Check the usedVector contents: " << std::endl;
	std::cout << used.size() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "End program: " << std::endl;
}