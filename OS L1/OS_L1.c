#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main() {
	setlocale(LC_ALL, "Rus");
	int* cpu;
	int* process1;
	int* process2;
	int n;
	printf("Введите количество процессов: ");
	scanf("%d", &n);
	cpu = (int*)malloc(n * 2 * sizeof(int));
	process1 = (int*)malloc(n * 2 * sizeof(int));
	process2 = (int*)malloc(n * 2 * sizeof(int));
	for (int i = 0; i < n; ++i) 
	{
		scanf("%d", cpu + i * 2 + 0);
		*(cpu + i * 2 + 1) = i + 1;
	}
	for (int i = n - 1; i >= 0; i--) 
	{
		for (int j = 0; j < i; ++j) 
		{
			if (*(cpu + (j) * 2 + 0) < *(cpu + (j + 1) * 2 + 0)) 
			{
				int temp1 = *(cpu + (j) * 2 + 0);
				int temp2 = *(cpu + (j) * 2 + 1);
				*(cpu + (j) * 2 + 0) = *(cpu + (j + 1) * 2 + 0);
				*(cpu + (j + 1) * 2 + 0) = temp1;
				*(cpu + (j) * 2 + 1) = *(cpu + (j + 1) * 2 + 1);
				*(cpu + (j + 1) * 2 + 1) = temp2;
			}
		}
	}
	int sum_time1, sum_time2;
	sum_time1 = sum_time2 = 0;
	int f1, f2, koll_process_4;
	f1 = f2 = koll_process_4 = 0;
	while (koll_process_4 < n)
	{
		if (sum_time1 <= sum_time2)
		{
			sum_time1 += *(cpu + koll_process_4 * 2 + 0);
			*(process1 + f1 * 2 + 0) = *(cpu + koll_process_4 * 2 + 0);
			*(process1 + f1 * 2 + 1) = *(cpu + koll_process_4 * 2 + 1);
			koll_process_4 += 1;
			f1 += 1;
		}
		if (sum_time1 > sum_time2)
		{
			sum_time2 += *(cpu + koll_process_4 * 2 + 0);
			*(process2 + f2 * 2 + 0) = *(cpu + koll_process_4 * 2 + 0);
			*(process2 + f2 * 2 + 1) = *(cpu + koll_process_4 * 2 + 1);
			koll_process_4 += 1;
			f2 += 1;
		}
		
		
	}
	printf("Результат работы: \n");
	printf("1 процеcсор: ");
	for (int i = 0; i < f1; ++i) 
	{
		printf("%d ", *(process1 + i * 2 + 1));
	}
	printf("Суммарное время обработки = %d\n", sum_time1);
	printf("2 процеcсор: ");
	for (int i = 0; i < f2; ++i) 
	{
		printf("%d ", *(process2 + i * 2 + 1));
	}
	printf("Суммарное время обработки = %d\n", sum_time2);
}