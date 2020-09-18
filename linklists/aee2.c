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
void insertionatbeg()
{
	struct node *temp,*p;
	int item;
	printf("enter the element to be inseted at beg\n");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(start == NULL)
	{
		start=temp;
	}
	else
	{
       temp->next=start;
       start->prev=temp;
       temp->prev=NULL;
       start=temp;
	}
}
void insertatend()
{
	int item;
   struct node *temp,*p;
   printf("enter the item to be inserted at end\n");
   scanf("%d",&item);
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=item;
   temp->next=NULL;
   temp->prev=NULL;
   p=start;
   while(p->next!=NULL)
   {
   	p=p->next;
   }	
   p->next=temp;
   temp->prev=p;
   temp->next=NULL;
}
void deleteat()
{
	struct node *p,*temp;
	temp=start;
	start=start->next;
	start->prev=NULL;
	free(temp);
}
void deleatend()
{
  struct node *p,*temp,*pre;
  p=start;
  while(p->next!=NULL)
  {
  	p=p->next;
  }
  temp=p;
  p->prev->next=NULL;
  free(temp);

}
void insertbefore()
{
  int item,val;	
  struct node *temp,*pre,*p;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the elemnt beofre which the item is inserted\n");
  scanf("%d",&val);
  printf("enter the item insert  before the element \n");
  scanf("%d",&item);
  temp->data=item;
  temp->next=NULL;
  temp->prev=NULL;
  p=start;
  while(p->data!=val)
  {
  	pre=p;
  	p=p->next;
  }
   p->prev=temp;
  pre->next=temp;
  temp->next=p;
  temp->prev=pre;
  
 
}
void insertafter()
{
	int val,item;
	struct node *temp,*p,*pre;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the element after which the item be inserted\n");
	scanf("%d",&val);
	printf("enter the val to insert\n");
	scanf("%d",&item);
	temp->data=item;
	temp->next=NULL;
	temp->prev=NULL;
	p=start;
	while(p->data!=val)
	{
		p=p->next;
	}
    temp->next=p->next;
    temp->prev=p;
	p->next=temp;
}
void deletebefore()
{
  struct node *temp,*p,*pre;
  int val;
  printf("enter the val before which the element deleted\n");
  scanf("%d",&val);
  p=start;
  while(p->data!=val)
  {
  	pre=p;
  	p=p->next;
  }
  pre->prev->next=pre->next;
  p->prev=pre->next;
  free(pre);
  
}
void deletafter()
{
	struct node *p,*temp,*pre;
	int val;
	printf("enter the val after which the element deleted\n");
	scanf("%d",&val);
	p=start;
	while(p->data!=val)
	{
		p=p->next;
	}
	temp=p->next;
	p->next=p->next->next;
    free(temp);
}
bool search()
{
	int val;
	struct node *temp,*p;
	printf("enter the element to be searched\n");
	scanf("%d",&val);
	p=start;
	while(p!=NULL)
	{
		if(p->data == val)
		{
			return true;
		}
		p=p->next;
	}
	return false;
}
void display()
{
	struct node *p;
	if(start == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		p=start;
		while(p!=NULL)
		{
			printf("%d",p->data);
			p=p->next;
		}
	}
}


int main()
{
   struct node *temp,*p;
   int item,choice=1;
   while(choice)
  { 	
   printf("enter the data \n");
   scanf("%d",&item);
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=item;
   temp->next=NULL;
   if(start == NULL)
   {
   	start=temp;
   	temp->prev=NULL;
   }
   else
   {
   	p=start;
   	while(p->next!=NULL)
   	{
   		p=p->next;
   	}
   	p->next=temp;
   	temp->prev=p;
   	temp->next=NULL;
   }
   printf("continue?");
   scanf("%d",&choice);
  }
  if(search() == true)
  {
  	printf("Yes");
  }
  else
  {
  	printf("No");
  }
  /*insertionatbeg();
  insertatend();
  deleteat();
  deleatend();
  insertbefore();
  insertafter();
  deletebefore();
  deletafter();*/
  
}