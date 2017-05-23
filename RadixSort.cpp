/*Author -- AJAY KUMAR*/
#include <bits/stdc++.h>
using namespace std;
#define base 10

/*Counting sort*/
inline void countsort(int a[],int n,int m){
	int output[n+5];
	int cnt[base];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
		cnt[ (a[i]/m) % base ]++;

	for(int i = 1;i<base;i++)
		cnt[i] += cnt[i-1];

	for(int i=n-1;i>=0;i--){
		output[cnt[(a[i]/m)%base] - 1] = a[i];
		cnt[(a[i]/m)%base]--;
	}

	for(int i=0;i<n;i++)
		a[i] = output[i];
	return;
}

inline void radixsort(int a[],int n){
	int m = 0;
	/*Find the Maximum Element*/
	for(int i=1;i<n;i++)
		if(a[i] > a[m])
			m = i;

	int K = a[m];
	//cout << K ;
	/*Sort according to digit wise*/
	for(int digit = 1 ; K/digit > 0 ;digit *= 10)	
		countsort(a,n,digit);

}

int main(){
	int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(a)/sizeof(a[0]);
	radixsort(a,n);
	printf("Sorted Array : ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
