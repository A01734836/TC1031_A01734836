#include "Node.h"
#include <iostream>
using namespace std;

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        destroy(root);
    }

    void destroy(Node *node)
    {
        if (node != nullptr)
        {
            destroy(node->getLeft());
            destroy(node->getRight());
            delete node;
        }
    }
    bool search(int data)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                return true;
            }
            current = (data < current->getData()) ? current->getLeft() : current->getRight();
            // valor = (condicion)? valor_si_se_cumple : valor_si_no_se_cumple;
            //if(data < current->getData()){
            //    current = current->getLeft();
            //}else{
            //    current = current->getRight();
            //}
        }
        return false;
    }
    void insert(int data)
    {
        Node *current = root;
        Node *father = nullptr;

        while (current != nullptr)
        {
            if (current->getData() == data)
            {
                return;
            }
            father = current;
            current = (current->getData() > data) ? current->getLeft() : current->getRight();
        }

        if (father == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            (father->getData() > data) ? father->setLeft(new Node(data)) : father->setRight(new Node(data));
        }
    }

    int howManyChildren(Node *node)
    {
        int number = 0;
        if (node->getLeft() != nullptr)
            number++;
        if (node->getRight() != nullptr)
            number++;
        return number;
    }

    void remove(int data)
    {
        Node *current = root;
        Node *father = nullptr;
        while (current != nullptr && current->getData() != data)
        {
            father = current;
            current = (current->getData() > data) ? current->getLeft() : current->getRight();
        }

        if (current == nullptr)
        {
            return;
        }

        int numeroHijos = howManyChildren(current);
        switch (numeroHijos)
        {
        case 0:
            if (father == nullptr)
            {
                root = nullptr;
            }
            else
            {
                if (father->getData() > data)
                {
                    father->setLeft(nullptr);
                }
                else
                {
                    father->setRight(nullptr);
                }
            }
            delete current;
            break;
        case 1:
            if(father == nullptr){
                if(current->getLeft() != nullptr){
                    root = current->getLeft();
                }else{
                    root = current->getRight();
                }
            }else{
                if(father->getData() > data){
                    if(current->getLeft() != nullptr){
                        father->setLeft(current->getLeft());
                    }else{
                        father->setLeft(current->getRight());
                    }
                }else{
                    if(current->getLeft() != nullptr){
                        father->setRight(current->getLeft());
                    }else{
                        father->setRight(current->getRight());
                    }
                }
            }
            delete current;
            break;

        case 2:
            break;
        }
        
    }

    void preorder(Node *r){
        
        if(r!=nullptr){
            cout<<r->getData()<<" ";
            preorder(r->getLeft());
            preorder(r->getRight());
        }
    }

    void inorder(Node *r){
        
        if(r!=nullptr){
            inorder(r->getLeft());
            cout<<r->getData()<<" ";
            inorder(r->getRight());
        }
    }

    void postorder(Node *r){
        
        if(r!=nullptr){
            postorder(r->getLeft());
            postorder(r->getRight());
            cout<<r->getData()<<" ";
        }
    }

    void printLevelOrder(Node *r){
        int h=getHeight(r);
        int i;
        for (i=1; i<=h; i++){
            printGivenLevel(r, i);
        }
    }   

    void printGivenLevel(Node *r, int level){
        if(r==nullptr){
            return;
        }
        if(level==1){
            cout<<r->getData()<<" ";
        }else if(level>1){
            printGivenLevel(r->getLeft(), level-1);
            printGivenLevel(r->getRight(), level-1);
        }
    } 

    void visit(int order){
        if(order==1){
            cout<<"PreOrder:"<<endl;
            preorder(root);
            cout<<endl;
        } else if(order==2){
            cout<<"InOrder:"<<endl;
            inorder(root);
            cout<<endl;
        } else if(order==3){
            cout<<"PostOrder:"<<endl;
            postorder(root);
            cout<<endl;
        } else if(order==4){
            cout<<"Level by Level"<<endl;
            printLevelOrder(root);
            cout<<endl;
        }

    }

    int getHeight(Node* r){
        if(r==nullptr){
            return 0;
        } else{
            int left=getHeight(r->getLeft());
            int right=getHeight(r->getRight());
            if(left>=right){
                return left+1;
            } else{
                return right+1;
            }
        }
    }
    
    int height(){
        return getHeight(root);
    }

    void ancestors(int data){
        Node *current=root;
        while(current!=nullptr){
            if(current->getData()==data){
                cout<<endl;
                return;
            }else{
                cout<<current->getData()<<" ";
                if(data<current->getData()){
                    current=current->getLeft();
                } else{
                    current=current->getRight();
                }
            }
        }
        cout<<"Este numero no esta en el arbol"<<endl;
    }

    int whatLevelAmI(int data){
        Node *current=root;
        int level=1;
        while(current!=nullptr){
            if(current->getData()==data){
                return level;
            }else if(data<current->getData()){
                current=current->getLeft();
            }else{
                current=current->getRight();
            }
            level++;
        }
        return -1;
    }
};