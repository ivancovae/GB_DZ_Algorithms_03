#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void solution00();
void solution01();
void solution02();

void menu();
void genArrays();

// Задание выполнил Иванцов Александр Евгеньевич
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int select = 0;

	genArrays();

	do
	{
		menu();
		scanf("%i", &select);
		switch (select)
		{
		case 1:
			solution00();
			break;
		case 2:
			solution01();
			break;
		case 3:
			solution02();
			break;
		case 0:
			printf("Программа закончила свое выполнение.\n");
			break;
		default:
			printf("Некорректный символ, введите значения из списка меню.\n");
		}
	} while (select != 0);
	system("pause");
	return 0;
}

void menu()
{
	printf("Меню выбора решения задания:\n\n");

	printf("1. Решение задачи 1\n");
	printf("2. Решение задачи 2\n");
	printf("3. Решение задачи 3\n");
	printf("0. Завершение выполнения программы\n");
}

void descriptionTask(char *task)
{
	printf("\n##########################################\n");
	printf("\nУсловие задачи:\n");
	printf(task);
}

void endTask()
{
	printf("\n##########################################\n\n");
}

// Определяем максимальный размер массива
#define MaxN 100

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

typedef int bool;
#define true 1
#define false 0

// Распечатываем массив
void print(int N, int *a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6i", a[i]);
	printf("\n");
}

int a[MaxN]; // создаём массив максимального размера
int b[MaxN]; // копия для сравнения алгоритмов
int c[MaxN]; // копия для сравнения алгоритмов
int d[MaxN]; // копия для сравнения алгоритмов
int countItems = 0;

void genArrays()
{
	countItems = rand() % 100;

	for (int i = 0; i < countItems; i++)
	{
		int value = rand() % 100;
		a[i] = value;
		b[i] = value;
		c[i] = value;
		d[i] = value;
	}
}

// Полный алгоритм пузырьковой сортировки
int bubbleSort(int N, int *a)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			// простая операция сравнения
			count++;
			if (a[j] > a[j + 1])
			{
				// простая операция перестановки
				count++;
				swap(&a[j], &a[j + 1]);
			}
		}
	}
	return count;
}

// Алгоритм пузырьковой сортировки, если массив частично отсортирован(оптимизация избыточных операций)
int bubbleSortSpec(int N, int *a)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		//Эта переменная будет хранить количество перестановок в рамках текущей итерации
		int counter = 0;

		for (j = 0; j < N - 1; j++)
		{
			// простая операция сравнения
			count++;
			if (a[j] > a[j + 1])
			{
				// простая операция перестановки
				count++;
				swap(&a[j], &a[j + 1]);
				//Раз поменяли местами, увеличим счетчик перестановок
				counter++;
			}
		}
		//Если было не больше одной перестановки
		if (counter <= 1)
			break; //Прерываем цикл (прекращаем сортировку)
	}
	return count;
}

// Задание 1: Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//				оптимизированной и не оптимизированной программы.Написать функции сортировки, которые
//				возвращают количество операций.
void solution00()
{
	descriptionTask("Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения\n\tоптимизированной и не оптимизированной программы.Написать функции сортировки, которые\n\tвозвращают количество операций.\n");
	// Ввод данных
	printf("Массив до сортировки");
	print(countItems, a);
	
	// Решение
	printf("Результат: ");

	printf("\n Количество простых операций в пузырьковом алгоритме: %d\n", bubbleSort(countItems, &a));
	printf("Массив после сортировки");
	print(countItems, a);
	printf("\n Количество простых операций в оптимизированном пузырьковом алгоритме: %d\n", bubbleSortSpec(countItems, &b));
	printf("Массив после сортировки");
	print(countItems, b);

	endTask();
}

/* Шейкер-сортировка */
int shakerSort(int N, int *a)
{
	// границы
	int left = 0,
		right = N - 1,
		count = 0;

	while (left <= right)
	{
		// прямой обход
		for (int i = left; i < right; i++)
		{
			count++;
			if (a[i] > a[i + 1]) {
				count++;
				swap(&a[i], &a[i + 1]);
			}
		}
		right--;
		// обратный обход
		for (int i = right; i > left; i--)
		{
			count++;
			if (a[i - 1] > a[i]) {
				count++;
				swap(&a[i], &a[i - 1]);
			}
		}
		left++;
	}
	return count;
}

// Задание 2: Реализовать шейкерную сортировку.
void solution01()
{
	descriptionTask("Реализовать шейкерную сортировку.\n");
	// Ввод данных
	printf("Массив до сортировки");
	print(countItems, c);

	// Решение
	printf("Результат: ");
	printf("\n Количество простых операций в шейкерной сортировке: %d\n", shakerSort(countItems, &c));
	printf("Массив после сортировки");
	print(countItems, c);

	endTask();
}

int binary_find(int N, int *a, int key)
{
	int m, l = 0, r = N - 1;
	while (true)
	{
		if (l > r) return (-1); // значение не найдено
		m = l + (r - l) / 2; // определение середины
		if (a[m] < key) l = m + 1; // если значение среднего элемента, меньше ключа, то смотреть правую половину
		if (a[m] > key) r = m - 1; // если значение среднего элемента, больше ключа, то смотреть левую половину
		if (a[m] == key) return m; // найдено значение
	}
}

// Задание 3: Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
//				массив.Функция возвращает индекс найденного элемента или - 1, если элемент не найден.
void solution02()
{
	descriptionTask("Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный\n\tмассив.Функция возвращает индекс найденного элемента или - 1, если элемент не найден.\n");
	// Ввод данных
	int key = rand() % 100;
	printf("Значение поиска: %d\n", key);
	print(countItems, c);
	int res = binary_find(countItems, &c, key);
	// Решение
	printf("Результат: ");
	if (res == -1) printf("Элемент со значением %d не найден.\n", key);
	else printf("Элемент со значением %d найден в позиции %d.\n", key, res);

	endTask();
}