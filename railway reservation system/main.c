#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rlyres.h"
#include "conio2.h"
#include <ctype.h>
#include <io.h>

int main()
{
   int choice;
   int x;
   Passenger *ptr;
   add_trains();
   int result;
   int ticket_no;
   char *ptrain_no;
   char *pmob_no;
   int *pticket_no;
  while(1)
   {
       clrscr();
       choice=enterchoice();
       if(choice==9)
       {
           exit(0);
       }
    switch(choice)
       {
       case 1:
           fflush(stdin);
           clrscr();
           view_trains();
           getch();
          break;

       case 2:
           fflush(stdin);
           clrscr();
           ptr=get_passenger_details();

           if(ptr!=NULL)
           {
             x=book_ticket(*ptr);
             if(x==-1)
                printf("\nBooking Failed !!");
             else
             {
                textcolor(GREEN);
                printf("Ticket successfully booked.\n Your ticket no. is %d",x);
             }
           textcolor(WHITE);
           printf("\n Press any key to go back to main menu screen");

           getch();
           }
        break;

       case 3:
           fflush(stdin);
           clrscr();
           ticket_no=accept_ticket_no();
         if(ticket_no!=0)
                view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
          break;

       case 4:
           fflush(stdin);
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
           break;

       case 5:
           fflush(stdin);
           clrscr();
           view_all_bookings();
           textcolor(WHITE);
           printf("\n\nPress any key to go back to the main screen");

           getch();
          break;

       case 6:
           fflush(stdin);
           clrscr();
           ptrain_no=accept_train_no();
           x=check_train_no(ptrain_no);
           if(x==1)
           {
            clrscr();
            view_booking(ptrain_no);
           }
           else
             printf("No details of the ticket found");

             textcolor(WHITE);
             printf("\n Press any key to go back to main menu screen");

             getch();
            break;

       case 7:

            clrscr();
            fflush(stdin);
            ticket_no = accept_ticket_no();
            if(ticket_no!=0)
                {
                    result = cancel_ticket(ticket_no);
                    if(result == 0)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked against ticket no %d",ticket_no);

                    }
                    else if(result == 1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Ticket no %d successfully cancelled!",ticket_no);
                    }
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");

             }

            getch();
            clrscr();
            break;


       case 8:

            clrscr();
            fflush(stdin);
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            {
                result=cancel_train(ptrain_no);
                if(result==0)
                  {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked in train no no %s",ptrain_no);

                    }
                    else
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no %s successfully cancelled!",ptrain_no);
                    }

            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");

            }


            getch();
            clrscr();
            break;


       default:
        textcolor(LIGHTRED);
        printf("Wrong Choice ! Try Again \n");
        getch();
        clrscr();
       }
   }

    return 0;
}
