#include <stdio.h>
#include <stdlib.h>

int main(int args, const char *argv[]) {

    system("chcp 1251 > nul");

    int number;
    int d = 0, i = 1;

    printf("������� �����: ");
    fflush(stdout);
    scanf("%d", &number);

    while (i <= number) {
        if (number % i++ == 0)
            d++;
        else
            continue;
        if (number % i == 3)
            break;
    }
    printf("�������� ����� %d %s �������� �������.", number, (d == 2) ? "\b" : "��");

    return 0;
}