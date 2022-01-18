#include <stdio.h> //zalaczanie glownej biblioteki
#include <stdlib.h> //zalaczanie biblioteki potrzebnej do obslugi tablic dynamicznych

float w; //w -> wartosc wielomianu
float x; //x -> argument, dla ktorego obliczamy wartosc
int n = 0; //n -> stopien wielomianu
int i, j, k; // zmienne dodatkowe

int main()
{
    printf("Podaj argument: ");
    scanf("%f", &x);

    FILE *fptr;//tworzenie wskaznika do pliku tekstowego
    int *a;

    if ((fptr = fopen("C:/Users/Root/Desktop/github/Horner/horner.txt","r")) == NULL)//otwieranie pliku tekstowego
    {
       printf("Error opening file!\n");
       exit(1);
    }
    while (fscanf(fptr,"%d", &i) > 0)
    {
       if (n == 0)
         a = malloc(sizeof(int));//Przydziela pamiec
       else
         a = realloc(a, (n+1)*sizeof(int));//Zmienia rozmiar poprzednio przydzielonej pamieci.
       a[n] = i;
       ++n;
    }
    fclose(fptr);//zamkniecie pliku tekstowego

    printf("Twoje wspolczynniki to: ");

    for (i = 0; i < n; ++i) printf("%d, ", a[i]);

        printf("\n");

    n=n-1;//Zaczynamy odczytywanie tablicy od tylu. W n-tej komorce znajduje sie null, czyli znak konca, wiec musimy pobierac wartosci wspolczynnikow wielomianu od komorki n-1
    j=n;

    for(i=0; i<j; i++)//odwracanie elementow tablicy
    {
        k=a[i];
        a[i]=a[j];
        a[j]=k;
        j--;
    }

    if (n>0)
    {
        w=a[n]*x+a[n-1];//Mnozymy wspolczynnik a[n] przy najwiekszej potedze n przez argument x, nastepnie dodajemy do otrzymanej wartosci wspolczynnik przy mniejszej o 1 potedze
        for (i=n-2; i>=0; i--)//W celu stworzenia petli nadajemy zmiennej i wartosc n-2
        {
            w=w*x+a[i];//Otrzymany wynik w poprzednim kroku mnozymy przez ten sam x, a nastepnie dodajemy wspolczynnik przy kolejnej potedze mniejszej od poprzedniej o 1 do momentu, gdy i bêdzie mniejsze od 0
        }
        printf("Wynik wynosi: %.2f",w);
    }

    else if (n==0)
    {
        w=a[0];//W przypadku, gdy stopien wielomianu n jest rowny 0, wynikiem bedzie wyraz wolny wielomianu.
        printf("Wynik wynosi: %.2f",w);
    }

    if((fptr = fopen("C:/Users/Root/Desktop/github/Horner/horner.txt","w")) == NULL) //w liniach 66-73 -> wpisywanie do pliku
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "Wynik wynosi: %.2f",w);
    fclose(fptr);

    return 0;
}
