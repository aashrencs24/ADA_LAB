#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Print permutation
void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Find index of largest mobile element
int findLargestMobile(int a[], int dir[], int n) {
    int largest = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        // Check if mobile
        if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1]) {
            if (a[i] > largest) {
                largest = a[i];
                index = i;
            }
        }
        if (dir[i] == RIGHT && i < n - 1 && a[i] > a[i + 1]) {
            if (a[i] > largest) {
                largest = a[i];
                index = i;
            }
        }
    }
    return index;
}

void johnsonTrotter(int n) {
    int a[n], dir[n];

    // Step 1: initialize first permutation and directions
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    // Output first permutation
    printPerm(a, n);

    // Step 2: while there exists a mobile element
    while (1) {
        int k = findLargestMobile(a, dir, n);

        if (k == -1)  // no mobile element → last permutation reached
            break;

        // Step 3: swap k with adjacent element in its direction
        int swapIndex = k + dir[k];

        int temp = a[k];
        a[k] = a[swapIndex];
        a[swapIndex] = temp;

        int tempDir = dir[k];
        dir[k] = dir[swapIndex];
        dir[swapIndex] = tempDir;

        // After swap, new position of k
        int movedValue = a[swapIndex];

        // Step 4: reverse direction of all elements larger than k
        for (int i = 0; i < n; i++) {
            if (a[i] > movedValue)
                dir[i] = -dir[i];
        }

        // Step 5: output permutation
        printPerm(a, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
