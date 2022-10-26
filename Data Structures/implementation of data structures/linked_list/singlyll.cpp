#include <bits/stdc++.h>
using namespace std;

class Node{
	public :
		Node *next;
		int data;

		Node(int d){
			this->data = d;
		}
};

class singly_ll{

	Node *head;
	Node *tail;

	public:
		singly_ll(){
			head = NULL;
			tail = NULL;
		}
		void display(){
			Node *temp = head;
			while(temp != NULL){
				cout << temp -> data << " -> ";
				temp = temp -> next;
			}
			cout << "null";
		}
		void insert_head(int d){
			Node *node = new Node(d); 
			if(head == NULL){
				head = node;
				tail = node;
				return;
			}
			node -> next = head;
			head = node;
		}
		void insert_tail(int d){
			Node *node = new Node(d);
			if(tail == NULL){
				head = tail = node;
				return;
			}
			tail ->next = node;
			tail = node;
		}
		bool isEmpty(){
			return head == NULL;
		}
		void delete_head(){
			if(!isEmpty()){
				head = head -> next;
			}else{
				cout << "empty" << endl;;
			}
		}
		void delete_tail(){
			if(!isEmpty()){
				head = head -> next;
			}else{
				cout << "empty" << endl;;
			}
		}

		void insert_at_key(int d, int key){
			Node *node = new Node(d);

			Node *temp = head;
			for(int i = 0; i < key - 1; i++){
				temp = temp -> next;
			}
			if(temp == head){
				insert_head(d);
				return;
			}
			if(temp == tail){
				insert_tail(d);
				return;
			}
			node -> next = temp -> next;
			temp -> next = node;
		}

		void delete_at_key(int key){
			Node *temp = head;
			for(int i = 0; i < key - 1; i++){
				temp = temp->next;
			}

			temp->nextt = temp->next->nex;

		}
		
};
int main(){

	singly_ll ll;
	int c;
	do{
        cout << "enter your choice \n1.insert head \n2. insert tail \n3. delete head \n4. insert_at_key \n5. delete_at_key" << endl;
        int choice;
        cin >> choice;
        switch (choice){
            case 1 :
               cout << "enter the data : ";
                int a ;
                cin >> a;
                ll.insert_head(a);
                ll.display();
                break;
            case 2 :
               	cout << "enter the data : ";
                int b;
                cin >> b;
                ll.insert_tail(b);
                ll.display();
                break;
            case 3 :
            	ll.delete_head();
            	ll.display();
            	break;
            case 4:
            	cout << "enter the index ";
            	int key;
            	cin >> key;
               	cout << "enter the data : ";
                int c;
                cin >> c;
                ll.insert_at_key(c, key);
                ll.display();
                break;
            case 5:
            	cout << "enter the index ";
            	int key1;
            	cin >> key1;
               	cout << "enter the data : ";
                int c2;
                cin >> c2;
                ll.delete_at_key(c2, key1);
                ll.display();
                break;

            default:
                cout << "invalid input";
        }
        cout << "\ndo you wanna continue 1.yes 2.no ";
        cin >> c;
	}while (c == 1);

	return 0;
}

