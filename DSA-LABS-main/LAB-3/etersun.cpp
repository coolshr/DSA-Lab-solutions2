#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k = 3;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n];
    deque<int> dpque;
    dp[n - 1] = a[n - 1];
    dpque.push_back(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (dpque.front() - k > i)
            dpque.pop_front();
        dp[i] = a[i] + dp[dpque.front()];
        while (dp[dpque.back()] > dp[i])
            dpque.pop_back();
        dpque.push_back(i);
    }
    cout << dp[0];
    return 0;
}
