
# Aim

    To implement find and replace operation in a linked list using C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define a struct node containing:
            data → character or string
            next → pointer to next node

    Step 3: Create Linked List (createLinkedList)
        Read the input string
        For each character in the string:
            Create a new node
            Insert node at the end of the linked list

    Step 4: Input Pattern and Replacement (inputPattern)
        Read the pattern to find
        Read the replacement string

    Step 5: Find Pattern in Linked List (findPatternInList)
        Traverse the linked list
        For each possible starting node:
            Check if the next nodes match the pattern
            If match found, note the position(s)

    Step 6: Replace Pattern in Linked List (replacePatternInList)
        For each match found:
            Remove nodes corresponding to the pattern
            Insert new nodes for the replacement string

    Step 7: Output Result (outputLinkedList)
        Traverse the modified linked list and print the result

    Step 8: Stop
