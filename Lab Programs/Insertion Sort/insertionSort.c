// Sreehari S J
// Roll Number 58 [SR R1]

#include <stdio.h>

int insertionSort(int arr[], int n) {
    int i, j, key, steps = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            steps++; // shift step
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        steps++; // placement step
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

    steps = insertionSort(arr, n);

    printf("\nArray sorted using Insertion Sort:\n");
    display(arr, n);
    printf("Total steps taken: %d\n", steps);

    return 0;
}
