#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float T[];

int main ()
{
    printf("Podaj po przecinku wspolczynniki przy kolejnych potegach, zaczynajac od najwiekszej: ");
    scanf("%s", &T);

    FILE *fp; /* u¿ywamy metody wysokopoziomowej - musimy mieæ zatem identyfikator pliku, uwaga na gwiazdkê! */
    float a[] = T;
    if ((fp=fopen("horner.txt", "w"))==NULL)
    {
        printf ("Nie mogê otworzyæ pliku horner.txt do zapisu!\n");
        exit(1);
    }
    fprintf (fp, "%s", a); /* zapisz nasz ³añcuch w pliku */
    fclose (fp); /* zamknij plik */
    return 0;
 }
