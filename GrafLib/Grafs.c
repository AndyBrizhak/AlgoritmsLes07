#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <GrafLib.h>
// Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных.Задача 4.
// 4. *Создать библиотеку функций для работы с графами.

typedef struct node
{
	int value;
	struct node_t* next;
}   Node;


typedef struct queue
{
	Node* head;
	Node* tail;
}   Queue;

void Push(Queue* queue, int value)
{

	Node* node = malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;

	if (queue->head == NULL && queue->tail == NULL)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
}

int Pop(Queue* queue)
{
	int value = 0;
	Node* node;
	if (queue->head)
	{
		node = queue->head;
		value = node->value;
		queue->head = queue->head->next;
		free(node);
	}

	return value;
}





int main(int argc, char * argv[])
{

	char *locale = setlocale(LC_ALL, "");

	Queue* queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;


	FILE * file = fopen("data.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		getch();
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count);
	int* mas;   // матрица смежности
	mas = malloc(count*count * sizeof(int));
	int i;
	int j;
	printf("\n ");
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			fscanf(file, "%d", (mas + i * count + j));
			printf("%d ", *(mas + i * count + j));
		}
		printf("\n ");
	}
	getch();
	fclose(file);
	int *peekGr; // вершины графа
	peekGr = malloc(count * sizeof(int));
	for (int i = 0; i <count; i++)
	{
		peekGr[i] = 0; // исходно все вершины равны 0
		printf( "n\ %d ", peekGr[i]);
	}
	getchar();
	int st = 0;
	DFS(mas, peekGr, count, st);
	for (int i = 0; i <count; i++)
	{
		peekGr[i] = 0; // исходно все вершины равны 0
		printf("n\ %d ", peekGr[i]);
	}


	BFS(queue, peekGr, count);

	free(peekGr);
	free(mas);
	return 0;
}