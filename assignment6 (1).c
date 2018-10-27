#include<stdio.h>
#define MAX 50
struct queue{
char id[50]
}q[50];

int h=-1,t=-1;
void enqueue();
void dequeue();
void display();
main()
{

	int choice;
	char ans='y';
	printf("1) Airplane lands.\n");
	printf("2) Airplane takes off\n");
	printf("3) Display\n");
	printf("4) Exit\n\n");
	while(ans!='n'&&ans!='N')
	{

		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return;
			default:
				printf("Enter the valid choice.");
				break;
		}
		printf("\nDo you want to continue.? ");
		scanf("%c",&ans);
		scanf("%c",&ans);
	}
}



void enqueue()
{
	if(t==MAX-1)
	t=0;
	else
	t+=1;
	if(h==t)
	{
		printf("Airport is full");
		return;
	}
	printf("\nEnter the ID of plane:");
	scanf("%s",q[t].id);
	if(h==-1)
	h=0;

}


void dequeue()
{
	if(t==-1)
	{		
		printf("\nNo such plan in Airport which can do take off.\n");
		return;
	}
	else
	{
		printf("The plan with ID %s departured.",q[h].id);
	}
	if(h==t)
	{
		h=-1;
		t=-1;
		return;
	}
	else if(h==MAX-1)
	h=0;
	else
	h+=1;
}	


void display()
{
   	int i;
	if(h==-1)
	printf("Airport is Empty.");
	else
	{	
		for(i=h;i!=t+1;i++)
		{
			printf("%s\n",q[i].id);
			if(i==MAX-1)
			i=-1;
		}
	}
}





