#include <iostream>

struct Inscripcion
{

};

void leer(Inscripcion ptrRegistro,FILE *file)
{
    Inscripcion registro;
    fread(&registro, sizeof(registro),1, file );
    return;
}


void escribir(Inscripcion ptrRegistro,FILE *file)
{
    fwrite(registro, sizeof(registro),1, file );
    return;
}

int main()d
{
    FILE *diaFinales = NULL;
    FILE *finales = NULL;

    diaFinales = fopen("DIAFINALES.DAT","rb");
    if (fiaFinales == NULL)
    {
        exit(EXIT_FAILURE);
    }
    finales = fopen("DIAFINALES.DAT","rb");
    if (fiaFinales == NULL)
    {
        exit(EXIT_FAILURE);
    }

    getchar();
    return 0;
}