#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *link;
};
struct node *head=NULL,*New,*last=NULL;

void create();
void insert_beg();
void insert_end();
void insert_sp();
void delete_beg();
void delete_end();
void delete_sp();
void traverse();

int main()
{
  int ch;
  clrscr();
  printf("\n1.insert at beginning,\n2.insert at end,\n3.insert at specific position,\n4.delete from beginning,\n5.delete from end,\n6.delete from specific position,\n7.traverse,\n8.exit\n");
     while(1)
     {
      printf("enter your choice\t");
       scanf("%d",&ch);
		switch(ch)
		{
		   case 1:  insert_beg();
		   break;
		   case 2:  insert_end();
		   break;
		   case 3:  insert_sp();
		   break;
		   case 4:  delete_beg();
		   break;
		   case 5: delete_end();
		   break;
		   case 6:  delete_sp();
		   break;
		   case 7: traverse();
		   break;
		   case 8:  exit(0);
		   break;
		   default:
		   printf("enter correct choice");

		}
	   }

       }
void create()
{
 int ele;
 New=(struct node*)malloc(sizeof(struct node));
 printf("enter element to insert\n");
 scanf("%d",&ele);
 New->data=ele;
 New->link=NULL;
}

void findlast()
{
 last=head;
 while(last->link!=head)
 {
	last=last->link;
 }
}

void insert_beg()
{
 create();
 if(head==NULL)
 {
 head=New;
 New->link=head;
 }
 else
 {
   findlast();
   New->link=head;
   head=New;
   last->link=head;
 }
}

void delete_beg()
{
  struct node *temp=head;
  if(head==NULL)
   {
     printf("empty\n");
   }
 else
 {
  findlast();
  head=head->link;
    last->link=head;
  printf("deleted element is %d",temp->data);
  free(temp);
  }

}

void insert_end()
{
  create();
  if(head==NULL)
  {
	head=New;
	New->link=head;
  }
  else
  {
  findlast();
  New->link=head;
  last->link=New;
  }
}
void delete_end()
{
   struct node *pre,*temp;
   temp=head;
   if(head==NULL)
   {
     printf("empty list\n");
   }
   else
   {
   while(temp->link!=head)
   {
      pre=temp;
      temp=temp->link;
   }
   pre->link=head;
   printf("deleted element is %d",temp->data);
   free(temp);

   }

}

void traverse()
{
  struct node *temp=head;
  if(head==NULL)
  {
    printf("empty\n");
  }
  else
  {
    while(temp->link!=head)
    {
    printf("%d->",temp->data);
    temp=temp->link;
    }
     printf("%d->",temp->data);
  }


  printf("NULL\n");
}

void insert_sp()
{
int i=1,pos;
struct node *temp;
create();
printf("enter position to insert\n");
scanf("%d",&pos);
temp=head;
while(i<pos-1)
{
temp=temp->link;
i++;
}
New->link=temp->link;
temp->link=New;
}

void delete_sp()
{
  struct node *temp,*pre;
  int pos,i=1;
  printf("enter position to delete element\n");
  scanf("%d",&pos);
  if(head==NULL)
  {
	printf("Null\n");

  }
  else
  {
      temp=head;
      while(i<pos)
      {
	pre=temp;
	temp=temp->link;
	i++;
      }
  }
  pre->link=temp->link;
  free(temp);
}