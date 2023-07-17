#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to represent an employee/student record
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
    char contact[20];
} Record;

Record records[MAX_RECORDS];
int numRecords = 0;

// Function to add a new record
void addRecord() {
    Record newRecord;

    printf("Enter name: ");
    fgets(newRecord.name, sizeof(newRecord.name), stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = '\0'; // Remove newline character

    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    getchar(); // Consume the newline character

    printf("Enter address: ");
    fgets(newRecord.address, sizeof(newRecord.address), stdin);
    newRecord.address[strcspn(newRecord.address, "\n")] = '\0'; // Remove newline character

    printf("Enter contact information: ");
    fgets(newRecord.contact, sizeof(newRecord.contact), stdin);
    newRecord.contact[strcspn(newRecord.contact, "\n")] = '\0'; // Remove newline character

    newRecord.id = numRecords + 1; // Generate unique ID

    records[numRecords++] = newRecord;

    printf("Record added successfully.\n");
}

// Function to search for a record by ID or name
void searchRecord() {
    int searchId;
    char searchName[50];

    printf("Enter ID or name to search: ");
    scanf("%d", &searchId);
    getchar(); // Consume the newline character

    printf("Search results:\n");

    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == searchId || strcmp(records[i].name, searchName) == 0) {
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            printf("Contact: %s\n", records[i].contact);
            printf("-----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No matching record found.\n");
    }
}

// Function to update a record
void updateRecord() {
    int updateId;
    char updateName[50];

    printf("Enter ID or name to update: ");
    scanf("%d", &updateId);
    getchar(); // Consume the newline character

    printf("Update results:\n");

    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == updateId || strcmp(records[i].name, updateName) == 0) {
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            printf("Contact: %s\n", records[i].contact);
            printf("-----------------------\n");

            printf("Enter new name: ");
            fgets(records[i].name, sizeof(records[i].name), stdin);
            records[i].name[strcspn(records[i].name, "\n")] = '\0'; // Remove newline character

            printf("Enter new age: ");
            scanf("%d", &records[i].age);
            getchar(); // Consume the newline character

            printf("Enter new address: ");
            fgets(records[i].address, sizeof(records[i].address), stdin);
            records[i].address[strcspn(records[i].address, "\n")] = '\0'; // Remove newline character

            printf("Enter new contact information: ");
            fgets(records[i].contact, sizeof(records[i].contact), stdin);
            records[i].contact[strcspn(records[i].contact, "\n")] = '\0'; // Remove newline character

            printf("Record updated successfully.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No matching record found.\n");
    }
}

// Function to delete a record
void deleteRecord() {
    int deleteId;
    char deleteName[50];

    printf("Enter ID or name to delete: ");
    scanf("%d", &deleteId);
    getchar(); // Consume the newline character

    printf("Delete results:\n");

    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == deleteId || strcmp(records[i].name, deleteName) == 0) {
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            printf("Contact: %s\n", records[i].contact);
            printf("-----------------------\n");

            printf("Are you sure you want to delete this record? (y/n): ");
            char confirm;
            scanf("%c", &confirm);
            getchar(); // Consume the newline character

            if (confirm == 'y' || confirm == 'Y') {
                // Shift records after the deleted record to fill the gap
                for (int j = i; j < numRecords - 1; j++) {
                    records[j] = records[j + 1];
                }

                numRecords--;

                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion canceled.\n");
            }

            found = 1;
        }
    }

    if (!found) {
        printf("No matching record found.\n");
    }
}

// Function to display all records
void displayRecords() {
    printf("Employee/Student Records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Address: %s\n", records[i].address);
        printf("Contact: %s\n", records[i].contact);
        printf("-----------------------\n");
    }
}

// Function to display the menu and handle user choices
void displayMenu() {
    int choice;

    do {
        printf("\nEmployee/Student Record Management\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Display all records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                displayRecords();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    displayMenu();
    return 0;
}

