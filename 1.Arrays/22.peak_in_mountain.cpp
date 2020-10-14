#include <bits/stdc++.h>
using namespace std;
// leetcode 852
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int idx = 0;
    int i = 0;
    while (i + 1 < n && arr[i] < arr[i + 1])
        i++;
    return i;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 2, 3, 4};
    cout << peakIndexInMountainArray(arr);
    return 0;
}