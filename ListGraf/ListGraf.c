#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
// Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 2.
// 5. Написать функцию для преобразования матрицы смежности в вершины смежности.

typedef struct list
{
	int vertex;
	struct list* next;
}   List;

typedef struct listgr
{
	int graf;
	List list;
} arrListGR[100];

void DFS(int* mas, int *peekGr, int count, int st)
{
	int r;
	
	peekGr[st] = 2;

	for (r = 0; r < count; r++)
	{
		printf("\n peek GR %d = %d", st, peekGr[r]);
		
		if ((*(mas + st * count + r) != 0) && (peekGr[r] == 0))
		{

			DFS(mas, peekGr, count, r);
		}
	}


}

int main(int argc, char * argv[])
{

	char *locale = setlocale(LC_ALL, "");
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
	//int *peekGr; // вершины графа
	//peekGr = malloc(count * sizeof(int));

	arrListGR *arrlistgr;
	arrlistgr = malloc(count * sizeof(arrListGR));
	for (int i = 0; i <count; i++)
	{
		for ( j = 1; j < count; j++)
		{
			if (/*(*/*(mas + i * count + j) != 0/*) && (peekGr[r] == 0)*/)
			{
				List tmp;
				arrlistgr[i]->graf = i; 
				arrlistgr[i]->list = /*vertex = *(mas + i * count + j)*/
					
			}
		}
		/*
		if ((*(mas +  * count + r) != 0) && (peekGr[r] == 0))
		{

			DFS(mas, peekGr, count, r);
		}*/
		//peekGr[i] = 0; // исходно все вершины равны 0
		//printf("%d ", peekGr[i]);
	}
	getchar();
	/*DFS(mas, peekGr, count, 0);*/


	getchar();
	

	/*free(peekGr);*/
	free(mas);
	return 0;
}