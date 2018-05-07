#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
// Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 5.
// 5. Написать функцию для преобразования матрицы смежности в вершины смежности.





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
	
	for (int i = 0; i <count; i++)
	{
		printf("\n Graf %d  ", i);
		for ( j = 1; j < count; j++)
		{
			if (/*(*/*(mas + i * count + j) != 0/*) && (peekGr[r] == 0)*/)
			{
				printf("%d ", j);
				
					
			}
		}
		
	}
	getchar();
	getchar();
	free(mas);
	return 0;
}