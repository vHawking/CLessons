/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №3.
 * @author Вадим Ястребов.
 * @date 07.03.2018 г.
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
 * 1. Оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не
 * оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
 */

// Заполнение массива случайными числами.

void fillArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

// Копирование заполненного массива для сравнения количества операций. Это необходимо, чтобы все сортировки работали
// с одним одной и той же сгенерированной последовательностью элеметов, а не с разными рандомными версиями.

void copyArray(int *arrFrom, int *arrTo, int len) {
    int i;
    for (i = 0; i < len; i++)
        arrTo[i] = arrFrom[i];
}

// Вывод массива в консоль.

void printArray(int *arr, int len) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

// Пишем функцию для склонения слова «цикл» в зависимости от его числового значения.

char *counterVars(int counter) {
    int x1;
    int x2;
    x1 = counter % 10;
    x2 = counter % 100;

    if (x1 == 1 && x2 != 11) {
        return "цикл";
    } else if (x1 >= 2 && x1 <= 4 && (x2 < 10 || x2 >= 20)) {
        return "цикла";
    } else {
        return "циклов";
    }
}

// Вывод счетчика в консоль.

void printCounter(int counter) {
    printf("Количество операций – %d %s.\n", counter, counterVars(counter));
}

// Функция обмена местами соседних элементов массива.

void swapArr(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Классическая сортировка "пузырьком".

int bubbleSort(int *arr, int len) {
    int i;
    int j;
    int counter = 0;

    for (j = 0; j < len; j++) {
        for (i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swapArr(&arr[i], &arr[i + 1]);
            }
            counter++;
        }
    }
    return counter;
}

// Оптимизированная сортировка "пузырьком".

int bubbleSortPlus(int *arr, int len) {
    int i;
    int j;
    int counter = 0;

    for (i = 0; i < len; i++) {
        int flag = 1;
        for (j = (i % 2) ? 0 : 1; j < len - 1; j += 2) {
            if (arr[j] > arr[j + 1]) {
                swapArr(&arr[j], &arr[j + 1]);
                flag = 0;
            }
            counter++;
        }
        if (flag) {
            break;
        }
    }
    return counter;
}

// "Пузырьковая" сортировка с использованием цикла while.

int bubbleSortWhile(int *arr, int len) {
    char isSorted = 0;
    int counter = 0;

    while (!isSorted) {
        isSorted = 1;
        int i;
        for (i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                isSorted = 0;
                swapArr(&arr[i], &arr[i + 1]);
            }
            counter++;
        }
    }
    return counter;
}

// "Пузырьковая" сортировка с использованием цикла do-while.

int bubbleSortDoWhile(int *arr, int len) {
    char isSorted;
    int counter = 0;

    do {
        isSorted = 1;
        int i;
        for (i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                isSorted = 0;
                swapArr(&arr[i], &arr[i + 1]);
            }
            counter++;
        }
    } while (!isSorted);
    return counter;
}

/*
 * 2. *Реализовать шейкерную сортировку.
 */

int shakerSort(int *arr, int len) {
    int counter = 0;
    int left = 1;
    int right = len - 1;

    while (left <= right) {
        int i;
        for (i = left; i <= right; i++) {
            if (arr[i - 1] > arr[i]) {
                swapArr(&arr[i], &arr[i - 1]);
            }
            counter++;
        }
        right--;
        for (i = right; i >= left; i--) {
            if (arr[i - 1] > arr[i]) {
                swapArr(&arr[i], &arr[i - 1]);
            }
            counter++;
        }
        left++;
    }
    return counter;
}

int main() {
    setlocale(LC_ALL, ".1251");
    setbuf(stdout, NULL);

    const int len = 15;
    int arr0[len];
    int arr1[len];
    int arr2[len];
    int arr3[len];
    int arr4[len];
    int count;

    // Заполняем массив и копируем его для проверки всех написанных алгоритмов сортировки.

    fillArray(arr0, len);
    copyArray(arr0, arr1, len);
    copyArray(arr0, arr2, len);
    copyArray(arr0, arr3, len);
    copyArray(arr0, arr4, len);

    printf("\nМассив до сортировки:\n");
    printArray(arr0, len);

    printf("\nПузырьковая сортировка циклами for-for:\n");
    count = bubbleSort(arr0, len);
    printArray(arr0, len);
    printCounter(count);

    printf("\nУлучшенная пузырьковая сортировка циклами for-for:\n");
    count = bubbleSortPlus(arr1, len);
    printArray(arr1, len);
    printCounter(count);

    printf("\nУлучшенная пузырьковая сортировка циклом while:\n");
    count = bubbleSortWhile(arr2, len);
    printArray(arr2, len);
    printCounter(count);

    printf("\nУлучшенная пузырьковая сортировка циклом do-while:\n");
    count = bubbleSortDoWhile(arr3, len);
    printArray(arr3, len);
    printCounter(count);

    printf("\nШейкерная сортировка:\n");
    count = shakerSort(arr4, len);
    printArray(arr4, len);
    printCounter(count);

    return 0;
}