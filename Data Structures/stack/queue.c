#include<stdio.h>
#include<stdlib.h>
int rear=-1,front=-1;
void enqueue(int q[],int size)
{
  int data;
  if(rear==size-1 && front==0 || front==rear+1)
    printf("Queue is full");
  else
  {
    printf("Enter the element:");
    scanf("%d",&data);
    if(rear==-1 )
    {   
        front++;
        rear++;
        
       
      
    }
    else if( rear==size-1)
     {
       rear=0;
    
     }
     else
      {
          rear++;
          
      }
      q[rear]=data;
  }
}

int dequeue(int size)
{
  
  if(front==-1)
   printf("\n QUEUE is empty:\n");
  else{
    
    if(rear==front)
    {
      front=-1;
      rear=-1;
    }
    else if(front==size-1){
      front=0;

    }
    else{
      front++;
    }

  }
}


void display(int q[],int size)
{
    int i;
    if(front==-1)
     printf("\nQueue is empty:\n");
    else
    {
     printf("QUEUE elemnts are:");
     if(front<=rear)
     {
      for(int i=front;i<=rear;i++){
        printf("%d\t",q[i]);}}
    
    else
    {
     for(i=front;i<size;i++){
        printf("%d\t",q[i]);}
     for(i=0;i<=rear;i++)
      {
        printf("%d\t",q[i]);
      }
      
        
    }
    }
}

int main(){
  int choice,size,data,q[size];
  printf("\nEnter the size\n");
  scanf("%d",&size);

  do{
    printf("\n1.ENQUEUE");
    printf("\n2.DEQUEUE\n");
    printf("3.display");
    printf("\n4.exit\n");
    printf(" ENTER YOUR CHOICE\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
      enqueue(q,size);
      break;
    
    case 2:
     dequeue(size);
     break;
    case 3:
     display(q,size);
     break;
    case 4:
    exit(0);break;
     default:
      printf("Invalid option");break;
    
    }

  }while (choice!=0);
  return 0;
  
}