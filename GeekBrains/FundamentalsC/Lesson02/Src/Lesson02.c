#include <stdio.h>
#include <windows.h>

int main(int args, const char* argv[]) {
    setbuf(stdout, NULL);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i = 65535;
    int input;

    printf("Hello World!\n");
    printf("���������� i ����� ��������: %d\n", i);
    printf("���������� i ����������� �� ������: %p\n", &i);

    printf("������� ����� �����: ");
    scanf(" %d", &input);

    printf("���������� input ������� �������� %d", input);
    return 0;
}