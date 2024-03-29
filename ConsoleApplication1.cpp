// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Nimigean Emanuela-gr 30226
/*
Se cere implementarea​ corectă și​ eficienta a operațiilor de​ inserare si​ căutare într-­o tabela de dispersie ce folosește adresarea deschisa cu verificare pătratică.
In urma evaluarii operatiei de cautare in tabele de dispersie cu adresare deschisa si verificare patratica, am obtinut urmatoarele date referitoare la efortul mediu si maxim:
alfa:	efort mediu gasit   efort maxim gasit   efort mediu negasit   efort maxim negasit
0.8:        12                   1354                   8000               8000
0.85:       11.4                 2091                   8506               8506
0.9:        10.7                 1568                   9006               9006
0.95:       8                    1819                   9506               9506
0.99:       6.7                  1002                   9906               9906
Observam ca efortul maxim pt elementele gasite este destul de redus comparat cu dimensiunea tabelei, iar cel mediu este chiar foarte mic;
de asemenea, efortul mediu pt elementele negasite este egal cu cel maxim deoarece este nevoie sa parcurgem toata tabela pt a confirma ca elementul respectiv nu apare in ea.
Prin urmare, tabelele de dispersie sunt extrem de eficiente, in cazul mediu statistic, in cautarea elementelor stocate in acestea.
*/

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int val, status;
}Cell;

enum { Free, Occupied };

int HToccupied(Cell *T, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (T[i].status == Free) return 0;
	}
	return 1;
}

void setHTfree(Cell *T, int n)
{
	for (int i = 0; i < n; i++)
	{
		T[i].status = Free;
	}
}

int quadratic(int key, int n, int i)
{
	int c1, c2;
	c1 = 1;
	c2 = 1;
	int value = ((key%n) + c1 * i + c2 * i*i) % n;
	return value;
}

void insert_quadratic(Cell *T, int key, int n)
{
	if (HToccupied(T, n))
	{
		printf("Tabela este plina, nu se mai pot insera chei");
		return;
	}
	int i = 0;
	int collision = 1;
	int h = 0;
	do
	{
		h = quadratic(key, n, i);
		if (T[h].status == Free)
		{
			collision = 0;
			T[h].status = Occupied;
			T[h].val = key;
		}
		else
		{
			i++;
		}
	} while (collision);
	//	T[h].status = Occupied;
	//	T[h].val= key;
}

int insereaza(Cell *T, int key, int n)
{
	int i = 0;
	do
	{
		int j = quadratic(key, n, i);
		if (T[j].status == Free)
		{
			T[j].val = key;
			T[j].status = Occupied;
			return j;
		}
		else
		{
			i++;
		}
	} while (i <= n);
	//perror("depasire");
}

int HTsearch(Cell *T, int key, int n)
{
	int i = 0, h = 0;
	do
	{
		h = quadratic(key, n, i);
		if (T[h].val == key)
		{
			return h;
		}
		i++;
	} while (T[h].status == Occupied && i < n);
	perror("not found");
}


int HTsearch2(Cell *T, int key, int n)
{
	int i = 0, h = 0, ok = 0;
	do
	{
		h = quadratic(key, n, i);
		if (T[h].val == key)
		{
			return i+1;
		}
		i++;
	} while (T[h].status == Occupied && i < n);
	
	return 0;
}


int HTsearch3(Cell *T, int key, int n)
{
	int i = 0, h = 0, ok = 0;
	do
	{
		h = quadratic(key, n, i);
		if (T[h].val == key)
		{
			return 0;
		}
		i++;
	} while (T[h].status == Occupied && i < n);

	return i;
}

void HTdelete(Cell *T, int key, int n)
{
	int i = 0, h = 0;
	do
	{
		h = quadratic(key, n, i);
		if (T[h].val == key)
		{
			T[h].status = Free;
			return;
		}
		i++;
	} while (T[h].status == Occupied && i < n);
	perror("nu exista cheia");
}

void printHT(Cell *T, int n)
{
	printf("\n  Tabela este: \n");
	for (int i = 0; i < n; i++)
	{
		if (T[i].status == Occupied)
		{
			printf("T[%d]=%d;\n ", i, T[i].val);
		}
		else
		{
			printf("T[%d]=--;\n ", i);

		}
	}
}

