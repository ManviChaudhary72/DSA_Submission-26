#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int capacity;
    int currSize;
    CircularQueue(int size){
        capacity=size;
        arr=new int[capacity];
        front=0;
        rear=-1;
        currSize=0;
    }
  void push(int val){
  if(currSize==capacity) {
    cout<<"CQ is Full\n";
    return;
  }
  rear=(rear+1)%capacity;
  arr[rear]=val;
  currSize++;
  }
  void pop(){
    if(currSize==0) {
    cout<<"CQ is Empty\n";
    return;
  }
    front=(front+1)%capacity;
    currSize--;
   }
   int frontElement(){
    if(currSize==0) {
    cout<<"CQ is Empty\n";
    return -1;
  }
  return arr[front];
   }
};
int main(){
    CircularQueue q(3);
    q.push(5);
    q.push(4);
    q.push(9);
    q.pop();
    q.push(10);
    while(q.currSize!=0){
        cout<<q.frontElement()<<" ";
        q.pop();
    }
}
