#include <bits/stdc++.h>
using namespace std;

class dequeue{
public:
	int size;
    int front, rear;
    int *arr;
    dequeue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int d){
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size -1){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = d;
        return true;
    }
    int popFront(){
        if(isEmpty()){
            cout << "q is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ // single element
            front = rear = -1;
        } else if (front == size -1) {
            front = 0; // maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

    bool pushRear(int d){
        if(isFull()){
            cout << "q full" << endl;
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = d;
        return true;
    }
    int popRear(){
        if(isEmpty()){
            cout << "q is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){  // single element
            front = rear = -1;
        }
        else if(rear == 0){ // to maintain cyclic nature
            rear = size - 1;
        }
        else{
            rear--;
        }
        return ans;
    }
    bool isEmpty(){
        if(front == -1)
            return true;
        else
            return false;
    }
    bool isFull(){
        //                                                      rear is infront of front
        if( (front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))){
            return true;
        }
        else {
            return false;
        }
    }
    int getFront(){
        if(isEmpty()){
            cout << "q is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(isEmpty()){
            cout << "q is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    void display(){
        if(isEmpty()){
            cout << "q is empty" << endl;
            return;
        }
        int i;
        cout << "front -> " << arr[front] << endl;;
        cout << "items ->";
        for(i = front; i != rear; i = (i + 1) % size ){
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
        cout << "rear -> " << arr[rear] << endl;
    }

};

int main(){
	dequeue q(5);
    int z;
    do{
        cout << "\nenter the choice : \n 1.insert front \n 2.insert rear \n 3.delete front \n 4.delete rear" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:cout << "enter a data : ";
                int a;
                cin >> a;
                q.pushFront(a);
                q.display();
                break;
            case 2: cout << "enter a data : ";
                int b;
                cin >> b;
                q.pushRear(b);
                q.display();
                break;
            case 3:
                q.popFront();
                q.display();
                break;
            case 4:
                q.popRear();
                q.display();
                break;
            default:cout << "invalid input";
        }
        cout << "do you want to continue [1-yes / 2-no] :";
        cin >> z;
    }while(z == 1);
	return 0;
}
