#include <stdio.h>

void helix(int a[10][10], int str, int stb)
{
    int z, b, x = 0, y = 1, step = 1, xx = (10-str)/2, yy = (10-stb)/2;

    z = str*stb;

    while (step != z+1)
    {
        for (b = x; b < stb; b++)
        {
            a[x+xx][b+yy] = step;
            step++;
        }

        for (b = y; b < str; b++)
        {
            a[b+xx][(stb-1)+yy] = step;
            step++;
        }

        if (step == z+1)
        {
            break;
        }

        y++;
        stb--;

        for (b = stb-1; b > x; b--)
        {
            a[str-1+xx][b+yy] = step;
            step++;
        }

        for (b = str-1; b > x; b--)
        {
            a[b+xx][x+yy] = step;
            step++;
        }

        x++;
        str--;
    }
}

int main () {
    setbuf(stdout, NULL);
    int str, stb, mass_a[10][10] = {};

    printf("Введите размер матрицы: ");
    scanf("%i %i", &str, &stb);

    helix(mass_a, str, stb);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mass_a[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("%i   ", mass_a[i][j]);
            }
        }
        printf("\n");
    }
    return (0);
}