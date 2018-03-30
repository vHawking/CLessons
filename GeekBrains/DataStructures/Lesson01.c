/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №1.
 * @author Вадим Ястребов.
 * @date 28.02.2018 г.
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 * 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h);
 * где m-масса тела в килограммах, h - рост в метрах.
 */

double bmiCalc(float height, float weight) {
    return (weight / ((height * height) * 0.0001));
}

/*
 * 2. Написать программу обмена значениями двух целочисленных переменных с использованием третьей переменной;
 */

void swapVars1(int *x, int *y) {
    int z;
    z = *y;
    *y = *x;
    *x = z;
}

/*
 * 2.* Написать программу обмена значениями двух целочисленных переменных без использования третьей переменной;
 */

void swapVars2(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

/*
 * 3. Написать программу нахождения корней заданного квадратного уравнения.
 * Так как на вебинаре мы не подключали никакие библиотеки, кроме stdio.h, то я решил разобраться самостоятельно, как
 * работает алгоритм извлечения квадратного корня (всё-таки алгоритмы проходим). Написал свою функцию squareRoot(),
 * которую я вызывал при решении квадратного уравнения. Таким образом, получилось обойтись без math.h.
 */

float squareRoot(float n) {
    float x = n;
    float y = 1;
    float z = 0.01;

    while (x - y > z) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

char *quadEquation(float a, float b, float c, float *root1, float *root2) {
    if (a != 0) {
        float d = b * b - 4 * a * c;

        if (d > 0) {
            *root1 = (-b + squareRoot(d)) / (2 * a);
            *root2 = (-b - squareRoot(d)) / (2 * a);
            return "FULL_ANSWER";
        } else if (d == 0) {
            *root1 = -b / 2 * a;
            return "ONE_ROOT";
        } else {
            return "NO_ROOTS";
        }
    } else {
        *root1 = -c / b;
        return "NOT_SQUARE";
    }
}

/*
 * 4. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
 */

char *seasonsDetection(int m) {
    int month;

    if (m <= 0 || m > 12) {
        return "некорректное значение";
    } else {
        month = m % 12;

        if (month == 0 && month <= 2) {
            return "Зима";
        } else if (m >= 3 && m <= 5) {
            return "Весна";
        } else if (m >= 6 && m <= 8) {
            return "Лето";
        } else if (m >= 9 && m <= 11) {
            return "Осень";
        }
    }
}

/*
 * 5. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
 */

char *agesAdd(int age) {
    int x1;
    int x2;

    x1 = age % 10;
    x2 = age % 100;

    if (x1 == 1 && x2 != 11) {
        return "год";
    } else if (x1 >= 2 && x1 <= 4 && (x2 < 10 || x2 >= 20)) {
        return "года";
    } else {
        return "лет";
    }
}

/*
 * 6.* С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить,
 * относятся ли к поля к одному цвету или нет.
 */

char *checkCells(int x1, int x2, int y1, int y2) {
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        return "одинаковый";
    } else {
        return "не совпадает";
    }
}

char *checkColorCells(int x1, int x2, int y1, int y2) {
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        return (x1 + y1) % 2 == 0 ? "чёрный" : "белый";
    } else {
        return "поля разных цветов";
    }
}

/*
 * 7. Даны целые положительные числа sizeY и K. Используя только операции сложения и вычитания, найти частное от деления
 * нацело sizeY на K, а также остаток от этого деления.
 */

int fancyQuotient(int n, int k) {
    int result = 0;

    if (n <= 0 || k <= 0) {
        return 0;
    } else {
        while (n >= k) {
            n -= k;
            result++;
        }
        return result;
    }
}

int fancyRemainder(int n, int k) {
    if (n <= 0 || k <= 0) {
        return 0;
    } else {
        while (n >= k) {
            n -= k;
        }
        return n;
    }
}

/*
 * 8. Дано целое число (N > 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли
 * в записи числа sizeY нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
 */

char *divideNumsTF(int number) {
    while (number > 0) {
        if (number % 2 != 0) {
            return "false";
        }
        number /= 10;
    }
    return "true";
}

/*
 * 9.* Написать функцию, генерирующую случайное число от 1 до 100 без использования стандартной функции rand();
 */

int myRand() {
    static int num = 1112;
    num = ((num * num) / 100) % 10000;
    return num;
}

int getRandom(int i, int max) {
    return myRand() % (max + 1 - i) + i;
}

/*
 * 10.* Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
 * Например, 25 \ :sup: 2 = 625.
 * Напишите программу, которая вводит натуральное число sizeY и выводит на экран все автоморфные числа, не превосходящие sizeY.
 */

