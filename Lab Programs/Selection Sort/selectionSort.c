// Sreehari S J
// Roll Number 58 [SR R1]

#include <stdio.h>

int selectionSort(int arr[], int n) {
    int i, j, minIndex, temp, steps = 0;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            steps++; // comparison
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            steps++; // swap
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

    steps = selectionSort(arr, n);

    printf("\nArray sorted using Selection Sort:\n");
    display(arr, n);
    printf("Total steps taken: %d\n", steps);

    return 0;
}
