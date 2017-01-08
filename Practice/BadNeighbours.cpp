/*
Problem Link : https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
Points Achieved : 104.86/250
Author : nickzuck_007
Tags: Dynamic Programming
*/

include<bits/stdc++.h>

using namespace std ; 

class BadNeighbors{
    private:
        int n ;
        int dp[45], dp1[45];
    public: 
        int maxDonations(vector<int> donations){
            n = donations.size() ;
            int ans ; 
            dp[0] = donations[0] ;
            dp[1] = donations[1] ;
            dp[2] = donations[2] + donations[0] ;
            for(int i = 3 ; i < n-1 ; i++){
                dp[i] = max(dp[i-2], dp[i-3]) + donations[i] ;
            }
            dp1[1] = donations[1] ; 
            dp1[2] = donations[2] ;
            dp1[3] = donations[3] ;
            for(int i = 4 ; i <n ;i++){
                dp1[i] = max(dp1[i-2] , dp1[i-3]) + donations[i];
            }
            //cout << dp[n-2] << "  " << dp1[n-1] << endl ;
            ans = max(dp[n-2], dp1[n-1]) ;
            return ans ;
        }
};
