#include <iostream>
#include <string.h>

// atoi
// isdigit
int longitudCadena(char cadena[])
{
    int i=0;
    while(cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

bool esPalindromo (char cadena[], int len)
{
    int  i=0;
    bool capicua=true;
    while ( capicua && i<(len-1)/2)
    {
        if (cadena[i] != cadena[len-i] )
            capicua=false;
        i++;
    }
    return capicua;
}

int main()
{
    char cadena[81]="neuquen";
    int len = 0;

    printf("Ingrese una cadeana de caracteres ");
    
    scanf("%80s", cadena);
    printf("%s\n", cadena);

    len = longitudCadena(cadena);

    if (esPalindromo(cadena,len-1))
    {
        printf("La palabra %s es un palindromo\n ", cadena);
    }
    else
    {
        printf("La palabra %s no es un palindromo\n ", cadena);
    }

    //printf ("\nPresione enter para continuar...");
    system("pause");
    return 0;
}
