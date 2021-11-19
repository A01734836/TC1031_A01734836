#pragma once
#include <iostream>
#include <queue>
#include "VertexEdge.hpp"
int time = 0;
int numVert = 0;
using namespace std;

template <class T>
class Graph{
    private:
        int cantVertex;
        int cantEdges;
        int maxAdj;
        Vertex<T>* headVertex;
    
    public:

        // CONSTRUCTOR ===================================================================================

        Graph(int n, int m){
            this->cantVertex = n;
            this->cantEdges = m;
            this->headVertex = nullptr;
        }

        // VACIO =========================================================================================

        bool isEmpty(){
            if(headVertex == nullptr){
                return true;
            }
            else{
                return false;
            }
        }

        // SETTERS Y GETTERS ===============================================================================

        Vertex<T>* getHeadVertex(){
            return this->headVertex;
        }

        Vertex<T>* setHeadVertex(T data){
            this->headVertex = this->getDirVertex(data);
        }

        Vertex<T>* getDirVertex(T id){
            Vertex<T>* curr = headVertex;
            while(curr != nullptr){
                if(curr->getId() == id){
                    return curr;
                }
                curr = curr->getNextVertex();
            }
            cout << "No existe un vertice con ese identificador" << endl;
            return nullptr;
        }

        // LISTAS DE ADYACENCIA ==========================================================================

        void printAdjList(){
            if(this->isEmpty()){
                return;
            }
            Vertex<T>* currVertex = headVertex;
            while(currVertex != nullptr){
                Edge<T>* currEdge = currVertex->getNextEdge();
                cout << currVertex->getId() << " |";
                while(currEdge != nullptr){
                    cout << " -" << currEdge->getCost() << "-> ";
                    cout << currEdge->getDestiny()->getId() << " |";
                    currEdge = currEdge->getEdgeNext();
                }
                cout << endl;
                currVertex = currVertex->getNextVertex();
            }
        }

        void getAdjListVertex(T data){
            Vertex<T>* aux = this->getDirVertex(data);
            Edge<T>* v = aux->getNextEdge();
            cout << aux->getId() << " |";
            while(v != nullptr){
                cout << " -> ";//<< " -" << v->getCost() << "-> ";
                cout << v->getDestiny()->getId() << " |";
                v = v->getEdgeNext();
            }
            cout << endl;
            v = v->getEdgeNext();
        }

        // METODOS DE INSERCION ===========================================================================

        void insertVertex(T iD){
            Vertex<T>* v = new Vertex<T>(nullptr, nullptr, iD);
            if(this->isEmpty()){
                headVertex = v;
                return;
            }
            Vertex<T>* currVertex = headVertex;
            while(currVertex->getNextVertex() != nullptr){
                if(currVertex->getId() == v->getId()){
                    cout << "ID vertex previamente insertado" << endl;
                    return;
                }
                currVertex = currVertex->getNextVertex();
            }
            currVertex->setNextVertex(v);
        }

        void insertEdge(T Origin, T Destiny, string month, int day, string hour, string reason){
            if(this->isEmpty()){
                cout << "Grafo vacio" << endl;
                return;
            }
            Vertex<T>* vOrigin = this->getDirVertex(Origin);
            Vertex<T>* vDestiny = this->getDirVertex(Destiny);
            Edge<T>* currEdge = vOrigin->getNextEdge();
            if(currEdge == nullptr){
                vOrigin->setNextEdge(new Edge<T>(vDestiny, nullptr, month, day, hour, reason));
            }
            if(currEdge != nullptr){
                while(currEdge->getEdgeNext() != nullptr){
                    currEdge = currEdge->getEdgeNext();
                }
                currEdge->setEdgeNext(new Edge<T>(vDestiny, nullptr, month, day, hour, reason));
            }
            vOrigin->incrCantEdges();
        }

        // RECORRIDOS ===================================================================================

        void BFS(T id){
            cout << "RECORRIDO BFS" << endl;
            Vertex<T>* aux = headVertex;
            while(aux != nullptr){
                aux->setPass(false);
                aux->setDist(-1);
                aux->setFather(nullptr);
                aux = aux->getNextVertex();
            }
            aux = this->getDirVertex(id);
            aux->setPass(true);
            aux->setDist(0);
            aux->setFather(nullptr);
            queue<Vertex<T>*> cola;
            cola.push(aux);
            while(!cola.empty()){
                Vertex<T>* u = cola.front();
                cout << u->getId() << " - Nivel: " << u->getDist() << endl;
                numVert++;
                cola.pop();
                Edge<T>* v = u->getNextEdge();
                while(v != nullptr){
                    if(v->getDestiny()->getPass() == false){
                        v->getDestiny()->setPass(true);
                        v->getDestiny()->setDist(u->getDist() + 1);
                        v->getDestiny()->setFather(u);
                        cola.push(v->getDestiny());
                    }
                    v = v->getEdgeNext();
                }
                u->setPass(true);
            }
            cout << numVert << endl;
        }

        void DFS(){
            cout << "RECORRIDO DFS" << endl;
            Vertex<T>* aux = headVertex;
            while(aux != nullptr){
                aux->setPass(false);
                aux->setFather(nullptr);
                aux = aux->getNextVertex();
            }
            time = 0;
            aux = headVertex;
            while(aux != nullptr){
                if(aux->getPass() == false){
                    cout << "SIGUEINTE RECORRIDO" << endl;
                    DFS_Visit(aux);
                }
                aux = aux->getNextVertex();
            }
        }

        void DFS_Visit(Vertex<T>* u){
            time++;
            u->setTimeI(time);
            u->setPass(true);
            Edge<T>* v = u->getNextEdge();
            while(v != nullptr){
                if(v->getDestiny()->getPass() == false){
                    v->getDestiny()->setFather(u);
                    DFS_Visit(v->getDestiny());
                }
                v = v->getEdgeNext();
            }
            u->setPass(true);
            time++;
            u->setTimeO(time);
            cout << u->getId() << " TimeI: " << u->getTimeI() << " TimeO: " << u->getTimeO() << endl;
        }

        // CALCULO DE ADYACENCIAS ======================================================================

        void calcMaxAdj(){
            Vertex<T>* aux = headVertex;
            int maxAdj = 0;
            while(aux != nullptr){
                maxAdj = max(aux->getCantEdges(), maxAdj);
                aux = aux->getNextVertex();
            }
            this->maxAdj = maxAdj;
        }

        void printVertexMaxEdges(){
            Vertex<T>* aux = headVertex;
            while(aux != nullptr){
                if(aux->getCantEdges() == this->maxAdj){
                    cout << aux->getId() << " | Num Edges: " << aux->getCantEdges() << endl;
                }
                aux = aux->getNextVertex();
            }
        }
};