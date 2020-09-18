#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<stdbool.h> 

 struct node
    {
        int data;
        struct node *next;
    };
    struct node *start=NULL;
   void insertatend()
     {
        struct node *temp,*p;
        int item;
        printf("enter the data\n");
        scanf("%d",&item);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=item;
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
         }
         p->next=temp;
         temp->next=NULL;
        
     } 

   void insertat()
   {
    struct node *temp,*p;
    int item;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&item);
    if (start == NULL)  
        {
            start=temp;
        }
        else
        {
            temp->data=item;
            temp->next=NULL;
        }    
    temp->data=item;
    temp->next=start;
    start=temp; 

    } 
  void deleteatbeg()
       {
        struct node *temp;
        int data;
        printf("enter the no to be deleted\n");
        scanf("%d",&data);
        temp=start;
        start=start->next;
        free(temp);
                
       }
void display()
   {
    
  struct node *p;
  
   if(start==NULL)
    {           
   printf("list is epty\n");           
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
 bool search()
 {
    int t;
   struct node *temp,*p ,*next;
   p=start;
   printf("enter the element to be searched \n");
   scanf("%d",&t);
   while(p!=NULL)
   {
      if(p->data == t)
      {
        return true;
      }
      p=p->next;

   } 
   return false;
 }
 void deleteatend()
    {
        struct node *temp,*p;
        int data;
        printf("enter the data to be deleted \n");
        scanf("%d",&data);
        p=start;
        while(p->next!=NULL)
        {
            temp=p;
            p=p->next;
                
        }
        temp->next=NULL;
        free(p);
        
        
    }
     void insertbefore()
    {
        struct node *temp,*p,*preptr;
        int data,val;
        printf("enter the elemente to be inserted\n");
        scanf("%d",&data);
        printf("enter the no.before which to inserr\n");
        scanf("%d",&val);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        p=start;
        while(p->data!=val)
        {
            preptr=p;
            p=p->next;
        }    
        preptr->next=temp;
        temp->next=p;   
    }
    void reverse() 
    { 
       
        struct node * current = start;
        
        struct node  *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
           
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
        start = prev; 
    } 
   void swap()
   {
    int x,y;
    struct node *temp;
    printf("enter the two elements to swap \n");
    scanf("%d%d",&x,&y);
    if(x  == y)
        return;

    struct node *px=NULL,*p=start;
    while(p->data!=x)
    {
        px=p;
        p=p->next;
    } 
    struct node *py=NULL,*z=start;
    while(z->data!=y)
    {
        py=z;
        z=z->next;
    } 

    if(z == NULL|| p == NULL)
        return;

    if(px!=NULL)
    {
        px->next=z;
    }
    else
    {
        start=z;
    }

    if(py!=NULL)
    {
        py->next=p;
    }
    else
    {
        start=p;
    }
    temp=z->next;
    z->next=p->next;
    p->next=temp;

   }
   void detect()
   {
    struct node *p,*q;
    p=start;
    q=start;
    while(p && q &&q->next)
    {
        p=p->next;
        q=q->next->next;
        if(p == q)
        {
            printf("found loop");
        }
        else
        {
             printf("not found");  
        }
    }
   } 
int main()
{
   
    struct node   *first, *temp,*p;
    int count = 0,item;
    int choice = 1;
 
    while (choice)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data item\n");
        scanf("%d", &item);
        temp->data=item;
        temp->next=NULL;
        if (start == NULL)  
        {
            start=temp;
        }
        else
        {
            p=start;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
                start->next->next->next->next=start;
        }
        printf("continue?");
        scanf("%d",&choice);
    }
    swap();
    display();
   
return 0;
    
}        