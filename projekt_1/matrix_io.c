#include <stdio.h>
#include "matrix_io.h"

void wypisz(double M[MAX][MAX], int w, int k)
{
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int wczytaj_macierz(const char *nazwa, double M[MAX][MAX], int *w, int *k)
{
    FILE *f;
    int i, j, wynik;

    f = fopen(nazwa, "r");
    if (f == NULL) {
        return BLAD_OTWARCIA;
    }

    if (fscanf(f, "%d %d", w, k) != 2) {
        fclose(f);
        return BLAD_WYMIAROW;
    }

    if (*w < 1 || *w > MAX || *k < 1 || *k > MAX) {
        fclose(f);
        return BLAD_ZAKRES;
    }

    for (i = 0; i < *w; i++) {
        for (j = 0; j < *k; j++) {
            wynik = fscanf(f, "%lf", &M[i][j]);
            if (wynik == EOF) {
                fclose(f);
                return BLAD_ZA_MALO;
            }
            if (wynik != 1) {
                fclose(f);
                return BLAD_ELEMENT;
            }
        }
    }

    fclose(f);
    return OK;
}

int zapisz_macierz(const char *nazwa, double M[MAX][MAX], int w, int k)
{
    FILE *f;
    int i, j, blad;

    f = fopen(nazwa, "w");
    if (f == NULL) {
        return BLAD_ZAPISU;
    }

    fprintf(f, "%d %d\n", w, k);
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            if (j > 0) {
                fprintf(f, " ");
            }
            fprintf(f, "%.2f", M[i][j]);
        }
        fprintf(f, "\n");
    }

    blad = ferror(f);
    if (fclose(f) != 0) {
        blad = 1;
    }

    if (blad) {
        return BLAD_ZAPISU;
    }
    return OK;
}