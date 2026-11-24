#include <stdio.h>
#include "matrix.h"
#include "matrix_io.h"

int main(int argc, char *argv[])
{
    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];
    int wA, kA, wB, kB, wC, kC;
    int op, kod;
    char plik_a[256], plik_b[256], plik_c[256];
    const char *nazwa_a;
    const char *nazwa_b;
    const char *nazwa_c;

    if (argc == 1) {
        printf("Podaj nazwe pliku A: ");
        if (scanf("%255s", plik_a) != 1) {
            printf("Blad: %s\n", opis_bledu(BLAD_OTWARCIA));
            return BLAD_OTWARCIA;
        }

        printf("Podaj nazwe pliku B: ");
        if (scanf("%255s", plik_b) != 1) {
            printf("Blad: %s\n", opis_bledu(BLAD_OTWARCIA));
            return BLAD_OTWARCIA;
        }

        printf("Podaj nazwe pliku wynikowego: ");
        if (scanf("%255s", plik_c) != 1) {
            printf("Blad: %s\n", opis_bledu(BLAD_ZAPISU));
            return BLAD_ZAPISU;
        }

        printf("Operacja: 1 - dodawanie, 2 - odejmowanie, 3 - mnozenie\n");
        if (scanf("%d", &op) != 1) {
            op = 0;
        }

        nazwa_a = plik_a;
        nazwa_b = plik_b;
        nazwa_c = plik_c;
    } else if (argc == 5) {
        nazwa_a = argv[1];
        nazwa_b = argv[2];
        nazwa_c = argv[3];

        op = 0;
        if (argv[4][0] != '\0' && argv[4][1] == '\0') {
            if (argv[4][0] == '1' || argv[4][0] == '+') {
                op = 1;
            } else if (argv[4][0] == '2' || argv[4][0] == '-') {
                op = 2;
            } else if (argv[4][0] == '3' || argv[4][0] == '*') {
                op = 3;
            }
        }

        if (op == 0) {
            printf("Blad: %s\n", opis_bledu(BLAD_OPERACJI));
            return BLAD_OPERACJI;
        }
    } else {
        printf("Blad: %s\n", opis_bledu(BLAD_PARAMETROW));
        printf("Uzycie: %s [plik_A plik_B plik_wynik 1|2|3|+|-|*]\n", argv[0]);
        return BLAD_PARAMETROW;
    }

    kod = wczytaj_macierz(nazwa_a, A, &wA, &kA);
    if (kod != OK) {
        printf("Blad (%s): %s\n", nazwa_a, opis_bledu(kod));
        return kod;
    }

    kod = wczytaj_macierz(nazwa_b, B, &wB, &kB);
    if (kod != OK) {
        printf("Blad (%s): %s\n", nazwa_b, opis_bledu(kod));
        return kod;
    }

    kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
    if (kod != OK) {
        printf("Blad: %s\n", opis_bledu(kod));
        return kod;
    }

    wypisz(C, wC, kC);

    kod = zapisz_macierz(nazwa_c, C, wC, kC);
    if (kod != OK) {
        printf("Blad: %s\n", opis_bledu(kod));
        return kod;
    }

    printf("Wynik zapisano do pliku %s\n", nazwa_c);
    return OK;
}