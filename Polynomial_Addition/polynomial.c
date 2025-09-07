

#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term poly1[10], poly2[10], result[20];
    int n1, n2, n3 = 0;
    int i = 0, j = 0;

    printf("Enter number of terms in 1st polynomial: ");
    scanf("%d", &n1);
    for (int k = 0; k < n1; k++) {
        printf("Enter coefficient and exponent for term %d: ", k + 1);
        scanf("%d %d", &poly1[k].coeff, &poly1[k].exp);
    }

    printf("Enter number of terms in 2nd polynomial: ");
    scanf("%d", &n2);
    for (int k = 0; k < n2; k++) {
        printf("Enter coefficient and exponent for term %d: ", k + 1);
        scanf("%d %d", &poly2[k].coeff, &poly2[k].exp);
    }

    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            if (poly1[i].coeff + poly2[j].coeff != 0) {
                result[n3].coeff = poly1[i].coeff + poly2[j].coeff;
                result[n3].exp = poly1[i].exp;
                n3++;
            }
            i++; j++;
        } else if (poly1[i].exp > poly2[j].exp) {
            result[n3] = poly1[i];
            n3++;
            i++;
        } else {
            result[n3] = poly2[j];
            n3++;
            j++;
        }
    }

    while (i < n1) {
        result[n3] = poly1[i];
        n3++;
        i++;
    }
    while (j < n2) {
        result[n3] = poly2[j];
        n3++;
        j++;
    }

    printf("\nSum of polynomials: ");
    int printed_terms = 0;
    for (int k = 0; k < n3; k++) {
        if (result[k].coeff == 0) continue;

        if (printed_terms > 0) {
            printf(" + ");
        }

        if (result[k].exp == 0) {
            printf("%d", result[k].coeff);
        } else if (result[k].exp == 1) {
            printf("%dx", result[k].coeff);
        } else {
            printf("%dx^%d", result[k].coeff, result[k].exp);
        }
        printed_terms++;
    }

    if (printed_terms == 0) {
        printf("0");
    }
    printf("\n");

    return 0;
}