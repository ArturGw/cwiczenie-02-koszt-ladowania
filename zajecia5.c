main(int)

    FILE *f;
int w, k;
f = fopen("dane/A.txt", "r");
if (f == NULL)
{
    printf("Blad: nie mozna otworzyc pliku\n");
    return 1;
}
if (fscanf(f, "%d %d", &w, &k) != 2)
{
    printf("Blad: brak wymiarow\n");
    fclose(f);
    return 1;
}
printf("Wymiary: %d x %d\n", w, k);
fclose(f);

int wczytaj_macierz(const char *nazwa, double M[][MAX],
                    int *w, int *k);
kod = wczytaj_macierz("dane/A.txt", A, &wA, &kA);

if (!wymiary_poprawne(*w, *k))
{
    return BLAD_ZAKRES;
}
for (i = 0; i < *w; i++)
{
    for (j = 0; j < *k; j++)
    {
        wynik = fscanf(f, "%lf", &M[i][j]);
        if (wynik == EOF)
        {
            return BLAD_ZA_MALO;
        }
        if (wynik != 1)
        {
            return BLAD_ELEMENT;
        }
    }
}

int wczytaj_macierz(const char *nazwa, double M[][MAX],
                    int *w, int *k)
{
    FILE *f;
    int kod;
    f = fopen(nazwa, "r");
    if (f == NULL)
    {
        return BLAD_OTWARCIA;
    }
    kod = czytaj_dane(f, M, w, k);
    fclose(f);
    return kod;
}

printf("Operacja: 1 - dodawanie, 2 - odejmowanie, 3 - mnozenie\n");
if (scanf("%d", &op) != 1)
{
    op = 0;
}
kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
if (kod != OK)
{
    fprintf(stderr, "Blad: %s\n", opis_bledu(kod));
    return 1;
}
wypisz(C, wC, kC);

fprintf(f, "%d %d\n", w, k);
for (i = 0; i < w; i++)
{
    for (j = 0; j < k; j++)
    {
        if (j > 0)
        {
            fprintf(f, " ");
        }
        fprintf(f, "%.2f", M[i][j]);
    }
    fprintf(f, "\n");
}
blad = ferror(f);
if (fclose(f) != 0)
{
    blad = 1;
}
return blad ? BLAD_ZAPISU : OK;