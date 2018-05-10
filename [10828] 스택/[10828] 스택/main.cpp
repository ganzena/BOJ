#include <iostream>
#include <string>

using namespace std;
class Stack{
public:
    void Push(int);
    void Pop();
    void Size();
    void Empty();
    void Top();
    
    Stack() : stack(new int [1000]), top(-1){};
private:
    int* stack;
    int top;
};

void Stack::Push(int num){
    stack[++top] = num;
}

void Stack::Pop(){
    if(top < 0)
        cout<<-1<<endl;
    else{
        cout<<stack[top--]<<endl;
    }
}

void Stack::Size(){
    cout<<top+1<<endl;
}

void Stack::Empty(){
    if(top < 0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}

void Stack::Top(){
    if(top < 0)
        cout<<-1<<endl;
    else
        cout<<stack[top]<<endl;
}

int main(int argc, const char * argv[]) {
    int counter;
    string command;
    int commandNum;
    Stack stack;
    cin>>counter;
    while(counter > 0){
        cin>>command;
        if(command.compare("push") == 0){
            cin>>commandNum;
            stack.Push(commandNum);
        }else if(command.compare("pop") == 0){
            stack.Pop();
        }else if(command.compare("size") == 0){
            stack.Size();
        }else if(command.compare("empty") == 0){
            stack.Empty();
        }else if(command.compare("top") == 0){
            stack.Top();
        }
        counter--;
    }
    
    
    return 0;
}
