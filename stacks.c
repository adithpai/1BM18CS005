#include<stdio.h>
#include<stdlib.h>
 

 
int top=-1,stack[5];
void push();
void pop();
void display();
 
void main()
{
	int ch;
	
	while(1)
	{
		
		printf("1.Push 2.Pop 3.Display 4.Exit");
		printf("\nEnter your choice(1-4):");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			
			default: printf("\ninvalid");
		}
	}
}
 
void push()
{
	int ele;
	
	if(top==5-1)
	{
		printf("\nStack is full");
	}
	else
	{
		printf("\nEnter element to push:");
		scanf("%d",&ele);
		top=top+1;
		stack[top]=ele;
	}
}
 
void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nDeleted element is %d",stack[top]);
		top=top-1;
	}
}
 
void display()
{
	int i;
	
	if(top==-1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nStack is=");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}