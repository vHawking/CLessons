#include <stdio.h>
#include <windows.h>

int main(int args, const char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char abc;
    for(abc = 'A'; abc <= 'Z'; abc++) {
        printf("%c ", abc);
    }
    printf("\n");

    int a = 10, b = 20;
    while(a <= b) {
        printf("%d ", a);
        a++;
    }

    int x = 10, y = 20;
    int even = 0;
    while(x < y) {
        if(x % 2 == 0)
            even++;
        x++;
    }
    printf("\nКоличество чётных чисел равно %d", even);

    int i = 36, f = 5;
    int dev = i % f;
    printf("\nОстаток от деления по модулю %d на %d равен: %d", i, f, dev);
    return 0;
}