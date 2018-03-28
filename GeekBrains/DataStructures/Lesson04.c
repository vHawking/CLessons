/**
 * �������� ������� �� ����� "��������� � ��������� ������".
 *
 * @version ������ �4.
 * @author ����� ��������.
 * @date 11.03.2018 �.
 */

#include <stdio.h>
#include <locale.h>

const int sizeX = 5;
const int sizeY = 5;

/*
 *  1.* ����� ���������� ��������� ���������� ������ �� ���� � �������������. ������� �������� ��� �� ������ ��������.
 *
 * ����� �����������, ��� 0 - ��� �������:
 *
 *  1   1   1   1   1
 *  1   0   1   1   1
 *  1   1   1   0   1
 *  1   0   1   1   1
 *  1   1   1   1   1
 */

// ������������� �������

void setBarrier(int barrier[sizeY][sizeX]) {
    int i;
    int j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            barrier[i][j] = 1;
        }
        barrier[1][1] = 0;
        barrier[2][3] = 0;
        barrier[3][1] = 0;
    }
}

// ������� ������� ����������� ��������

int calcRoutes(int i, int j, int barrier[sizeY][sizeX]) {
    if (i == 0 && j == 0) {
        return 1;
    } else {
        return barrier[i][j] == 1 ? calcRoutes(i, j - 1, barrier) + calcRoutes(i - 1, j, barrier) : 0;
    }
}

// ��������� ������ ����������

void fillArr(int arr[sizeY][sizeX], int barrier[sizeY][sizeX]) {
    int i;
    int j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            arr[i][j] = calcRoutes(i, j, barrier);
        }
    }
}

int main() {
    setlocale(LC_ALL, ".1251");

    int arr[sizeY][sizeX];
    int barriers[sizeY][sizeX];

    int i;
    int j;

    // ������ �����������
    
    setBarrier(barriers);

    // ��������� �������� ������ ������������� � ���������� ������
    
    fillArr(arr, barriers);

    // �������� ������
    
    printf("���������� ����� ������ � �������������:\n\n");
    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}