/**
 * �������� ������� ����� "��������� � ��������� ������".
 *
 * @version ������ �1.
 * @author ����� ��������.
 * @date 28.02.2018 �.
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>


#define FULL_ANSWER 0
#define ONE_ROOT 1
#define NO_ROOTS 2
#define NOT_SQUARE 3

/*
 * 1. ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I = m / (h * h);
 * ��� m-����� ���� � �����������, h - ���� � ������.
 */

double bmiCalc(float height, float weight) {
    return (weight / ((height * height) * 0.0001));
}

/*
 * 2. �������� ��������� ������ ���������� ���� ������������� ���������� � �������������� ������� ����������;
 */

void swapVars1(int *x, int *y) {
    int z;
    z = *y;
    *y = *x;
    *x = z;
}

/*
 * 2.* �������� ��������� ������ ���������� ���� ������������� ���������� ��� ������������� ������� ����������;
 */

void swapVars2(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

/*
 * 3. �������� ��������� ���������� ������ ��������� ����������� ���������.
 * ��� ��� �� �������� �� �� ���������� ������� ����������, ����� stdio.h, �� � ����� ����������� ��������������, ���
 * �������� �������� ���������� ����������� ����� (��-���� ��������� ��������). ������� ���� ������� squareRoot(),
 * ������� � ������� ��� ������� ����������� ���������. ����� �������, ���������� �������� ��� math.h.
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

int quadEquation(float a, float b, float c, float *x1, float *x2) {
    if (a != 0) {
        float d = b * b - 4 * a * c;

        if (d > 0) {
            *x1 = (-b + squareRoot(d)) / (2 * a);
            *x2 = (-b - squareRoot(d)) / (2 * a);
            return FULL_ANSWER;
        } else if (d == 0) {
            *x1 = -b / 2 * a;
            return ONE_ROOT;
        } else {
            return NO_ROOTS;
        }
    } else {
        *x1 = -c / b;
        return NOT_SQUARE;
    }
}

/*
 * 4. � ���������� �������� ����� ������. ��������� ����������, � ������ ������� ���� �� ���������.
 */

char *seasonsDetection(int m) {
    if (m >= 1 && m <= 2 || m == 12) {
        return "����";
    } else if (m >= 3 && m <= 5) {
        return "�����";
    } else if (m >= 6 && m <= 8) {
        return "����";
    } else if (m >= 9 && m <= 11) {
        return "�����";
    }
}

/*
 * 5. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
 */

char *agesAdd(int age) {
    int x1;
    int x2;

    x1 = age % 10;
    x2 = age % 100;

    if (x1 == 1 && x2 != 11) {
        return "���";
    } else if (x1 >= 2 && x1 <= 4 && (x2 < 10 || x2 >= 20)) {
        return "����";
    } else {
        return "���";
    }
}

/*
 * 6.* � ���������� �������� �������� ���������� ���� ����� ��������� ����� (x1, y1, x2, y2). ��������� ����������,
 * ��������� �� � ���� � ������ ����� ��� ���.
 */

//char *checkColorCells(int x1, int y1) {
//    return (x1 + y1) % 2 == 0 ? "������" : "�����";
//}
//
//char *checkCells(int x1, int x2, int y1, int y2) {
//    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
//        return "����������";
//    } else {
//        return "�� ���������";
//    }
//}

char *checkCells(int x1, int x2, int y1, int y2) {
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        return "����������";
    } else {
        return "�� ���������";
    }
}

char *checkColorCells(int x1, int x2, int y1, int y2) {
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        return (x1 + y1) % 2 == 0 ? "������" : "�����";
    } else {
        return "���� ������ ������";
    }
}

// strcat("���������� ", (x1 + y1) % 2 == 0 ? "������" : "�����");

/*
 * 7. ���� ����� ������������� ����� sizeY � K. ��������� ������ �������� �������� � ���������, ����� ������� �� �������
 * ������ sizeY �� K, � ����� ������� �� ����� �������.
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
 * 8. ���� ����� ����� sizeY (> 0). � ������� �������� ������� ������ � ������ ������� �� ������� ����������, ������� ��
 * � ������ ����� sizeY �������� �����. ���� �������, �� ������� True, ���� ��� � ������� False.
 */

int divideNumsTF(int number) {
    while (number > 0) {
        if (number % 2 != 0) {
            return 1;
        }
        number /= 10;
    }
    return 0;
}

/*
 * 9.* �������� �������, ������������ ��������� ����� �� 1 �� 100 ��� ������������� ����������� ������� rand();
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
 * 10.* ����������� �����. ����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.
 * ��������, 25 \ :sup: 2 = 625.
 * �������� ���������, ������� ������ ����������� ����� sizeY � ������� �� ����� ��� ����������� �����, �� ������������� sizeY.
 */

