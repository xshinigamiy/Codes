/*Author --  AJAY KUMAR*/
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &v){
	if(v.size() == 0)
		return 0;
	
	vector<int> t(v.size(),-1);
	t[0] = v[0];
	int length = 1;

	for(int i = 1;i<v.size();i++){
		
		if(v[i] < t[0])
			t[0] = v[i];
		else if(v[i] > t[length-1])
			t[length] = v[i] , length++; 
		else
			t[lower_bound(t.begin(),t.begin()+length ,v[i]) - t.begin()] = v[i];
		//int pos = lower_bound(t.begin(),t.end()-1,v[i]) - t.begin();
	
	}
	return length;
}


int main(){
	vector<int> v{99, -7, 10, 9, 2, 3, 8, 8, 1, 2, 3};
	printf("LIS Length = %d\n",func(v));
	return 0;
}
