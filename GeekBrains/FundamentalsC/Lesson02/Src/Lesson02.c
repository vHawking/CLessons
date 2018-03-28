#include <stdio.h>
#include <windows.h>

int main(int args, const char* argv[]) {
    setbuf(stdout, NULL);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i = 65535;
    int input;

    printf("Hello World!\n");
    printf("Переменная i имеет значение: %d\n", i);
    printf("Переменная i расположена по адресу: %p\n", &i);

    printf("Введите целое число: ");
    scanf(" %d", &input);

    printf("Переменная input приняла значение %d", input);
    return 0;
}