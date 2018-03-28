#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);
    system("chcp 1251 > nul");
    /*
    char answer;

    printf("Вы хотите, чтобы вас поприветствовали? (y/n) ");
    scanf("%c", &answer);
    if(answer == 'y') {
        printf("Привет!");
        } else if(answer == 'n') {
        printf("До свидания!");
        } else {
        printf("Ваше решение непонятно.");
        }
     */

    int a = 10, b = 15;
    a = (a > b) ? b : 0;
    if (a > b)
        a = b;
    else
        a = 0;

    printf("\n%s", (1 > 0) ? "true" : "false");


    return 0;
}