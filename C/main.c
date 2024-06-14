#include <stdio.h>

void Insert_Reservation ();
void Delete_Reservation ();
void Search_Reservation ();
void Create_Reservation ();

struct Reservation
{
    int reservationID;
    char guestname[50];
    char roomtype[50];
    struct Reservation *next
};

typedef struct Reservation nodeptr;


int main(void) 
{
   
}