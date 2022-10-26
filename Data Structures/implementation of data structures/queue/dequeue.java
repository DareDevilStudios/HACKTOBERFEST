
import java.util.Scanner;

public class dequeue{

    int size;
    int front, rear;
    int arr[];
    dequeue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushFront(int d){
        if(isFull()){
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size -1){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = d;
    }
    int popFront(){
        if(isEmpty()){
            System.out.println("q is empty");
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ // single element
            front = rear = -1;
        } else if (front == size -1) {
            front = 0; // maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

    void pushRear(int d){
        if(isFull()){
            System.out.println("q full");
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = d;
    }
    int popRear(){
        if(isEmpty()){
            System.out.println("q is empty");
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size - 1;
        }
        else{
            rear--;
        }
        return ans;
    }
    boolean isEmpty(){
        if(front == -1)
            return true;
        else
            return false;
    }
    boolean isFull(){
        //                                                      rear is infront of front
        if( (front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))){
            return true;
        }
        else {
            return false;
        }
    }
    int getFront(){
        if(isEmpty()){
            System.out.println("q is empty");
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(isEmpty()){
            System.out.println("q is empty");
            return -1;
        }
        return arr[rear];
    }
    void display(){
        if(isEmpty()){
            System.out.println("q is empty");
            return;
        }
        int i;
        System.out.println("front -> " + arr[front]);
        System.out.print("items ->");
        for(i = front; i != rear; i = (i + 1) % size ){
            System.out.print(arr[i] + " ");
        }
        System.out.println(arr[i]);
        System.out.println("rear -> " + arr[rear]);
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        dequeue q = new dequeue(size);
        int z;
        do{
            System.out.println("enter the choice : \n 1.insert front \n 2.insert rear \n 3.delete front \n 4.delete rear");
            int choice;
            choice = sc.nextInt();
            switch(choice){
                case 1:System.out.println("enter a data");
                    int a = sc.nextInt();
                    q.pushFront(a);
                    q.display();
                    break;
                case 2: System.out.println("enter a data");
                    int b = sc.nextInt();
                    q.pushRear(b);
                    q.display();
                    break;
                case 3:
                    q.popFront();
                    q.display();
                    break;
                case 4:
                    q.popRear();
                    q.display();
                    break;
                default:System.out.println("invalid input");
            }
            System.out.print("do you want to continue [1-yes / 2-no] :");
            z = sc.nextInt();
        }while( z == 1);
    }
}
