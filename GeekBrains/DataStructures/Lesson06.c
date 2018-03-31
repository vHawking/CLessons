/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №6.
 * @author Вадим Ястребов.
 * @date 17.03.2018 г.
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 15

int arr[SIZE] = {15, 8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 14, 13};
int i = 0;

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
} Node;

/*
 * 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
 */

long simpleHash(char *string) {
    long hash = 0;

    while (*string != '\0') {
        hash += *string++;
        hash = hash << 1;
    }
    return hash;
}

/*
 * 2. Переписать программу, реализующее двоичное дерево поиска:
 *      а) Добавить в него обход дерева различными способами;
 *      б) Реализовать поиск в двоичном дереве поиска;
 */

void preOrderTravers(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void insideOrderTravers(Node *root) {
    if (root) {
        insideOrderTravers(root->left);
        printf("%d ", root->data);
        insideOrderTravers(root->right);
    }
}

void endOrderTravers(Node *root) {
    if (root) {
        endOrderTravers(root->left);
        endOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

Node *tree(int n) {
    Node *newNode;
    int value;
    int nL;
    int nR;
    if (n == 0)
        newNode = NULL;
    else {
        value = arr[i++];
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = tree(nL);
        newNode->right = tree(nR);
    }
    return newNode;
}

// Распечатка двоичного дерева в виде скобочной записи

void printTree(Node *root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

int searchTree(Node *root, int value) {
    int result = 0;
    if (root) {
        result = searchTree(root->right, value);
        if (result == 0)
            result = searchTree(root->left, value);
        if (root->data == value)
            result = 1;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    setbuf(stdout, NULL);

    printf("Задание 1\n");
    char *string = "Hello everybody";
    printf("Сума кодов символов строки \"%s\" = %li.\n\n", string, simpleHash(string));

    printf("Задание 2\n");
    Node *greatTree = tree(SIZE);

    printTree(greatTree);
    printf("\n");

    int i;
    for (i = 0; i < SIZE + 1; i++) {
        printf("%d ", searchTree(greatTree, i));
    }
    printf("\n");
    return 0;
}