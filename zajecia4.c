
#include <stdio.h>

#define MAX 20

int wymiary_poprawne(int w, int k);
int zgodne_do_sumy(int wA, int kA, int wB, int kB);

void dodaj(double A[][MAX], double B[][MAX],
           double C[][MAX], int w, int k);

void odejmij(double A[][MAX], double B[][MAX],
             double C[][MAX], int w, int k);

void wypisz(double M[][MAX], int w, int k);

int main(void) {
    int wA = 2, kA = 3;
    double A[MAX][MAX] = {
        {1.5, 2.0, 3.75},
        {4.1, 5.8, 6.2}
    };

    int wB = 2, kB = 3;
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

    if (wymiary_poprawne(wA, kA) &&
        wymiary_poprawne(wB, kB)) {

        if (zgodne_do_sumy(wA, kA, wB, kB)) {
            dodaj(A, B, C, wA, kA);
            printf("\nSuma macierzy A i B:\n");
            wypisz(C, wA, kA);

            odejmij(A, B, C, wA, kA);
            printf("\nRoznica macierzy A i B:\n");
            wypisz(C, wA, kA);
        } else {
            printf("\nNie mozna dodac ani odjac macierzy - "
                   "maja rozne wymiary.\n");
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

void wypisz(double M[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}
