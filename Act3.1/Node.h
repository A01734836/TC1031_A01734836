class Node{
    private:
        int data;
        Node *left;
        Node *right;
    public:
        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(int data, Node *left, Node *right){
            this->data = data;
            this->left = left;
            this->right = right;
        }
        int getData(){
            return this->data;
        }
        Node* getLeft(){
            return this->left;
        }
        Node* getRight(){
            return this->right;
        }
        void setData(int data){
            this->data = data;
        }
        void setLeft(Node *left){
            this->left = left;
        }
        void setRight(Node *right){
            this->right = right;
        }
};