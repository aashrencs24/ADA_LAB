#include <stdio.h>

// Structure for an item
struct Item
{
    int weight;
    int profit;
    float ratio;
};

// Function to sort items based on profit/weight ratio (Descending)
void sortItems(struct Item items[], int n)
{
    struct Item temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack Function
float fractionalKnapsack(struct Item items[], int n, int capacity)
{
    float totalProfit = 0.0;

    // Sort items by ratio
    sortItems(items, n);

    for (int i = 0; i < n; i++)
    {
        // If whole item can be included
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            // Include fractional part
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weights and profits
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);

        // Calculate ratio
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit =
        fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
