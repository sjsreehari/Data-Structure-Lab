// Sreehari S J
// Roll Number 58 [SR R1]

#include <stdio.h>

int bubbleSort(int arr[], int n) {
    int i, j, temp, steps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            steps++; // comparison
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                steps++; // swap
            }
        }
    }
    return steps;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, steps, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    steps = bubbleSort(arr, n);

    printf("\nArray sorted using Bubble Sort:\n");
    display(arr, n);
    printf("Total steps taken: %d\n", steps);

    return 0;
}
