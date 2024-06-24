#include<iostream>
#include<queue>
using namespace std;

// construction of a binary tree using preorder and inorder Traversal
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
    for(int i = 0; i < size; i++){
        int element = inorder[i];
        int index = i;
        valuetoMapindex[element]= index;
    }
}

Node* constructTreeFromPreAndIn(map<int,int> valuetoMapindex,int inorder[],int preorder[],int size,int &preIndex, int inorderStart,int inorderEnd ){

    // base case
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    // solve 1 case
    int element = preorder[preIndex];
    preIndex++;
    Node* root = new Node(element);

    // searching element for root -> left from inorder
    // int position = searchInorder(inorder, size, element);
    int position = valuetoMapindex[element];

    //recursion
    root -> left = constructTreeFromPreAndIn(valuetoMapindex,inorder, preorder, size, preIndex, inorderStart, position-1);
    root -> right = constructTreeFromPreAndIn(valuetoMapindex,inorder, preorder, size, preIndex, position+1, inorderEnd);

    return root;


}

int main() {

    int inorder[] = {10, 8, 6, 2, 4, 12};
    int preorder[] = {2,8,10, 6,4 ,12};
    int size = 6;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = 5;
    map<int,int> valuetoMapindex;

    createMapping(inorder,size, valuetoMapindex);

    Node* root =  constructTreeFromPreAndIn(valuetoMapindex,inorder, preorder, size, preIndex, inorderStart, inorderEnd);
    cout<< "Required Tree"<<endl;
    levelOrderTraversal(root);
    return 0;

}
