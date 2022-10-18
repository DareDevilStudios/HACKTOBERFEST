#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head1=NULL;
struct node*head2=NULL;


void insert(struct node*head,int data)
{
 struct node*newnode1,*ptr1;
 ptr1=head;
 newnode1=(struct  node*)malloc(sizeof(struct node));
 newnode1->data=data;
 newnode1->next=NULL;
 if(head1==NULL) head=newnode1;
 else{
     while(ptr1->next!=NULL)
     {
       ptr1=ptr1->next;
     }
     ptr1->next=newnode1;
 }
}





struct node*merge( struct node*h1,struct node*h2)
{
   

    if(h1==NULL)
     return h2;
    else if(h2==NULL)
    {
        return h1; 
    }

    if(h1->data<h2->data)
    {
      h1->next=merge(h1->next,h2);
      return h1;
    }
    else
      {
        h2->next=merge(h1,h2->next);
        return h2;
      }
     
    
    
}

void diplay(struct node*h)
{   
    printf("\nMERGED LINKED LIST IS:");
    while(h!=NULL){
        printf("%d\t",h->data);
        h=h->next;                                                     
    }
}

int main()
{
    int choice ,data1,data2;
    do{
    printf("\n1.Insert for LL 1:");
    printf("\n2.Insert for LL 2:");
    printf("\n3.Display merged LL:");
    printf("\n4.exit:");
    printf("\nEnter the choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
      printf("\nEmtert the data 1:");
      scanf("%d",&data1);
      insert(head1,data1);
      break;
    case 2:
      printf("\nEmtert the data 2:");
      scanf("%d",&data2);
      insert(head2,data2);
      break;
    case 3:
      merge(head1,head2);
      printf("\nMERGED\n");
      struct node*n=merge(head1,head2);
      diplay(n);
      break;
    case 4:
     exit(0);
     break;
    
    default:
        break;
    }}while(choice!=0);
    return 0;
}
