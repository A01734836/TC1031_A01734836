#include "LinkList.hpp"
#include "Entrada.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits.h>
using namespace std;

void merge(LinkList<Entrada> &list, int start, int half, int end){
    int i = start, j = half+1, k = 0;
    LinkList<Entrada> aux;
    while(i <= half && j <= end){
        if(list.read(i).decIP < list.read(j).decIP){
            aux.push(list.read(i));
            i++;
        }
        else{
            aux.push(list.read(j));
            j++;
        }
        k++;
    }
    while(i <= half){
        aux.push(list.read(i));
        i++;
        k++;
    }
    while(j <= end){
        aux.push(list.read(j));
        j++;
        k++;
    }
    for(int i=start; i<=end; i++){
        list.update(i, aux.read(i-start));
    }
}

void mergeSort(LinkList<Entrada> &list, int start, int end){
    int half;
    if(start<end){
        half = (start+end)/2;
        mergeSort(list,start,half);
        mergeSort(list,half+1,end);
        merge(list,start,half,end);
    }
}

int main(){
    fstream bitacora("bitacora.txt");
    int tDia;
    string tMes, tHora, tIP, tRazon;
    Entrada registro;
    LinkList<Entrada> lista;

    // Ciclo while para leer todos los datos dentro del archivo txt
    while(!bitacora.eof()){
        bitacora >> tMes; // Lectura y asigancion de valores a variables
        bitacora >> tDia;
        bitacora >> tHora;
        bitacora >> tIP;
        getline(bitacora,tRazon); // Lectura de toda la razon

        registro.hora = tHora; // Asignaciones de valores a la struct
        registro.setFecha(tMes,tDia);
        registro.IP = tIP;
        registro.setIPports();
        registro.razon = tRazon;
        lista.push(registro); // Agregar al final cada instancia nueva
    }

    Node<Entrada>* current = lista.getHead();

    /*cout << lista.getSize() << endl;

    cout << lista.read(lista.getSize()-1).decIP << endl;
    lista.read(lista.getSize()-1).imprimir();*/

    mergeSort(lista, 0, lista.getSize()-1);

    for(int i = 0; i < lista.getSize(); i++){
        current->getData().imprimir();
        current = current->getNext();
    }
}