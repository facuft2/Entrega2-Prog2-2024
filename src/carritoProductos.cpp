#include "../include/carritoProductos.h"

struct rep_carritoProductos{
    TProducto producto;
    TCarritoProductos sig;
};

TCarritoProductos crearCarritoProductosVacio(){
    TCarritoProductos carritoProductos = NULL;
    return carritoProductos;
}

void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto){
    TCarritoProductos nuevoNodo = new rep_carritoProductos;
    nuevoNodo->producto = producto;
    nuevoNodo->sig = NULL;
    if (carritoProductos == NULL){
        carritoProductos = nuevoNodo;
    } else {
        TCarritoProductos aux = carritoProductos;
        TCarritoProductos ant = NULL;
        while (aux != NULL && idTProducto(aux->producto) < idTProducto(producto)){
            ant = aux;
            aux = aux->sig;
        }
        if (ant == NULL){
            nuevoNodo->sig = carritoProductos;
            carritoProductos = nuevoNodo;
        } else {
            ant->sig = nuevoNodo;
            nuevoNodo->sig = aux;
        }
    }
}

void imprimirCarritoProductos(TCarritoProductos carritoProductos){
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL){
        imprimirTProducto(aux->producto);
        aux = aux->sig;
    }
}

void liberarCarritoProductos(TCarritoProductos &carritoProductos){
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL){
        TCarritoProductos sig = aux->sig;
        liberarTProducto(aux->producto);
        delete aux;
        aux = sig;
    }
    carritoProductos = NULL;
}

bool esVacioCarritoProductos(TCarritoProductos carritoProductos){
    return carritoProductos == NULL;
}

bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL && idTProducto(aux->producto) != idProducto){
        aux = aux->sig;
    }
    return aux != NULL;
}

TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    TCarritoProductos aux = carritoProductos;
    while (aux != NULL && idTProducto(aux->producto) != idProducto){
        aux = aux->sig;
    }
    return aux->producto;
}

void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto){
    TCarritoProductos aux = carritoProductos;
    TCarritoProductos ant = NULL;
    while (aux != NULL && idTProducto(aux->producto) != idProducto){
        ant = aux;
        aux = aux->sig;
    }
    if (ant == NULL){
        carritoProductos = aux->sig;
    } else {
        ant->sig = aux->sig;
    }
    liberarTProducto(aux->producto);
    delete aux;
}