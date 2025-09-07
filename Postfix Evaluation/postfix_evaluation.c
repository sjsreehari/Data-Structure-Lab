// ...existing code...


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;


int varValues[26] = {0};  


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}


int evaluatePostfix(char postfix[]) {
    char *token = strtok(postfix, " ");
    int op1, op2, result;

    while (token != NULL) {

        if (isalpha(token[0]) && strlen(token) == 1) {
            int value = varValues[token[0] - 'A'];
            push(value);
        }
     
        else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
       
        else if (strlen(token) == 1 && strchr("+-*/^", token[0])) {
            op2 = pop();
            op1 = pop();
            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = 1;
                          for (int i = 0; i < op2; i++)
                              result *= op1;
                          break;
            }
            push(result);
        }
        else {
            printf("Invalid token: %s\n", token);
            return -1;
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char postfix[MAX];
    int usedVars[26] = {0}; 

    printf("Enter postfix expression using variables (space-separated, like A B + C *):\n");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';

   
    char tempPostfix[MAX];
    strcpy(tempPostfix, postfix);  

    char *token = strtok(tempPostfix, " ");
    while (token != NULL) {
        if (isalpha(token[0]) && strlen(token) == 1) {
            int index = token[0] - 'A';
            if (!usedVars[index]) {
                printf("Enter value for %c: ", token[0]);
                scanf("%d", &varValues[index]);
                usedVars[index] = 1;
            }
        }
        token = strtok(NULL, " ");
    }


    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
