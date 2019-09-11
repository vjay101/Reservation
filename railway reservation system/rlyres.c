#include <stdio.h>
#include "conio2.h"
#include <stdlib.h>
#include "rlyres.h"
#include <ctype.h>
#include <string.h>
#include <io.h>

int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(40,1);
    printf("RAILWAY RESERVATION SYSTEM\n");

    for(i=0;i<=119;i++)
    {
        printf("-");
    }
        printf("\n Select an option :\n");
        printf(" 1- View Trains.\n 2- Book Ticket.\n 3- View Ticket.\n");
        printf(" 4- Search Ticket No.\n 5- View All Bookings.\n 6- View Train Bookings.\n");
        printf(" 7- Cancel Ticket.\n 8- Cancel Train.\n 9- Quit.\n\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        return(choice);

}
void add_trains()
{
    FILE *fp;
    fp=fopen("F:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
        {"123","BPL","KHND",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360}
       };
    fp=fopen("F:\\myproject\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(Train),1,fp);
    fclose(fp);
    }
    else
    {
        printf("File already present");
        fclose(fp);
    }
}
void view_trains()
{
    clrscr();
    int i;
    Train trn;
    FILE *fp;
    fp=fopen("F:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("SORRY !! Record not found.");
    }
    else
    {
    textcolor(YELLOW);
    printf("\n TRAIN NO.");
    gotoxy(40,2);
    printf("FROM");
    gotoxy(60,2);
    printf("TO");
    gotoxy(80,2);
    printf("FIRST AC FAIR");
    gotoxy(100,2);
    printf("SECOND AC FAIR\n");
    for(i=0;i<=119;i++)
      {
       printf("-");
      }
    fread(&trn,sizeof(Train),1,fp);
    for(i=5;feof(fp)==0;i++)
     {
       gotoxy(1,i);
       printf(" %s",trn.train_no);
       gotoxy(40,i);
       printf("%s",trn.from);
       gotoxy(60,i);
       printf("%s",trn.to);
       gotoxy(80,i);
       printf("%d",trn.fac_fair);
       gotoxy(100,i);
       printf("%d",trn.sac_fair);
       fread(&trn,sizeof(Train),1,fp);
    }
    fclose(fp);
    textcolor(WHITE);
    printf("\n\n\n\n  Press any key to go back to main screen");
    }
}

/*int check_train_no(char *trainno)
{
    FILE *fp;
    fp=fopen("f:\\myproject\\alltrains.dat","rb");
    Train t;
    while(fread(&t,sizeof(t),1,fp)==1)
    {
      if(strcmp(t.train_no,trainno)==0)
        {
          fclose(fp);
          return 1;
        }
    }
 fclose(fp);
 return 0;
}*/

