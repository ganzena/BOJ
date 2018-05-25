//
//  main.cpp
//  BinarySearchTree
//
//  Created by YOO TAEWOOK on 2018. 5. 17..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class Tree;

class Node{
    friend class Tree;
public:
    Node(int data):value(data), left(nullptr), right(nullptr){}
private:
    int value;
    Node* left;
    Node* right;
};

class Tree{
public:
    Node* root;
    Tree():root(nullptr){
    }
    
    Node* Insert(Node*, int);
    Node* Search(Node*, int);
    Node* Delete(Node*, int);
    Node* FindMin(Node*);
    Node* FindMax(Node*);
    Node* GetRoot();
    void Print(Node*);
private:
    
};

Node* Tree::Insert(Node* node, int data){
    if(root == nullptr){ //인터넷에 보니깐 이렇게들 함
        root = new Node(data);
        return node;
    }
    if(node == nullptr){ //호출할 때 node에 root를 넣어서 하려고하는데, root에 저장이 안됨
        node = new Node(data);
        return node;
    }else if(node->value < data){
        node->right = Insert(node->right, data);
    }else if(node->value > data){
        node->left = Insert(node->left, data);
    }else{
        cout<<data<<" is already in BST."<<endl;
        return nullptr;
    }
    return node;
}

Node* Tree::Search(Node* node, int data){
    if(node == nullptr){
        cout<<data<<" is not in the BST."<<endl;
        return nullptr;
    }else{
        if(node->value < data){
            return Search(node->right, data);
        }else if(node->value > data){
            return Search(node->left, data);
        }else{
            cout<<data<<"is in the BST."<<endl;
            return node;
        }
    }
}

Node* Tree::Delete(Node* node, int data){
    Node* target;
    if(node == nullptr){
        cout<<data<<"is not in the BST"<<endl;
    }else{
        if(node->value < data){
            Delete(node->right, data);
        }else if(node->value > data){
            Delete(node->left, data);
        }else if(node->left && node->right){ // 지울 값을 찾았고, 자식 노드 2개가 모두 있을 경우
            node->value = FindMin(node->right)->value; //오른쪽에서 가장 작은 값을 찾고, 그 값을 지우려했던 node에 저장한다.
            node->right = Delete(node->right, node->value); //지우려한 값은 없어졌고, 새로 업데이트 된 값을 오른쪽에서 지우면 된다
        }else{// 지울 값을 찾았고, 자식 노드가 1개 있거나 아예 없을 경우
            target = node; // 지울 값을 가진 노드의 주소값을 target이 가리킴
            if(node->right == nullptr) // 지우기 전에 자식노드가 있을 경우, 현재 노드가 자식의 주소를 가리키게함
                node = node->left;
            else if(node->left == nullptr)
                node = node->right;
            delete(target);
        }
    }
    return node;
}

Node* Tree::FindMax(Node* node){
    if(node == nullptr)
        return nullptr;
    else{
        while(node->right)
            node = node->right;
    }
    return node;
}

Node* Tree::FindMin(Node* node){
    if(node == nullptr)
        return nullptr;
    else{
        while(node->left)
            node = node->left;
    }
    return node;
}

Node* Tree::GetRoot(){
    return root;
}

void Tree::Print(Node* T){
    if(T == nullptr)
        return;
    cout<<T->value<<" ";
    Print(T->left);
    Print(T->right);
}

int main(int argc, const char * argv[]) {
    Tree BST;
    BST.Insert(BST.root, 5);
    BST.Insert(BST.root, 2);
    BST.Insert(BST.root, 3);
    BST.Insert(BST.root, 6);
    BST.Insert(BST.root, 7);
    BST.Insert(BST.root, 1);
    BST.Insert(BST.root, 4);
    BST.Insert(BST.root, 9);
    BST.Insert(BST.root, 8);
    BST.Delete(BST.root, 2);
    BST.Delete(BST.root, 5);
    BST.Print(BST.GetRoot());
    cout<<endl;
    
    //5, 2, 3, 6, 7, 1, 4, 9, 8
    
    return 0;
}
