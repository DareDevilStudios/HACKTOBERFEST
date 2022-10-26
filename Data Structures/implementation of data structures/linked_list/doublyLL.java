package linked_list;

import  java.util.*;

public class doublyLL {
    public  class Node {
        public Node next;
        public Node prev;
        public int data;
        public Node(int d) {
            data = d;
//            next = prev = null;
        }
    }
    public Node head; // by default value is null
    public Node tail;

    public doublyLL(){
        head = tail = null;
    }

    public void display(){
        Node temp = head;
        while ( temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
    public boolean isEmpty(){
        return head == null;
    }

    public void insertHead(int d){
        Node node = new Node(d);
        if(head == null){
            head = node;
            tail = node;
        }
        else{
            node.next = head;
            head.prev = node;
            head = node;
        }
    }
    public void insertTail(int d){
        Node node = new Node(d);
        if(tail == null) {
           tail = node;
           head = node;
        }
        else {
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
    }

    public void deleteFirst(){
        Node temp = head;
        if(head.next == null){
            head = tail = null;
        }
        else{
            temp.next.prev = null;
            head = temp.next;
            temp.next = null;
        }
    }
    public void deleteLast(){
        Node temp = tail;
        if(tail.prev == null){
            head = tail = null;
        }
        else{
            temp.prev.next = null;
            tail = tail.prev;
            temp.prev = null;
        }
    }
    void insetATkey(int d, int key){
        Node node = new Node(d);
        Node temp = head;
        for(int i = 0; i < key - 1 && temp.next != null; i++){
            temp = temp.next;
        }

        if(key == 0){
            insertHead(d);
            return;
        }
        if(temp == tail){  // if index is greater than size
            insertTail(d);
            return;
        }
        node.next = temp.next;
        temp.next.prev = node;
        temp.next = node;
        node.prev = temp;
        display();
//        delete(node);
    }

    void deleteATkey(int key){
        if(!isEmpty()){
            Node current = head;
            Node previous = null;
            for(int i = 0; i < key && current.next != null; i++){
                previous = current;
                current = current.next;
            }
            if(current == head){
                deleteFirst();
                return;
            }
            if(current == tail){
                deleteLast();
                return;
            }
            current.prev = null;
            previous.next = current.next;
            previous.next.prev = previous;
            current.next = null;
        }else{
            System.out.println("empty");
        }
    }

    public int sizeofLL(){
        Node temp = head;
        int s = 0;
        while(temp!=null){
            temp = temp.next;
            s++;
        }
        return s;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c,key;

        doublyLL ll = new doublyLL();
        do{
            System.out.println("enter your choice \n1.insert first \n2.insert last \n3.delete first " +
                    "\n4.delete last \n5.insert at a key \n6.delete at a key ");
            int choice = sc.nextInt();
            switch (choice){
                case 1:
                    System.out.print("enter the data :");
                    int d = sc.nextInt();
                    ll.insertHead(d);
                    ll.display();
                    break;
                case 2:
                    System.out.print("enter the data :");
                    int a = sc.nextInt();
                    ll.insertTail(a);
                    ll.display();
                    break;
                case 3:
                    if(!ll.isEmpty()){
                        ll.deleteFirst();
                        ll.display();
                        break;
                    }
                    else{
                        System.out.println("empty list");
                        break;
                    }
                case 4:
                    if(!ll.isEmpty()){
                        ll.deleteLast();
                        ll.display();
                        break;
                    }
                    else{
                        System.out.println("empty list");
                        break;
                    }
                case 5:
                    int Size = ll.sizeofLL();
                    System.out.println("size = " + Size);
                    System.out.print("enter the index:");
                    key = sc.nextInt();
                    if(Size < key){
                        System.out.println("invalid key");
                        break;
                    }
                    System.out.print("enter the data :");
                    int data = sc.nextInt();
                    ll.insetATkey(data, key);
                    ll.display();
                    break;

                case 6:
                    int size = ll.sizeofLL();
                    System.out.println("size = " + size);
                    if(size == 0 ){
                        System.out.println("empty list");
                        break;
                    }
                    System.out.print("enter the index:");
                    key = sc.nextInt();
                    if(size <= key){
                        System.out.println("invalid key");
                        break;
                    }
                    ll.deleteATkey(key);
                    ll.display();
                    break;

                default:
                    System.out.println("invalid input");
            }
            System.out.println("\ndo you wanna continue 1.yes 2.no ");
            c = sc.nextInt();
        }while (c == 1);
    }
}
