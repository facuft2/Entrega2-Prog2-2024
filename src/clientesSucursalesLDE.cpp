#include "../include/clientesSucursalesLDE.h"

struct rep_clientesSucursalesLDE {
    TClientesABB clientesABB;
    int idSucursal;
    TClientesSucursalesLDE siguiente, anterior;
};

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia() {
    TClientesSucursalesLDE nuevaLista = new rep_clientesSucursalesLDE;
    nuevaLista->clientesABB = NULL;
    nuevaLista->anterior = NULL;
    nuevaLista->siguiente = NULL;
    return nuevaLista;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE lista, TClientesABB clientesABB, int idSucursal) {
    if (lista->clientesABB == NULL) {
        lista->clientesABB = clientesABB;
        lista->idSucursal = idSucursal;
        return;
    }

    TClientesSucursalesLDE actual = lista;
    TClientesSucursalesLDE nuevaSucursal = crearTClientesSucursalesLDEVacia();
    nuevaSucursal->idSucursal = idSucursal;
    nuevaSucursal->clientesABB = clientesABB;

    while (actual->anterior != NULL && edadPromedioTClientesABB(actual->anterior->clientesABB) > edadPromedioTClientesABB(clientesABB)) {
        actual = actual->anterior;
    }
    while (actual->siguiente != NULL && edadPromedioTClientesABB(actual->siguiente->clientesABB) <= edadPromedioTClientesABB(clientesABB)) {
        actual = actual->siguiente;
    }

    if (edadPromedioTClientesABB(actual->clientesABB) > edadPromedioTClientesABB(clientesABB)) {
        nuevaSucursal->siguiente = actual;
        nuevaSucursal->anterior = actual->anterior;
        if (actual->anterior != NULL) {
            actual->anterior->siguiente = nuevaSucursal;
        }
        actual->anterior = nuevaSucursal;
    } else {
        nuevaSucursal->anterior = actual;
        nuevaSucursal->siguiente = actual->siguiente;
        if (actual->siguiente != NULL) {
            actual->siguiente->anterior = nuevaSucursal;
        }
        actual->siguiente = nuevaSucursal;
    }

    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }
    lista = actual;
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &lista) {
    if (lista->clientesABB == NULL) {
        delete lista;
        lista = NULL;
        return;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }
    while (actual != NULL) {
        if (actual->clientesABB != NULL) {
            liberarTClientesABB(actual->clientesABB);
        }
        TClientesSucursalesLDE temp = actual;
        actual = actual->siguiente;
        delete temp;
        temp = NULL;
    }
}

void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE lista) {
    printf("clientesSucursalesLDE de grupos:\n");
    if (lista == NULL || lista->clientesABB == NULL) {
        return;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }
    while (actual != NULL) {
        printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(actual->clientesABB));
        imprimirTClientesABB(actual->clientesABB);
        actual = actual->siguiente;
    }
}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE lista) {
    printf("clientesSucursalesLDE de grupos:\n");
    if (lista->clientesABB == NULL) {
        return;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    while (actual != NULL) {
        printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(actual->clientesABB));
        imprimirTClientesABB(actual->clientesABB);
        actual = actual->anterior;
    }
}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE lista) {
    if (lista == NULL || lista->clientesABB == NULL) {
        return 0;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }

    nat total = 0;
    while (actual != NULL) {
        ++total;
        actual = actual->siguiente;
    }

    return total;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE lista) {
    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }
    return actual->clientesABB;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE lista, int n) {
    if ((int)cantidadTClientesABBClientesSucursalesLDE(lista) < n) {
        return NULL;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }

    int contador = 1;
    while (contador < n) {
        ++contador;
        actual = actual->siguiente;
    }
    return actual->clientesABB;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE lista) {
    if (lista == NULL || lista->clientesABB == NULL) {
        return NULL;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    TClientesABB clientesABB = actual->clientesABB;
    if (actual == lista) {
        lista->clientesABB = NULL;
        return clientesABB;
    }

    if (actual->anterior != NULL) {
        actual->anterior->siguiente = NULL;
    }

    actual->clientesABB = NULL;
    delete actual;
    return clientesABB;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE lista, int n) {
    if ((int)cantidadTClientesABBClientesSucursalesLDE(lista) < n) {
        return NULL;
    }

    TClientesSucursalesLDE actual = lista;
    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }

    int contador = 1;
    while (contador < n) {
        ++contador;
        actual = actual->siguiente;
    }

    TClientesABB cliente = actual->clientesABB;
    if (actual == lista) {
        lista->clientesABB = NULL;
        return cliente;
    }

    if (actual->anterior != NULL) {
        actual->anterior->siguiente = actual->siguiente;
    }
    if (actual->siguiente != NULL) {
        actual->siguiente->anterior = actual->anterior;
    }

    actual->clientesABB = NULL;
    delete actual;
    return cliente;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE lista) {
    TClientesSucursalesLDE actual = lista;
    int veces[1000] = {0};

    while (actual->anterior != NULL) {
        actual = actual->anterior;
    }

    int maxId = 0;
    while (actual != NULL) {
        int cantidadClientes = cantidadClientesTClientesABB(actual->clientesABB);
        for (int i = 1; i <= cantidadClientes; i++) {
            TCliente cliente = obtenerNesimoClienteTClientesABB(actual->clientesABB, i);
            int id = idTCliente(cliente);
            ++veces[id];
            if (id >= maxId) {
                maxId = id;
            }
        }
        actual = actual->siguiente;
    }

    int maxRepeticiones = 0;
    int idMasRepetido = 0;
    for (int i = 0; i <= maxId; i++) {
        if (veces[i] > maxRepeticiones) {
            maxRepeticiones = veces[i];
            idMasRepetido = i;
        }
    }

    TClientesSucursalesLDE iterador = lista;
    while (iterador->anterior != NULL) {
        iterador = iterador->anterior;
    }
    while (iterador->siguiente != NULL) {
        if (existeTClienteTClientesABB(iterador->clientesABB, idMasRepetido)) {
            return obtenerTClienteTClientesABB(iterador->clientesABB, idMasRepetido);
        }
        iterador = iterador->siguiente;
    }

    return NULL;
}
