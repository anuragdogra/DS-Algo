#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
void display()
{
    struct node *p,*temp;
   p=start;
  	do
  	{
  		printf("%d",p->data);
  		p=p->next;
  	}while(p!=start);
} 	
void insertatbeg()
{
	int item;
	struct node *temp,*p;
	printf("enter the item to insert at begining\n ");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;

	temp->next=start;
	p=start;
	while(p->next!=start)
  	{
  		p=p->next;
  	}
  	p->next=temp;
  	start=temp;
}
void insertatend()
{
	int item;
	struct node *temp,*p;
	printf("enter the item to be inseted at end\n");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	p=start;
	while(p->next!=start)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=start;
}
 void insertatloc()
  {
    struct node *temp,*p,*preptr;
    int pos,item;
    printf("enter the pos");
    scanf("%d",&pos);
    printf("enter the data\n");
    scanf("%d",&item);
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=item;                  
    
    
    	p=start;
    	while(p->data!=pos)
    	{
    		preptr=p;
    		p=p->next;
    	}
    	temp->next=p;
    	preptr->next=temp;
    }
  
int main()
{
  struct node *p,*temp;
  int choice=1,item;
  while(choice)
  {
  	printf("enter the data\n");
  	scanf("%d",&item);
  	temp=(struct node*)malloc(sizeof(struct node));
  	temp->data=item;
  	temp->next=NULL;
  	if(start == NULL)
  	{
  		start=temp;
  		temp->next=start;
  	}
  	else
  	{
  		p=start;
  		while(p->next!=start)
  		{
  			p=p->next;
  		}
  		p->next=temp;
  		temp->next=start;
  	}
  	printf("continue?");
    scanf("%d",&choice);
  }
   /*insertatbeg();
   insertatend();*/
   insertatloc();
   display();
}