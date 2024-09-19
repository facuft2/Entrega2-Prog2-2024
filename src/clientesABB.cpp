#include "../include/clientesABB.h"

struct rep_clientesABB {
    TCliente cliente;
    TClientesABB izq;
    TClientesABB der;
};

TClientesABB crearTClientesABBVacio(){
    return NULL;
}

void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente){
    if(clientesABB == NULL){
        clientesABB = new rep_clientesABB;
        clientesABB->cliente = cliente;
        clientesABB->izq = NULL;
        clientesABB->der = NULL;
    }else{
        int idCliente = idTCliente(cliente);
        int idActual = idTCliente(clientesABB->cliente);

        if(idCliente < idActual){
            insertarTClienteTClientesABB(clientesABB->izq, cliente);
        }else{
            insertarTClienteTClientesABB(clientesABB->der, cliente);
        }
    }
}

void imprimirTClientesABB(TClientesABB clientesABB){
    if(clientesABB != NULL){
        imprimirTClientesABB(clientesABB->izq);
        imprimirTCliente(clientesABB->cliente);
        imprimirTClientesABB(clientesABB->der);
    }
}

void liberarTClientesABB(TClientesABB &clientesABB){
    if(clientesABB != NULL){
        liberarTClientesABB(clientesABB->izq);
        liberarTClientesABB(clientesABB->der);
        liberarTCliente(clientesABB->cliente);
        delete clientesABB;
        clientesABB = NULL;
    }
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if(clientesABB == NULL){
        return false;
    }else if(idTCliente(clientesABB->cliente) == idCliente){
        return true;
    }else if(idCliente < idTCliente(clientesABB->cliente)){
        return existeTClienteTClientesABB(clientesABB->izq, idCliente);
    }else{
        return existeTClienteTClientesABB(clientesABB->der, idCliente);
    }
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if(idTCliente(clientesABB->cliente) == idCliente){
        return clientesABB->cliente;
    }else if(idCliente < idTCliente(clientesABB->cliente)){
        return obtenerTClienteTClientesABB(clientesABB->izq, idCliente);
    }else{
        return obtenerTClienteTClientesABB(clientesABB->der, idCliente);
    }

}

nat alturaTClientesABB(TClientesABB clientesABB){
    if(clientesABB == NULL){
        return 0;
    }else{
        nat alturaIzq = alturaTClientesABB(clientesABB->izq);
        nat alturaDer = alturaTClientesABB(clientesABB->der);
        return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
    }
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL) {
        return NULL;
    }
    
    while (clientesABB->der != NULL) {
        clientesABB = clientesABB->der;
    }
    
    return clientesABB->cliente;
}

void liberarNodo(TClientesABB &clientesABB){
    if (clientesABB != NULL) {
        liberarTCliente(clientesABB->cliente);
        delete clientesABB;
        clientesABB = NULL;
    }
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente){
    if (clientesABB == NULL) {
        return;
    }
    if (idCliente == idTCliente(clientesABB->cliente)) {
        if (clientesABB->izq == NULL && clientesABB->der == NULL) {
            liberarNodo(clientesABB);
        } else if (clientesABB->izq == NULL) {
            TClientesABB temp = clientesABB;
            clientesABB = clientesABB->der;
            liberarNodo(temp);
        } else if (clientesABB->der == NULL) {
            TClientesABB temp = clientesABB;
            clientesABB = clientesABB->izq;
            liberarNodo(temp);
        } else {
            TCliente maxIzq = maxIdTClienteTClientesABB(clientesABB->izq);
            TCliente copiaMaxIzq = copiarTCliente(maxIzq);
            removerTClienteTClientesABB(clientesABB->izq, idTCliente(maxIzq));
            liberarTCliente(clientesABB->cliente);
            clientesABB->cliente = copiaMaxIzq;
        }
    } else if (idCliente < idTCliente(clientesABB->cliente)) {
        removerTClienteTClientesABB(clientesABB->izq, idCliente);
    } else {
        removerTClienteTClientesABB(clientesABB->der, idCliente);
    }
}

int cantidadClientesTClientesABB(TClientesABB clientesABB){
    if(clientesABB == NULL){
        return 0;
    }else{
        return 1 + cantidadClientesTClientesABB(clientesABB->izq) + cantidadClientesTClientesABB(clientesABB->der);
    }
}

float edadPromedioTClientesABB(TClientesABB clientesABB){
    if(clientesABB == NULL){
        return 0;
    }else{
        return (edadTCliente(clientesABB->cliente) + edadPromedioTClientesABB(clientesABB->izq) * cantidadClientesTClientesABB(clientesABB->izq) + edadPromedioTClientesABB(clientesABB->der) * cantidadClientesTClientesABB(clientesABB->der)) / cantidadClientesTClientesABB(clientesABB);
    }
}

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n){
    int cantIzq = cantidadClientesTClientesABB(clientesABB->izq);
    if(cantIzq == n - 1){
        return clientesABB->cliente;
    }else if(cantIzq < n - 1){
        return obtenerNesimoClienteTClientesABB(clientesABB->der, n - cantIzq - 1);
    }else{
        return obtenerNesimoClienteTClientesABB(clientesABB->izq, n);
    }
}

