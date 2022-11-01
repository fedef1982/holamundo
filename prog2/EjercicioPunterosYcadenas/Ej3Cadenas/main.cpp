#include <iostream>
#include <string.h>

using namespace std;
/*
3) Dada una cadena, cuya longitud máxima es de 15 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena forma una dirección de ip válida.
Ejemplo:
192.168.1.23 → verdadero
192.168.1.z → falso
10.250.244.255 → verdadero
*/

int charAdig(char c)
{
    if ( c > 47 || c < 58 ) return c - 48;
    return -1;
}

bool esDig(char c)
{
    if ( c == '0' ||
         c == '1' ||
         c == '2' ||
         c == '3' ||
         c == '4' ||
         c == '5' ||
         c == '6' ||
         c == '7' ||
         c == '8' ||
         c == '9' ) return true;
    return false;
}

int main()
{
    char cadena[16]="25.25.25.25";

    bool esIP=true;
    int i=0;
    int contOctetos=0;
    char c;

    c = *cadena;

    while (c != '\0')
    {

        int octeto=0;
        int j=0;
        while (c != '\0' && c != '.' )
        {
            if (!(esDig(c)) || j > 2 || contOctetos >= 2)
            {
                cout<<"NO Es IP VALIDA";
                return 0;
            }           
            
            if (j==0)
            {    
                octeto = charAdig(c);
            }
            if (j==1)
            {    
                octeto = octeto * 10 + charAdig(c);
            }
            if (j==2)
            {    
                octeto = octeto * 10 + charAdig(c);
            }

            j++;
            i++;

            c = *(cadena+i);
        }
        contOctetos++;

        if ( octeto < 0 || octeto > 255 ) 
        {
            cout<<"NO Es IP VALIDA";
            return 0;
        } 

        if ( c ='.')
        {
            i++;
            c = *(cadena+i);
        }

    }

    if (esIP) cout<<"Es IP VALIDA";
    else cout<<"NO Es IP VALIDA";

    getchar();

    return 0;
}


