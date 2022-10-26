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

class Stack{
	public:
		Node* top;
		Stack(){
			top = NULL;
		}
		bool isEmpty(){
			return top == NULL;
		}
		void push(int d){
			Node* node = new Node(d);
			node->next = top;
			top = node;
		}
		void pop(){
			if(!isEmpty()){
				top = top->next;
			}else{
				cout << "stack underflow " << endl;
			}
			
		}
		void display(){
			Node* temp = top;
			cout << "top";
			while(temp != NULL){
				cout << " -> " <<temp->data ;
				temp = temp->next;
			}
			cout << endl;
		}

};

int main(){
	Stack st;
	int c;
	do{
        cout << "enter your choice \n1.push \n2.pop" << endl;
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                cout << "enter the data : " ;
                int a ;
                cin >> a;
                st.push(a);
                st.display();
                break;
            case 2:
                st.pop();
                st.display();
                break;
 
            default:
                cout << "invalid input";
        }
        cout << "\ndo you wanna continue 1.yes 2.no ";
        cin >> c;
	}while (c == 1);
	return 0;
}