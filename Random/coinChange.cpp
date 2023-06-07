#include<bits/stdc++.h>
using namespace std;

// Recursive Function
int minCoins(int coins[], int m, int N)
{
  // base case
  if (N == 0)
    return 0;
  
  // Initialize result
  int res = INT_MAX;
  
  // Try every coin that has smaller value than m
  for (int i=0; i<m; i++)
  {
    if (coins[i] <= N)
    {
      int sub_res = 1 + minCoins(coins, m, N-coins[i]);
      // see if result can minimized
      if (sub_res < res)
        res = sub_res;
    }
  }
  return res;
}

int main() {
  int coins[] = {1,5};
  int sum = 14; 
  int total_coins = 2;
  cout << minCoins(coins,total_coins,sum);
}