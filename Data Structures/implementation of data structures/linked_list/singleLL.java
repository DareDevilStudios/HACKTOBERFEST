package linked_list;

import  java.util.*;
public class singleLL {
    public class Node {
        public Node next;
        public int data;

        public Node(int d) {
            data = d;
        }
    }

    public Node head;
    public singleLL(){
        head = null;
    }

    public void insertFirst(int d){
        Node node = new Node(d);
        node.next = head;
        head = node;
    }

    public void insertLast(int d){
        Node node = new Node(d);
        if(head == null){
            node.next = head;
            head = node;
        }
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = node;
        node.next = null;
    }

    public void display(){
        Node temp  = head;
        while (temp != null){
            System.out.printf(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.print("null");
    }
    public boolean isEmpty(){
        return head == null;
    }

    public int deleteFirst(){
        int temp = head.data;
        head = head.next;
        return temp;
    }

    public int deleteLast(){ // here we looking for second last element to make next node null
            Node last = head;
            if(head.next == null){   // same as delete first
                int temp = head.data;
                head = null;
                return temp;
            }
            else {
                while (last.next.next != null) {
                    last = last.next;
                }
                int temp = last.data;
                last.next = null;
                return temp;
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

    public void insertAfterKey(int key,int d){
        Node node = new Node(d);
        Node temp = head;
        if(head == null){
//            insertFirst(d);
         }
        for(int i = 0; i < key - 1; i++){
            temp = temp.next;
        }
        node.next = temp.next;
        temp.next = node;
    }

    public void deleteAfterKey(int key){
        Node temp = head;
        for(int i = 0; i < key - 1; i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c, size, key;

        singleLL ll = new singleLL();
        do{
            System.out.println("enter your choice \n1.insert first \n2.insert last \n3.delete first " +
                    "\n4.delete last \n5.insert at key \n6.delete from key");
            int choice = sc.nextInt();
            switch (choice){
                case 1:
                    System.out.print("enter the data :");
                    int d = sc.nextInt();
                    ll.insertFirst(d);
                    ll.display();
                    break;
                case 2:
                    System.out.print("enter the data :");
                    int a = sc.nextInt();
                    ll.insertLast(a);
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
                    size = ll.sizeofLL();
                    System.out.println("size = " + size);
                    System.out.print("enter the index :");
                     key = sc.nextInt();
                    if(size < key - 1){
                        System.out.println("invalid key");
                        break;
                    }
                    System.out.print("enter the data :");
                    int data = sc.nextInt();
                    if(key == 0){
                        ll.insertFirst(data);
                        ll.display();
                        break;
                    }
                    else{
                        ll.insertAfterKey(key, data);
                        ll.display();
                        break;
                    }
                case 6:
                    size = ll.sizeofLL();
                    System.out.println("size = " + size);
                    if(size == 0 ){
                        System.out.println("empty list");
                        break;
                    }
                    System.out.print("enter the index :");
                    key  = sc.nextInt();
                    if(size <= key ){
                        System.out.println("invalid key");
                        break;
                    }
                    if(key == 0){
                        ll.deleteFirst();
                        ll.display();
                        break;
                    }
                    ll.deleteAfterKey(key);
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
