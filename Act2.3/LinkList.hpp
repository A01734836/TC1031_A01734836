// CLASE DE LISTAS LIGADAS
#include "Node.hpp"
#include <iostream>
#pragma once

using namespace std;

template <class T>
class LinkList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        // METODOS IMPLEMENTADOS EN CLASE
        LinkList();
        ~LinkList();
        int getSize(){return size;};
        void deleteAll();
        Node<T>* getHead(){
            return head;
        }

        // METODOS IMPLEMENTADOS PARA LA ACTIVIDAD
        void push(T data);
        T read(int index);
        void update(int index, T data);
        void del(int value);
        void printList();
        void printList(int index);
        void rPrintList();
};

template <class T>
LinkList<T>::LinkList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
LinkList<T>::~LinkList(){
    deleteAll();
}

template <class T>
void LinkList<T>::deleteAll(){
    Node<T>* current = head;
    while(head != nullptr){
        head = head->getNext();
        delete current;
        current = head;
    }
    size = 0;
}

template <class T>
void LinkList<T>::printList(){
    Node<T>* current = head;
    while(current != nullptr){
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <class T>
void LinkList<T>::printList(int index){
    int i = 0;
    Node<T>* current = head;
    while(current != nullptr && i < index){
        cout << current->getData() << endl;
        current = current->getNext();
        i++;
    }
}

template <class T>
void LinkList<T>::rPrintList(){
    Node<T>* current = tail;
    while(current != nullptr){
        cout << current->getData() << endl;
        current = current->getPrev();
    }
}

// CODIFICACION DE METODOS ESPECIFICOS DE LA ACTIVIDAD

// Metodo de insertar un elemento en la ADT.
template <class T>
void LinkList<T>::push(T data){
    if(size == 0){
        head = new Node<T>(data, nullptr, head);
        tail = head;
    }
    else{
        tail->setNext(new Node<T>(data, nullptr, tail));
        tail = tail->getNext();
    }
    size++;
}

// Metodo que busca un elemento dentro de la ADT. 
template <class T>
T LinkList<T>::read(int index){
    int half = (size-1)/2;
    int i; // Declaracion de contador
    Node<T>* current;
    if(index == 0){
        return head->getData();
    }
    else if(index == this->size-1){
        return tail->getData();
    }
    else if(index<=half){
        i=0;
        current = head;
        while(current != nullptr){ // Busqueda Secuencial
            if(i == index){
                // cout << "Dato encontrado en posicion: " << i << "   Dato: " << current->getData() << endl;
                return current->getData(); // Se regresa la informacion de la posicion requerida
            }
            current = current->getNext(); // Se avanzan los apuntadores
            i++;
        }
    }
    else{
        i=size-1;
        current = tail;
        while(current != nullptr){ // Busqueda Secuencial
            if(i == index){
                // cout << "Dato encontrado en posicion: " << i << "   Dato: " << current->getData() << endl;
                return current->getData(); // Se regresa la informacion de la posicion requerida
            }
            current = current->getPrev(); // Se avanzan los apuntadores
            i--;
        }
    }
}

// Metodo que busca un elemento dentro del ADT y lo actualiza por otro
template <class T>
void LinkList<T>::update(int index, T data){
    int i, half=(size-1)/2;
    Node<T>* current;
    if(index == 0){
        return head->setData(data);
    }
    else if(index == this->size-1){
        return tail->setData(data);
    }
    else if (index<=half){
        i=0;
        current = head;
        while(current != nullptr){ // Busqueda Secuencial
            if(i == index){
                // cout << "Dato encontrado en posicion: " << i << "   Dato: " << current->getData() << endl;
                current->setData(data); // Se regresa la informacion de la posicion requerida
                return;
            }
            current = current->getNext(); // Se avanzan los apuntadores
            i++;
        }
    }
    else{
        i=size-1;
        current = tail;
        while(current != nullptr){ // Busqueda Secuencial
            if(i == index){
                // cout << "Dato encontrado en posicion: " << i << "   Dato: " << current->getData() << endl;
                current->setData(data); // Se regresa la informacion de la posicion requerida
                return;
            }
            current = current->getPrev(); // Se avanzan los apuntadores
            i--;
        }
    }
    /*while(current != nullptr){ // Busqueda secuencial;
        if(i == index){
            current->setData(data); // Se asigna nueva informacion al indice deseado
            return;
        }
        current = current->getNext();
        i++;
    }*/
}

// Metodo que busca un elemento dentro del ADT y lo elimina
template <class T>
void LinkList<T>::del(int index){
    int i = 0; // Variable que lleva la cuenta del indice
    // Crecion de dos apuntadores, uno que empieza en la cabeza, otro que se dirigira al elemento previo
    Node<T>* temp = head;
    Node<T>* prev;
    // Caso en el que el indice sea 0, osea la cabeza
    if(temp != nullptr && index == i){ // No debe se apuntar a nulo y debe ser igual a 0
        head = temp->getNext(); // Se asigna el nuevo head, al siguiente elemento
        head->setPrev(nullptr);
        delete temp; // Se libera memoria
        size--;
        return; // Se sale del metodo
    }
    if(index == size-1){
        temp = tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
        delete temp; // Se libera memoria
        size--;
        return; // Se sale del metodo
    }
    // Caso en el que el indice no es la cabeza
    while(temp != tail && index != i){ // Se cicla hasta que se encuentre el indice buscado
        prev = temp; // Se va almacenando el apuntador
        temp = temp->getNext(); // Se obtiene el siguiente apuntador
        i++; // Se incrementa el contador de indice
    }
    // Caso en el que se teclee un indice mayor a size
    if(temp == nullptr){
        return; // Sale del programa
    }
    // Se cambia el apuntador del elemento previo al siguiente correspondiente
    prev->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());
    delete temp; // Se limpia memoria
    size--; // Se decrementa la variable size en 1
}