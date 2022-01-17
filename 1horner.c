#include <stdio.h>
#include <stdlib.h>

float w;
float x;
int n = 0;
int i, j, k;

int main()
{
    printf("Podaj argument: ");
    scanf("%f", &x);

    FILE *fptr;
    int *a;

    if ((fptr = fopen("C:/users/root/desktop/C++/co_jest_nie_tak_z_hornerem/horner.txt","r")) == NULL)
    {
       printf("Error opening file!\n");
       exit(1);
    }
    while (fscanf(fptr,"%d", &i) > 0)
    {
       if (n == 0)
         a = malloc(sizeof(int));
       else
         a = realloc(a, (n+1)*sizeof(int));
       a[n] = i;
       ++n;
    }
    fclose(fptr);

    for (i = 0; i < n; ++i)
        printf("%d\n", a[i]);

    n=n-1;
/*  j==n;

    for(i=0; i<j-1; i++)
    {
        k=a[i];
        a[i]=a[j];
        a[j]=k;
        j--;
    }

    for (i = 0; i < n; ++i)
        printf("%d\n", a[i]);
*/
    if (n>0)
    {
        w=a[n]*x+a[n-1];
        for (i=n-2; i>=0; i--)
        {
            w=w*x+a[i];
        }
        printf("Wynik wynosi: %.2f",w);
    }

    else if (n==0)
    {
        w=a[0];
        printf("Wynik wynosi: %.2f",w);

    }

    return 0;
}

