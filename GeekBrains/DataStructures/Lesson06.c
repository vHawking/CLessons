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

#define SIZE 10

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
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
 *      в) *Добавить в программу указания из какого файла считывать данные, каким образом обходить дерево.
 */

// Создание нового узла

Node *getFreeNode(T value, Node *parent) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла

void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else {
            exit(2); // дерево построено неправильно
        }
    }
}

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

int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i = 0;
Node* tree (int n) {
    Node* newNode;
    int value;
    int nL;
    int nR;
    if (n == 0)
        newNode = NULL;
    else {
        value = arr[i++];
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (Node*)malloc(sizeof(Node));
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

int main() {
    setlocale(LC_ALL, "Russian");
    setbuf(stdout, NULL);

    // Задание 1

    char *string = "Hello everybody";
    printf("Сума кодов символов строки \"%s\" = %li.\n", string, simpleHash(string));

    // Задание 2

    Node *arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *Tree = NULL;
    FILE *file = fopen("../database/data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество записей
    int i;
    for (i = 0; i < count; i++) {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);

    printf("\n");

    printTree(Tree);
    printf("\n\nPreOrderTravers: \t");
    preOrderTravers(Tree);

    printf("\nInOrderTravers: \t");
    insideOrderTravers(Tree);

    printf("\nPostOrderTravers: \t");
    endOrderTravers(Tree);

    printf("\n");
    return 0;
}