#include <stdio.h>

#define MAX 20

int wymiary_poprawne(int w, int k);
int zgodne_do_sumy(int wA, int kA, int wB, int kB);
int zgodne_do_mnozenia(int kA, int wB);

void dodaj(double A[][MAX], double B[][MAX],
           double C[][MAX], int w, int k);

void odejmij(double A[][MAX], double B[][MAX],
             double C[][MAX], int w, int k);

void pomnoz(double A[][MAX], double B[][MAX],
            double C[][MAX], int wA, int kA, int kB);

void wypisz(double M[][MAX], int w, int k);

int main(void) {
    int wA = 2, kA = 3;
    double A[MAX][MAX] = {
        {1.5, 2.0, 3.75},
        {4.1, 5.8, 6.2}
    };

    int wB = 3, kB = 2;
    double B[MAX][MAX] = {
        {7.0, 8.1},
        {9.2, 10.3},
        {11.4, 12.5}
    };

    double C[MAX][MAX];

    printf("Macierz A:\n");
    wypisz(A, wA, kA);

    printf("\nMacierz B:\n");
    wypisz(B, wB, kB);

    if (!wymiary_poprawne(wA, kA)) {
        printf("\nNiepoprawne wymiary macierzy A.\n");
    }

    if (!wymiary_poprawne(wB, kB)) {
        printf("\nNiepoprawne wymiary macierzy B.\n");
    }

    if (wymiary_poprawne(wA, kA) && wymiary_poprawne(wB, kB)) {

        
        if (zgodne_do_sumy(wA, kA, wB, kB)) {
            dodaj(A, B, C, wA, kA);
            printf("\nSuma macierzy A i B:\n");
            wypisz(C, wA, kA);

            odejmij(A, B, C, wA, kA);
            printf("\nRoznica macierzy A i B:\n");
            wypisz(C, wA, kA);
        } else {
            printf("\nNie mozna dodac ani odjac macierzy - maja rozne wymiary.\n");
        }

        
        if (zgodne_do_mnozenia(kA, wB)) {
            pomnoz(A, B, C, wA, kA, kB);
        
            printf("\nIloczyn macierzy A i B (wynik o wymiarach %dx%d):\n", wA, kB);
            wypisz(C, wA, kB);
        } else {
            printf("\nNie mozna pomnozyc macierzy - niezgodne wymiary (kolumny A != wiersze B).\n");
        }
    }

    return 0;
}

int wymiary_poprawne(int w, int k) {
    return w >= 1 && w <= MAX &&
           k >= 1 && k <= MAX;
}

int zgodne_do_sumy(int wA, int kA, int wB, int kB) {
    return wA == wB && kA == kB;
}

int zgodne_do_mnozenia(int kA, int wB) {
    return kA == wB;
}

void dodaj(double A[][MAX], double B[][MAX],
           double C[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void odejmij(double A[][MAX], double B[][MAX],
             double C[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB) {
    int i, j, n;
    double suma;
    
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            suma = 0.0;
            for (n = 0; n < kA; n++) {
                suma = suma + A[i][n] * B[n][j];
            }
            C[i][j] = suma;
        }
    }
}

void wypisz(double M[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}
