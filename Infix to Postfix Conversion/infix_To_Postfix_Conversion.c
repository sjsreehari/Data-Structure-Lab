// ...existing code...

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
char output[MAX];
int outIndex = 0;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


void infixToPostfix(char infix[]) {
    int i;
    char ch;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (isalnum(ch)) {                
            output[outIndex++] = ch;
        } 
        else if (ch == '(') {            
            push(ch);
        } 
        else if (ch == ')') {            
            while (!isEmpty() && peek() != '(')
                output[outIndex++] = pop();
            pop(); 
        } 
        else { 
            while (!isEmpty() && 
                  ((precedence(peek()) > precedence(ch)) ||
                  (precedence(peek()) == precedence(ch) && ch != '^'))) {
                output[outIndex++] = pop();
            }
            push(ch);
        }
    }
    while (!isEmpty()) { 
        output[outIndex++] = pop();
    }
    output[outIndex] = '\0';
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    printf("Postfix expression: %s\n", output);

    return 0;
}
