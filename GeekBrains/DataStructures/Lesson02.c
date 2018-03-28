/**
 * �������� ������� �� ����� "��������� � ��������� ������".
 *
 * @version ������ �2.
 * @author ����� ��������.
 * @date 03.03.2018 �.
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
 * 1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������;
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
 * 2. ����������� ������� ���������� ����� a � ������� b ��� ��������;
 */

int simplePow(int a, int b) {
    int result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

/*
 * 2a. ����������� ������� ���������� ����� a � ������� b ����������;
 */

int recursePow(int a1, int b1) {
    if (b1 == 0) {
        return 1;
    } else {
        return a1 * recursePow(a1, --b1);
    }
}

/*
 * 2b. ����������� ������� ���������� ����� a � ������� b ����������, ��������� �������� �������� �������;
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
 * 3.* ��������� ����������� ����� �����. � ��������� ��� �������: ��������� 1, ������� �� 2.
 * ������� ���������� ��������, ������� ����� 3 ����������� � ����� 20? ������ � �������������� ��������.
 * ��� ���������� ��������? ��������� ���������� ������ � ����.
 * ����� �������� ������ ������� (��. ����� ������), ����� �� �������. �������, ��� ��� �� �������� ��� ���������� �����.
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

//    // ������� 1
//
//    int x;
//    char binary[64] = {"b'"};
//
//    printf("\n������� ����� � ���������� ������� ���������: ");
//    scanf("%d", &x);
//
//    decimalToBinary(x, binary);
//    printf("����� %d � �������� ������� ���������: %s.\n", x, binary);
//
//    //  ������� 2
//
//    int a, b;
//
//    printf("\n������� ��������� �������: ");
//    scanf("%d", &a);
//    printf("������� ���������� �������: ");
//    scanf("%d", &b);
//
//    printf("��������� ���������� ����� %d � ������� %d ����� %d.\n", a, b, simplePow(a, b));
//
//    //  ������� 2a
//
//    int a1, b1;
//
//    printf("\n������� ��������� �������: ");
//    scanf("%d", &a1);
//    printf("������� ���������� �������: ");
//    scanf("%d", &b1);
//
//    printf("��������� ���������� ����� %d � ������� %d ����� %d.\n", a1, b1, recursePow(a1, b1));
//
//    //  ������� 2b
//
//    int a2, b2;
//
//    printf("\n������� ��������� �������: ");
//    scanf("%d", &a2);
//    printf("������� ���������� �������: ");
//    scanf("%d", &b2);
//
//    printf("��������� ���������� ����� %d � ������� %d ����� %d.\n", a2, b2, recursePowEven(a2, b2));
//
    //  ������� 3*

    int i = 3, j = 20;

    printf("\n���������� �������������� %d � %d �����: %d.\n", i, j, calcOperations(i, j));

    return 0;
}
