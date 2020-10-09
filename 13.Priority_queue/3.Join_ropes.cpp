#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int a[n];
        // for(int i=0;i<n;i++)cin>>a[i];
        priority_queue<ll int, vector<ll int>, greater<ll int>> pq;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pq.push(a);
        }

        ll int sum = 0;
        ll int second = 0;
        ll int first = 0;
        ll int ans = 0;
        while (!pq.empty())
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();

            sum = first + second;
            ans += sum;

            if (!pq.empty())
                pq.push(sum);

            second = 0;
        }
        cout << ans << endl;
    }
    return 0;
}