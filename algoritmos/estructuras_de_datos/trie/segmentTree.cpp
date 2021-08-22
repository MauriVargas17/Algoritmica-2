#include <iostream>
#include <stdio.h>

using namespace std;
int numbers[] = {1,2,3,4};

struct node {
    // crear una variable por query
    int maximo;
    int minimo;
    int sum = 0;
}segmentTree[1000000];

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].maximo = numbers[ini];
        segmentTree[nodoActual].minimo = numbers[ini];
        segmentTree[nodoActual].sum = numbers[ini];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        // Ir por el hijo Izq
        init(ini, medio, hijoIzq);
        // Ir por el hijo Der
        init(medio + 1, fin, hijoDer);
        // Actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
        segmentTree[nodoActual].minimo = max(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
        segmentTree[nodoActual].sum = segmentTree[hijoIzq].sum + segmentTree[hijoDer].sum;
    }
}

node query(int ini, int fin, int nodoActual, int i, int j) {
    if(ini >= i && fin <= j){
        return segmentTree[nodoActual];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if ( j <= medio ) {
            return query(ini, medio, hijoIzq, i, j);
        }else if (i > medio){
            return query(medio+1,fin,hijoDer,i,j);
        } else {
            node queryIzq = query(ini,medio,hijoIzq,i,j);
            node queryDer = query(medio+1,fin,hijoDer,i,j);

            node resultado;
            resultado.maximo = max(queryIzq.maximo, queryDer.maximo);
            
            resultado.minimo = min(queryIzq.minimo, queryDer.minimo);
           
            resultado.sum = queryIzq.sum + queryDer.sum;
            
            return resultado;
           
        }
    }
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio && posicion > final ) {
        return ;
    }

    if( inicio == final ) {
        segmentTree[nodoActual].maximo = valor;
        segmentTree[nodoActual].minimo = valor;
        segmentTree[nodoActual].sum = valor;
    } else {

        int mid = (inicio + final ) / 2;
        int nodoIzquierdo = 2 * nodoActual + 1;
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho
        update(mid+1, final, nodoDerecho, posicion, valor );

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].maximo = max(segmentTree[nodoIzquierdo].maximo,  segmentTree[nodoDerecho].maximo);
        segmentTree[nodoActual].minimo = min(segmentTree[nodoIzquierdo].minimo, segmentTree[nodoDerecho].minimo);

    }
}

int findDivisors(int n)
{
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) counter++;
    }
    return counter;
}
int main() {
    
    
    int n = 3;
    init(0,n,0);
    cout<<"La suma es: "<<query(0,3,0,2,3).sum<<endl;
    
    cout<<"Segment tree: "<<endl;
    int i = 0;
    while (segmentTree[i].sum != 0){
        cout<<segmentTree[i].sum<<" ";
        i++;
    }
    return 0;
}
 
 