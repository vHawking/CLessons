#include <stdio.h>
#include <windows.h>

int main() {
    setbuf(stdout, NULL);
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int age, weight;
    char name[100];

    printf("Введите ваше имя: ");
    scanf("%s", name);
    printf("Введите ваш возраст: ");
    scanf("%d", &age);
    printf("Введите ваш вес: ");
    scanf("%d", &weight);

    printf("\nПроверяем введенные данные.");
    printf("\nВаше имя: %s \tВаш возраст: %d лет \tВаш вес: %d кг.", name, age, weight);
    printf("\nАдрес переменной, хранящей наше имя в памяти компьютера: 0x%p\n", &name);

}