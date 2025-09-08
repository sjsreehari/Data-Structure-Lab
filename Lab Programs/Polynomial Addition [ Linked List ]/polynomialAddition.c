#include <stdio.h>
#include <stdlib.h>

// Structure for each node
struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node *insertNode(struct Node *head, int coef, int exp)
{
    struct Node *newNode = createNode(coef, exp);
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display polynomial
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->coef);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        if (temp->next != NULL && temp->next->coef >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *p1 = poly1;
    struct Node *p2 = poly2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            int sumCoef = p1->coef + p2->coef;
            if (sumCoef != 0)
            {
                result = insertNode(result, sumCoef, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            result = insertNode(result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else
        {
            result = insertNode(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    // Copy remaining terms
    while (p1 != NULL)
    {
        result = insertNode(result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        result = insertNode(result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;

    int n1, n2, coef, exp;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coefficient exponent) in descending order of exponent:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d %d", &coef, &exp);
        poly1 = insertNode(poly1, coef, exp);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coefficient exponent) in descending order of exponent:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &coef, &exp);
        poly2 = insertNode(poly2, coef, exp);
    }

    // Display polynomials
    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);

    // Add polynomials
    sum = addPolynomials(poly1, poly2);

    // Display result
    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}