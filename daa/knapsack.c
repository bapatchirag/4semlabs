#include <stdio.h>
#define SIZE 10

int n, maxWeight;
int knapsack[SIZE][SIZE];           // Knapsack table
int weights[SIZE], values[SIZE];    // Weights and values of objects
int objectStack[SIZE], sTop = -1;   // Objects put into knapsack

// Worker functions
int knapsackgen();
void backtrack();

// Helper functions
int max(int, int);
void printStack(int[], int);

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Enter weights, values and max weight
    int i;
    printf("Enter the weights: \n");
    for(i = 0; i <= n; i++) {
        if(!i)
            weights[i] = 0;
        else
            scanf("%d", &weights[i]);
    }

    printf("Enter the values: \n");
    for(i = 0; i <= n; i++){
        if(!i)
            values[i] = 0;
        else
            scanf("%d", &values[i]);
    }

    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);

    printf("Maximum weight is: %d\n", knapsackgen());
    backtrack();
    printf("Objects put in knapsack: ");
    printStack(objectStack, sTop);

    return 0;
}

// Generates table for dynamic programming and returns maximum value possible
int knapsackgen(){
    int i, w;

    for(i = 0; i <= n; i++){
        for(w = 0; w <= maxWeight; w++) {
            if(!(i & w))
                knapsack[i][w] = 0;
            else{
                if(w < weights[i])
                    knapsack[i][w] = knapsack[i-1][w];
                else
                    knapsack[i][w] = max(knapsack[i-1][w], knapsack[i-1][w-weights[i]] + values[i]);
            }
        }
    }

    return knapsack[n][maxWeight];
}

// Backtracks through the table and pushes knapsack objects onto stack
void backtrack(){
    int i = n, w = maxWeight;
    while(i & w){
        if(knapsack[i][w] != knapsack[i-1][w]){
            objectStack[++sTop] = i;
            w -= weights[i];
        }
        i--;
    }
}

// Returns maximum of two integers
int max(int a, int b){
    return (a > b ? a : b);
}

// Prints stack elements
void printStack(int stack[], int top){
    int i;
    for(i = top; i >= 0; i--)
        printf("%d\t", stack[i]);
    printf("\n");
}
