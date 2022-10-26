#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
	int arr[100];
	int size;
	int top;
	Stack(int size){
		this->size = size;
		top = -1;
	}
	bool isFull(){
		return top == size;
	}
	bool isEmpty(){
		return top == -1;
	}
	void push(int data){
		if(!isFull()){
			arr[++top] = data;
		}else{
			cout << "stack overflow " << endl;
		}
	}
	int pop(){
		if(!isEmpty()){
			int a = arr[top];
			top--;
			return a;
		}else{
			cout << " stack underflow " << endl;
		}
		
	}
	void display(){
		for(int i = 0; i <= top; i++){
			cout << arr[i] << " - ";
		}
		cout << "top" << endl;
	}
};

int main(){

	Stack st(2);
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