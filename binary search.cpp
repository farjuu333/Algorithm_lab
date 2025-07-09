#include<iostream>
using namespace std;
/* sort the array if not sorted */
void bubbleSort(int arr[], int len) {
    if (len == 1)
        return;

    for (int i = 0; i < len - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    bubbleSort(arr, len - 1);
}
/* perform binary search */
int binarySearch(int arr[], int first, int last, int num) {
    if (first==last) {
        if(arr[first]==num)
            return first;
        else
            return -1;

    }
        int middle = (first+last)/2;

        if (arr[middle] == num)
            return middle;

        if (arr[middle] > num)
            return binarySearch(arr, first, middle - 1, num);

        return binarySearch(arr, middle + 1, last, num);
    }

int main() {
    int len, num;
    cout << "Enter the Size: ";
    cin >> len;
    int arr[len];
    cout << "Enter " << len << " Elements: ";
    for(int i = 0; i < len; i++)
        cin >> arr[i];

    // sort the array using recursive bubble sort
    bubbleSort(arr, len);

    // print the sorted array
    cout << "\nThe New Sorted Array is:\n";
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";

    // now back to binary search
    cout << "\n\nEnter Element to be Searched: ";
    cin >> num;

    int result = binarySearch(arr, 0, len - 1, num);
    if(result != -1)
        cout << "\nThe search item " << num << " is found at Position " << result + 1;
    else
        cout << "\nThe search item " << num << " is not found in given Array.";

    cout << endl<<endl<<endl;
    return 0;
}
