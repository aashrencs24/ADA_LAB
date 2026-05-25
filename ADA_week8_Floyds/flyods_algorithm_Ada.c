#include <stdio.h>

#define MAX 10
#define INF 99999

int main() {
    int n, i, j, k;
    int W[MAX][MAX], D[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weight matrix:\n");
    printf("(Enter %d for INF if no edge exists)\n", INF);

    // Input weight matrix W
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    // Step: D ← W
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }

    // Floyd Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (D[i][k] != INF && D[k][j] != INF &&
                    D[i][k] + D[k][j] < D[i][j]) {

                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Output result matrix D
    printf("\nShortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
