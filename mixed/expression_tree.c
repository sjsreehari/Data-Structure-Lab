// Sulaika
// Roll No : 60
// expression tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data[50];
    struct Node *left, *right;
};

struct Node* stack[100];
int top = -1;

void push(struct Node* n) { stack[++top] = n; }
struct Node* pop() { return stack[top--]; }

struct Node* newNode(char *tok) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    strcpy(n->data, tok);
    n->left = n->right = NULL;
    return n;
}

void inorder(struct Node* root) {
    if (root) {
        if (root->left && root->right) printf("( ");
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
        if (root->left && root->right) printf(") ");
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->data);
    }
}

int height(struct Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}


// Fill a matrix representing the tree, for pyramid-style printing
void fillMatrix(struct Node* node, char matrix[][128], int row, int col, int tree_height) {
    if (!node) return;
    int len = strlen(node->data);
    for (int k = 0; k < len; k++)
        matrix[row][col + k] = node->data[k];
    int offset = 1 << (tree_height - row - 1); // 2^(tree_height-row-1)
    if (node->left)
        fillMatrix(node->left, matrix, row+1, col - offset, tree_height);
    if (node->right)
        fillMatrix(node->right, matrix, row+1, col + offset, tree_height);
}

// Print tree as a pyramid
void printPyramidTree(struct Node* root) {
    int h = height(root);
    int rows = h;
    int cols = (1 << h) * 2;
    char matrix[32][128];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = ' ';
    fillMatrix(root, matrix, 0, cols/2, h);
    for (int i = 0; i < rows; i++) {
        int last_char = cols - 1;
        while (last_char >= 0 && matrix[i][last_char] == ' ') last_char--;
        for (int j = 0; j <= last_char; j++)
            putchar(matrix[i][j]);
        putchar('\n');
    }
}

int main() {
    struct Node* root = NULL;
    char line[500];
    printf("Enter postfix expression (space separated):\n");
    scanf(" %[^\n]", line);

    char* token = strtok(line, " ");
    while (token) {
        if (isdigit(token[0]) || isalpha(token[0])) push(newNode(token));
        else {
            struct Node* n = newNode(token);
            n->right = pop();
            n->left = pop();
            push(n);
        }
        token = strtok(NULL, " ");
    }

    root = pop();

    printf("\nExpression Tree :\n");
    printPyramidTree(root);

    printf("\nInfix Expression : ");
    inorder(root);
    printf("\nPrefix Expression : ");
    preorder(root);
    printf("\nPostfix Expression : ");
    postorder(root);
    printf("\n");

    return 0;
}