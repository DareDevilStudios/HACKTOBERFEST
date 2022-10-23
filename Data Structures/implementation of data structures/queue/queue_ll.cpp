#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	Node* next;
	int data;
	Node(int d){
		data = d;
	}
};

class Queue{
public:
	Node* front;
	Node* rear;
	int size;
	Queue(){
		front = rear = NULL;
	}

	void enqueue(int d){
		Node* node = new Node(d);
		if(front == NULL){
			front = rear = node;
			size++;
		}
		else{
			rear -> next = node;
			rear = node;
			size++;
		}
	}
	int dequeue(){
		if(front == NULL){
			return 0;
		}
		else{
			int d = front -> data;
			front = front -> next;
			size--;
			return d;
		}
	}
	void display(){
		Node* temp = front;
		if(!front&& !rear){
			cout << "empty queue" << endl;
		}
		else{
			while(temp){
				cout << temp -> data << " -> ";
				temp = temp -> next;
			}
			cout << " NULL " << endl;
		}
	}
	int Front(){
		return front -> data;
	}
	int Rear() {
		return rear -> data;
	}
	int Qsize(){
		return size;
	}
	bool isFull(){
		Node* temp = front;
		int c = 0;
		while(temp){
			temp = temp -> next;
			c++;
		}
		return c == size;
	}
	bool isEmpty(){
		return front == rear;
	}
};

int main(){
	Queue q;
	int c;
	do{
        cout << "enter your choice \n1.insert \n2.delete \n3.print front \n4.print rear \n5.size" << endl;
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
            case 5:
            	cout << "size -> " << q.Qsize();    
            default:
                cout << "invalid input";
        }
        cout << "\ndo you wanna continue 1.yes 2.no ";
        cin >> c;
    }while (c == 1);

	return 0;
}
