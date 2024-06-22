#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Reservation {
    int reservationID;
    int duration;
    char guestName[50];
    char roomType[30];
    struct Reservation *next;
} reserve;

typedef struct Reservation *res_next;

res_next createReservation(int, char*, char*, int);
void insertReservation(int, char*, char*, int);
bool isIDTaken(int);
void deleteReservation(int);
void printReservations();
void searchReservation(int);
void calprice(int);

res_next head = NULL;

// Main function with menu
int main() {
    int choice, id, duration;
    char name[50], type[30];
    
    while (1) {
        printf("\nHotel Reservation System\n");
        printf("1. Insert Reservation\n");
        printf("2. Delete Reservation\n");
        printf("3. Search Reservation\n");
        printf("4. Print All Reservations\n");
        printf("5. Exit\n\n");
        printf("Price per night stay: $50.75\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Reservation ID: ");
                scanf("%d", &id);

                // Makes sure ID is not taken.
                while (isIDTaken(id)) { 
                    printf("\nError: Reservation ID %d is already taken. Enter again.\n\n", id);
                    printf("Enter Reservation ID: ");
                    scanf("%d", &id);
                }

                printf("Enter Guest Name: ");
                scanf("%s", name);

                printf("Enter Room Type: ");
                scanf("%s", type);
                
                printf("Enter duration of stay: ");
                scanf("%d", &duration);
                
                calprice(duration);
                insertReservation(id, name, type, duration);
                break; // Add break to prevent falling through to case 2
                
            case 2:
                printf("Enter Reservation ID to delete: ");
                scanf("%d", &id);
                deleteReservation(id);
                break;
            case 3:
                printf("Enter Reservation ID to search: ");
                scanf("%d", &id);
                searchReservation(id);
                break;
            case 4:
                printReservations();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new reservation node
res_next createReservation(int id, char* name, char* type, int duration) {
    res_next newReservation = (res_next) malloc(sizeof(reserve));
    newReservation->reservationID = id;
    strcpy(newReservation->guestName, name);
    strcpy(newReservation->roomType, type);
    newReservation->duration = duration; // Set duration here
    newReservation->next = NULL;
    return newReservation;
}

// Function to check if a reservation ID already exists
bool isIDTaken(int id) {
    res_next temp = head;
    while (temp != NULL) {
        if (temp->reservationID == id) {
            return true; // ID is already taken
        }
        temp = temp->next;
    }
    return false; // ID is available
}

// Function to insert a new reservation
void insertReservation(int id, char* name, char* type, int duration) {
    res_next newReservation = createReservation(id, name, type, duration);
    if (head == NULL) {
        head = newReservation;
    } else {
        res_next temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newReservation;
    }
    printf("Reservation added successfully.\n");
}

// Function to delete a reservation
void deleteReservation(int id) {
    if (head == NULL) {
        printf("No reservations to delete.\n");
        return;
    }
    res_next temp = head; 
    res_next prev = NULL;
    if (temp != NULL && temp->reservationID == id) {
        head = temp->next;
        free(temp);
        printf("Reservation deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->reservationID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Reservation not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Reservation deleted successfully.\n");
}

// Function to search for a reservation
void searchReservation(int id) {
    res_next temp = head;
    while (temp != NULL) {
        if (temp->reservationID == id) {
            printf("\nReservation ID: %d\n", temp->reservationID);
            printf("Guest Name: %s\n", temp->guestName);
            printf("Room Type: %s\n", temp->roomType);
            printf("Duration: %d\n", temp->duration); 
            return;
        }
        temp = temp->next;
    }
    printf("Reservation not found.\n");
}

// Function to print all reservations
void printReservations() {
    res_next temp = head;
    if (temp == NULL) {
        printf("No reservations available.\n");
        return;
    }
    while (temp != NULL) {
        printf("\nReservation ID: %d\n", temp->reservationID);
        printf("Guest Name: %s\n", temp->guestName);
        printf("Room Type: %s\n", temp->roomType);
        printf("Duration of Stay: %d\n", temp->duration);
        printf("\n");
        temp = temp->next;
    }
}

void calprice(int duration) {
    float cost = duration * 50.75;
    printf("\nThe total cost is: $%.2f\n", cost); // Adjusted for proper formatting
}
