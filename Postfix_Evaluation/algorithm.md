
# Aim

    To evaluate a postfix expression using stack in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define an array stack[MAX] to store operands
        top → integer index for top of stack
        MAX → maximum size of stack

    Step 3: Input Postfix Expression (inputPostfix)
        Read postfix expression as a string

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
            Insert operand at stack[top]

    Step 6: Pop Operation (pop)
        If stack is empty:
            Display underflow message
        Else:
            Remove operand from stack[top]
            Decrement top

    Step 7: Evaluate Postfix Expression (evaluatePostfix)
        For each character ch in postfix expression:
            If ch is operand:
                Push ch to stack
            Else if ch is operator:
                Pop two operands from stack
                Apply operator to operands
                Push result back to stack
        After all characters processed:
            The result is at stack[top]

    Step 8: Output Result (outputResult)
        Print result

    Step 9: Stop
