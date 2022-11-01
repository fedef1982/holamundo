#include <iostream>
#include <string.h>

using namespace std;
/*7. Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por
un punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si
no lo son. Los conjuntos deben ingresarse por teclado. (Definir parámetros y
codificar).
*/

struct STR_NODO
{
    char dato;
    STR_NODO *ste;
};

void create(STR_NODO **pila)
{
    *pila = NULL;
}

bool isEmpty(STR_NODO *pila)
{
    return pila == NULL;
}

void push(STR_NODO **pila, char valor)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return;
}

char pop(STR_NODO **pila)
{
    char dato = (*pila)->dato;
    STR_NODO *aux = *pila;
    *pila = (*pila)->ste;

    free(aux);
    return dato;
}

void clear(STR_NODO **pila)
{
    while (!isEmpty(*pila))
    {
      //printf("%c->", pop(pila));
      pop(pila);
    }
    //printf("NULL");
}

bool inversa(const char *palabra)
{
    char pal[255];
    char conjunto1[255];
    char conjunto2[255];

    STR_NODO *pila1 = NULL;
    STR_NODO *pila2 = NULL;
    STR_NODO *pilaAux = NULL;

    strcpy(pal, palabra);

    strcpy(conjunto1,strtok(pal,".\0\n"));
    strcpy(conjunto2,strtok(pal,".\0\n"));

    int i=0;
    while (conjunto1[i]!='\0')
    {
        push(&pila1,conjunto1[i]);
        i++;
    }
    
    int j=0;
    while (conjunto2[j]!='\0')
    {
        push(&pila2,conjunto2[j]);
        j++;
    }
    if (i != j )
    {
        clear(&pila1);
        clear(&pila2);
        return false;
    }

    while (!isEmpty(pila1))
    {
        char c;
        c=pop(&pila1);
        push(&pilaAux, c);
    }

    while (!isEmpty(pila2) && !isEmpty(pilaAux))
    {
        char c1,c2;
        c1= pop(&pila2);
        c2= pop(&pilaAux);
        if (c1 != c2)
            clear(&pila2);
            clear(&pilaAux);
            return false;
    } 
    
    return true;
}

int main()
{
    const char* palabra="ABcDe.eDcBA";

    if (inversa(palabra)) 
    {
        printf("Es inversa\n");
    }
    else 
    {
        printf("NO es inversa\n");
    }

    system("pause");
    return 0;
}