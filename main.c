#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* tablica napisow */
/* liczba argumentow --- s³ów */

int main(int argc, char *argv[]) {

	float wynik = 0;
	float x;
	int i;
	int liczba_zmiennych;
	//atof 
	//sscanf()


	for (i=1; i<argc; i++) {
	//wynik = wynik * atof(argv[i]);
	liczba_zmiennych = sscanf(argv[i], "%f", &x);
	if (liczba_zmiennych != 1) {
		printf("Blad konwersji argumentu %s na liczbê zmiennoprzecinkowa.\n", argv[i]);
		exit(-1);
	}
	wynik = wynik + x;
}

	printf("Suma = %f \n", wynik );
		
		
	return 0;
}
