#include <iostream>
#include <string.h>

struct finales
{
    int legajo;
    int codMat;
    char nombre[25];
};


int main()
{
    FILE* maestroFinales = fopen("MAESTROFINALES.DAT","wb");
    FILE* diaFinales = fopen("DIAFINALES.DAT","wb");

    finales regFinales;

    for (char i=0; i<4; i++)
    {
        regFinales.legajo=10000000+i*3;
        regFinales.codMat=900000+i*2;
        strcpy(regFinales.nombre,"federico ");
        regFinales.nombre[8]=i+48;
        fwrite(&regFinales,sizeof(regFinales),1,maestroFinales);
    }

    for (char i=0; i<3; i++)
    {
        regFinales.legajo=10000000+i*4;
        regFinales.codMat=900000+i*2;
        strcpy(regFinales.nombre,"fresco ");
        regFinales.nombre[6]=i+48;
        fwrite(&regFinales,sizeof(regFinales),1,diaFinales);
    }
    

    fclose(maestroFinales);
    fclose(diaFinales);

    getchar();
    return 0;
}