Passenger *get_passenger_details()
{

            clrscr();
        gotoxy(60,1);
            textcolor(LIGHTGREEN);
            printf("Press 0 to exit");
        gotoxy(1,1);
            textcolor(YELLOW);
            static Passenger psn;
            printf("Enter passenger name:");
            fflush(stdin);
            fgets(psn.p_name,20,stdin);
            char *pos;
            pos=strchr(psn.p_name,'\n');
            *pos='\0';
            if(strcmp(psn.p_name,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }

       gotoxy(1,2);
            int valid;
            printf("Enter gender(M/F):");
         do
         {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.gender);
             if(psn.gender == '0')
             {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
             }
            if(psn.gender!='M' && psn.gender!='F')
             {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("Error! Gender should be M or F (in uppercase)");
             valid=0;
             getch();
             gotoxy(19,2);
             printf(" \b");
             textcolor(YELLOW);
             }
         }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");


      gotoxy(1,3);
            printf("Enter train number:");


            do
            {
            fflush(stdin);
            scanf("%s",psn.train_no);
            if(strcmp(psn.train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            valid=check_train_no(psn.train_no);
            if(valid==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);

            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);

            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");

        gotoxy(1,4);
            printf("Enter travelling class(First AC-F,Second AC-S):");
            do
            {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.p_class);
            if(psn.p_class=='0')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.p_class!='F' && psn.p_class!='S')
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Travelling class should be F or S (in uppercase)");
            valid=0;
            getch();
            gotoxy(48,4);
            printf(" \b");
            textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");


        gotoxy(1,5);
            printf("Enter address:");
            fflush(stdin);
            fgets(psn.address,20,stdin);
            pos=strchr(psn.address,'\n');
            *pos='\0';
            if(strcmp(psn.address,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }

        gotoxy(1,6);
            printf("Enter age:");
           do
           {
            valid=1;
            fflush(stdin);
            scanf("%d",&psn.age);
            if(psn.age==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.age<=0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Age should be positive");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
            }
          }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");


        gotoxy(1,7);
            printf("Enter mobile number:");
            do
            {
            fflush(stdin);
            fgets(psn.mob_no,12,stdin);
            pos=strchr(psn.mob_no,'\n');
            if(pos!=NULL)
             *pos='\0';
            if(strcmp(psn.mob_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            valid = check_mob_no(psn.mob_no);
            if(valid == 0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,7);
            printf("\t\t\t\t\t\t");
            gotoxy(21,7);
            textcolor(YELLOW);
            }
            }while(valid == 0);
            return &psn;

}

 int get_booked_ticket_count(char *train_no,char tc)
{
     int count1 = 0;

    fflush(stdin);
    FILE *fp = fopen("F:\\myproject\\allbookings.dat","rb");
    if(fp == NULL)
        return 0;

    Passenger pr;

     while(fread(&pr,sizeof(pr),1,fp)==1)
    {

     if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
     {
         count1++;
     }
    }
    fclose(fp);
    return count1;
}

int last_ticket_no()
{

    Passenger pr;
    FILE *fp = fopen("F:\\myproject\\allbookings.dat","rb");
    if(fp == NULL)
        {
            return 0;
        }


     if(fread(&pr,sizeof(pr),1,fp)!=1)
        return 0;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}



int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
        {
            if(isdigit(*p_mob) == 0)
                return 0;
                p_mob++;
        }
return 1;
}

int book_ticket(Passenger p)
{

    int x,y;
    x = get_booked_ticket_count(p.train_no,p.p_class);
    if(x == 2)
    {
        textcolor(LIGHTRED);
        printf("All seats are full in %s in %c class !",p.train_no,p.p_class);
        return -1;

    }

    y = last_ticket_no();
    y = y+1;
    p.ticketno=y;
    FILE *fp;
    fp = fopen("F:\\myproject\\allbookings.dat","ab");
    if(fp == NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(Passenger),1,fp);
    fclose(fp);
    return y;
}

void view_ticket(int tno)
{
    FILE *fp;
    fp = fopen("F:\\myproject\\allbookings.dat","rb");

    if(fp == NULL)
    {
        textcolor(LIGHTRED);
        printf("No booking done yet");
        textcolor(YELLOW);
        return;
    }
    Passenger pr;
    int found = 0;

   while(fread(&pr,sizeof(pr),1,fp)== 1)
    {
      if(pr.ticketno == tno)
      {
        printf("NAME : %s\nGENDER : %c\nTRAIN NO. : %s\nCLASS : %c",pr.p_name,pr.gender,pr.train_no,pr.p_class);
        printf("\nADDRESS : %s\nAGE : %d\nMOBILE NO. : %s\nTICKET NO. : %d",pr.address,pr.age,pr.mob_no,pr.ticketno);


        FILE *fb;
        fb = fopen("F:\\myproject\\alltrains.dat","rb");
        if(fb == NULL)
            printf("Sorry");
        Train tr;
      while(fread(&tr,sizeof(tr),1,fb) == 1)
        {
          if(strcmp(tr.train_no,pr.train_no) == 0)
            {
             printf("\nFROM : %s\nTO : %s",tr.from,tr.to);

             if(pr.p_class == 'F')
                printf("\nFARE : %d\n",tr.fac_fair);

             else
                printf("\nFARE : %d\n",tr.sac_fair);
            }

        }
      fclose(fb);
      found++;
      }
   }
  fclose(fp);

    if(found == 0)
    {
        int x;
        textcolor(LIGHTRED);
        printf("Invalid ticket no.Enter a valid ticket no.");
        getch();
        textcolor(YELLOW);
        clrscr();
        x = accept_ticket_no();
        view_ticket(x);
        return;
    }
}

int accept_ticket_no()
{
     int ticketno,valid;

      printf("Enter ticket no.: ");
        do
        {
            valid = 1;
            fflush(stdin);

            scanf("%d",&ticketno);
            if(ticketno <= 0)
            {
             textcolor(LIGHTRED);
             gotoxy(1,25);
             printf("Error! Ticket no. should be positive");
             valid=0;
             getch();
             gotoxy(1,25);
             printf("\t\t\t\t\t\t\t");
             textcolor(YELLOW);
             gotoxy(1,2);
            }
        }while(valid == 0);
            return ticketno;
}


int cancel_ticket(int ticket_no)
{
  FILE *fp1 = fopen("F:\\myproject\\allbookings.dat","rb+");
  if(fp1 == NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2 = fopen("F:\\myproject\\temp.dat","wb+");
  Passenger pr;
  int found = 0;
  while(fread(&pr,sizeof(pr),1,fp1) == 1)
    {
      if(pr.ticketno != ticket_no)
      {
          fwrite(&pr,sizeof(pr),1,fp2);

      }

      else
      {
          found = 1 ;
      }
    }
    fclose(fp2);
    fclose(fp1);

    if(found == 0)
    {
        remove("F:\\myproject\\temp.dat");

    }
    else if(found >= 1)
    {
        remove("F:\\myproject\\allbookings.dat");
        rename("F:\\myproject\\temp.dat","F:\\myproject\\allbookings.dat");
    }

fflush(stdin);
 return found;
}


char * accept_train_no()
{
static char train_no[10];
int valid;
printf("Enter train number:");
            do
            {
            fflush(stdin);
            scanf("%s",train_no);
            if(strcmp(train_no,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Cancelling Input. . .!");
                textcolor(YELLOW);
                return NULL;
            }
            valid = check_train_no(train_no);
            if(valid == 0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);

            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);

            }
            }while(valid == 0);
clrscr();
return train_no;
}

int check_train_no(char *trainno)
{
    FILE *fp = fopen("F:\\myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
      if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }

    }
fclose(fp);
return 0;
}

int cancel_train(char *ptrain_no)
{
  FILE *fp1 = fopen("F:\\myproject\\allbookings.dat","rb+");
  if(fp1 == NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
  FILE *fp2=fopen("F:\\myproject\\temp.dat","wb+");
  Passenger pr;
  int found = 0;
  while(fread(&pr,sizeof(pr),1,fp1) == 1)
    {
      if(strcmp(pr.train_no,ptrain_no) != 0)
      {
          fwrite(&pr,sizeof(pr),1,fp2);
      }
      else
      {
          found = 1;
      }
    }
    fclose(fp2);
    fclose(fp1);

    if(found == 0)
    {
        remove("F:\\myproject\\temp.dat");
    }
    else
    {
        remove("F:\\myproject\\allbookings.dat");
        rename("F:\\myproject\\temp.dat","F:\\myproject\\allbookings.dat");
    }

return found;
}

char* accept_mob_no()
{
static char mob_no[11];
char *pos;
int valid;
printf("Enter mobile number:");
do
{
fflush(stdin);
fgets(mob_no,11,stdin);
pos=strchr(mob_no,'\n');
if(pos!=NULL)
   *pos='\0';
if(strcmp(mob_no,"0") == 0)
{
  textcolor(LIGHTRED);
  gotoxy(1,25);
  printf("\t\t\t\t\t\t\t");
  gotoxy(1,25);
  printf("Cancelling Input. . .!");
  getch();
  textcolor(YELLOW);
  return NULL;
}
valid=check_mob_no(mob_no);
if(valid == 0)
  {
   textcolor(LIGHTRED);
   gotoxy(1,25);
   printf("Error! Invalid Mobile No");
   getch();
   gotoxy(21,1);
   printf("\t\t\t\t\t\t");
   gotoxy(21,1);
   textcolor(YELLOW);
  }
 }while(valid == 0);
clrscr();
return mob_no;
}

int* get_ticket_no(char *p_mob_no)
{
   int count = 0;
   FILE *fp = fopen("F:\\myproject\\allbookings.dat","rb");
   if(fp == NULL)
    {
        return NULL;
    }
   Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p = (int*)malloc((count+1)*sizeof(int));
    int i = 0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i) = pr.ticketno;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}

void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no == NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("---------");
    for(i = 0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
getch();
}

void view_all_bookings()
{
    clrscr();
    int i;
    FILE *fp;
    fp = fopen("F:\\myproject\\allbookings.dat","rb");
    if(fp == NULL)
    {
        printf("No bookings done yet !");
        return;
    }
    gotoxy(1,1);
    printf("TRAIN NO.");
    gotoxy(20,1);
    printf("TICKET NO.");
    gotoxy(40,1);
    printf("CLASS");
    gotoxy(60,1);
    printf("NAME");
    gotoxy(90,1);
    printf("MOBILE NO.\n");
    for(i = 0;i<=119;i++)
    printf("-");

    Passenger pr;
    i = 3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        gotoxy(1,i);
        printf("%s",pr.train_no);
        gotoxy(20,i);
        printf("%d",pr.ticketno);
        gotoxy(40,i);
        printf("%c",pr.p_class);
        gotoxy(60,i);
        printf("%s",pr.p_name);
        gotoxy(90,i);
        printf("%s\n",pr.mob_no);
        i++;

    }
   fclose(fp);
}


