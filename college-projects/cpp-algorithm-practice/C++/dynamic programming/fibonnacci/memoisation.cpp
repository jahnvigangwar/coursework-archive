
#include <bits/stdc++.h>
using namespace std;

/* MEMOISATION appraoch */
//int fibo(int dp, int n)
int fibo(vector<int> dp, int n)
{
    if (n <= 1) return n;
    if(dp[n]!=-1) return dp[n];
    return fibo(dp, n-1) + fibo(dp, n-2);
    
}
int main()
{
    int n; cin>> n;
    // int dp[n+1];
    // memset(dp, -1, sizeof(dp));
    vector<int> dp(n+1,-1);
    
    cout<<fibo(dp, n);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: recursion stack space + array
//                  = O(n) + O(n) 
