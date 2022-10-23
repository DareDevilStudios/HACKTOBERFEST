package queue;
import java.util.*;

public class cicular_queue {
    int SIZE = 5;
    int front, rear;
    int items[];
    cicular_queue(int n) {
        SIZE = n;
        items = new int[SIZE];
        front = -1;
        rear = -1;
    }

    boolean isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }

    boolean isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }
    void enQueue(int element) {
        if (isFull()) {
            System.out.println("Queue is full");
        } else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            System.out.println("Inserted " + element);
        }
    }
    int deQueue() {
        int element;
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return (-1);
        } else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }
    void display() {
        int i;
        if (isEmpty()) {
            System.out.println("Empty Queue");
        } else {
            System.out.println("Front -> " + front);
            System.out.print("Items -> ");
            for (i = front; i != rear; i = (i + 1) % SIZE){
                System.out.print(items[i] + " ");
            }
            System.out.println(items[i]);
            System.out.println("Rear -> " + rear);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        cicular_queue q = new cicular_queue(size);
        int z;
        do{
            System.out.println("enter the choice : \n 1.enquqe \n 2.dequeue");
            int choice;
            choice = sc.nextInt();
            switch(choice){
                case 1:System.out.println("enter a data");
                    int a = sc.nextInt();
                    q.enQueue(a);
                    q.display();
                    break;
                case 2:
                    q.deQueue();
                    q.display();
                    break;
                default:System.out.println("invalid input");
            }
            System.out.print("do you want to continue [1-yes / 2-no] :");
            z = sc.nextInt();
        }while( z == 1);
    }
}
