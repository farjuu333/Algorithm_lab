#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int weight, value;
    double ratio;
};

bool com(item &a,item &b) {
    return a.ratio > b.ratio;
}

int main() {
    int x, y, num, i;
    cout << "Enter the number of items: ";
    cin >> num;

    item items[num];
    double w, total = 0;
    cout << "Enter the maximum capacity to select items: ";
    cin >> w;
    cout<<"enter value and weight: ";
    for (i = 0; i < num; i++) {
        cin >> x ;
        cin >> y;
        items[i].weight = y;
        items[i].value = x;
        items[i].ratio = (double)x / y;
    }

    sort(items, items + num, com);

    for (i = 0; i < num; i++) {
        if (items[i].weight <= w) {
            total += items[i].value;
            w -= items[i].weight;
        } else {
            total += items[i].ratio * w;
            break;
        }
    }

    cout <<"maximum profit: "<< total << endl;
    return 0;
}
