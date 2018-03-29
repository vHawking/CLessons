/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №2.
 * @author Вадим Ястребов.
 * @date 03.03.2018 г.
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 * 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
 */

void decimalToBinary(int x, char *binary) {
    if (x != 0) {
        decimalToBinary(x / 2, binary);
    } else {
        return;
    }
    strcat(binary, (x % 2) ? "1" : "0");
    return;
}

/*
 * 2. Реализовать функцию возведения числа a в степень b без рекурсии.
 */

int simplePow(int a, int b) {
    int result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

/*
 * 2a. Реализовать функцию возведения числа a в степень b рекурсивно.
 */

int recursePow(int a1, int b1) {
    if (b1 == 0) {
        return 1;
    } else {
        return a1 * recursePow(a1, --b1);
    }
}

/*
 * 2b. Реализовать функцию возведения числа a в степень b рекурсивно, используя свойство чётности степени.
 */

int recursePowEven(int a2, int b2) {

    if (b2 == 0) {
        return 1;
    } else if (b2 % 2 == 0) {
        return recursePowEven(a2 * a2, b2 >> 1);
    } else {
        return a2 * recursePowEven(a2, --b2);
    }
}

/*
 * 3.* Программа преобразует целое число. У программы две команды: Прибавить 1, множить на 2.
 * Сколько существует программ, которые число 3 преобразуют в число 20? Решить с использованием рекурсии.
 */

int calcOperations(int i, int j) {
    if (i < j) {
        return calcOperations(i + 1, j) + calcOperations(i * 2, j);
    } else if (i == j) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, ".1251");
    setbuf(stdout, NULL);

    printf("Задание 1\n");

    int x;
    char binary[64] = {"b'"};

    printf("Введите число в десятичной системе счисления: ");
    scanf("%d", &x);

    decimalToBinary(x, binary);
    printf("Число %d в двоичной системе счисления: %s.\n\n", x, binary);

    printf("Задание 2\n");

    int a, b;

    printf("Введите основание степени: ");
    scanf("%d", &a);
    printf("Введите показатель степени: ");
    scanf("%d", &b);

    printf("Результат возведения числа %d в степень %d равен %d.\n\n", a, b, simplePow(a, b));

    printf("Задание 2а\n");

    int a1, b1;

    printf("Введите основание степени: ");
    scanf("%d", &a1);
    printf("Введите показатель степени: ");
    scanf("%d", &b1);

    printf("Результат возведения числа %d в степень %d равен %d.\n\n", a1, b1, recursePow(a1, b1));

    printf("Задание 2б\n");

    int a2, b2;

    printf("Введите основание степени: ");
    scanf("%d", &a2);
    printf("Введите показатель степени: ");
    scanf("%d", &b2);

    printf("Результат возведения числа %d в степень %d равен %d.\n\n", a2, b2, recursePowEven(a2, b2));

    printf("Задание 3*\n");

    int i = 3, j = 20;

    printf("Количество преобразований %d в %d равно: %d.\n", i, j, calcOperations(i, j));

    return 0;
}