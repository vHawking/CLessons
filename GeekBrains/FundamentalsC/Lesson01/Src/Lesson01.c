#include <stdio.h>
#include <windows.h>

int main() {
    setbuf(stdout, NULL);
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int age, weight;
    char name[100];

    printf("������� ���� ���: ");
    scanf("%s", name);
    printf("������� ��� �������: ");
    scanf("%d", &age);
    printf("������� ��� ���: ");
    scanf("%d", &weight);

    printf("\n��������� ��������� ������.");
    printf("\n���� ���: %s \t��� �������: %d ��� \t��� ���: %d ��.", name, age, weight);
    printf("\n����� ����������, �������� ���� ��� � ������ ����������: 0x%p\n", &name);

}