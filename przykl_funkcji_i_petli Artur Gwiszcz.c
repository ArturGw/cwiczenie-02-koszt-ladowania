#include <stdio.h>

#define PI 3.14


double przelicz_omega_na_czest(double omega, int pokaz);
double przelicz_czest_na_omega(double f, int pokaz);

int main(void)
{
 
    double f1 = 50.0;
    double f2 = 100.0;

    printf("Czestotliwosc na Omega\n");
    double omega1 = przelicz_czest_na_omega(f1, 1);
    double omega2 = przelicz_czest_na_omega(f2, 1);

 
    printf("\n\nOmega na Czestotliwosc\n");
    
    {
        double w_test1 = omega1;
        double f_wynik1 = przelicz_omega_na_czest(w_test1, 0);
        printf("\nWynik dla omega = %4.1lf to czestotliwosc = %4.1lf Hz", w_test1, f_wynik1);
    }

    {
        double w_test2 = omega2;
        double f_wynik2 = przelicz_omega_na_czest(w_test2, 0);
        printf("\nWynik dla omega = %4.1lf to czestotliwosc = %4.1lf Hz", w_test2, f_wynik2);
    }

    
    printf("\n\nBezposrednie przeliczenie omega na czestotliwosc\n");
    przelicz_omega_na_czest(314.0, 1);
    przelicz_omega_na_czest(628.0, 1);

    return 0;
}


double przelicz_omega_na_czest(double omega, int pokaz)
{
   
    double f = omega / (2 * PI);

    if (pokaz)
    {
        printf("\nczestotliwosc wyliczona z omega = %4.1lf to %4.1lf Hz", omega, f);
    }
    return f;
}


double przelicz_czest_na_omega(double f, int pokaz)
{
    double omega = 2 * PI * f;

    if (pokaz)
    {
        printf("\nomega wyliczona z czestotliwosci = %4.1lf Hz to %4.1lf", f, omega);
    }
    return omega;
}
