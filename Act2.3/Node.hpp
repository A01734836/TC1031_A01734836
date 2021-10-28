// CLASE NODO PARA LISTAS LIGADAS
#pragma once

template <class T>
class Node{
    // ELEMENTOS PUBLICOS
    public:
        Node(T data); // Constructor solo con datos
        Node(T data, Node<T>* next, Node<T>* prev); // Constructor con datos y apuntador al siguiente elemento
        T getData(); // Obtener los datos
        Node<T>* getNext(); // Obtener el nodo siguiente
        Node<T>* getPrev(); // Obtener el nodo anterior
        void setData(T data); // Insertar los datos
        void setNext(Node<T>* next); // Insertar el apuntador al siguiente elemento
        void setPrev(Node<T>* prev); // Insertar apuntador a elemento anterior

    // ELEMENTOS PRIVADOS
    private:
        T data; // Datos
        Node<T> *next; // Apuntador a siguiente elemento
        Node<T> *prev; // Apuntador a elemento anterior
};

// DEFINICION DE METODOS
template <class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr; // Null Pointer
    this->prev = nullptr; // Null Pointer
}

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <class T>
T Node<T>::getData(){
    return this->data;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template <class T>
Node<T>* Node<T>::getPrev(){
    return this->prev;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template <class T>
void Node<T>::setPrev(Node<T>* prev){
    this->prev = prev;
}