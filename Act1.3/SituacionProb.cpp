#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
#include "Entrada.h"

// Quick Sort(swap, partition, quick)
//Merge Sort (Unir, Merge Sort)
// Merge sort (Unir, Merge)
void unir(vector<Entrada> &arr,int inicio, int mitad, int fin){
    int i,j,k;
    i = inicio;
    j = mitad + 1;
    k = 0;
    vector<Entrada> aux(fin - inicio + 1);

    while(i <= mitad && j <= fin){
        if(arr[i].fecha < arr[j].fecha){
            aux[k] = arr[i];
            i++;
        } else {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mitad){
        aux[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= fin){
        aux[k] = arr[j];
        j++;
        k++;
    }
    
    for(int i = inicio; i <= fin; i++){
        arr[i] = aux[i - inicio];
    }
}
void mergeSort(vector<Entrada> &arr, int inicio, int fin){
    int mitad;
    if(inicio < fin){
        mitad = (inicio + fin) / 2;
        mergeSort(arr,inicio,mitad);
        mergeSort(arr,mitad + 1,fin);
        unir(arr,inicio,mitad,fin);
    }
}

//Busqueda Secuencial
int busqSecuencial(vector<Entrada> &arr, int dato){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].fecha >= dato){
            return i;
        }
    }
    return -1;
}

int main(){
    // SECCION DE ORDENAMIENTO
    // Creacion de variables, vector de entradas, y entrada para almacenar los datos
    ifstream bitacora("bitacora.txt");
    int tDia;
    string tMes, tHora, tIP, tRazon;
    Entrada entrada;
    vector<Entrada> entradas;

    // Ciclo while para leer todos los datos dentro del archivo txt
    while(!bitacora.eof()){
        bitacora >> tMes; // Lectura y asigancion de valores a variables
        bitacora >> tDia;
        bitacora >> tHora;
        bitacora >> tIP;
        getline(bitacora,tRazon); // Lectura de toda la razon

        entrada.hora = tHora; // Asignaciones de valores a la struct
        entrada.setFecha(tMes,tDia);
        entrada.IP = tIP;
        entrada.razon = tRazon;
        entradas.push_back(entrada); // Agregar al final cada instancia nueva
    }

    mergeSort(entradas,0,entradas.size()-1); // Ordenamiento por Merge Sort

    // SECCION DE BUSQUEDA
    int mesInicio, diaInicio, mesFinal, diaFinal;
    int fechaInicial, fechaFinal;
    ofstream bitacoraOrdenada("bitacoraOrdenada.txt", ios::out); // Abrir el archivo en modo escritura

    // Obtencion de informacion del usuario
    cout << endl << "INICIO DE BUSQUEDA" << endl;
    cout << "Mes: ";
    cin >> mesInicio;
    cout << "Dia: ";
    cin >> diaInicio;
    fechaInicial = (mesInicio * 100 + diaInicio) * 1000000;

    cout << endl << "FINAL DE BUSQUEDA" << endl;
    cout << "Mes: ";
    cin >> mesFinal;
    cout << "Dia: ";
    cin >> diaFinal;
    fechaFinal = (mesFinal * 100 + diaFinal) * 1000000 + 240000;

    //Buscamos el primer dato
    int i = busqSecuencial(entradas,fechaInicial);
    // Ciclo de busqueda secuencial para obtener todos los datos con las especificaciones
    for(i; i < entradas.size(); i++){
        if(entradas[i].fecha >= fechaInicial && entradas[i].fecha <= fechaFinal){
            // Almacenar los datos en un archivo
            bitacoraOrdenada << entradas[i].sMes << " ";
            bitacoraOrdenada << entradas[i].sDia << " ";
            bitacoraOrdenada << entradas[i].hora << " ";
            bitacoraOrdenada << entradas[i].IP;
            bitacoraOrdenada << entradas[i].razon << endl;
            //Imprimimos a consola para verificar los resultados
            entradas[i].imprimir();
        } 
    }
    
    // Cerrar los archivos
    bitacora.close();
    bitacoraOrdenada.close();
    
    return 0;
}