#include<iostream>
#include<cstdlib>
#include<ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}

template<typename T>
void arr_app(T*& arr, int length, int num) {
	if (num <= 0)
		return;
	//Выделение памяти под новый массив нужного размера
	T* tmp = new T[length + num]{};
	//Копирование значений старого массива в новый
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	//Освобождение памяти, выделенной под старый массив
	delete[] arr;
	//Перенаправление указателя на новый массив.
	arr = tmp;
}

template<typename T>
	void arr_del(T*& arr, int length, int num){
		if (num <= 0)
			return;
		if (num >= length) {
			delete[] arr;
			arr = nullptr;
			return;
		}

		T* tmp = new T[length - num];
		for (int i = 0; i < length - num; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	//Динамическая память
	int* pointer = new int;//выделение участка динамической памяти размером в тип int(4 байта)

	*pointer = 7;
	std::cout << "*pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;
	if(pointer == nullptr)
	delete pointer;//освобождение памяти, выделенной динамически.


	pointer = new int;
	*pointer = 15;

	std::cout << "*pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;
	 //Утечка памяти - явление когда всвязи м небрежным применением указателей,
	 // в памяти остаются значения, не связанные с каким либо указателями.
	// Данные значения "блокируют" ячейки памяти и не дают другим программах с ними взаимодействовать.
	delete pointer;
	pointer == nullptr; 

	//Одномерные динамические массивы'
	std::cout << "Введите длину массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];
	fill_arr(darr, dsize, 1, 11);

	std::cout << "Массив:\n";
	print_arr(darr, dsize);

	delete[] darr;

	//Области прис=менения динамических массивов:
	//1.Размер массива не известен на этапе написания кода.
	//2.Размер массива должен иметь возможность измениться.
	//3.Реализация сложных структур данных.
	

	//Двумерные динамические массивы.
	int rows = 5, cols = 5;
	//int* mx = new int[rows][cols]; не работает.
	
	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];

	for (int i = 0; i < rows; i++)
		delete[]mx[i];
	delete[] mx;
	

	//Задача 1. Увеличение размеров массива
	std::cout << "Введите размер массива-> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите колличество новых элементов -> ";
	std::cin >> n;
	arr_app(arr1, size1, n);
	if (n > 0);
		size1 += n;

	std::cout << "Итоговый массив\n";
	print_arr(arr1, size1);

	delete[] arr1;

	//Задача 2.Уменьшение размера массива
	std::cout << "Введите размер массива-> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);

	std::cout << "Введите колличество элементов для удаления -> ";
	std::cin >> n;
	arr_del(arr2, size2, n);
	if (n >= size2)
		size2 = 0;
	if (n > 0);
		size2 -= n;

	std::cout << "Итоговый массив\n";
	print_arr(arr2, size2);

	delete[] arr2;






	return 0;
}