#include <bits/stdc++.h>
using namespace std;

int minChange(int n,int coins[], int amount) {
    
        int dp[n+1][amount+1];
        
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = 1e5;
                else if(coins[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        return dp[n][amount]>1e4 ? -1:dp[n][amount];
}


int main() {
  int len;//number of coins
  cout<<"Enter the number of Denominations: ";
  cin>>len;
  cout<<"Enter the coins -"<<endl;
  int coins[len];
  for(int i=0;i<len;i++){
    cin>>coins[i];
  }
  int amount;
  cout<<"Enter The amount: ";
  cin>>amount;
  cout<<"\nThe minimum number of coins needed = "<<minChange(len,coins, amount)<<endl;
}
//To view the code on github: https://github.com/johannasmriti/CoinChangeProblem/blob/main/main.cpp
