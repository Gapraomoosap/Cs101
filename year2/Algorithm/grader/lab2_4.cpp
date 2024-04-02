#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countSubsequences(vector<int>& arr) {
    int count = 1; 

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1] + 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); 

    int numSubsequences = countSubsequences(arr);
    cout << numSubsequences << endl;

    return 0;
}