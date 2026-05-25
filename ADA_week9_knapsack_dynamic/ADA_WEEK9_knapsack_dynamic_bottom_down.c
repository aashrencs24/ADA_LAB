#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Dynamic Programming (Bottom-Up Approach)
int knapsack(int W[], int P[], int n, int M)
{
    int V[n + 1][M + 1];

    // Build table V[][] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            // Base condition
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            // If current item's weight is greater than capacity j
            else if (W[i - 1] > j)
            {
                V[i][j] = V[i - 1][j];
            }
            // Choose maximum of including or excluding the item
            else
            {
                V[i][j] = max(
                    V[i - 1][j],
                    V[i - 1][j - W[i - 1]] + P[i - 1]
                );
            }
        }
    }

    return V[n][M];
}

int main()
{
    int n, M;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int W[n], P[n];

    // Input weights
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &W[i]);
    }

    // Input profits
    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &P[i]);
    }

    // Input knapsack capacity
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    // Find maximum profit
    int result = knapsack(W, P, n, M);

    printf("Maximum Profit = %d\n", result);

    return 0;
}

