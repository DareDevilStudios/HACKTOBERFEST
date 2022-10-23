package queue;
import java.util.*;

public class queue_using_ll {
    public class Node{
        public Node next;
        public int data;
        public Node(int d){
            data = d;
        }
    }

    public Node front;
    public Node rear;
    public int size = 0;
    public queue_using_ll(){
        front = rear = null;
    }

    public void enqueue(int d){
        Node node = new Node(d);
        if(front == null ){
            front = node;
            rear = node;
            ++size;
        }
        else {
            rear.next = node;
            rear = node;
            ++size;
        }

    }
    public int dequeue(){
        if(front == null){
            return 0;
        }
        else{
            int result = front.data;
            front = front.next;
            --size;
            return result;
        }

    }

    public void display(){
        Node temp = front;
        if(front == null && rear == null){
            System.out.println("empty queue");
        }
        else {
            while(temp != null){
                System.out.print(temp.data + " -> ");
                temp = temp.next;
            }
            System.out.println("null");
        }
    }


    public int Front(){
        return  front.data;
    }
    public int Rear(){
        return  rear.data;
    }
    public int qsize(){
            return size;
    }
    public boolean isFull(){
        Node temp = front;
        int c = 0;
        while(temp != rear){
            temp = temp.next;
            c++;
        }
        return c == size;
    }
    public boolean isEmpty(){
        return front == rear;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c;
        queue_using_ll q = new queue_using_ll();
        do{
            System.out.println("enter your choice \n1.insert \n2.delete \n3.print front \n4.print rear \n5.size");
            int choice = sc.nextInt();
            switch (choice){
                case 1:
                    System.out.print("enter the data :");
                    int d = sc.nextInt();
                    q.enqueue(d);
                    System.out.println(q.Front());
                    System.out.println(q.Rear());
                    q.display();
                    break;
                case 2:
                    q.dequeue();
                    q.display();
                    break;
                case 3:
                    System.out.println("front -> " + q.Front());
                    break;
                case 4:
                    System.out.println("rear -> " + q.Rear());
                    break;
                case 5:
                    System.out.println("size = " + q.qsize());
                    break;

                default:
                    System.out.println("invalid input");
            }
            System.out.println("\ndo you wanna continue 1.yes 2.no ");
            c = sc.nextInt();
        }while (c == 1);
    }
}
