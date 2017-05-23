/*Author -- AAY KUMAR*/
#include <bits/stdc++.h>
using namespace std;
void func(int *a,int n){
	int cmap = a[0];
	int cmip = a[0];
	int ans = a[0];

	for(int i=1;i<n;i++){
		cmap = max(cmip*a[i],max(cmap*a[i],a[i]));
		cmip = min(cmip*a[i],min(cmap*a[i],a[i]));
		ans = max(cmap,ans);
	}

	printf("Maxmum subarray product %d\n",ans);

}
int main(){
	int a[] = {6,-3,10,2,0,0,0,0,-2,-6,0};
	int n = sizeof(a)/sizeof(a[0]);
	func(a,n);
}