void view_booking(char * tr)
{
    int i = 4,j;
  FILE *fp;
  fp = fopen("F:\\myproject\\allbookings.dat","rb");
  if(fp == NULL)
  {
     printf("No bookings done yet !");
     return;
  }

               gotoxy(1,1);
               printf("TICKET NO.");
               gotoxy(20,1);
               printf("CLASS");
               gotoxy(40,1);
               printf("NAME");
               gotoxy(60,1);
               printf("GENDER");
               gotoxy(80,1);
               printf("AGE");
               gotoxy(90,1);
               printf("MOBILE NO.\n");


           for(j=1;j<=119;j++)
            printf("-");


  Passenger pr;

  while(fread(&pr,sizeof(pr),1,fp)==1)
  {
      if(strcmp(pr.train_no,tr)==0)
      {

          gotoxy(1,i);
          printf("%d",pr.ticketno);
          gotoxy(20,i);
          printf("%c",pr.p_class);
          gotoxy(40,i);
          printf("%s",pr.p_name);
          gotoxy(60,i);
          printf("%c",pr.gender);
          gotoxy(80,i);
          printf("%d",pr.age);
          gotoxy(90,i);
          printf("%s",pr.mob_no);

          printf("\n");
          i++;

      }

    }

  if((i-4)==0)
  {
    printf("No details of the train no. %s found",tr);
  }
  fclose(fp);
}










