#pragma once
using namespace std;

template <class T>
class Node{
    private:
        T data;
        int access;
        Node<T>* left;
        Node<T>* right;

    public:
        Node(T data){
            this->access = 0;
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(T data, Node<T>* left, Node<T>* rigth){
            this->access = 0;
            this->data = data;
            this->left = left;
            this->right = right;
        }

        T getData(){
            return data;
        }

        Node<T>* getLeft(){
            return this->left;
        }

        Node<T>* getRight(){
            return this->right;
        }

        void setData(T data){
            this->data = data;
        }

        void setLeft(Node<T>* left){
            this->left = left;
        }

        void setRight(Node<T>* right){
            this->right = right;
        }

        int numChildren(){
            int children = 0;
            if(this->getLeft() != nullptr){
                children++;
            }
            if(this->getRight() != nullptr){
                children++;
            }
            return children;
        }

        void incrAccess(){
            access++;
        }

        int getAccess(){
            return access;
        }
};