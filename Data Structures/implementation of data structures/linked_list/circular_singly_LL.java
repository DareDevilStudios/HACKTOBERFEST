package linked_list;
import java.util.*;

public class circular_singly_LL {

    public class Node{
        Node next;
        int data;
        public Node(int d){
            this.data = d;
        }
    }

    public Node head;
    public Node tail;

    public  circular_singly_LL(){
        head = tail = null;
    }

    public void insert(int d){
        Node node = new Node(d);
        if(head == null){
            head = node;
            tail = node;
            tail.next = head;
            return;
        }
        tail.next = node;
        tail = node;
        tail.next = head;
    }

    public void delete(int value){
        if(head == null){  // for empty list
            return;
        }
        if(head == tail){  // for single element
            head = null;
            tail = null;
            return;
        }

        Node node = head;
    }

    public void display(){
        Node node = head;
        if (head != null) {
            do {
                System.out.print(node.data + " -> ");
                    node = node.next;
            } while (node != head);
        }
        System.out.println("head");
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c;
        circular_singly_LL ll = new circular_singly_LL();
        do{
            System.out.println("enter your choice \n1.insert  \n2. delete ");
            int choice = sc.nextInt();
            switch (choice){

                case 1 :
                    System.out.print("enter the data : ");
                    int a = sc.nextInt();
                    ll.insert(a);
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
