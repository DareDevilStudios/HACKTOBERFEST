#include <bits/stdc++.h>
using namespace std;


class Node{
	public:
		Node *next;
		Node *pre;
		int data;
		Node(int d){
			data = d;
		}
};

class doubly_ll{
	public:
		Node *head;
		Node *tail;

	doubly_ll(){
		head = tail = NULL;
	}

	void display(){
		Node *temp = head;
		while(temp != NULL){
			cout << temp->data << " -> " ;
			temp = temp->next;
		}
		cout << "null" << endl;
	}

	void insert_head(int d){
		Node *node = new Node(d);
		if(head == NULL){
			head = tail = node;
			return;
		}

		node->next = head;
		head->pre = node;
		head = node;
	}	

	void insert_tail(int d){
		Node *node = new Node(d);
		if(tail == NULL){
			head = tail = NULL;
			return;
		}

		tail->next = node;
		node->pre = tail;
		tail = node;
	}

	bool isEmpty(){
		return head == NULL || tail == NULL;
	}

	void delete_head(){
		if(!isEmpty()){
			if(head->next == NULL){
				head = tail = NULL;
				return;
			}
			Node *temp = head;
			temp->next->pre = NULL;
			head = temp->next;
			temp->next = NULL;
		}else{
			cout << "empty" << endl;
		}
	}
	void delete_tail(){
		if(!isEmpty()){
			if(head->next == NULL){
				head = tail = NULL;
				return;
			}
			Node *temp = tail;
			temp->pre->next = NULL;
			tail = temp->pre;
			temp->pre = NULL;
			
		}else{
			cout << "empyt" << endl;
		}
	}

		void insert_at_key(int d, int key){
			Node *node = new Node(d);
			Node *temp = head;
			for(int i = 0; i < key - 1 && temp->next != NULL; i++){
				temp = temp -> next;
			}

			if(key == 0){
				insert_head(d);
				return;
			}
			if(temp == tail){  // if index is greate than size
				insert_tail(d);
				return;
			}
			node->next = temp->next;
			temp->next->pre = node;
			temp->next = node;
			node->pre = temp;
		}

		void delete_at_key(int key){
			if(!isEmpty()){
				Node *current = head;
				Node *previous = NULL;
				for(int i = 0; i < key && current->next != NULL; i++){
					previous = current;
					current = current -> next;
				}
				if(current == head){
					delete_head();
					return;
				}
				if(current == tail){
					delete_tail();
					return;
				}
				current->pre = NULL;
				previous->next = current->next;
				previous->next->pre = previous;
				current->next = NULL;
			}else{
				cout << "empty " << endl;
			}
		}
};

int main(){
	doubly_ll ll;
	int c;
	do{
        cout << "enter your choice \n1.insert head \n2. insert tail \n3. delete head \n4. delete tail \n5. insert_at_key \n6. delete_at_key" << endl;
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
        		ll.delete_tail();
        		ll.display();
        		break;
            case 5:
            	cout << "enter the index ";
            	int key;
            	cin >> key;
               	cout << "enter the data : ";
                int c;
                cin >> c;
                ll.insert_at_key(c, key);
                ll.display();
                break;
            case 6:
            	cout << "enter the index : " ;
            	int k;
            	cin >> k;
            	ll.delete_at_key(k);
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