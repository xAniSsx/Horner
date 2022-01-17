#include <stdio.h>

unsigned int n;
int i;
float w, x;

int main()
{
    printf("Podaj argument: ");
    scanf("%f", &x);
    printf("Podaj stopien wielomianu: ");
    scanf("%d", &n);
    printf("Podaj po przecinku wspolczynniki przy kolejnych potegach, zaczynajac od najmniejszej(wyrazu wolnego): ");
    float* a = malloc((n+1) * sizeof(*a)); // Dynamicznie definiujemy tablice o pamieci, wynoszacej n+1.

    for(int j=0; j<n+1; j++)
    {
        scanf(" %f", &a[j]);
    }

    if (n>0)
    {
        w=a[n]*x+a[n-1];
        for (i=n-2; i>=0; i--)
        {
            w=w*x+a[i];
        }
        printf("Wynik wynosi: %f",w);
    }

    else if (n==0)
    {
        w=a[0];
        printf("Wynik wynosi: %f",w);
    }

    else
        printf("Brak wyniku.");

    return 0;
}
