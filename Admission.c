#include <stdio.h>
struct student
{
    int id;
    int age;
    int marks;
};
int main()
{
    struct student s[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter id,age,marks of student %d\n",i+1);
        scanf("%d%d%d",&s[i].id,&s[i].age,s[i].marks);
        if(s[i].marks>=0&&s[i].marks<100)
        {
            if(int marks>=65)
            printf("eligible for admission");
            else
            printf("ineligible for admission");
        }
        else
        printf("Invalid data");
        
    }return 0;
}
