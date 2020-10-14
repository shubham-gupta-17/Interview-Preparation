#include <bits/stdc++.h>
using namespace std;
vector<int> sort(vector<int> &arr)
{
    int n = arr.size();
    int odd = 1;
    int even = 0;
    while (odd < n && even < n)
    {

        while (odd < n && arr[odd] % 2 == 1)
            odd += 2;
        while (even < n && arr[even] % 2 == 0)
            even += 2;

        if (odd < n && even < n)
            swap(arr[odd], arr[even]);
    }

    return arr;
}
int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7, 9, 11, 12, 13, 14, 16};
    sort(arr);
    for (int i : arr)
        cout << i << " ";
}