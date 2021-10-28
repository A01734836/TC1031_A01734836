#pragma once
#include <iostream>
#include <algorithm>
#include "Node.hpp"
#include "Entrada.hpp"
using namespace std;

template <class T>
class BST{
    private:
        Node<T>* root;
        int maxAccess;
        
    public:
        BST(){
            maxAccess = 0;
            root = nullptr;
        }

        ~BST(){
            destroy(root);
        }

        void destroy(Node<T>* node){
            if(node != nullptr){
                destroy(node->getLeft());
                destroy(node->getRight());
                delete node;
            }
        }

        int getMaxAccess(){
            return maxAccess;
        }

        Node<T>* getRoot(){
            return this->root;
        }

        bool search(T data){
            Node<T>* current = root;
            while(current != nullptr){
                if(current->getData().decIP == data.decIP){
                    // current->getData().imprimir();
                    return true;
                }
                current = (data.decIP < current->getData().decIP) ? current->getLeft() : current->getRight();
            }
            return false;
        }

        void insert(T data){
            if(root == nullptr){
                root = new Node<T>(data);
                return;
            }
            Node<T>* current = root;
            Node<T>* prev = nullptr;
            while(current != nullptr){
                if(current->getData().decIP == data.decIP){
                    current->incrAccess(); // Incrementar el numero de acceso en caso de repeticion
                    return;
                }
                prev = current;
                current = (data.decIP < current->getData().decIP) ? current->getLeft() : current->getRight();
            }
            (data.decIP < prev->getData().decIP) ? prev->setLeft(new Node<T>(data)) : prev->setRight(new Node<T>(data));
        }

        void inorden(Node<T>* current){
            if(current == nullptr){
                return;
            }
            else{
                inorden(current->getLeft());
                current->getData().imprimir();
                inorden(current->getRight());
            }
        }

        void calcMaxRep(Node<T>* current){ // Recorrido inorden para calcular max rep
            if(current == nullptr){
                return;
            }
            else{
                calcMaxRep(current->getLeft());
                maxAccess = max(maxAccess, current->getAccess());
                calcMaxRep(current->getRight());
            }
        }

        void printMaxAccess(Node<T>* current, int maxAccess){ // Recorrido inorden para desplegar max rep
            if(current == nullptr){
                return;
            }
            else{
                printMaxAccess(current->getLeft(), maxAccess);
                if(current->getAccess() >= maxAccess - 5){
                    current->getData().imprimir(); 
                    cout << "Num accesos: " << current->getAccess() << endl;
                }
                printMaxAccess(current->getRight(), maxAccess);
            }
        }

        void preorden(Node<T>* current){
            if(current == nullptr){
                return;
            }
            else{
                cout << current->getData() << endl;
                preorden(current->getLeft());
                preorden(current->getRight());
            }
        }

        void postorden(Node<T>* current){
            if(current == nullptr){
                return;
            }
            else{
                postorden(current->getLeft());
                postorden(current->getRight());
                cout << current->getData() << endl;
            }
        }

        void visit(int visit){
            switch(visit){
                case 1:
                    preorden(this->root);
                    break;
                case 2:
                    inorden(this->root);
                    break;
                case 3:
                    postorden(this->root);
                    break;
                case 4:
                    levelOrder(this->root);
                    break;
            }
        }

        int height(Node<T>* current){
            if(current == nullptr){
                return 0;
            }
            else{
                int leftH = height(current->getLeft());
                int rightH = height(current->getRight());
                return max(leftH, rightH) + 1;
            }
        }

        void ancestors(T data){
            if(!this->search(data)){
                return;
            }
            Node<T>* current = root;
            while(current != nullptr){
                if(current->getData() == data){
                    break;
                }
                cout << current->getData() << endl;
                current = (data < current->getData()) ? current->getLeft() : current->getRight();
            }
        }

        int whatlevelamI(T data){
            int cont = 1;
            Node<T>* current = root;
            while(current != nullptr){
                if(current->getData() == data){
                    return cont;
                }
                current = (data < current->getData()) ? current->getLeft() : current->getRight();
                cont++;
            }
            return cont;
        }

        bool printLevel(Node<T>* current, int level){
            if(current == nullptr){
                return false;
            }
            if(level == 1){
                cout << current->getData() << " ";
                return true;
            }
            bool left = printLevel(current->getLeft(), level-1);
            bool right = printLevel(current->getRight(), level-1);
            return left || right;
        }

        void levelOrder(Node<T>* current){
            int level = 1;
            while(printLevel(current, level)){
                level++;
                cout << endl;
            }
        }
};