int main()
{
	/*
	int n = 7;
	Cell *T = (Cell*)malloc(n * sizeof(Cell));
	setHTfree(T, n);
	printHT(T, n);
	*/
	/*  ///inserarea folosind prima varianta a funcctiei:
		insert_quadratic(T, 2, 7);
		insert_quadratic(T, 8, 7);
		insert_quadratic(T, 5, 7);
		insert_quadratic(T, 1, 7);
		printHT(T, n);
		insert_quadratic(T, 15, 7);
		insert_quadratic(T, 10, 7);
		insert_quadratic(T, 9, 7);
		printHT(T, n);
	*/
	/*///inserarea folosind pseudocodul din curs:
	printf("%d  ",insereaza(T, 2, 7));
	printHT(T, n);
	printf("%d   ",insereaza(T, 8, 7));
	printHT(T, n);
	printf("%d   ",insereaza(T, 5, 7));
	printHT(T, n);
	printf("%d   ",insereaza(T, 1, 7));
	printHT(T, n);
	printf("%d   ",insereaza(T, 15, 7));
	printHT(T, n);
	printf("%d   ",insereaza(T, 10, 7));
	printHT(T, n);
	printf("%d    ",insereaza(T, 9, 7));
	printHT(T, n);
	*/
	/*insereaza(T, 2, 7);
	insereaza(T, 8, 7);
	insereaza(T, 5, 7);
	insereaza(T, 1, 7);
	insereaza(T, 15, 7);
	insereaza(T, 10, 7);
	insereaza(T, 9, 7);
	printHT(T, n);
	*/
	/* ////cautarea:
	printf("%d\n", HTsearch(T, 15, 7));
	printf("%d\n", HTsearch(T, 2, 7));
	printf("%d\n", HTsearch(T, 10, 7));
	printf("%d\n", HTsearch(T, 22, 7));
	*/

	////
	/*
	int n = 19;
	Cell *T = (Cell*)malloc(n * sizeof(Cell));
	setHTfree(T, n);
	printHT(T, n);

	insereaza(T, 1, n);
	insereaza(T, 10, n);
	insereaza(T, 7, n);
	insereaza(T, 3, n);
	insereaza(T, 12, n);
	insereaza(T, 15, n);
	insereaza(T, 5, n);
	insereaza(T, 2, n);
	insereaza(T, 0, n);
	insereaza(T, 22, n);
	insereaza(T, 13, n);
	insereaza(T, 19, n);
	insereaza(T, 4, n);
	insereaza(T, 6, n);
	insereaza(T, 25, n);
	insereaza(T, 70, n);
	insereaza(T, 43, n);
	insereaza(T, 55, n);
	printHT(T, n); //factor de umplere: 18/19=0.947

	HTdelete(T, 25, n);
	HTdelete(T,2, n);
	HTdelete(T, 0, n);
	HTdelete(T, 27, n);
	HTdelete(T, 13, n);
	printHT(T,n);
	insereaza(T, 25, n);
	printHT(T, n);
	*/

	////// factor de umplere=0.8 si N=10007 => n=8000 (alfa=0.799)
/*  int totalAccesari = 0, totalGasite = 0, totalNAccesari=0,totalNegasite=0;
	for (int r = 0; r < 5; r++) {
		int n = 8000;
		Cell *T = (Cell*)malloc(n * sizeof(Cell));
		setHTfree(T, n);
		//printHT(T, n);
		int k = 0;
		while (k < 8000)
		{
			int x = rand() % 10000;
			if (insereaza(T, x, n) >= 0);
			{
				insereaza(T, x, n);
				k++;
			}
		}
		//printHT(T, n);
		int maxG = 0,maxNG=0, Nsum=0,Nop=0, sum = 0, gasit = 0, negasit = 0, op = 0;
	/*	while (gasit < 1500)
		{
			op = 0;
		
			gasit++;
			op += HTsearch2(T, T[rand() % 8000].val, n);
	//		printf("\ncasute accesate:%d ", op);
			sum += op;
			if (op > maxG)
			{
				maxG = op;
			}
		}
		totalGasite += gasit;
		totalAccesari += sum;
		printf("\ngasite[%d]=%d ", r, gasit);
		printf("\nsum[%d]=%d ", r, sum);////=>nr de accesari pt a gasi cele 1500 de elem
		printf("\nefortMaximGasite[%d]:%d ", r, maxG);////max:1394
		printf("\ntotalGasite:%d ", totalGasite);
		printf("\ntotalAccesari:%d ", totalAccesari);////=>91356 accesari pt a gasi cele 7500 elem=>efort mediu gasite=91356/7500=aprox.12
	*//*
		while (negasit < 1500)
		{
			Nop = 0;
			
			negasit++;
			Nop += HTsearch3(T,(rand() % 10000)+10000, n);
			//		printf("\ncasute accesate:%d ", op);
			Nsum += Nop;
			if (Nop > maxNG)
			{
				maxNG = Nop;
			}
		}

		totalNegasite += negasit;
		totalNAccesari += Nsum;
		printf("\nnegasite[%d]=%d ", r, negasit);
		printf("\nNsum[%d]=%d ", r, Nsum);////=>nr de accesari pt a gasi cele 1500 de elem,dar pe care nu le gaseste
		printf("\nefortMaximNeGasite[%d]:%d ", r, maxNG);////max:8000
		printf("\ntotalNeGasite:%d ", totalNegasite);
		printf("\ntotalNAccesari:%d ", totalNAccesari);////=>60000000 accesari pt cele 7500 elem pe care nu le-a gasit => efort mediu negasite: 1600;
	}
*/

////// factor de umplere=0.85 si N=10007 => n~=8506
/*  int totalAccesari = 0, totalGasite = 0, totalNAccesari=0,totalNegasite=0;
	for (int r = 0; r < 5; r++) {
		int n = 8506;
		Cell *T = (Cell*)malloc(n * sizeof(Cell));
		setHTfree(T, n);
		//printHT(T, n);
		int k = 0;
		while (k < 8506)
		{
			int x = rand() % 10000;
			if (insereaza(T, x, n) >= 0);
			{
				insereaza(T, x, n);
				k++;
			}
		}
		//printHT(T, n);
		int maxG = 0,maxNG=0, Nsum=0,Nop=0, sum = 0, gasit = 0, negasit = 0, op = 0;
		while (gasit < 1500)
		{
			op = 0;
			
			gasit++;
			op += HTsearch2(T, T[rand() % 8506].val, n);
	//		printf("\ncasute accesate:%d ", op);
			sum += op;
			if (op > maxG)
			{
				maxG = op;
			}
		}
		totalGasite += gasit;
		totalAccesari += sum;
		printf("\ngasite[%d]=%d ", r, gasit);
		printf("\nsum[%d]=%d ", r, sum);////=>nr de accesari pt a gasi cele 1500 de elem
		printf("\nefortMaximGasite[%d]:%d ", r, maxG);
		printf("\ntotalGasite:%d ", totalGasite);
		printf("\ntotalAccesari:%d ", totalAccesari);
	
	while (negasit < 1500)
	{
		Nop = 0;

		negasit++;
		Nop += HTsearch3(T, (rand() % 10000) + 10000, n);
		//		printf("\ncasute accesate:%d ", op);
		Nsum += Nop;
		if (Nop > maxNG)
		{
			maxNG = Nop;
		}
	}

	totalNegasite += negasit;
	totalNAccesari += Nsum;
	printf("\nnegasite[%d]=%d ", r, negasit);
	printf("\nNsum[%d]=%d ", r, Nsum);////=>nr de accesari pt a gasi cele 1500 de elem,dar pe care nu le gaseste
	printf("\nefortMaximNeGasite[%d]:%d ", r, maxNG);
	printf("\ntotalNeGasite:%d ", totalNegasite);
	printf("\ntotalNAccesari:%d ", totalNAccesari);
	}
*/




////// factor de umplere=0.9 si N=10007 => n~=9006
/*  int totalAccesari = 0, totalGasite = 0, totalNAccesari=0,totalNegasite=0;
	for (int r = 0; r < 5; r++) {
		int n = 9006;
		Cell *T = (Cell*)malloc(n * sizeof(Cell));
		setHTfree(T, n);
		//printHT(T, n);
		int k = 0;
		while (k < 9006)
		{
			int x = rand() % 10000;
			if (insereaza(T, x, n) >= 0);
			{
				insereaza(T, x, n);
				k++;
			}
		}
		//printHT(T, n);
		int maxG = 0,maxNG=0, Nsum=0,Nop=0, sum = 0, gasit = 0, negasit = 0, op = 0;
		while (gasit < 1500)
		{
			op = 0;
			
			gasit++;
			op += HTsearch2(T, T[rand() % 9006].val, n);
	//		printf("\ncasute accesate:%d ", op);
			sum += op;
			if (op > maxG)
			{
				maxG = op;
			}
		}
		totalGasite += gasit;
		totalAccesari += sum;
		printf("\ngasite[%d]=%d ", r, gasit);
		printf("\nsum[%d]=%d ", r, sum);////=>nr de accesari pt a gasi cele 1500 de elem
		printf("\nefortMaximGasite[%d]:%d ", r, maxG);
		printf("\ntotalGasite:%d ", totalGasite);
		printf("\ntotalAccesari:%d ", totalAccesari);
		
	while (negasit < 1500)
	{
		Nop = 0;

		negasit++;
		Nop += HTsearch3(T, (rand() % 10000) + 10000, n);
		//		printf("\ncasute accesate:%d ", op);
		Nsum += Nop;
		if (Nop > maxNG)
		{
			maxNG = Nop;
		}
	}

	totalNegasite += negasit;
	totalNAccesari += Nsum;
	printf("\nnegasite[%d]=%d ", r, negasit);
	printf("\nNsum[%d]=%d ", r, Nsum);////=>nr de accesari pt a gasi cele 1500 de elem,dar pe care nu le gaseste
	printf("\nefortMaximNeGasite[%d]:%d ", r, maxNG);
	printf("\ntotalNeGasite:%d ", totalNegasite);
	printf("\ntotalNAccesari:%d ", totalNAccesari);
	}
*/



////// factor de umplere=0.95 si N=10007 => n~=9506
/*  int totalAccesari = 0, totalGasite = 0, totalNAccesari=0,totalNegasite=0;
	for (int r = 0; r < 5; r++) {
		int n = 9506;
		Cell *T = (Cell*)malloc(n * sizeof(Cell));
		setHTfree(T, n);
		//printHT(T, n);
		int k = 0;
		while (k < 9506)
		{
			int x = rand() % 10000;
			if (insereaza(T, x, n) >= 0);
			{
				insereaza(T, x, n);
				k++;
			}
		}
		//printHT(T, n);
		int maxG = 0,maxNG=0, Nsum=0,Nop=0, sum = 0, gasit = 0, negasit = 0, op = 0;
		while (gasit < 1500)
		{
			op = 0;
			
			gasit++;
			op += HTsearch2(T, T[rand() % 9506].val, n);
	//		printf("\ncasute accesate:%d ", op);
			sum += op;
			if (op > maxG)
			{
				maxG = op;
			}
		}
		totalGasite += gasit;
		totalAccesari += sum;
		printf("\ngasite[%d]=%d ", r, gasit);
		printf("\nsum[%d]=%d ", r, sum);////=>nr de accesari pt a gasi cele 1500 de elem
		printf("\nefortMaximGasite[%d]:%d ", r, maxG);
		printf("\ntotalGasite:%d ", totalGasite);
		printf("\ntotalAccesari:%d ", totalAccesari);

	while (negasit < 1500)
	{
		Nop = 0;

		negasit++;
		Nop += HTsearch3(T, (rand() % 10000) + 10000, n);
		//		printf("\ncasute accesate:%d ", op);
		Nsum += Nop;
		if (Nop > maxNG)
		{
			maxNG = Nop;
		}
	}

	totalNegasite += negasit;
	totalNAccesari += Nsum;
	printf("\nnegasite[%d]=%d ", r, negasit);
	printf("\nNsum[%d]=%d ", r, Nsum);////=>nr de accesari pt a gasi cele 1500 de elem,dar pe care nu le gaseste
	printf("\nefortMaximNeGasite[%d]:%d ", r, maxNG);
	printf("\ntotalNeGasite:%d ", totalNegasite);
	printf("\ntotalNAccesari:%d ", totalNAccesari);
	}
*/




////// factor de umplere=0.99 si N=10007 => n~=9906
/*  int totalAccesari = 0, totalGasite = 0, totalNAccesari=0,totalNegasite=0;
	for (int r = 0; r < 5; r++) {
		int n = 9906;
		Cell *T = (Cell*)malloc(n * sizeof(Cell));
		setHTfree(T, n);
		//printHT(T, n);
		int k = 0;
		while (k < 9906)
		{
			int x = rand() % 10000;
			if (insereaza(T, x, n) >= 0);
			{
				insereaza(T, x, n);
				k++;
			}
		}
		//printHT(T, n);
		int maxG = 0,maxNG=0, Nsum=0,Nop=0, sum = 0, gasit = 0, negasit = 0, op = 0;
		while (gasit < 1500)
		{
			op = 0;
			
			gasit++;
			op += HTsearch2(T, T[rand() % 9906].val, n);
	//		printf("\ncasute accesate:%d ", op);
			sum += op;
			if (op > maxG)
			{
				maxG = op;
			}
		}
		totalGasite += gasit;
		totalAccesari += sum;
		printf("\ngasite[%d]=%d ", r, gasit);
		printf("\nsum[%d]=%d ", r, sum);////=>nr de accesari pt a gasi cele 1500 de elem
		printf("\nefortMaximGasite[%d]:%d ", r, maxG);
		printf("\ntotalGasite:%d ", totalGasite);
		printf("\ntotalAccesari:%d ", totalAccesari);

	while (negasit < 1500)
	{
		Nop = 0;

		negasit++;
		Nop += HTsearch3(T, (rand() % 10000) + 10000, n);
		//		printf("\ncasute accesate:%d ", op);
		Nsum += Nop;
		if (Nop > maxNG)
		{
			maxNG = Nop;
		}
	}

	totalNegasite += negasit;
	totalNAccesari += Nsum;
	printf("\nnegasite[%d]=%d ", r, negasit);
	printf("\nNsum[%d]=%d ", r, Nsum);////=>nr de accesari pt a gasi cele 1500 de elem,dar pe care nu le gaseste
	printf("\nefortMaximNeGasite[%d]:%d ", r, maxNG);
	printf("\ntotalNeGasite:%d ", totalNegasite);
	printf("\ntotalNAccesari:%d ", totalNAccesari);
	}
*/

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
