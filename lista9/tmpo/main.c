#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char name[MAX_FIELD_SIZE];
    char phone[MAX_FIELD_SIZE];
    char birthday[MAX_FIELD_SIZE];
} Contact;

void loadContacts(Contact contacts[], int* numContacts) {
    FILE* file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char line[MAX_FIELD_SIZE * 3];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token;
        token = strtok(line, ",");
        strcpy(contacts[*numContacts].name, token);
        token = strtok(NULL, ",");
        strcpy(contacts[*numContacts].phone, token);
        token = strtok(NULL, ",");
        strcpy(contacts[*numContacts].birthday, token);
        (*numContacts)++;
    }
    
    fclose(file);
}

void saveContacts(Contact contacts[], int numContacts) {
    FILE* file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].birthday);
    }
    
    fclose(file);
}

void addContact(Contact contacts[], int* numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("Contact book is full.\n");
        return;
    }
    
    Contact newContact;
    
    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';
    
    printf("Enter phone number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';
    
    printf("Enter birthday: ");
    fgets(newContact.birthday, sizeof(newContact.birthday), stdin);
    newContact.birthday[strcspn(newContact.birthday, "\n")] = '\0';
    
    contacts[*numContacts] = newContact;
    (*numContacts)++;
}

void displayContacts(Contact contacts[], int numContacts) {
    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Birthday: %s\n", contacts[i].birthday);
        printf("--------------------\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    
    loadContacts(contacts, &numContacts);
    
    int choice;
    do {
        printf("Contact Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        
        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                saveContacts(contacts, numContacts);
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}
