#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Edge;

template <class T>
class Vertex{
    private:
        T idV;
        Vertex<T>* nextVertex;
        Vertex<T>* father;
        Edge<T>* nextEdge;
        bool pass;
        int dist;
        int timeI;
        int timeO;
        int cantEdges;

    public:
        Vertex(Vertex<T>* nextVertex, Edge<T>* nextEdge, T idV){
            this->idV = idV;
            this->nextVertex = nextVertex;
            this->nextEdge = nextEdge;
            this->pass = false;
            this->dist = 0;
            this->father = nullptr;
            this->cantEdges = 0;
        }

        void setTimeI(int timeI){
            this->timeI = timeI;
        }

        int getTimeI(){
            return this->timeI;
        }

        void setTimeO(int timeO){
            this->timeO = timeO;
        }

        int getTimeO(){
            return this->timeO;
        }

        void setFather(Vertex<T>* father){
            this->father = father;
        }

        Vertex<T>* getFather(){
            return this->father;
        }

        void setPass(bool pass){
            this->pass = pass;
        }

        bool getPass(){
            return this->pass;
        }

        void setDist(int dist){
            this->dist = dist;
        }

        int getDist(){
            return this->dist;
        }

        void setId(T idV){
            this->idV = idV;
        }

        T getId(){
            return this-> idV;
        }

        void setNextVertex(Vertex<T>* nextVertex){
            this->nextVertex = nextVertex;
        }

        Vertex<T>* getNextVertex(){
            return this->nextVertex;
        }

        void setNextEdge(Edge<T>* nextEdge){
            this->nextEdge = nextEdge;
        }

        Edge<T>* getNextEdge(){
            return this->nextEdge;
        }

        int getCantEdges(){
            return this->cantEdges;
        }

        void incrCantEdges(){
            cantEdges++;
        }
};

template <class T>
class Edge{
    private:
        T cost;
        string month;
        int day;
        string hour;
        string reason;
        Vertex<T>* destiny;
        Edge<T>* EdgeNext;

    public:
        Edge(Vertex<T>* destiny, Edge<T>* EdgeNext, T cost){
            this->destiny = destiny;
            this->EdgeNext = EdgeNext;
            this->cost = cost;
        }

        Edge(Vertex<T>* destiny, Edge<T>* EdgeNext, string month, int day, string hour, string reason){
            this->destiny = destiny;
            this->EdgeNext = EdgeNext;
            this->month = month;
            this->day = day;
            this->hour = hour;
            this->reason = reason;
        }
        
        string getReason(){
            return this->reason;
        }

        void setCost(T cost){
            this->cost = cost;
        }

        T getCost(){
            return this->cost;
        }

        void setDestinty(Vertex<T>* destiny){
            this->destiny = destiny;
        }

        Vertex<T>* getDestiny(){
            return this->destiny;
        }

        void setEdgeNext(Edge<T>* EdgeNext){
            this->EdgeNext = EdgeNext;
        }

        Edge<T>* getEdgeNext(){
            return this->EdgeNext;
        }
};