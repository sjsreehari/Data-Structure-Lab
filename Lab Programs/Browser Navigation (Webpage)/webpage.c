// Question : implement backward and forward navigation of visited webpages in a web browser using doubly linked list operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Define structure for a node
struct Node {
    char url[SIZE];
    struct Node* prev;
    struct Node* next;
};

// Pointers to manage navigation
struct Node* head = NULL;
struct Node* current = NULL;

// Function to visit a new page
void visitPage(char url[]) {
    // allocate size of node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    newNode->prev = NULL;

    // If no page visited yet
    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        // Remove forward history
        if (current->next != NULL) {
            struct Node* temp = current->next;
            while (temp != NULL) {
                struct Node* toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }
            current->next = NULL;
        }

        // Link the new node
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    printf("Visited: %s\n", url);
}

// Function to go back
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
        return;
    }
    current = current->prev;
    printf("Moved back to: %s\n", current->url);
}

// Function to go forward
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page.\n");
        return;
    }
    current = current->next;
    printf("Moved forward to: %s\n", current->url);
}

// Function to display current page
void displayCurrentPage() {
    if (current == NULL)
        printf("No page visited yet.\n");
    else
        printf("Current Page: %s\n", current->url);
}

// Main function
int main() {
    int choice;
    char url[SIZE];

    while (1) {
        printf("\n--- Browser Navigation Menu ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, SIZE, stdin);
                url[strcspn(url, "\n")] = '\0'; // remove newline
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
