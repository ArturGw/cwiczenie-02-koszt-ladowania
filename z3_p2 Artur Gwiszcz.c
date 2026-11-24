#include <stdio.h>
/*
Z3 opis zadania
napisac procedure licz¹c¹ objetosc walca
Pi*r*r*h
procedura ma miec parametry r i h

wywo³ywaæ w petli dla r zmieniajacego sie od 1 do 10 a h sta³e iles tam

poprosic o podanie r_od, r_do i krok i analogicznie znowu w petli obliczac
*/

#define PI 3.141592653589793

double objetosc_walca(double r, double h)
{
    return PI * r * r * h;
}

void petla_stala(void)
{
    double h = 5.0;
    int r;
    
    printf("\nObliczenia dla r od 1 do 10 (h = %.2lf)", h);
    
    for (r = 1; r <= 10; r++)
    {
        double v = objetosc_walca(r, h);
        printf("\nPromien r = %d, h = %.2lf -> Objetosc = %.2lf", r, h, v);
    }
}

void petla_uzytkownika(void)
{
    int r_od = 0, r_do = 0, r_krok = 1;
    int r;
    double h = 0.0;

    printf("\n\nObliczenia interaktywne");
    printf("\nPodaj r_od: ");
    scanf("%d", &r_od);
    
    printf("Podaj r_do: ");
    scanf("%d", &r_do);
    
    printf("Podaj krok: ");
    scanf("%d", &r_krok);

    printf("Podaj wysokosc h: ");
    scanf("%lf", &h);

    printf("\nWyniki dla r od %d do %d z krokiem %d (h = %.2lf):", r_od, r_do, r_krok, h);
    
    for (r = r_od; r <= r_do; r += r_krok)
    {
        double v = objetosc_walca(r, h);
        printf("\nPromien r = %d -> Objetosc = %.2lf", r, v);
    }
}

int main(void)
{
    petla_stala();
    petla_uzytkownika();
    
    return 0;
}
