#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.hpp"
using namespace std;

int main(){
    // INICIOALIZACION DE OBJETO FSTREAM Y VARIABLES RECOLECTORAS
    fstream archivo("bitacoraACT4_3.txt", ios::in);
    
    // DECLARACION DE VARIABLES RECOLECTORAS
    string month, hour, originIP, destinIP, reason;
    int day, n, m;

    // OBTENCION DE NUM DE VERTEX Y EDGES
    archivo >> n >> m;
    cout << "Cant. Vertex: " << n << "  Cant. Edges: " << m << endl;

    // INTANCIA DE GRAFO
    Graph<string> red(n, m);

    // LECTURA DE ARCHIVO
    int i = 0;
    while(i < n){ // Lectura de los vertices existentes (IP)
        archivo >> originIP;
        red.insertVertex(originIP);
        i++;
    }

    i = 0;
    while(i < m){ // Lectura de las aristas existentes (IP -> IP)
        archivo >> month >> day >> hour >> originIP >> destinIP;
        getline(archivo, reason);
        stringstream sOrigin(originIP), sDestin(destinIP);
        getline(sOrigin, originIP, ':');
        getline(sDestin, destinIP, ':');
        red.insertEdge(originIP, destinIP, month, day, hour, reason);
        i++;
    }

    // CALCULO DE FANOUT MAXIMO
    red.calcMaxAdj();

    // IMPRESION DE VERTICES CON MAYOR FANOUT
    cout << "IP WITH HIGHEST FANOUT RATE" << endl;
    red.printVertexMaxEdges(); cout << endl;
}