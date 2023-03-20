// DynamicMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void arr_add(int*& arr, int length, int num) {
    if (num <= 0)
        return;
    int* tmp = new int[length + num] {};//Заполняем нулями оставшиеся ячейки
    for (int i = 0; i < length; i++)
        tmp[i] = arr[i];
    delete[] arr;
    arr = tmp;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;

    //Динамические переменные
   /* int* pointer = new int;//Выделение динамической памяти размером 4 байта
    *pointer = 7;//Запись значения выделенную в область памяти
    std::cout << "*pointer=" << *pointer << std::endl;

    delete pointer;//Очистка предыдущей выделенной памяти - для того чтобы другие приложения могли использовать это участок памяти

    //*pointer = 100; ОШИБКА



    pointer = new int;
    *pointer = 15;
    std::cout<< "*pointer=" << *pointer << std::endl;

    delete pointer;*/

    //Динамические массивы
    //Отличия динамического от статическогоЖ
    //1 В качестве длины динамического массива может быть указана переменная
    //2 С помощью специальных программных конструкций размер динамического массива может быть изменен
    //3 Т.к. статический массив находится в стеке, работа с ним происходит в разы быстрее
    //4 Элементы динамического массива необходимо очищать, чтобы не допускать утечки памяти

   /* int d_size;
    std::cout << "Введите длину массива: ";
    std::cin >> d_size;

    int* d_arr = new int[d_size];

   // int* d_arr = new int[10];

    std::cout << "Ввод данных в массив: ";
    for (int i = 0; i < 10; i++) {
        std::cout << "Введите " << i + 1 << " элемент";
        std::cin >> d_arr[i];
    }
    std::cout << "получившийся массив: \n[";
    for (int i = 0; i < 10; i++) 
        std::cout << d_arr[i]<<", ";
        std::cout << "\b\b]\n";
        delete[] d_arr;*/

        //Двумерные динамические массивы
    /*int rows, cols;
    std::cin >> rows >> cols;
    //int* mx = new int[rows][cols]; ERROR

    int** mx = new int* [rows];
    for (int i = 0; i < rows; i++)
        mx[i] = new int[cols];//Выделение памяти под двумерный динамический массив
    //Использование массива
    mx[0][0] = 10;

    //Освобождение памяти
    for (int i = 0; i < rows; i++)
        delete[] mx[i];
    delete[] mx;*/

    //Задача 1. Увеличение размера массива
    std::cout << "Введите размер массива: ";
    int size1;
    std::cin >> size1;
    int* arr1 = new int[size1];
    srand(time(NULL));
    std::cout << "Изначальный массив: \n";
    for (int i = 0; i < size1; i++) {
        arr1[i] = rand() % 10 + 1;
        std::cout << arr1[i] << '\t';
    }
    std::cout << std::endl;

    std::cout << "Введите количество дополнительных элементов: ";
    std::cin >> n;
    arr_add(arr1, size1, n);
    size1 += n;

    std::cout << "Итоговый массив: \n";
    for (int i = 0; i < size1; i++)
        std::cout << arr1[i] << '\t';
    std::cout << std::endl;

    //Прочитать про move-семантику

}

