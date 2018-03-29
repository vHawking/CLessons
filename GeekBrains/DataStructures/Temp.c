//#include <stdio.h>
//#include <math.h>
//
//#define X 8
//#define Y 8
//#define QUEENS 8
//
//int board[Y][X];
//
//void annull(int arr[Y][X]) {
//	int i;
//	int j;
//	for (i = 0; i < Y; i++)
//		for (j = 0; j < X; j++)
//			arr[i][j] = 0;
//}
//
//void printBoard(int arr[Y][X]) {
//	int i;
//	int j;
//	for (i = 0; i < Y; i++) {
//		for (j = 0; j < X; j++)
//			printf("%3d", arr[i][j]);
//		printf("\n");
//	}
//}
//
//int queens(int n) {
//	if (checkBoard() == 0) return 0;
//	if (n == QUEENS + 1) return 1;
//	int col;
//	int row;
//	for (row = 0; row < Y; row++)
//		for (col = 0; col < X; col++) {
//			if (board[row][col] == 0) {
//				board[row][col] = n;
//				if (queens(n + 1))
//					return 1;
//				board[row][col] = 0;
//			}
//		}
//	return 0;
//}
//
//int checkBoard() {
//	int i;
//	int j;
//	for (i = 0; i < Y; i++)
//		for (j = 0; j < X; j++)
//			if (board[i][j] != 0)
//				if (checkQueen(i, j) == 0)
//					return 0;
//	return 1;
//}
//
//int checkQueen(int x, int y) {
//	int i;
//	int j;
//	for(i = 0; i < Y; i++)
//		for(j = 0; j < X; j++)
//			// Если нашли фигуру
//			if (board[i][j] != 0)
//				if (!(i == x && j == y)) {// Если это не наша фигура
//					// Лежат на одной вертикали или горизонтали
//					if (i - x == 0 || j - y == 0) return 0;// Лежат на одной диагонали
//					if (abs(i - x) == abs(j - y)) return 0;
//				}
//// Если дошли сюда, то всё в порядке
//	return 1;
//}
//
//
//int main() {
//	annull(board);
//	queens(1);
//	printBoard(board);
//
//
//	return 0;
//}

/*
 * HwSix.c
 *
 *  Created on: 30 авг. 2017 г.
 *      Author: ivanovcinnikov
 */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define SIZE 10
//1. Реализовать простейшую хеш-функцию. На вход функции подаётся строка,
//на выходе сумма кодов символов.

//2. Переписать программу, реализующее двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;

//3. *Разработать базу данных студентов из трёх полей “Имя”, “Возраст”,
// “Табельный номер” в которой использовать все знания, полученные на уроках.

//4. ****Считайте данные в двоичное дерево поиска. Реализуйте поиск по
//какому-нибудь полю базы данных (возраст, номер)


//struct Node {
//    int data;
//    struct Node* left;
//    struct Node* right;
//    struct Node* parent;
//};
//typedef struct Node Node;
//
//void preOrderTravers(Node* root) {
//    if(root) {
//        printf("%d ", root->data);
//        preOrderTravers(root->left);
//        preOrderTravers(root->right);
//    }
//}
//
//void inOrderTravers(Node* node) {
//    if(node) {
//        inOrderTravers(node->left);
//        printf("%d ", node->data);
//        inOrderTravers(node->right);
//    }
//}
//
//void postOrderTravers(Node* node) {
//    if(node) {
//        postOrderTravers(node->left);
//        postOrderTravers(node->right);
//        printf("%d ", node->data);
//    }
//}
//
//int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//int i = 0;
//Node* tree (int n) {
//    Node* newNode;
//    int value;
//    int nL;
//    int nR;
//    if (n == 0)
//        newNode = NULL;
//    else {
//        value = arr[i++];
//        nL = n / 2;
//        nR = n - nL - 1;
//        newNode = (Node*)malloc(sizeof(Node));
//        newNode->data = value;
//        newNode->left = tree(nL);
//        newNode->right = tree(nR);
//    }
//    return newNode;
//}
//
//void printTree(Node *root) {
//    if (root)
//    {
//        printf("%d", root->data);
//        if (root->left || root->right)
//        {
//            printf("(");
//            if (root->left)
//                printTree(root->left);
//            else
//                printf("NULL");
//            printf(",");
//
//            if (root->right)
//                printTree(root->right);
//            else
//                printf("NULL");
//            printf(")");
//        }
//    }
//}
//
//int searchTree(Node* root, int value) {
//    int result = 0;
//    if(root) {
//        result = searchTree(root->right, value);
//        if(result == 0)
//            result = searchTree(root->left, value);
//        if (root->data == value)
//            result = 1;
//    }
//    return result;
//}
//
//typedef struct {
//    int number;
//    char name[256];
//    int age;
//} Student;
//
//struct StudentTree{
//    Student* data;
//    struct StudentTree* left;
//    struct StudentTree* right;
//};
//typedef struct StudentTree StudentTree;
//
//Student* readCSV(FILE* f) {
//    Student* s = (Student*) malloc(sizeof(Student));
//    int num;
//    char name[256];
//    int age;
//    fscanf(f, "%d,%d,%[^\n]s", &num, &age, name);
//    s->number = num;
//    s->age = age;
//    strcpy(s->name, name);
//    return s;
//}
//
//StudentTree* studentsTree (int n, FILE* f) {
//    StudentTree* newNode;
//    int nL;
//    int nR;
//    if (n == 0)
//        newNode = NULL;
//    else {
//        nL = n / 2;
//        nR = n - nL - 1;
//        newNode = (StudentTree*) malloc(sizeof(StudentTree));
//        newNode->data = readCSV(f);
//        newNode->left = studentsTree(nL, f);
//        newNode->right = studentsTree(nR, f);
//    }
//    return newNode;
//}
//
//Student* searchAge(StudentTree* root, int value) {
//    Student* result = NULL;
//    if(root) {
//        result = searchAge(root->right, value);
//        if (result == NULL)
//            result = searchAge(root->left, value);
//        if (root->data->age == value)
//            result = root->data;
//    }
//    return result;
//}
//
//int main() {
//    Node* greatTree = tree(SIZE);
//
//    printTree(greatTree);
//    printf("\n");
//
//    int i;
//    for(i = 0; i < SIZE + 1; i++)
//        printf("%d ", searchTree(greatTree, i));
//    printf("\n");
//
//    return 0;
//}
