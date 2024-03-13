#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int rate;
	int num;
} info_t;

void readFromFile(FILE* inp, info_t* arr, int size) {
	int i = 0;
	while (i != size)
	{
		fscanf(inp, " %[^0-9]%d %d", &arr[i].name, &arr[i].rate, &arr[i].num);
		i++;
	}
}

void display(info_t* arr, int size) {
	printf("      FLY INFORMATION FOR COMPANIES\n");
	printf("--------------------------------------------\n");
	for (int i = 0; i < size; i++)
		printf("%-15s    %2d   %5d\n", arr[i].name, arr[i].rate, arr[i].num);
}

int binarySearch(info_t* arr, int top, int bottom, int key) {
	int mid;
	while (top <= bottom)
	{
		mid = (bottom + top) / 2;
		if (arr[mid].num == key)
			return (mid);
		else if (arr[mid].num > key)
			bottom = mid - 1;
		else
			top = mid + 1;
	}
	return (-1);
}

int main(void)
{
	FILE* inp;
	inp = fopen("fly.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		int size;
		info_t* arr;
		fscanf(inp, "%d", &size);
		arr = (info_t*)malloc(sizeof(info_t) * size);

		readFromFile(inp, arr, size);
		fclose(inp);

		display(arr, size);
		printf("\n");
		int numOfPeople, index;
		do {
			printf("Enter number of people to see the campaign: ");
			scanf("%d", &numOfPeople);
			if (numOfPeople != -1)
			{
				index = binarySearch(arr, 0, size - 1, numOfPeople);
				if (index == -1)
					printf("%d NOT FOUND for the campaign\n", numOfPeople);
				else
					printf("%s found on the %d sale rate %d people\n", arr[index].name, arr[index].rate, arr[index].num);
			}
			printf("\n");
		} while (numOfPeople != -1);
	}
	return 0;
}