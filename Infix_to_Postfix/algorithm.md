
# Aim

    To convert an infix expression to postfix expression using stack in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array stack[MAX] to store operators
        top → integer index for top of stack
        MAX → maximum size of stack

    Step 3: Input Infix Expression (inputInfix)
        Read infix expression as a string
        Initialize postfix expression as empty string

    Step 4: Check if Stack is Empty (isEmpty)
        If top == -1:
            Return true
        Else:
            Return false

    Step 5: Push Operation (push)
        If stack is full:
            Display overflow message
        Else:
            Increment top
            Insert operator at stack[top]

    Step 6: Pop Operation (pop)
        If stack is empty:
            Display underflow message
        Else:
            Remove operator from stack[top]
            Decrement top

    Step 7: Get Precedence (getPrecedence)
        Return precedence value for operator

    Step 8: Convert Infix to Postfix (infixToPostfix)
        For each character ch in infix expression:
            If ch is operand:
                Add ch to postfix expression
            Else if ch is '(': 
                Push ch to stack
            Else if ch is ')':
                Pop and add to postfix until '(' is found
                Pop '(' from stack
            Else if ch is operator:
                While stack is not empty and precedence of ch <= precedence of stack[top]:
                    Pop and add to postfix
                Push ch to stack
        After all characters processed:
            Pop remaining operators from stack and add to postfix

    Step 9: Output Postfix Expression (outputPostfix)
        Print postfix expression

    Step 10: Stop
