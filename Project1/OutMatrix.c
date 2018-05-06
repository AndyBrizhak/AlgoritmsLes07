#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
// Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 1.
//  1. Написать функцию, которая считывает матрицу смежности из файла и выводит её на
//экран.


int main(int argc, char * argv[])
{

	/*char *locale = setlocale(LC_ALL, "");*/
	FILE * file = fopen("data.txt", "r");
	/*FILE * file = fopen(str, "r");*/
	if (file == NULL)
	{
		puts("Can't open file!");
		getch();
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count); 
	int i;
	int j;
	printf("\n ");

	for (i = 0; i < count; i++)
	{

		for ( j = 0; j < count; j++)
		{
			int value;
			fscanf(file, "%d", &value);
			printf("%d ", value);
		}
		printf("\n ");
	}
	getch();
	fclose(file);



	return 0;
}