#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float sumuj(unsigned int n, float v[]) {
	float wynik = 0;
	int i;
	for (i=0; i < n; i++) {
		wynik += v[i];
	}
	return wynik;
}

int konwertuj_na_floaty(int argc, char*napisy[], float docelowa_tablica[]) {
	int i;
	for (i = 0; i < argc; i++) {
		docelowa_tablica[i] = atof(napisy[i+1]);
	}
	return i-1;
}

void wypisz_tablice(int n, float v[]) {
	int i;
	printf("[%d]: ", n);
	for (i = 0; i < n; i++)
		printf("%f ", v[i]);
		printf("\n");
}

int main(int argc, char *argv[]) {
	float v[10];
	int n;
	
	n = konwertuj_na_floaty(argc, argv, v);
	
	
	printf("Suma =  %f\n", sumuj(n, v));
	printf("Srednia = %f\n", sumuj(n, v) / n);
	
	return 0; 
}
