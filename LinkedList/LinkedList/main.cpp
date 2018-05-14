//
//  main.cpp
//  LinkedList
//
//  Created by YOO TAEWOOK on 2018. 5. 14..
//  Copyright © 2018년 YOO TAEWOOK. All rights reserved.
//

#include <iostream>

using namespace std;

class Node{
    friend class List;
public:
    Node(int data, Node* next, Node* prev):data(data), next(next), prev(prev){};
    Node(int data):data(data), next(nullptr), prev(nullptr){};
    Node():data(NULL), next(nullptr), prev(nullptr){};
private:
    int data;
    Node* next;
    Node* prev;
};

class List{
public:
    List();
    void Insert(int);
    void Delete(int);
    void Search(int);
    void Print();
    void ReversePrint();
    int IsEmpty();
    //~List();
private:
    Node* head;
    Node* tail;
    int size; //리스트의 크기
};

int List::IsEmpty(){
    if(size)
        return 0;
    else
        return 1;
}
List::List(){
    head = tail = nullptr; //첫 세팅은 head tail 모두 nullptr
    size = 0;
}

void List::Insert(int data){
    Node* tempNode = new Node(data); //임시 노드 생성
    Node* position = head;
    if(IsEmpty()){ //비어있는 경우 head에 넣어준다.
        head = tempNode;
        tail = tempNode;
    }else{
        if(head->data > data){ // head 앞에 놓이게 될 경우
            tempNode->next = head;
            head->prev = tempNode;
            head = tempNode;
        }else if(tail->data < data){ // tail 뒤에 놓이게 될 경우
            tail->next = tempNode;
            tempNode->prev = tail;
            tail = tempNode;
        }else{ // 그 외
            while(position->data < data && position != nullptr) // (position->prev) -> (임시 노드) -> (Position)
                position = position->next;
            
            tempNode->next = position;
            tempNode->prev = position->prev;
            position->prev->next = tempNode;
            position->prev = tempNode;
        }
    }
    size++;
    //Cyclic LinkedList 설정
    head->prev = tail;
    tail->next = head;
}

void List::Delete(int target){
    if(IsEmpty()){
        cout<<"List is empty"<<endl;
    }else{
        Node* tempNode = head;
        while(tempNode->data != target && tempNode != nullptr){ //지울 데이터의 위치 찾기
            tempNode = tempNode->next;
        }
        //(tempNode->prev) -> (tempNode) -> (tempNode->next)
        //(tempNode->prev) -> (tempNode->next)
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
        if(tempNode->next == nullptr) //tempNode가 tail이었을 경우
            tail = tempNode->prev; //tail의 위치를 한 칸 앞으로 옮겨준다.
        delete(tempNode);
        size--;
    }
    head->prev = tail;
    tail->next = head;
}

void List::Search(int target){
    Node* position = head;
    if(IsEmpty()){
        cout<<"List is empty"<<endl;
    }else{
        while(position->data != target && position != nullptr)
            position = position->next;
        if(position->data == target)
            cout<<target<<" is in the list"<<endl;
        else
            cout<<target<<" is not in the list"<<endl;
    }
}

void List::Print(){
    Node* P = head;
    while(P != nullptr){
        cout<<P->data<<" -> ";
        P = P->next;
    }
    cout<<endl;
}

void List::ReversePrint(){
    Node* P = tail;
    while(P != nullptr){
        cout<<P->data<<" -> ";
        P = P->prev;
    }
    cout<<endl;
}


int main(int argc, const char * argv[]) {
    List L = List();
    L.Insert(30);
    L.Insert(20);
    L.Insert(10);
    L.Insert(50);
    L.Insert(40);
    L.Insert(70);
    L.Insert(60);
    L.Delete(50);
    L.Print();
    L.ReversePrint();
    return 0;
}
