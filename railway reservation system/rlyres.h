#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[20];
    char from[20];
    char to[20];
    int fac_fair;
    int sac_fair;
};
typedef struct Train Train;
struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[20];
    char p_class;
    char address[20];
    int age;
    char mob_no[11];
    int ticketno;

};
typedef struct Passenger Passenger;
int enterchoice();
void add_trains();
void view_trains();
int accept_ticket_no();
int book_ticket(Passenger );
int *get_ticket_no(char *);
void view_ticket(int);
void view_all_bookings();
void view_booking(char *);
int cancel_train(char *);
Passenger * get_passenger_details();
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int check_mob_no(char *);
char* accept_train_no();
int check_train_no(char *);
int cancel_ticket(int);
char* accept_mob_no();
void view_all_tickets(char *,int *);







#endif // RLYRES_H_INCLUDED
