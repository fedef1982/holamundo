#include <iostream>
#include <string.h>

#define MAX_BUFFER 255
using namespace std;


struct Pedido
{
    char codP[10];
    int codC;
    char recibido;
};

struct Cliente
{
    int codC;
    char nombre[20];
    char apellido[20];
    char email[20];
};

struct Recibido
{
    char email[20];
    char mensaje[256];
};

Pedido leerPedido(FILE* pedido);
Cliente leerCliente(FILE* clientes,int codC);

int main()
{
    FILE *pedidos = fopen("Pedidos.txt","r");
    FILE *clientes = fopen("Agenda.dat","rb");
    FILE *recibidos = fopen("Recibidos.dat","wb");

    Cliente rCliente;
    Recibido rRecibido;
    Pedido rPedido = leerPedido(pedidos);

    while (!feof(pedidos))
    {
        if (rPedido.recibido=='S');
        {
            rCliente = leerCliente(clientes, rPedido.codC);
            strcpy(rRecibido.email, rCliente.email);
            strcpy(rRecibido.mensaje, "Estimado/a ");
            strcat(rRecibido.mensaje, rCliente.nombre);
            strcat(rRecibido.mensaje, ", su pedido ");
            strcat(rRecibido.mensaje, rPedido.codP);
            strcat(rRecibido.mensaje, " se encuentra disponible para ser retirado");  
            fwrite(&rRecibido,sizeof(Recibido),1,recibidos);       
        }
        Pedido rPedido = leerPedido(pedidos);
    }
    
    fclose(pedidos);
    fclose(clientes);
    fclose(recibidos);
    getchar();
    return 0;
}

Pedido leerPedido(FILE* pedidos)
{
    Pedido rPedido;
    char buffer[MAX_BUFFER];

    if (fgets(buffer, MAX_BUFFER, pedidos) != NULL)
    {
        strcpy(rPedido.codP,(strtok(buffer,",")));
        rPedido.codC = atoi(strtok(NULL,","));
        rPedido.recibido = strtok(NULL,",\n")[0];
    }

    return rPedido;
}
Cliente leerCliente(FILE* clientes,int codC)
{
    Cliente rCliente;
    fseek(clientes, sizeof(Cliente) * (codC-1), SEEK_SET );
    fread(&rCliente, sizeof(Cliente), 1, clientes);
    return rCliente;
}