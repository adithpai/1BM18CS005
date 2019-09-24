#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* Node;
Node getnode()
{
    Node p;
    p=(Node)malloc(sizeof(struct node));
}
Node insertfront(int e,Node head)
{
    Node p;
    p=getnode();
    p->data=e;
    p->next=head;
    head=p;
    return head;
}
void insertend(Node head,int item)
{
    Node p,q;
    q=getnode();
    q->data=item;
    p=head;
    while(p->next!=NULL)
    {
       p=p->next;
       }
    p->next=q;
    q->next=NULL;
}
void show(Node head)
{
    Node p=head;
	if(head == NULL)
	{
		printf("List is empty \n");
		exit(0);
	}
	p = head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
Node insert(Node head,int e,int pos)
{
    int c=1;
    Node p,q,r;
    q=getnode();
    q->data=e;
    if(head==NULL)
    {
       if(pos==1)
       return q;
    else
    {
       printf("Inalid Position \n");
       return head;
     }
    }
    if(pos==1)
    {
       q->next=head;
       head=q;
       return head;
     }
    else{
         r=head;
         while(r!=NULL && c!=pos)
         {
            p=r;
            r=r->next;
            c++;
         }
        if(c==pos)
        {
          p->next=q;
          q->next=r;
          return head;
        }
        else{
             printf("Invalid Position\n");
             return head;
             }
         }  
         }  
Node insertval(Node head,int val,int e)
{
    Node p,q,r;
    int f,c=0;
    q=getnode();
    p=head;
    q->data=e;
    if(p->data==val)
    {
        q->next=head;
        head=q;
        return head;
    }
    while(p!=NULL)
    {
        if(p->data==val)
        {
            f=1;
            break;
        }
        r=p;
        p=p->next;
    }
    if(f==1)
    {
        r->next=q;
        q->next=p;
        return head;
    }
    else
    {
    printf("Value not present");
    return head;
    }
 }
int main()
{
    Node head;
    head=NULL;
    int ch,ch1,e,p;
    do{
        printf("Enter your choice\n1 to insert node at front\n2 to insert node at end\n3 to insert node at any position\n4 to display\n");
 scanf("%d",&ch); 
 switch(ch)
 {
 case 1:
 
 printf("Enter element to be inserted \n");
 scanf("%d",&e);
 head=insertfront(e,head);
 break;
 case 2:
 
 printf("Enter element to be inserted\n");
 scanf("%d",&e);
 insertend(head,e);
 break;
 case 3:
 
 printf("Enter element to be inserted and position\n");
 scanf("%d%d",&e,&p);
 head=insert(head,e,p);
 break;
 case 4:
 show(head);
 break;
 }
 printf("Enter 1 to continue and 0 to exit\n");
 scanf("%d",&ch1);
 }while(ch1!=0);
 return 0;
}

