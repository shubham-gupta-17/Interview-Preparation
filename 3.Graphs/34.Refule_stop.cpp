#include <bit/stdc++.h>
using namespace std;
// leetcode 871
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    if (target == 0 || startFuel >= target)
        return 0;
    int station = 0;
    int idx = 0;

    // acc to question the input will be sorted on the basis of distance
    priority_queue<int> que;
    que.push(startFuel);
    int currentFuel = 0;
    while (!que.empty())
    {
        // int size=que.size();
        // while(size--){
        int top = que.top();
        que.pop();
        currentFuel += top;
        if (currentFuel >= target)
            return station;

        // push all the stations which we can visit with currentFuel stock
        while (idx < stations.size() && stations[idx][0] <= currentFuel)
        {
            que.push(stations[idx][1]);
            idx++;
        }

        station++;
    }

    return -1;
}
int main()
{
    int t = 200;
    int fuel = 50;
    vector<vector<int>> sta = [ [ 25, 25 ], [ 50, 100 ], [ 100, 100 ], [ 150, 40 ] ];
    minRefuelStops(t, fuel, sta);
    return 0;
}