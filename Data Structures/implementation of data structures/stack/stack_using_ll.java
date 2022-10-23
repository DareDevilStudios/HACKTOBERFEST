package stack;
import java.util.*;

public class stack_using_ll {

    public class Node{
        Node next;
        int data;

        public Node(int d){
            data = d;
        }
    }


    int size;
    Node top;
    int count;

    public stack_using_ll(int size){
        top = null;
        this.size = size;
        this.count = -1;
    }


    public void push(int d){
        if(!isFull()){
            Node node = new Node(d);
            node.next = top;
            top = node;
            count++;
        }else{
            System.out.println("Stack overflow!!!");
        }

    }

    public int pop(){
        if(!isEmpty()){
            int d = top.data;
            top = top.next;
            count--;
            return d;
        }else{
            System.out.println("Stack underflow!!!");
            return 0;
        }

    }

    public void display(){
        Node temp = top;
        while (temp != null){
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.print("Null");
    }

    public int peek(){
        if(!isEmpty()){
            return top.data;
        }
        System.out.println("empty stack");
        return 0;
    }

    public boolean isFull(){
        return size - 1 == count;
    }
    public boolean isEmpty(){
        return count == -1;
    }



    public static  void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c;
        int size;
        System.out.print("Enter the size of stack : ");
        size = sc.nextInt();
        stack_using_ll st = new stack_using_ll(size);
        do{
            System.out.println("enter your choice \n1.push \n2.pop \n3.peek \n4.display");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("enter the data");
                    int a = sc.nextInt();
                    st.push(a);
                    st.display();
                    break;
                case 2:
                    st.pop();
                    st.display();
                    break;
                case 3:
                    System.out.println(st.peek());
                    break;
                case 4 :
                    st.display();
                    break;

                default:
                    System.out.println("invalid input");
            }
            System.out.println("\ndo you wanna continue 1.yes 2.no ");
            c = sc.nextInt();
        }while (c == 1);
    }



}
