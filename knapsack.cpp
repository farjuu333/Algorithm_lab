#include <iostream>
using namespace std;

// Function to solve 0/1 knapsack problem
int knapsack(int index, int w, int weights[], int values[]) {
    if (index == 0) {
        if (weights[0] <= w)
            return values[0];
        else
            return 0;
    }

    int dontPick = knapsack(index - 1, w, weights, values);
    int pick = 0;
    if (weights[index] <= w)
        pick = values[index] + knapsack(index - 1, w - weights[index], weights, values);

    return max(pick, dontPick);
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Maximum value in Knapsack = " << knapsack(n - 1, W, weights, values) << endl;

    return 0;
}