void amNums() {
    long int n = 0, i = 0;
    long int x = 0, y = 0, res = 0;

    printf("\nInput number sizeY > 0: ");
    scanf("%li", &n);

    if (n < 0 || n > 65535) {
        printf("Incorrect number length.\n");
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

    // Ex. 1

//    float height = 171;
//    float weight 72;
//
//    printf("��� ������ ����� ���� (BMI) ����� %.2f\n\n", bmiCalc(height, weight));
//
//    // Ex. 2
//
//    int x = 11, y = 77;
//    printf("�������������� ����������: x = %d, y = %d.", x, y);
//    swapVars1(&x, &y);
//    printf("\n���������� ����� ������ ����������: x = %d, y = %d.\n\n", x, y);
//
//    // Ex. 2*
//
//    printf("�������������� ����������: x = %d, y = %d.", x, y);
//    swapVars2(&x, &y);
//    printf("\n���������� ����� ������ ����������: x = %d, y = %d.\n\n", x, y);
//
//    // Ex. 3
//
//    float a, b, c, x1, x2;
//
//    printf("������� ����������� a: ");
//    scanf("%f", &a);
//    printf("������� ����������� b: ");
//    scanf("%f", &b);
//    printf("������� ����������� c: ");
//    scanf("%f", &c);
//
//    printf("\n���������� ��������� ����: ax*x + bx + c = 0;\n");
//
//    switch (quadEquation(a, b, c, &x1, &x2)) {
//        case FULL_ANSWER:
//            printf("��������� ����� ��� ����� x1 = %.2f, x2 = %.2f.\n", x1, x2);
//            break;
//        case ONE_ROOT:
//            printf("��������� ����� ���� ������ x1 = %.2f.\n", x1);
//            break;
//        case NO_ROOTS:
//            printf("��������� �� ����� ������.\n");
//            break;
//        case NOT_SQUARE:
//            printf("��������� �� �������� ����������, �� ����� ������ x1 = %.2f.\n", x1);
//            break;
//        default:
//            printf("Unexpected function behavior.\n");
//    }
//
//    // Ex. 4
//
//    int m;
//
//    do {
//        printf("\n������� ����� ������ �� 1 �� 12, ��� ������� 0 ��� ������: ");
//        scanf("%d", &m);
//
//        if (m >= 0 && m <= 12) {
//            printf("��� %s.\n", seasonsDetection(m));
//            break;
//        } else if (m == 0) {
//            printf("���������� ������...");
//            break;
//        } else {
//            printf("����� ������������ ����� ������.\n");
//        }
//    } while (m < 0 || m > 12);
//
//    // Ex. 5
//
//    int age;
//
//    printf("\n������� ���� �������: ");
//    scanf("%d", &age);
//
//    printf("��� %d %s.\n", age, agesAdd(age));
//
    // Ex. 6

//    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
//
//    printf("\n������� ���������� ������ x1: ");
//    scanf("%d", &x1);
//    printf("������� ���������� ������ y1: ");
//    scanf("%d", &y1);
//    printf("������� ���������� ������ x2: ");
//    scanf("%d", &x2);
//    printf("������� ���������� ������ y2: ");
//    scanf("%d", &y2);
//
//    char *isColor = checkColorCells(x1, y1);
//    char *isSameOrNot = checkCells(x1, x2, y1, y2);
//
//    printf("���� ����� �������� ���� %s � %s.\n", isSameOrNot, isSameOrNot == "����������" ? isColor : "\b\b\b");
//
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    printf("\n������� ���������� ������ x1: ");
    scanf("%d", &x1);
    printf("������� ���������� ������ y1: ");
    scanf("%d", &y1);
    printf("������� ���������� ������ x2: ");
    scanf("%d", &x2);
    printf("������� ���������� ������ y2: ");
    scanf("%d", &y2);

    printf("���� ����� �������� ���� %s - %s.", checkCells(x1, x2, y1, y2), checkColorCells(x1, x2, y1, y2));

//    // Ex. 7
//
//    int n;
//    int k;
//    int quotient;
//    int remainder;
//
//    do {
//        printf("\n������� sizeY (������������� �����): ");
//        scanf("%d", &n);
//        printf("������� K (������������� �����): ");
//        scanf("%d", &k);
//    } while (n <= 0 || k <= 0);
//
//    quotient = fancyQuotient(n, k);
//    remainder = fancyRemainder(n, k);
//
//    printf("sizeY / K: ����� �� ������� = %d, ������� �� ������� = %d.\n", quotient, remainder);
//
//    // Ex. 8
//
//    int number;
//    int positiveOrNo;
//
//    do {
//        printf("\n������� sizeY (������������� �����): ");
//        scanf("%d", &number);
//
//        positiveOrNo = divideNumsTF(number);
//    } while (number <= 0);
//
//    printf("sizeY �������� %s", (positiveOrNo == 0) ? "������ ����� � False.\n" : "�������� ����� - True.\n");
//
//    // Ex. 9
//
//    int max = 100;
//    int i;
//
//    for (i = 0; i < 20; i++) {
//        printf("%d, ", getRandom(i, max));
//    }
//    printf("\b\b\n");
//
//    // Ex. 10
//
//    amNums();

    return 0;
}
