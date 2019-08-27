#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void push(char item,char s[100],int *t);
char pop(char s[100],int *t);
int precedence(char symbol);
void convert(char infix[100],char postfix[100]);
int main()
{
 char infix[100],postfix[100];
 printf("Enter the infix Expression\n");
gets(infix);
convert(infix,postfix);
printf("postfix expression is \n");
puts(postfix);
return 0;
}
void push(char item,char s[100],int*t)
{
 if(*t==99)
{
 printf("stack overflow\n");
return;
}
else
{
 *t=*t+1;
 s[*t]=item;
}
}
char pop(char s[100],int *t)
{
 char item;
 if(*t==-1)
{
 printf("Stack underflow");
return 'x';
}
else
{
 item=s[*t];
*t=*t-1;
return item;
}
}
int precedence(char symbol)
{
 if(symbol=='^')
{
 return 3;
}
else if(symbol=='*'||symbol=='/')
{
 return 2;
}
else if(symbol=='+'||symbol=='-')
{
 return 1;
}
else 
{ 
 return 0;
}
}
void convert(char infix[100],char postfix[100])
{
 char item,x,stack[100];
int top=-1;
int i=0,j=0;push('c',stack,&top);
strcat(infix,")");
item=infix[i];
while(item!='\0')
{
 if(item=='c')
{
 push(item,stack,&top);
}
else if(isalpha(item)||isdigit(item))
{
 postfix[j]=item;
j++;
}
else if(item==')')
{
 x=pop(stack,&top);
while(x!='c')
{
 postfix[j]=x;
j++;
x=pop(stack,&top);
}
}
else
{
 while(precedence(stack[top]>precedence(item))
 {
  postfix[j]=item;
j++;
pop(stack,stop);
}
push(item,stack,stop);
}
i++;
item=infix[i];
}
postfix[j]='\0';
}
 
 
