/**
 * �������� ������� �� ����� "��������� � ��������� ������".
 *
 * @version ������ �3.
 * @author ����� ��������.
 * @date 07.03.2018 �.
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
 * 1. �������������� ����������� ����������. �������� ���������� �������� ��������� ���������������� � ��
 * ���������������� ���������. �������� ������� ����������, ������� ���������� ���������� ��������.
 */

// ���������� ������� ���������� �������.

void fillArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

// ����������� ������������ ������� ��� ��������� ���������� ��������. ��� ����������, ����� ��� ���������� ��������
// � ����� ����� � ��� �� ��������������� ������������������� ��������, � �� � ������� ���������� ��������.

void copyArray(int *arrFrom, int *arrTo, int len) {
    int i;
    for (i = 0; i < len; i++)
        arrTo[i] = arrFrom[i];
}

// ����� ������� � �������.

void printArray(int *arr, int len) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

// ����� �������� � �������.

void printCounter(int counter) {
    printf("���������� �������� � %d ������.\n", counter);
}

// ������� ������ ������� �������� ��������� �������.

void swapArr(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// ������������ ���������� "���������".

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

// ���������������� ���������� "���������".

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

// "�����������" ���������� � �������������� ����� while.

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

// "�����������" ���������� � �������������� ����� do-while.

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
 * 2. *����������� ��������� ����������.
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

    // ��������� ������ � �������� ��� ��� �������� ���� ���������� ���������� ����������.

    fillArray(arr0, len);
    copyArray(arr0, arr1, len);
    copyArray(arr0, arr2, len);
    copyArray(arr0, arr3, len);
    copyArray(arr0, arr4, len);

    printf("\n������ �� ����������:\n");
    printArray(arr0, len);

    printf("\n����������� ���������� ������� for-for:\n");
    count = bubbleSort(arr0, len);
    printArray(arr0, len);
    printCounter(count);

    printf("\n���������� ����������� ���������� ������� for-for:\n");
    count = bubbleSortPlus(arr1, len);
    printArray(arr1, len);
    printCounter(count);

    printf("\n���������� ����������� ���������� ������ while:\n");
    count = bubbleSortWhile(arr2, len);
    printArray(arr2, len);
    printCounter(count);

    printf("\n���������� ����������� ���������� ������ do-while:\n");
    count = bubbleSortDoWhile(arr3, len);
    printArray(arr3, len);
    printCounter(count);

    printf("\n��������� ����������:\n");
    count = shakerSort(arr4, len);
    printArray(arr4, len);
    printCounter(count);

    return 0;
}
