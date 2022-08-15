// Header
#include <bits/stdc++.h>
// Define
using namespace std;

// Global elements
int arr[9];

// Function

// Driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (arr[k] != arr[i] && arr[k] != arr[j])
                        cout << arr[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}
