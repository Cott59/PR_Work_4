#include <iostream>
#include <ctime>
#include <cstdlib>



void print_arr(int arr[], const int length) {
	
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

void clear_arr(int arr[], const int length, int num1) {
	for (int i = 0; i < length; i++)
		if (arr[i] == num1)
			arr[i] = 0;
}

int  index_sum(int arr1[], int arr2[], const int length1, const int length2, int index) {
	if (index >= length1 || index >= length2||index<0) {
		std::cout << " ERROR \n";
		return 0;
	}
	return (arr1[index] + arr2[index]);
}

template<typename T>
double mean_arr(T arr, const int length) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	return ((min + max) / 2.0);
}

void prime_range(int num1, int num2) {
	for (int i = num1; i <= num2; i++) {
		int counter = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				counter++;
		}
		if (counter == 2)
			std::cout << i << ' ';
	}
}

void prime_range(int num2) {
	for (int i = 1; i <= num2; i++) {
		int counter = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				counter++;
		}
		if (counter == 2)
			std::cout << i << ' ';
	}
}
template<typename T>
void permute_arr(T arr, const int length) {
	if (length%2==0)
		for (int i = 0; i <= length / 2; i++)
			for (int j = length - 1; j >= length / 2; j--)
				std::swap(arr[i], arr[j]);
	else
		for (int i = 0; i <= length / 2; i++)
			for (int j = length - 1; j >= length / 2; j--)
				std::swap(arr[i], arr[j]);

}




int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	const int size1 = 20;
	int arr1[size1];
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
		arr1[i] = rand() % 50;
	std::cout << " Массив 1 \n";
	print_arr(arr1, size1);

	std::cout << " Введите число : ";
	std::cin >> n;
	clear_arr(arr1,size1,n);
	print_arr(arr1, size1);

	const int size2 = 20;
	int arr2[size2];
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
		arr2[i] = rand() % 80;
	std::cout << " Массив 2 \n";
	print_arr(arr2, size2);
	int index;
	std::cout << " Введите число : ";
	std::cin >> index;
	std::cout <<" Сумма элементов под индексов "<<index<<" = "<< index_sum(arr1, arr2, size1, size2, index);
	std::cout << "\n\n";
	std::cout<<" среднее арифметическое минимального и максимального числа в массиве 2 = "<< mean_arr(arr2, size2);
	std::cout << "\n\n";
	std::cout << "Простые числа от 10 до 30:\n";
	prime_range(10, 30);
	std::cout << "\nПростые числа от 1 до 20:\n";
	prime_range(20);
	std::cout << "\n\n";

	const int size3 = 8;
	int arr3[size3];
	
	for (int i = 0; i < size3; i++)
		arr3[i] = rand() % 11;
	std::cout << " задача 5 \n Массив 2  Изначальный \n";
	print_arr(arr3, size3);
	permute_arr(arr3,size3);
	std::cout << " Массив 2  Итоговый \n";
	print_arr(arr3, size3);


	return 0;
}