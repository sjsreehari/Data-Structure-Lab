#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    struct Node *next;
};

struct Node *head = NULL;

void insertSentence(char *sentence) {
    char *token = strtok(sentence, " ");
    struct Node *prev = NULL;

    while (token != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->word, token);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            prev = head;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
        token = strtok(NULL, " ");
    }
}

void displaySentence() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("No sentence stored!\n");
        return;
    }
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void replaceWord(char *oldWord, char *newWord) {
    struct Node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->word, oldWord) == 0) {
            strcpy(temp->word, newWord);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("Word '%s' not found!\n", oldWord);
}

void main() {
    char sentence[200], oldWord[50], newWord[50];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);
    insertSentence(sentence);
    printf("\nCurrent sentence:\n");
    displaySentence();
    printf("\nEnter the word to be replaced: ");
    scanf("%s", oldWord);
    printf("Enter the new word: ");
    scanf("%s", newWord);
    replaceWord(oldWord, newWord);
    printf("\nEdited sentence:\n");
    displaySentence();
}