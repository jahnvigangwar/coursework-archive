#include <bits/stdc++.h>
using namespace std;

/* TAbulation appraoch */
int main() 
{
  int n;
  cin>>n;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
  
}

// Time Complexity: O(n)
// Space Complexity: array = O(n) ---> no recursion stack space
