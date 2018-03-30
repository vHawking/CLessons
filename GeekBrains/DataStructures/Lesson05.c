/**
 * Домашнее задание по курсу "Алгоритмы и структуры данных".
 *
 * @version Лекция №5.
 * @author Вадим Ястребов.
 * @date 15.03.2018 г.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T int

const int BRACES_VALID = -1;

struct Node {
    T data;
    int index;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

void push(List *lst, T value) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Переполнение стека");
        return;
    }
    tmp->data = value;
    tmp->index = lst->size;
    tmp->next = lst->head;
    tmp->prev = NULL;
    if (lst->head != NULL)
        lst->head->prev = tmp;
    else
        lst->tail = tmp;
    lst->head = tmp;
    lst->size++;
}

T popS(List *lst) {
    if (lst->size <= 0) {
        printf("Стек пуст");
        return -1;
    }
    Node *tmp = NULL;
    T value = lst->head->data;
    tmp = lst->head;
    lst->head = lst->head->next;
    if (lst->size > 1)
        lst->head->prev = NULL;
    else
        lst->tail = NULL;
    free(tmp);
    lst->size--;
    return value;
}

/*
 * 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 */

void decToBin(long dec, char *bin) {
    List stack;
    stack.head = NULL;
    stack.tail = NULL;
    stack.size = 0;

    while (dec > 0) {
        push(&stack, dec % 2);
        dec /= 2;
    }
    while (stack.size > 0)
        strcat(bin, popS(&stack) ? "1" : "0");
}

/*
 * 2. Написать программу, которая определяет, является ли введенная скобочная
 * последовательность правильной. Примеры правильных скобочных
 * выражений: (), ([])(), {}(), ([{}]),
 * неправильных — )(, ())({), (, ])}), ([(])
 * для скобок [,(,{.
 * Например: (2+(2*2)) или [2/{5*(4+7)}]
 */

int bracesCheck(char *expression) {
    const int TYPES = 3;
    char braces[][2] = {{'(', ')'},
                        {'[', ']'},
                        {'{', '}'}};
    List b;
    b.head = NULL;
    b.tail = NULL;
    b.size = 0;

    while (*expression != '\0') {
        int i;
        for (i = 0; i < TYPES; i++)
            if (*expression == braces[i][0])
                push(&b, i);

        for (i = 0; i < TYPES; i++)
            if (*expression == braces[i][1]) {
                if (b.size == 0) return 0;
                if (i == b.head->data)
                    popS(&b);
                else
                    return b.size;
            }
        expression++;
    }
    return BRACES_VALID;
}

/*
 * 4.* Создать функцию, копирующую односвязный список (то есть создает в памяти
 * копию односвязного списка, без удаления первого списка).
 */

void copyList(List *from, List *to) {

    Node *current = from->tail;
    while (current != NULL) {
        push(to, current->data);
        current = current->prev;
    }
}

void printList(List *st) {
    Node *current = st->head;
    while (current != NULL) {
        printf("Индекс: %d Значение: %d\n", current->index, current->data);
        current = current->next;
    }
    printf("--------\n");
}

int main() {

    printf("Задание 1\n");
    char binary[64] = {"b'"};
    decToBin(11, binary);
    printf("%s\n\n", binary);

    printf("Задание 2\n");
    printf("%d\n", bracesCheck(")"));
    printf("%d\n", bracesCheck("{ ( [ {} [] () ] ) }"));
    printf("%d\n\n", bracesCheck("(2 + (2 * 2))"));

    printf("Задание 4\n");
    int i;
    List f, t;
    f.head = NULL;
    f.tail = NULL;
    f.size = 0;
    t.head = NULL;
    t.tail = NULL;
    t.size = 0;

    for (i = 0; i < 10; i++)
        push(&f, i);

    copyList(&f, &t);
    printList(&f);
    printList(&t);

    return 0;
}