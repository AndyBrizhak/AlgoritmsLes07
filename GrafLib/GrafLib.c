#include <GrafLib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
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

void DFS(int* mas, int *peekGr, int count, int st)
{
	int r;
	/*cout << st + 1 << " ";*/
	peekGr[st] = 2;

	for (r = 0; r < count; r++)
	{
		printf("\n peek GR %d = %d", st, peekGr[r]);
		/*if ((*mas[st][r] != 0) && (nodes[r] == 0))*/
		if ((*(mas + st * count + r) != 0) && (peekGr[r] == 0))
		{

			DFS(mas, peekGr, count, r);
		}
	}


}

//void BFS(Queue * queue, int * peekGr, int count)
//{
//	int k;
//	int l;
//	Push(queue, 0);
//	peekGr[0] = 2;
//	printf("\n peek GR %d = %d", 0, peekGr[0]);
//	while (queue->head != NULL && queue->tail != NULL)
//	{
//		k = Pop(queue);
//		for (l = 1; l < count; l++)
//		{
//			if (peekGr[l] == 0)
//			{
//				Push(queue, l);
//				peekGr[l] = 2;
//				printf("\n peek GR %d = %d", l, peekGr[l]);
//			}
//		}
//
//	}
//	getchar();
//}