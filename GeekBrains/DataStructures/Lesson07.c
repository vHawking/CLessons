/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №7.
 * @author Вадим Ястребов.
 * @date 24.03.2018 г.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxHeight 25
#define maxWidth 25

int matrix[maxHeight][maxWidth];

typedef struct GraphNode {
    int value;
    int index;
    int isChecked;
    struct GraphNode *qnext;
    struct GraphNode *qprev;
} GraphNode;

typedef struct MatrixNode {
    char from;
    char to;
    int len;
    struct MatrixNode *next;
} MatrixNode;

/*
1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
2. Написать рекурсивную функцию обхода графа в глубину.
3. Написать функцию обхода графа в ширину.
4. *Создать библиотеку функций для работы с графами.
*/

void readMatrixSize(FILE *f, int *width, int *height) {
    int lines = 0;
    int commas = 0;
    int max = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        if (c == ',')
            commas++;

        if (c == '\n') {
            lines++;
            if (commas > max)
                max = commas;
            commas = 0;
        }
    }
    *height = lines + 1;
    *width = max + 1;
}

void readMatrix(FILE *f) {
    int i = 0, j = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%d%c", &matrix[i][j], &c);
        j++;
        if (c == '\n' || c == '\r') {
            j = 0;
            i++;
        }
    }
}

void printMatrix(int size) {
    int i, j;
    for (i = -1; i < size; i++) {
        for (j = -1; j < size; j++)
            (j < 0) ? printf("%c ", (i < 0) ? ' ' : 65 + i)
                    : (i < 0) ? printf("%c ", 65 + j) : printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

typedef struct Queue {
    GraphNode *head;
    GraphNode *tail;
    int size;
} Queue;

void qPush(Queue *q, int value) {
    GraphNode *tmp = (GraphNode *) malloc(sizeof(GraphNode));
    if (tmp == NULL) {
        printf("Недостаточно памяти.\n");
        return;
    }
    tmp->qnext = q->head;
    tmp->qprev = NULL;
    tmp->value = value;
    tmp->index = q->size;
    if (q->head == NULL) {
        q->tail = tmp;
    } else {
        q->head->qprev = tmp;
    }
    q->head = tmp;
    q->size++;

}

int qPop(Queue *q) {
    if (q->size == 0) {
        printf("Стек пуст.\n");
        return -1;
    }
    int value = q->tail->value;
    GraphNode *tmp = q->tail;
    q->tail = q->tail->qprev;
    if (q->size > 1) {
        q->tail->qnext = NULL;
    } else {
        q->head = NULL;
    }
    q->size--;
    free(tmp);

    return value;
}

int isChecked[maxWidth] = {0};

int depthTravers(int start, int goal, int size) {
    printf("%c", 65 + start);
    if (start == goal || isChecked[start]) {
        return 1;
    } else {
        isChecked[start] = 1;
        int j;
        for (j = 0; j < size; j++)
            if (matrix[start][j] == 1 && isChecked[j] == 0)
                return depthTravers(j, goal, size);
    }
    return 0;
}

Queue q;
int used[maxWidth] = {0};

int widthTravers(int start, int goal, int size) {
    qPush(&q, start);
    int steps = 0;
    while (q.size > 0) {
        int value = qPop(&q);
        if (used[value] == 1) continue;
        used[value] = 1;
        printf("%c", 65 + value);
        steps++;
        if (value == goal)
            return steps;

        int i;
        for (i = 0; i < size; i++) {
            if (matrix[value][i] == 1 && used[i] == 0)
                qPush(&q, i);

        }
    }
    return -1;
}

MatrixNode *transformMatrix(int size) {
    MatrixNode *m = NULL;
    MatrixNode *p = NULL;
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j]) {
                p = (MatrixNode *) malloc(sizeof(MatrixNode));
                if (!p) {
                    puts("Ошибка памяти.\n");
                    exit(1);
                }
                p->next = m;
                p->from = (char) (65 + i);
                p->to = (char) (65 + j);
                p->len = matrix[i][j];
                m = p;
            }
        }
    }
    return p;
}

void printTransform(MatrixNode *p) {
    MatrixNode *m = p;
    while (m) {
        printf("%c->%c:%d\n", m->from, m->to, m->len);
        m = m->next;
    }
}

int main() {

    int h;
    int w;
    FILE *file;

    file = fopen("../database/matrix.csv", "r");
    if (file == NULL)
        return 1;

    readMatrixSize(file, &w, &h);
    if (h != w) {
        printf("Матрица должна быть квадратной.");
        return 1;
    }
    printf("Глубина = %d Ширина = %d\n\n", h, w);
    rewind(file);
    readMatrix(file);
    fclose(file);

    printMatrix(w);
    puts("");

    printf(" : В глубину (B->E): %d\n", depthTravers(1, 4, 6));
    printf(" : В ширину (B->E): %d\n\n", widthTravers(1, 4, 6));

    return 0;
}