void amNums() {
    long int n = 0, i = 0;
    long int x = 0, y = 0, res = 0;

    printf("Введите натуральное число sizeY > 0: ");
    scanf("%li", &n);

    if (n < 0 || n > 65535) {
        printf("Некорректная размерность числа.\n");
        return;
    }

    while (i <= n) {
        if (i > 1 && i % 10 != 5 && i % 10 != 6) {
            i++;
            continue;
        }

        x = i;
        y = i * i;
        res = 1;

        while (x > 0) {
            if (x % 10 != y % 10) {
                res = 0;
                break;
            }

            x /= 10;
            y /= 10;
        }

        if (res != 0)
            printf("%li * %li = %li.\n", i, i, i * i);
        i++;
    }
}

int main() {
    setlocale(LC_ALL, ".1251");
    setbuf(stdout, NULL);

    printf("Задание 1\n");

    float height = 171;
    float weight = 72;

    printf("Ваш индекс массы тела (BMI) равен %.2f\n\n", bmiCalc(height, weight));

    printf("Задание 2\n");

    int x = 11, y = 77;
    printf("Инициалированы переменные: x = %d, y = %d.", x, y);
    swapVars1(&x, &y);
    printf("\nПеременные после обмена значениями: x = %d, y = %d.\n\n", x, y);

    printf("Задание 2*\n");

    printf("Инициалированы переменные: x = %d, y = %d.", x, y);
    swapVars2(&x, &y);
    printf("\nПеременные после обмена значениями: x = %d, y = %d.\n\n", x, y);

    printf("Задание 3\n");

    float a, b, c, root1, root2;

    printf("Решить квадратное уравнение вида: ax^2 + bx + c = 0;\n");

    printf("Введите коэффициент a: ");
    scanf("%f", &a);
    printf("Введите коэффициент b: ");
    scanf("%f", &b);
    printf("Введите коэффициент c: ");
    scanf("%f", &c);

    char *solution = quadEquation(a, b, c, &root1, &root2);
    if (solution == "FULL_ANSWER") {
        printf("Уравнение имеет два корня x1 = %.2f, x2 = %.2f.\n\n", root1, root2);
    } else if (solution == "ONE_ROOT") {
        printf("Уравнение имеет один корень x1 = %.2f.\n\n", root1);
    } else if (solution == "NO_ROOTS") {
        printf("Уравнение не имеет корней.\n\n");
    } else if (solution == "NOT_SQUARE") {
        printf("Уравнение не является квадратным, но имеет корень x1 = %.2f.\n\n", root1);
    } else {
        printf("Неожиданне поведение функции.\n\n");
    }

    printf("Задание 4\n");

    int m;

    printf("Введите номер месяца от 1 до 12: ");
    scanf("%d", &m);
    printf("Это %s.\n\n", seasonsDetection(m));

    printf("Задание 5\n");

    int age;

    printf("Введите свой возраст: ");
    scanf("%d", &age);

    printf("Вам %d %s.\n\n", age, agesAdd(age));

    printf("Задание 6\n");

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    printf("Введите координаты ячейки x1: ");
    scanf("%d", &x1);
    printf("Введите координаты ячейки y1: ");
    scanf("%d", &y1);
    printf("Введите координаты ячейки x2: ");
    scanf("%d", &x2);
    printf("Введите координаты ячейки y2: ");
    scanf("%d", &y2);

    printf("Цвет ячеек игрового поля %s - %s.\n\n", checkCells(x1, x2, y1, y2), checkColorCells(x1, x2, y1, y2));

    printf("Задание 7\n");

    int n;
    int k;
    int quotient;
    int remainder;

    do {
        printf("Введите sizeY (положительное число): ");
        scanf("%d", &n);
        printf("Введите K (положительное число): ");
        scanf("%d", &k);
    } while (n <= 0 || k <= 0);

    quotient = fancyQuotient(n, k);
    remainder = fancyRemainder(n, k);
    printf("sizeY / K: целое от деления = %d, остаток от деления = %d.\n\n", quotient, remainder);

    printf("Задание 8\n");

    int number;
    char *positiveOrNo;

    do {
        printf("Введите N (положительное число): ");
        scanf("%d", &number);
    } while (number <= 0);

    positiveOrNo = divideNumsTF(number);
    printf("Число N содержит %s – %s.\n\n", (positiveOrNo == "false") ? "нечётные цифры" : "чётные цифры", positiveOrNo);

    printf("Задание 9\n");

    int max = 100;
    int i;

    for (i = 0; i < 20; i++) {
        printf("%d, ", getRandom(i, max));
    }
    printf("\b\b\n\n");

    printf("Задание 10\n");

    amNums();

    return 0;
}