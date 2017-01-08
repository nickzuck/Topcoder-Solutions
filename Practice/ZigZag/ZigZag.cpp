#include<iostream>

#define MAX 1000 

using namespace std ; 

bool reverseSign(int a , int b){
    if(a < 0 && b >0){
        return true ; 
    }
    if(a > 0 && b<0){
        return true ;
    }

    return false ;
}

void printArray(int arr[], int n ){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] <<" " ;
    }
    cout << endl; 

}

int lis(int brr[] , int n){
    
    if(n < 2){
        return n;    
    }
    int i , j , max, arr[n] ;
    int dp[n] ;
    for(j = 0, i = 0 ; i <n-1 ; i++ , j++){
        arr[j] = brr[i+1] - brr[i];
    }
    printArray(arr, n-1);

    //initialize the dp array
    for (i = 0 ; i <n ; i++ ) {
        dp[i]= 2 ;
    }
    n = n-1;
    //compute lis at each index
    for (i = 1 ;  i<n ; i++){
        for (j = 0 ;j<i ; j++){

            // we are looking for max value of dp[i] that can be obtained
            if (dp[i] < (dp[j] + 1)&& reverseSign(arr[i],arr[j])){
                dp[i] = dp[j] + 1 ; 
                cout << "Dp[i] = "<< dp[i] << endl  ;
            }
        }
    }

    max =  0 ; 

    for (i = 0 ; i<n ; i++){
        if (dp[i] > max)
            max = dp[i] ;
    }
    
return max ;
    
}


int main ()
{
    int n , arr[MAX]  , i ;   
    cin >> n ; 
    for (i = 0 ;i<n ; i++){
        cin >> arr[i] ;     
    }
    int ans = lis (arr , n ) ;
    cout << "The answer is " << ans << endl ;
return 0 ; 
}
