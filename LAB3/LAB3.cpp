// Задана действительная матрица Aij размерности n×m.
  // Написать программу, которая определяет целые числа
  //  b1, b2, …, bn, равные индексам максимальных
  //  элементов строк матрицы
  //  (если в строке 2 и более максимальных элементов,
  //  то использовать любой индекс). 

#include <iostream>
#include <random>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    // Задаем параметры массива
    int N, M;

    std::cout << "Введите количество столбцов матрицы: " << std::endl;
    std::cin >> N;
    std::cout << "Введите количество строк матрицы: " << std::endl;
    std::cin >> M;

    int** massiv;
    massiv = new int* [M];

    for (int i = 0; i < N; i++) {
        massiv[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            massiv[i][j] = rand();
        }
    }

    //Вывод массива на экран

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << " " << massiv[i][j];
        }
        std::cout << std::endl;
    }


    int num = 0;
    int Max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Max < massiv[i][j]) {
                Max = massiv[i][j];
                num = j;
            }
        }
        std::cout << num << " " << Max << std::endl;
        Max = 0;
    }

    for (int i = 0; i < N; i++) {
        delete[] massiv[i];
    }
    delete[] massiv;

    return 0;
}