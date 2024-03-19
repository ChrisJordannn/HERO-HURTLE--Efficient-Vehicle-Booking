
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void delay(int n)
{
  int i,c,d;
  n=n/1000;
  for(i=0;i<n;i++)
  {
  for(c=0;c<=10000;c++)
    for(d=0;d<=1000;d++);
  }
}

typedef struct Rider
{
  char Name[20];
  int Age, Rating, Distance_travelled, 
  Number_of_rides, phone_number, aadhar;
  struct Rider *link;
}Rider_t;

typedef struct Head
{
  int total_number;
  Rider_t *head;
}List_t;

List_t* List_initilize(List_t *list)
{
  list->head=NULL;
  list->total_number=0;
  return list;
}
void Add_Rider(List_t *list)
{
    Rider_t *NewRider = NULL;
    char Name[20];
    int Age = 0;
    int phone_number = 0;
    int aadhar = 0;
    NewRider = (Rider_t *)malloc(sizeof(Rider_t));
    if (NewRider == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nENTER THE NAME OF THE RIDER:");
    scanf("%s", &Name);
    strcpy(NewRider->Name, Name);
    printf("\nENTER THE AGE OF THE RIDER:");
    scanf("%d", &Age);
    printf("\nENTER THE PHONE NUMBER OF THE RIDER:");
    scanf("%d", &phone_number);
    printf("\nENTER THE AADHAR OF THE RIDER:");
    scanf("%d", &aadhar);
    NewRider->Age = Age;
    NewRider->phone_number = phone_number;
    NewRider->aadhar = aadhar;
    NewRider->Rating = 0;
    NewRider->Number_of_rides = 0;
    NewRider->Distance_travelled = 0;
    NewRider->link = NULL;

    if (list->head == NULL) {
        list->head = NewRider;
    } else {
        Rider_t *temp = list->head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = NewRider;
    }
    
    list->total_number++;
}

void Display_Rider(List_t *list)
{
  if(list==NULL)
  {
    printf("\nTHERE ARE NO RIDERS\n\n\n");
    getch();
  }
  else
  {
    int count=1;
    Rider_t *temp;
    temp=list->head;
    while(temp!=NULL)
    {
      printf("\nNAME OF THE RIDER IS : %s\n",temp->Name);
      printf("AGE OF THE RIDER IS :%d\n",temp->Age);
      printf("PHONE NUMBER OF THE RIDER IS :%d\n",temp->phone_number);
      printf("AADHAR OF THE RIDER IS :%d\n",temp->aadhar);
      printf("RATING OF THE RIDER IS :%d\n",temp->Rating);
      printf("NUMBER OF RIDES BY THE RIDER IS :%d\n",temp->Number_of_rides);
      printf("DISTANCE TRAVELLED BY THE RIDER IS :%d\n",temp->Distance_travelled);
      printf("THE POSITION OF THIS IS %d\n___________\n\n\n",count);
      getch();
      count+=1;
      temp=temp->link;
    }
  }
}
void Remove_Rider(List_t *list)
{
  if(list->head==NULL)
  {
    printf("\nTHERE ARE NO RIDERS TO REMOVE");
  }
  else if(list->head->link==NULL)
  {
    printf("\nTHE LAST RIDER");
    list->head=NULL;
    list->total_number=0;
  }
  else
  {
    Rider_t *temp=list->head;
    Rider_t *prev=NULL;
    while(temp->link!=NULL)
    {
      prev=temp;
      temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
    list->total_number-=1;
  }
}

void Server_function(List_t *list)
{
  int choice1=0;
  printf("ENTER YOUR CHOICE\n 1-ADD A RIDER\n 2-REMOVE A RIDER \n 3-DISPLAY THE RIDERS AND THEIR PERFORMANCE \n 4-Exit\n CHOICE:");
  scanf("%d",&choice1);
  switch(choice1)
  {
    case 1:Add_Rider(list);
	  break;
    case 2:Remove_Rider(list);
	  break;
    case 3:Display_Rider(list);
	  break;
    default:printf("\nNO MORE OPERATIONS");
	    break;
  }
}

void Choose_Rider(List_t *list)
{
  Display_Rider(list);
  if(list->head==NULL)
  {
    printf("\nTHERE ARE NO RIDERS TO CHOOSE\n\n\n");
  }
  else if(list->head->link==NULL)
  {
    Rider_t *Rider=list->head;
    int i;
    int journey=0;
    int distance=0;
    int rating=0;
    printf("\nTHERE IS ONLY ONE RIDER TO CHOOSE SO YOU HAVE TO CHOOSE HIM\n");
    printf("ENTER THE DISTANCE TO BE TRAVELLED :\n");
    scanf("%d",&distance);
    printf("THE RIDER IS ON HIS WAY\n");
    for(i=0;i<10;i++)
    {
      printf("#");
      delay(1000);
    }
    printf("THE RIDER HAS SUCCESSFULLY REACHED YOUR LOCATION\n");
    printf("DO YOU WANT TO START THE JOURNEY?\n1-YES\n0-NO");
    scanf("%d",&journey);
    if(journey==0)
      {
        printf("\nSORRY TO HEAR THIS,HAVE A GOOD DAY\nNOTE YOU WILL BE FINED FOR CANCELLING THE RIDE ON YOUR NEXT RIDE");
        return;
      }
    else
      {
        int i;
        int expense=13;
        int totalcost=expense*distance;
        printf("\nTHE COST OF THE RIDE FOR EACH KM IS %d",expense);
        printf("\nYOUR JOURNEY HAS STARTED");
        for(i=0;i<100;i++)
        {
          printf("#");
          delay(1000);
        }
          printf("\n");
          printf("\nYOUR JOURNEY HAS FINISHED");
          printf("\nTHE COST OF THE RIDE IS %d",totalcost);
          Rider->Distance_travelled+=distance;
          Rider->Number_of_rides+=1;
          printf("\nENTER THE RATING OF THE RIDE:");
          scanf("%d",&rating);
          Rider->Rating=((Rider->Rating*((Rider->Number_of_rides)-1)+rating)/Rider->Number_of_rides);
      }
  }
    else
      {
        int journey=0;
        int distance=0;
        int rating=0,i;
        Rider_t *Rider=list->head;
        int pos=0;
        printf("ENTER THE POSITION OF THE RIDER YOU WANT TO CHOOSE");
        scanf("%d",&pos);
        if(pos>list->total_number)
        {
          printf("SORRY YOU HAVE CHOOSEN AN INVALID POSITION\n");
          return;
        }
        for(i=1;i<pos;i++)
        {
          Rider=Rider->link;
        }
        printf("\n\n\n\nTHE RIDER NAME IS %s\n",Rider->Name);
        printf("ENTER THE DISTANCE TO BE TRAVLLED:\n");
        scanf("%d",&distance);
        printf("THE RIDER IS ON HIS WAY\n");
        delay(5000);
        printf("THE RIDER HAS SUCCESSFULLY REACHED YOUR LOCATION\n");
        printf("DO YOU WANT TO START THE JOURNEY?\n1-YES\n0-NO\n");
        scanf("%d",&journey);
        if(journey==0)
          {
            printf("\nSORRY TO HEAR THIS,HAVE A GOOD DAY\nNOTE YOU WILL BE FINED FOR CANCELLING THE RIDE ON YOUR NEXT RIDE");
            return;
          }
        else
          {
            int i;
            int expense=15;
            int totalcost=expense*distance;
            printf("\nTHE COST OF THE RIDE FOR EACH KM IS %d",expense);
            printf("\nYOUR JOURNEY HAS STARTED");
            for(i=0;i<100;i++)
            {
              printf("#");
              delay(1000);
            }
            printf("\n");
            printf("\nYOUR JOURNEY HAS FINISHED");
            printf("\nTHE COST OF THE RIDE IS %d",totalcost);
            Rider->Distance_travelled+=distance;
            Rider->Number_of_rides+=1;
            printf("\nENTER THE RATING OF THE RIDE");
            scanf("%d",&rating);
            Rider->Rating=((Rider->Rating*((Rider->Number_of_rides)-1)+rating)/Rider->Number_of_rides);
          }
      }
}

void Client_function(List_t *list)
{
  int choice1=0;
  printf("ENTER YOUR CHOICE\n 1-DISPLAY THE RIDERS\n 2-CHOOSE A RIDER\n 3-Exit\n CHOICE:");
  scanf("%d",&choice1);
  switch(choice1)
  {
    case 1:Display_Rider(list);
	  break;
    case 2:Choose_Rider(list);
	  break;
    default:printf("\nSORRY TO HEAR THIS! HOPE YOU VISIT US AGAIN");
	    return;
  }
}
void main()
{
  int choice=0;
  int statement=0;
  List_t *List=NULL;
  List=(List_t*)malloc(sizeof(List_t*));
  List=List_initilize(List);
  while(1)
  {
    choice=0;
    printf("\nARE YOU A CLIENT OR SERVER\n1-CLIENT\n2-SERVER\n3-EXIT THE PROGRAM\n");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:Client_function(List);
	     break;
      case 2:Server_function(List);
	     break;
      default:printf("\nINVALID STATEMENT,EXITING THE PROGRAM BYE BYE!");
	      statement=1;
	      break;
     }
    if(statement==1)
    {
      break;
    }
  }
}
