
# Aim

    To implement sparse matrix operations (creation, display, transpose, addition) using arrays in C.

# Algorithm

    Step 1: Start

    Step 2: Define Data Structure
        Define a struct element containing:
            row   → integer row index
            col   → integer column index
            value → integer value

    Step 3: Declare Arrays and Variables
        sparse[rows][cols] → stores the original matrix
        terms[]            → stores non-zero elements as array of struct element
        result[]           → stores result of operations (like addition, transpose)
        m → number of rows
        n → number of columns
        count → number of non-zero elements

    Step 4: Create Sparse Matrix (createSparseMatrix)
        Read m and n
        For i = 0 to m - 1:
            For j = 0 to n - 1:
                Read sparse[i][j]
                If sparse[i][j] != 0:
                    Store row, col, value in terms[count]
                    Increment count

    Step 5: Display Sparse Matrix (displaySparseMatrix)
        Print all non-zero elements from terms[] as:
            row   col   value

    Step 6: Transpose Sparse Matrix (transposeSparseMatrix)
        For each element in terms[]:
            Swap row and col
            Store in result[]
        Sort result[] by row, then by column (if required)

    Step 7: Add Two Sparse Matrices (addSparseMatrices)
        For each element in terms1[] and terms2[]:
            If row and col match:
                Add values
                Store in result[]
            Else:
                Store non-matching elements as is
        Update count for result[]

    Step 8: Display Resultant Matrix (displayResultMatrix)
        Print all non-zero elements from result[] as:
            row   col   value

    Step 9: Stop
