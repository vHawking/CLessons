/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №4.
 * @author Вадим Ястребов.
 * @date 11.03.2018 г.
 */

#include <stdio.h>
#include <locale.h>

#define He 8
#define Wi 8

const int sizeX = 5;
const int sizeY = 5;

/*
 *  1.* Найти количество маршрутов шахматного короля на поле с препятствиями. Барьеры поставил как на слайде вебинара.
 *
 * Карта препятствий, где 0 - это барьеры:
 *
 *  1   1   1   1   1
 *  1   0   1   1   1
 *  1   1   1   0   1
 *  1   0   1   1   1
 *  1   1   1   1   1
 */

// Устанавливаем барьеры

void setBarrier(int barrier[sizeY][sizeX]) {
    int i;
    int j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            barrier[i][j] = 1;
        }
    }
    barrier[1][1] = 0;
    barrier[2][3] = 0;
    barrier[3][1] = 0;
}

// Обходим барьеры рекурсивной функцией

int calcRoutes(int i, int j, int barrier[sizeY][sizeX]) {
    if (i == 0 && j == 0) {
        return 1;
    } else {
        return barrier[i][j] == 1 ? calcRoutes(i, j - 1, barrier) + calcRoutes(i - 1, j, barrier) : 0;
    }
}

// Заполняем массив маршрутами

void fillArr(int arr[sizeY][sizeX], int barrier[sizeY][sizeX]) {
    int i;
    int j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            arr[i][j] = calcRoutes(i, j, barrier);
        }
    }
}

/*
 * 2.*** Требуется обойти конём шахматную доску размером 8х8, пройдя через все поля доски по одному разу. Здесь
 * алгоритм решения такой же как и в задаче о 8 ферзях.
 */

int desk[He][Wi];

// Возможные варианты ходов конем

int possible[][2] = {
        {-2, 1},
        {-1, 2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1}
};

// Максимальное число ходов

int maxMoves = He * Wi - 1;

// Проверка на допустимость такого хода

int isPossible(int x, int y) {
    return x >= 0 && x < He && y >= 0 && y < Wi && desk[x][y] == 0;
}

// Вывод доски

void printDesk() {
    printf("\n");
    for (int i = 0; i < He; i++) {
        for (int j = 0; j < Wi; j++)
            printf("%3d ", desk[i][j]);
        puts("");
    }
}

// Обход конем рекурсивно

int knightMove(int currentX, int currentY, int move) {
    int nextX, nextY;
    desk[currentX][currentY] = move;
    if (move > maxMoves) return 1;

    for (int i = 0; i < 7; i++) {
        nextX = currentX + possible[i][1];
        nextY = currentY + possible[i][0];
        if (isPossible(nextX, nextY) && knightMove(nextX, nextY, move + 1))
            return 1;
    }

    desk[currentX][currentY] = 0;
    return 0;
}

int main() {
    setlocale(LC_ALL, ".1251");

    int arr[sizeY][sizeX];
    int barriers[sizeY][sizeX];

    int i;
    int j;

    // Ставим препятствия

    setBarrier(barriers);

    // Заполняем основной массив препятствиями и маршрутами обхода

    fillArr(arr, barriers);

    // Печатаем массив

    printf("Количество ходов короля с препятствиями:\n\n");
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nТребуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу:\n");

    knightMove(0, 0, 1);
    printDesk();

    return 0;
}