/* Author -- AJAY KUMAR
  MNNIT ALLAHABAD, ALLAHABAD
*/

#include <bits/stdc++.h>
using namespace std;

/*
Question  - Given an array of numbers, find the maximum and minimum sum of sub sequences at a distance > M
						E.g. arr = {3, 4, -2, 1, -2, 4, 6, -3, 5}, M = 2
						max = 13 {4 + 4 + 5}, min = -5 {-2 -3}


*/

int func(int * a ,int n , int m){
	int dp[n + 1][2];
	dp[0][0] = 0;
	dp[0][1] = a[0];

	for(int i = 1 ; i < n ; i++ ){
		dp[i][0] = ((i-1) >= 0 ? max(dp[i-1][0] , dp[i-1][1]) : 0 );
		dp[i][1] = a[i] + ((i- m - 1) >= 0 ? max(dp[i- m - 1][0] , dp[i - m - 1][1]) : 0 );
	}
	return max(dp[n-1][0] , dp[n - 1][1]);
}
int main(){
	int a[] = {1,2,3,4,5,-5,-4,-3,-2,-1};
	int n = sizeof(a)/sizeof(a[0]);
	int m = 0;
	int pp = func(a , n, m);
	
	//invert the array elements
	for(int i = 0 ; i < n ; i++ )
			a[i] = -i[a];

	int ppm = func(a , n, m);
	ppm = -ppm;	
	printf("%d %d\n",pp,ppm);
	return 0;
}
