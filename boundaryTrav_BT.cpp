#include<iostream>
#include<queue>
using namespace std;

//printing boundary of a node

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this -> data= val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* createTree(){
    int data;
    cout<<"Enter the data: ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<endl;

    root-> left = createTree();
    root-> right = createTree();
}

void levelOrderTraversal(Node* root){
    cout<<endl;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
             cout<<front-> data<<" ";
             if(front-> left != NULL){
                q.push(front-> left);
             }
             if(front-> right != NULL){
                q.push(front-> right);
             }
        }
    }

}

void leftBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root-> left == NULL && root-> right == NULL){
        return;
    }

    cout<<root-> data<<" ";
    if(root -> left != NULL){
        leftBoundary(root-> left);
    }
    else{
        leftBoundary(root-> right);
    }

}

void printLeafNode(Node* root){
    if(root == NULL){
        return;
    }

    if(root-> left == NULL && root-> right == NULL){
        cout<<root-> data<<" ";
    }

    printLeafNode(root-> left);
    printLeafNode(root-> right);
}

void rightBoundary(Node* root){
    if(root == NULL){
        return;
    }

    if(root-> left == NULL && root-> right == NULL){
        return;
    }

    if(root-> right != NULL){
        rightBoundary(root-> right);
    }
    else{
        rightBoundary(root-> left);
    }
    cout<<root-> data<<" ";
}

void boundaryTraversal(Node* root){
    if(root== NULL){
        return;
    }

    cout<<root-> data<<" ";
    leftBoundary(root-> left);
    printLeafNode(root-> left);
    printLeafNode(root-> right);
    rightBoundary(root-> right);
   
}

int main() {

    Node* root = createTree();
    levelOrderTraversal(root);
    boundaryTraversal(root);

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
}