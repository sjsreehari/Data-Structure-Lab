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

    Step 4: Convert Infix to Postfix (infixToPostfix)
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

    Step 5: Output Postfix Expression (outputPostfix)
        Print postfix expression

    Step 6: Stop
