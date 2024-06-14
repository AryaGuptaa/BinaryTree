#include<iostream>
#include<queue>
using namespace std;

// creation
// preorder traversal
// inorder traversal
// postorder traversal
// levelorder traversal
// left view print

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* createTree(){
    cout<<"Enter the value for node: ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }  

    //step 1 - create node
    Node* root = new Node(data);
    //step 2 - create left subtree
    cout<<endl;
    cout<<" For left of node "<<root->data<<endl;
    root -> left = createTree();
    //step 3 - create right subtree
    cout<<endl;
    cout<<" For right of node "<<root->data<<endl;
    root -> right = createTree();

    return root;
}

void preOrderTraversal(Node* root) {
    //base case
    if(root == NULL){
        return;
    }
    //N L R
    //N
    cout<<root->data<<" ";
    //L
    preOrderTraversal(root -> left);
    //R
    preOrderTraversal(root -> right);
    
}

void inOrderTraversal(Node* root) {
    //base case
    if(root == NULL){
        return;
    }
    //L N R
    //L
    inOrderTraversal(root -> left);
    //N
    cout<<root->data<<" ";
    //R
    inOrderTraversal(root -> right);
    
}

void postOrderTraversal(Node* root) {
    //base case
    if(root == NULL){
        return;
    }
    //L R N
    //L
    postOrderTraversal(root -> left);
    //R
    postOrderTraversal(root -> right);
    //N
    cout<<root->data<<" ";
    
}

void levelorderTraversal(Node* root) {

    cout<<endl;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
        while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }

        else {
            cout<<front -> data<<" ";

            if(front -> left != NULL) {
                q.push(front -> left);
             }
            if(front -> right != NULL) {
                q.push(front-> right);
             }
        }
    }    
}

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if(root == NULL) return;
    if(level == leftView.size()){
        leftView.push_back(root-> data);
    }
    printLeftView(root->left, level +1, leftView);
    printLeftView(root-> right, level+1, leftView);
}

int main() {

    Node* root = createTree();
    // cout<<"Root node: "<<root ->data<<endl;
    // cout<<"Printing Pre order: "<<endl;
    // preOrderTraversal(root);
    // cout<<endl;
    // cout<<"Printing in order: "<<endl;
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<"Printing Post order: "<<endl;
    // postOrderTraversal(root);
    // cout<<endl;

    // cout<<"Level order: "<<endl;
    levelorderTraversal(root);
    vector<int> leftView;
    printLeftView(root, 0, leftView);

    cout<<"printing left view: "<<endl;
    for(int i = 0; i< leftView.size(); i++) {
        cout<<leftView[i]<<" ";
    }
    cout<<endl;

    return 0;
    //  10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
}