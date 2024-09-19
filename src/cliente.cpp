#include "../include/cliente.h"

struct rep_cliente {
    int id;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int edad;
};

TCliente crearTCliente(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TCliente cliente = new rep_cliente;
    cliente->id = id;
    strcpy(cliente->nombre, nombre);
    strcpy(cliente->apellido, apellido);
    cliente->edad = edad;
    return cliente;
}

void imprimirTCliente(TCliente cliente){
    printf("Cliente %s %s\n", cliente->nombre, cliente->apellido);
    printf("Id: %d\n", cliente->id);
    printf("Edad: %d\n", cliente->edad);
}

void liberarTCliente(TCliente &cliente){
    if (cliente != NULL){
        delete cliente;
        cliente = NULL;
    }
}

void nombreTCliente(TCliente cliente, char nombre[MAX_NOMBRE]){
    strcpy(nombre, cliente->nombre);
}

void apellidoTCliente(TCliente cliente, char apellido[MAX_APELLIDO]){
    strcpy(apellido, cliente->apellido);
}

int idTCliente(TCliente cliente){
    return cliente->id;
}

int edadTCliente(TCliente cliente){
    return cliente->edad;
}

TCliente copiarTCliente(TCliente cliente){
    return crearTCliente(cliente->id, cliente->nombre, cliente->apellido, cliente->edad);
}
