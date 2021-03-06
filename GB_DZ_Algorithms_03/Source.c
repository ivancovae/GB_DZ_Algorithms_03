#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void solution00();
void solution01();
void solution02();
void solution03();
void solution04();

void menu();
void genArrays();

void testAlgorithms();

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
		case 4:
			solution03();
			break;		
		case 5:
			solution04();
			break;
		case 10:
			testAlgorithms();
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
	printf("4. Решение задачи 4\n");
	printf("5. Решение задачи 5\n");
	printf("10. Анализ алгоритмов\n");
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
int e[MaxN]; // копия для сравнения алгоритмов
int f[MaxN]; // копия для сравнения алгоритмов
int countItems = 0;

void genArrays()
{
	countItems = rand() % MaxN;

	for (int i = 0; i < countItems; i++)
	{
		int value = rand() % MaxN;
		a[i] = value;
		b[i] = value;
		c[i] = value;
		d[i] = value;
		e[i] = value;
		f[i] = value;
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
	printf("Массив до сортировки\n");
	print(countItems, a);
	
	// Решение
	printf("Результат: ");

	printf("\n Количество простых операций в пузырьковом алгоритме: %d\n", bubbleSort(countItems, &a));
	printf("Массив после сортировки\n");
	print(countItems, a);
	printf("\n Количество простых операций в оптимизированном пузырьковом алгоритме: %d\n", bubbleSortSpec(countItems, &b));
	printf("Массив после сортировки\n");
	print(countItems, b);

	endTask();
}

/* Шейкер-сортировка */
int shakerSort(int N, int *a)
{
	// границы и подсчет операций
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
	printf("Массив до сортировки\n");
	print(countItems, c);

	// Решение
	printf("Результат: ");
	printf("\n Количество простых операций в шейкерной сортировке: %d\n", shakerSort(countItems, &c));
	printf("Массив после сортировки\n");
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
	int key = rand() % MaxN;
	printf("Значение поиска: %d\n", key);
	print(countItems, c);
	int res = binary_find(countItems, &c, key);
	// Решение
	printf("Результат: ");
	if (res == -1) printf("Элемент со значением %d не найден.\n", key);
	else printf("Элемент со значением %d найден в позиции %d.\n", key, res);

	endTask();
}

// Сортировка выбором
int selectionSort(int N, int *a)
{
	int count = 0;
	int j = 0;
	int minIndex = 0;
	for (int i = 0; i < N; i++)
	{
		minIndex = i;
		for (j = i + 1; j < N; j++)
		{
			count++;
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		count++;
		swap(&a[i], &a[minIndex]);
	}
	return count;
}

// Сортировка вставками
int insertSort(int N, int *a)
{
	int count = 0;
	int temp;
	int i, j;
	for (i = 0; i < N; i++)
	{
		temp = a[i];
		j = i;
		//простая операция сравнения
		count++;
		while (j > 0 && a[j - 1] > temp)
		{
			//простая операция свапа
			count++;
			swap(&a[j], &a[j - 1]);
			j--;
		}
	}
	return count;
}

// Задание 4: *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
//				сложностью алгоритма.
void solution03()
{
	descriptionTask("*Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической\n\tсложностью алгоритма.\n");
	// Ввод данных
	printf("Массив до сортировки\n");
	print(countItems, d);

	// Решение
	printf("Результат: ");
	printf("\n Количество простых операций в сортировке методом выборка: %d\n", selectionSort(countItems, &d));
	printf("Массив после сортировки\n");
	print(countItems, d);
	printf("\n Количество простых операций в сортировке вставками: %d\n", insertSort(countItems, &e));
	printf("Массив после сортировки\n");
	print(countItems, e);
	
	endTask();
}

int binaryInsertSorting(int *a, int N)
{	
	int count = 0;
	int i, j;
	int key;
	int l = 0, m = 0, r = 0;
	for (i = 1; i < N; i++)
	{
		key = a[i];
		l = 0;
		r = i - 1;
		while (l < r)
		{
			m = l + (r - l) / 2;
			//простая операция сравнения
			count++;
			if (key < a[m])
				r = m;
			else
				l = m + 1;
		}
		for (j = i; j > l + 1; j--)
		{
			//простая операция присвоения
			//count++;
			a[j] = a[j - 1];
			a[l] = key;
		}
	}
	return count;
}

void testAlgorithms()
{
	descriptionTask("*Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической\n\tсложностью алгоритма.\n");

	genArrays();

	printf("\n Количество элементов: %d\n", countItems);
	print(countItems, a);
	printf("\n Количество простых операций в пузырьковом алгоритме: %d - сложность O(n^2)=%lf\n", bubbleSort(countItems, &a), pow(countItems, 2));
	printf("\n Количество простых операций в оптимизированном пузырьковом алгоритме: %d - сложность O(n^2)=%lf\n", bubbleSortSpec(countItems, &b), pow(countItems, 2));
	printf("\n Количество простых операций в шейкерной сортировке: %d - сложность O(n^2)=%lf\n", shakerSort(countItems, &c), pow(countItems, 2));
	printf("\n Количество простых операций в сортировке методом выборка: %d - сложность O(n^2)=%lf\n", selectionSort(countItems, &d), pow(countItems, 2));
	printf("\n Количество простых операций в сортировке вставками: %d - сложность O(n^2)=%lf\n", insertSort(countItems, &e), pow(countItems, 2));
	printf("\n Количество простых операций в сортировке методом выборка: %d - сложность O(n^2)=%lf\n", binaryInsertSorting(&f, countItems), log(countItems)*countItems);

	endTask();
}

// Задание 5: ** Реализовать сортировку вставками, используя бинарный поиск
void solution04()
{
	descriptionTask("**Реализовать сортировку вставками, используя бинарный поиск\n");
	// Ввод данных
	printf("Массив до сортировки\n");
	print(countItems, f);

	// Решение
	printf("Результат: ");
	printf("\n Количество простых операций в сортировке методом выборка: %d\n", binaryInsertSorting(&f, countItems));
	printf("Массив после сортировки\n");
	print(countItems, f);

	endTask();
}