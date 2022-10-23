package queue;

import java.util.Scanner;

public class queue_using_arr {
    int arr[];
    int size;
    int front;
    int rear;
    queue_using_arr(int n){
        size = n;
        front = rear = 0;
        arr = new int[size];
    }

    boolean isFull(){
        return rear == size;
    }
    boolean isEmpty(){
        return front == rear;
    }

    void enqueue(int d){
        if(isFull()){
            System.out.println("q is full");
            return;
        }
        arr[rear] = d;
        rear++;
    }
    int dequeue(){
        if(!isEmpty()){
            int a = arr[front];
            front++;
            return a;
        }
        else{
            System.out.println("q is empty");
            return -1;
        }
    }
    void display(){
        for(int i = front; i < rear; i++){
            System.out.print(arr[i] + " ");
        }
    }
    int Front(){
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }
    int Rear(){
        if(!isEmpty()){
            return arr[rear - 1];
        }
        return -1;
    }
    int qsize(){
        return rear - front;
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c;
        int size = sc.nextInt();
        queue_using_arr q = new queue_using_arr(size);
        do{
            System.out.println("enter your choice \n1.insert \n2.delete \n3.print front \n4.print rear \n5.size \n6.empty \n7.full");
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
                case 6:
                    System.out.println(q.isEmpty());
                    break;
                case 7:
                    System.out.println(q.isFull());
                    break;

                default:
                    System.out.println("invalid input");
            }
            System.out.println("\ndo you wanna continue 1.yes 2.no ");
            c = sc.nextInt();
        }while (c == 1);
    }
}
