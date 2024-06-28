#include<iostream>
#include<queue>
#include<map>
using namespace std;

// createion of a tree
// level order traversal
// views
        // printing left view 
        // printing right view
        // printing top view
        //printing bottom view
// boundary traversal

class Node {
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


void levelOrderTrav(Node* root){
    cout<<endl;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<< front-> data<<" ";
            if(front -> left != NULL) {
                q.push(front -> left);
             }
            if(front -> right != NULL) {
                q.push(front-> right);
             }
        }
    }
}

void printLeftView(Node* root, int level, vector<int> &leftView){
    if(root == NULL){
        return;
    }

    if(level == leftView.size()){
        leftView.push_back(root-> data);
    }

    printLeftView(root-> left, level+1, leftView);
    printLeftView(root-> right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int> &rightView){
    if(root == NULL){
        return;
    }

    if(level == rightView.size()){
        rightView.push_back(root-> data);
    }

    printRightView(root-> right, level+1, rightView);
    printRightView(root-> left, level+1, rightView);
}

void printTopView(Node* root){

    map<int, int> hdToNodeMap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //if there is no entry of hd, then create new entry
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode -> data;
        }

        //childs
        if(frontNode-> left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode-> right != NULL){
            q.push(make_pair(frontNode-> right, hd+1));
        }

    }

    cout<<"printing top view: "<<endl;
    for(auto i: hdToNodeMap){
        cout<< i.second << " ";
    }
    cout<<endl;
}

void printBottomView(Node* root){

    map<int, int> hdToNodeMap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        hdToNodeMap[hd] = frontNode -> data;

        //childs
        if(frontNode-> left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode-> right != NULL){
            q.push(make_pair(frontNode-> right, hd+1));
        }

    }

    cout<<"printing top view: "<<endl;
    for(auto i: hdToNodeMap){
        cout<< i.second << " ";
    }
    cout<<endl;
}




int main(){

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    Node* root = createTree();
    levelOrderTrav(root);

    vector<int> leftView;
    printLeftView(root, 0 , leftView);
    cout<<"Printing left view: "<<endl;
    for(int i=0; i< leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;


    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout<<"Printing right view: "<<endl;
    for(int i=0; i< rightView.size(); i++){
        cout<<rightView[i]<<" ";
    }
    cout<<endl;

    printTopView(root);
    printBottomView(root);

}