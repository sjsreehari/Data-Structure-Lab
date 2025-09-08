
# Aim

    To implement polynomial addition using linked lists in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define a struct node containing:
            coeff → integer coefficient
            exp   → integer exponent
            next  → pointer to next node

    Step 3: Create Polynomial Linked List (createPolynomialList)
        For each term in the polynomial:
            Read coeff and exp
            Create a new node
            Insert node into the linked list in decreasing order of exponent

    Step 4: Input Polynomials (inputPolynomials)
        Read number of terms for each polynomial
        For each polynomial, call createPolynomialList

    Step 5: Add Two Polynomials (addPolynomials)
        Initialize pointers p1 and p2 to the heads of the two polynomials
        While both p1 and p2 are not NULL:
            If p1->exp == p2->exp:
                Add coefficients
                If sum != 0:
                    Create a new node with sum and exp
                Move both pointers forward
            Else if p1->exp > p2->exp:
                Create a new node with p1's coeff and exp
                Move p1 forward
            Else:
                Create a new node with p2's coeff and exp
                Move p2 forward
        Copy remaining terms from either polynomial to result

    Step 6: Display Resultant Polynomial (displayPolynomial)
        Traverse the result linked list
        For each node:
            Print coeff and exp in polynomial format

    Step 7: Stop
