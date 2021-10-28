#include <iostream>
#include "BST.hpp"
#include "Entrada.hpp"
#include <fstream>
using namespace std;

int main(){
    fstream bitacora("bitacora2.txt");
    int tDia;
    string tMes, tHora, tIP, tRazon;
    Entrada registro;
    BST<Entrada> arbol; // BST para almacenar los datos

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
        registro.setIPports(); // Generacion de datos a comparar
        registro.razon = tRazon;
        arbol.insert(registro); // Agregar al final cada instancia nueva
    }

    arbol.calcMaxRep(arbol.getRoot()); // Calcular el numero maximo de repeticiones

    cout << "=== IPs con mayor numero de ingresos ===" << endl;

    arbol.printMaxAccess(arbol.getRoot(), arbol.getMaxAccess()); // 5 IPs con mas ingresos

    // Cerrar Archivo
    bitacora.close();
}