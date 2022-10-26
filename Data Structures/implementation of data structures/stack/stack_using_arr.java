package stack;
import java.util.*;

public class stack_using_arr {

    int size;
    int arr[];
    int top;

    public  stack_using_arr(int size){
        this.size = size;
        this.arr = new int[size];
        this.top = -1;
    }

    public void push(int d){
        if(!isFull()){
            top++;
            arr[top] = d;
        }else{
            System.out.println("stack overflow!!!!");
        }

    }

    public int pop(){
        if(!isEmpty()){
            int temp = top;
            top--;
            return arr[temp];
        }else{
            System.out.println("stack underflow!!!!");
        }
        return 0;

    }

    public int peek(){
        if(!isEmpty()){
            return arr[top];
        }else{
            System.out.println("empty stack");
        }
        return -1;

    }

    public boolean isFull(){
        if(top == size - 1){
            return true;
        }
        return false;
    }
    public boolean isEmpty(){
        if(top == -1){
            return  true;
        }
        return false;
    }


    public void display(){
//        for(int i : arr){
//            System.out.print(i + " ");
//        }
        System.out.println();
        int i = 0;
        while (i <= top){
            System.out.print(arr[i++] + " ");
        }
        System.out.println();
    }





    public static  void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int c;
        int size;
        System.out.print("Enter the size of stack : ");
        size = sc.nextInt();
        stack_using_arr st = new stack_using_arr(size);
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
