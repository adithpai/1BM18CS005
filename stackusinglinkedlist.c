
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node *NODE;

NODE getnode();
NODE insertfront(int item, NODE head);
void display(NODE head);
NODE deletefront(NODE head);

int main()
{
	NODE head;
	head = NULL;
	int item,pos,ch,ch1;
	do
	{
		printf("Enter\n1: Insertion \n2: Deletion \n3: Display the contents of the list\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{ 
					printf("Enter the item to be inserted at the front\n");
	 				scanf("%d",&item);
	 				head = insertfront(item,head);
	 				break; 
				}

                        case 2: {
					head = deletefront(head); 
					break;
                                } 
                        
                        case 3: { 
                                    
					printf("\nContents of the linked list are\n");
	 				display(head);
	 				printf("\n");
	 				break; 
				}
			default: printf("\nInvalid Input\n");
		}

                printf("\nEnter any value to continue and 1 to exit\n");
	scanf("%d",&ch1);
	} while(ch1!=1);
	return 0;
}
     
 NODE getnode()
{
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	if(p!=NULL)
	{
		return p;
	}
	else 
	{
		printf("\nMemory could not be allocated\n");
		exit(0);
	}
}


void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		exit(0);
	}
	p = head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}	
}

NODE insertfront(int item, NODE head)
{
	NODE p;
	p=getnode();
	p->data = item;
	p->next = head;
	head = p;
	return head;
}
NODE deletefront(NODE head)
{
	NODE p = head; 
	if (head==NULL)
	{
		printf("\nList is empty\n"); 
		return head;
	}
	printf("The deleted element is %d", p->data);
	head = p->next;
	free(p);
	return head;
}


