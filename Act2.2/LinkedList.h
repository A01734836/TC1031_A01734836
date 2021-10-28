#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"

template <class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        int getSize();
        void deleteAll();
        void addFirst(T data);
        void addLast(T data);
        void create(T data,int pos);
        T read(int pos);
        void update(T data,int pos);
        void del(int pos);
};

template <class T>
LinkedList<T>::LinkedList(){
    head=nullptr;
    size=0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *current=head;
    while(head!=nullptr){
        head=head->getNext();
        delete current;
        current=head;
    }
    size=0;
}

template <class T>
void LinkedList<T>::addFirst(T data){
    head=new Node<T>(data,head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    Node<T> *current=head;
    if(size==0){
        addFirst(data);
        return;
    }

    while(current->getNext()!=nullptr){
        current=current->getNext();
    }
    current->setNext(new Node<T>(data));
    size++;
}

template <class T>
void LinkedList<T>::create(T data,int pos){
    if(pos>size){
        cout<<"La lista es muy pequena para anadir el valor"<<endl;
        return;
    }
    if(pos==0){
        addFirst(data);
        return;
    }
    if(pos==size){
        addLast(data);
        return;
    }
    Node<T> *current=head;
    Node<T> *next;
    for(int i=0;i<pos-1;i++){
        current=current->getNext();
    }
    next=current->getNext();
    current->setNext(new Node<T>(data,next));
    size++;
}

template <class T>
T LinkedList<T>::read(int pos){
    if(pos>=size){
        cout<<"Ese valor no existe"<<endl;
        return -1;
    }
    Node<T> *current=head;
    for(int i=0;i<pos;i++){
        current=current->getNext();
    }
    return current->getData();
}

template <class T>
void LinkedList<T>::update(T data,int pos){
    if(pos>=size){
        cout<<"Este valor no existe"<<endl;
        return;
    }
    Node<T> *current=head;
    for(int i=0;i<pos;i++){
        current=current->getNext();
    }
    current->setData(data);
}

template <class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
void LinkedList<T>::del(int pos){
    if(pos>=size){
        cout<<"Este valor no existe"<<endl;
        return;
    }
    Node<T> *current=head;
    if(pos==0){
        head=head->getNext();
        delete current;
        size--;
        return;
    }
    Node<T> *last, *next;
    for(int i=0;i<pos;i++){
        last=current;
        current=current->getNext();
    }
    next=current->getNext();
    delete current;
    size--;
    last->setNext(next);
}

#endif