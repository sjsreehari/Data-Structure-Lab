#include <stdio.h>
#define MAX 10

int a[MAX][MAX], b[MAX][MAX];
int sp1[MAX * MAX][3], sp2[MAX * MAX][3], sum[MAX * 2][3], trans1[MAX * MAX][3], trans2[MAX * MAX][3];
int r, c, k1 = 1, k2 = 1;

void inputMatrices()
{
    int i, j;
    printf("Enter the order of the matrices (rows and columns): ");
    scanf("%d %d", &r, &c);

    printf("Enter the first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &b[i][j]);
}

void convertToSparse()
{
    int i, j;
    k1 = 1;
    sp1[0][0] = r;
    sp1[0][1] = c;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != 0)
            {
                sp1[k1][0] = i;
                sp1[k1][1] = j;
                sp1[k1][2] = a[i][j];
                k1++;
            }
    sp1[0][2] = k1 - 1;

    k2 = 1;
    sp2[0][0] = r;
    sp2[0][1] = c;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (b[i][j] != 0)
            {
                sp2[k2][0] = i;
                sp2[k2][1] = j;
                sp2[k2][2] = b[i][j];
                k2++;
            }
    sp2[0][2] = k2 - 1;

    printf("\nMatrices converted to sparse form.\n");
}

void displaySparse(int s[MAX * MAX][3], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

void addSparseMatrices()
{
    int i = 1, j = 1, k = 1;
    sum[0][0] = r;
    sum[0][1] = c;

    while (i < k1 && j < k2)
    {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1])
        {
            int temp = sp1[i][2] + sp2[j][2];
            if (temp != 0)
            {
                sum[k][0] = sp1[i][0];
                sum[k][1] = sp1[i][1];
                sum[k][2] = temp;
                k++;
            }
            i++;
            j++;
        }
        else if (sp1[i][0] < sp2[j][0] ||
                 (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1]))
        {
            sum[k][0] = sp1[i][0];
            sum[k][1] = sp1[i][1];
            sum[k][2] = sp1[i][2];
            i++;
            k++;
        }
        else
        {
            sum[k][0] = sp2[j][0];
            sum[k][1] = sp2[j][1];
            sum[k][2] = sp2[j][2];
            j++;
            k++;
        }
    }

    while (i < k1)
    {
        sum[k][0] = sp1[i][0];
        sum[k][1] = sp1[i][1];
        sum[k][2] = sp1[i][2];
        i++;
        k++;
    }

    while (j < k2)
    {
        sum[k][0] = sp2[j][0];
        sum[k][1] = sp2[j][1];
        sum[k][2] = sp2[j][2];
        j++;
        k++;
    }

    sum[0][2] = k - 1;

    printf("\nSum of Sparse Matrices:\n");
    displaySparse(sum, k);
}

void transposeSparse(int sp[MAX * MAX][3], int k, int trans[MAX * MAX][3])
{
    int i, j, pos = 1;

    trans[0][0] = sp[0][1];
    trans[0][1] = sp[0][0];
    trans[0][2] = sp[0][2];

    for (i = 0; i < sp[0][1]; i++)
    {
        for (j = 1; j <= sp[0][2]; j++)
        {
            if (sp[j][1] == i)
            {
                trans[pos][0] = sp[j][1];
                trans[pos][1] = sp[j][0];
                trans[pos][2] = sp[j][2];
                pos++;
            }
        }
    }
}

void showMenu()
{
    printf("\n========= SPARSE MATRIX MENU =========\n");
    printf("1. Input Matrices\n");
    printf("2. Convert to Sparse Matrices\n");
    printf("3. Display Sparse Matrix 1\n");
    printf("4. Display Sparse Matrix 2\n");
    printf("5. Add Sparse Matrices\n");
    printf("6. Transpose Sparse Matrix 1\n");
    printf("7. Transpose Sparse Matrix 2\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

void main()
{
    int choice;

    while (1)
    {
        showMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputMatrices();
            break;
        case 2:
            convertToSparse();
            break;
        case 3:
            printf("\nSparse Matrix 1:\n");
            displaySparse(sp1, k1);
            break;
        case 4:
            printf("\nSparse Matrix 2:\n");
            displaySparse(sp2, k2);
            break;
        case 5:
            addSparseMatrices();
            break;
        case 6:
            transposeSparse(sp1, k1, trans1);
            printf("\nTranspose of Sparse Matrix 1:\n");
            displaySparse(trans1, trans1[0][2] + 1);
            break;
        case 7:
            transposeSparse(sp2, k2, trans2);
            printf("\nTranspose of Sparse Matrix 2:\n");
            displaySparse(trans2, trans2[0][2] + 1);
            break;
        case 8:
            printf("Exiting program.\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}