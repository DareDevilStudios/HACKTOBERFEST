#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
	int* arr;
	int size;
	int front;
	int rear;
	Queue(int s){
		size = s;
		arr = new int[size];
		front = rear = 0;
	}

	bool isFull(){
		return rear == size;
	}
	bool isEmpty(){
		return front == rear;
	}
	void enqueue(int d){
		if(isFull()){
			cout << "queue is full" << endl;
			return;
		}
		arr[rear++] = d;
	}
	int dequeue(){
		if(isEmpty()){
			cout << "queue is empty" << endl;
			return - 1;
		}
		return arr[front++];
	}
	void display(){
		for(int i = front; i < rear; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int Front(){
		return isEmpty() ? -1 : arr[front];
	}
	int Rear(){
		return isEmpty() ? -1 : arr[rear - 1];
	}
};

int main(){
	Queue q(5);
	int c;
	do{
        cout << "enter your choice \n1.insert \n2.delete \n3.print front \n4.print rear " << endl;
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                cout << "enter the data :";
                int d ;
                cin >> d;
                q.enqueue(d);
                q.display();
                break;
            case 2:
                q.dequeue();
                q.display();
                break;
            case 3:
                cout << "front -> " << q.Front();
                break;
            case 4:
                cout << "rear -> " << q.Rear();
                break;
            default:
                cout << "invalid input";
        }
        cout << "\ndo you wanna continue 1.yes 2.no ";
        cin >> c;
    }while (c == 1);
}

