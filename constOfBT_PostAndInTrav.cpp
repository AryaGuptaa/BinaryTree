#include<iostream>
#include<queue>
#include<map>
using namespace std;

// construction of a binary tree using postorder and inorder Traversal
//with and without the help of map

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root -> data<< " ";
    preOrderTraversal(root-> left);
    preOrderTraversal(root-> right);

}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root-> left);
    cout<<root -> data<< " ";
    inOrderTraversal(root-> right);

}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root-> left);
    postOrderTraversal(root-> right);
    cout<<root -> data<< " ";

}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else {
            cout<< front-> data <<" ";

            if(front -> left !=NULL){
                q.push(front -> left);
            }
            if(front -> right != NULL){
                q.push(front-> right);
            }
        }
    }
}

int searchInorder(int inorder[], int size, int target){
    for(int i = 0; i < size; i++) {
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}

void createMapping(int inorder[], int size, map<int, int> & valuetoMapindex){
    for(int i = size; i > 0; i--){
        int element = inorder[i];
        int index = i;
        valuetoMapindex[element]= index;
    }
}

Node* constructTreeFromPostAndIn(map<int,int> valuetoMapindex,int inorder[],int postorder[],int size,int &postIndex, int inorderStart,int inorderEnd ){

    // base case
    if(postIndex < 0|| inorderStart > inorderEnd){
        return NULL;
    }

    // solve 1 case
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    // searching element for root -> left from inorder
    // int position = searchInorder(inorder, size, element);
    int position = valuetoMapindex[element];

    //recursion
    root -> right = constructTreeFromPostAndIn(valuetoMapindex,inorder, postorder, size, postIndex, position+1, inorderEnd);
    root -> left = constructTreeFromPostAndIn(valuetoMapindex,inorder, postorder, size, postIndex, inorderStart, position-1);
    

    return root;


}

int main() {

    int inorder[] = {8,14,6,2,10,4};
    int postorder[] = {8,6,14,4,10,2};
    int size = 6;
    int postIndex = 5;
    int inorderStart = 0;
    int inorderEnd = 5;
    map<int,int> valuetoMapindex;

    createMapping(inorder,size, valuetoMapindex);

    

    Node* root =  constructTreeFromPostAndIn(valuetoMapindex, inorder, postorder, size, postIndex, inorderStart, inorderEnd);
    cout<< "Required Tree"<<endl;
    levelOrderTraversal(root);
    return 0;

}