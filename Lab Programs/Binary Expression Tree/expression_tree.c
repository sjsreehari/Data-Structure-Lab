#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from postfix
struct Node* buildTree(char postfix[]) {
    top = -1; // reset stack
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {  // operand (single digit)
            push(createNode(c));
        } else {  // operator
            struct Node* node = createNode(c);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop(); // root
}

// Print traversals
void printInfix(struct Node* root) {
    if (root) {
        if (root->left && root->right) printf("(");
        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);
        if (root->left && root->right) printf(")");
    }
}

void printPrefix(struct Node* root) {
    if (root) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void printPostfix(struct Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}

void clearTree(struct Node* root) {
    if (root) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    char postfix[100];
    int choice;

    while (1) {  // infinite loop until exit
        printf("\n--- Binary Expression Tree ---\n");
        printf("1. Create tree (enter postfix)\n");
        printf("2. Print infix expression\n");
        printf("3. Print prefix expression\n");
        printf("4. Print postfix expression\n");
        printf("5. Clear tree\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression (digits & operators): ");
                scanf("%s", postfix);
                clearTree(root); // clear old tree before new
                root = buildTree(postfix);
                printf("Expression tree created.\n");
                break;
            case 2:
                if (root) { printf("Infix: "); printInfix(root); printf("\n"); }
                else printf("Tree not created.\n");
                break;
            case 3:
                if (root) { printf("Prefix: "); printPrefix(root); printf("\n"); }
                else printf("Tree not created.\n");
                break;
            case 4:
                if (root) { printf("Postfix: "); printPostfix(root); printf("\n"); }
                else printf("Tree not created.\n");
                break;
            case 5:
                if (root) { clearTree(root); root = NULL; printf("Tree cleared.\n"); }
                else printf("Tree not created.\n");
                break;
            case 6:
                clearTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
