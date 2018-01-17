//
//  main.cpp
//  [1991] 트리 순회
//
//  Created by YOO TAEWOOK on 2018. 1. 17..
//  Copyright © 2018년 YooTae-Ook. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Tree* SearchTree;
typedef struct Tree* Node;
typedef char ElementType;
struct Tree{
    ElementType value;
    SearchTree left;
    SearchTree right;
    
};
enum Direction {LEFT, RIGHT};

SearchTree InsertNode(SearchTree, ElementType, ElementType, Direction);
void PrintInorder(SearchTree);
void PrintPreorder(SearchTree);
void PrintPostorder(SearchTree);

int main()
{
    int number;
    Direction direction;
    SearchTree T = (Tree*)malloc(sizeof(Tree));
    T->value = 'A';
    T->left = T->right = NULL;
    cin>>number;
    
    for(int i = 0 ; i < number ; i++){
        char p, l, r;
        cin>>p>>l>>r;;
        if(l != '.'){
            direction = LEFT;
            InsertNode(T, p, l, direction);
        }
        if(r != '.'){
            direction = RIGHT;
            InsertNode(T, p, r, direction);
        }
    }
    
    PrintPreorder(T);
    cout<<endl;
    PrintInorder(T);
    cout<<endl;
    PrintPostorder(T);
    cout<<endl;
}

SearchTree InsertNode(SearchTree T, ElementType parent, ElementType input, Direction direction){
    
    if(T == NULL){
        T = (Tree*)malloc(sizeof(Tree));
        T->value = input;
        T->left = T->right = NULL;
        return T;
    }else{
        if(T->value != parent){
            if(direction == LEFT){
                if(T->left != NULL)
                    T->left = InsertNode(T->left, parent, input, direction);
                if(T->right != NULL)
                    T->right = InsertNode(T->right, parent, input, direction);
            }else{
                if(T->right != NULL)
                    T->right = InsertNode(T->right, parent, input, direction);
                if(T->left != NULL)
                    T->left = InsertNode(T->left, parent, input, direction);
            }
        }else{
            if(direction == LEFT){
                if(T->left == NULL)
                    T->left = InsertNode(T->left, parent, input, direction);
                else
                    T->right = InsertNode(T->right, parent, input, direction);
            } else{
                if(T->right == NULL)
                    T->right = InsertNode(T->right, parent, input, direction);
                else
                    T->left = InsertNode(T->left, parent, input, direction);
            }
        }
        return T;
    }
}
void PrintInorder(SearchTree T){
    if(T == NULL)
        return;
    
    PrintInorder(T->left);
    cout<<T->value;
    PrintInorder(T->right);
    
}

void PrintPreorder(SearchTree T){
    if(T == NULL)
        return;
    
    cout<<T->value;
    PrintPreorder(T->left);
    PrintPreorder(T->right);
}

void PrintPostorder(SearchTree T){
    if(T == NULL)
        return;
    
    PrintPostorder(T->left);
    PrintPostorder(T->right);
    cout<<T->value;
}

