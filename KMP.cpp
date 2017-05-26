/* Author -- AJAY KUMAR 
	 MNNIT ALLAHABAD, ALLAHABAD
*/
#include <bits/stdc++.h>
using namespace std;
void compute(int a[],string &s){
	int i = 1;
	int j = 0;
	a[0] = 0;
	while(i < s.length()) {
		if(s[i] == s[j]) 
			j++ , a[i] = j , i++;
		else 
			if(j != 0)
				j = a[j-1];
			else
				a[i] = 0 , i++;
	}
	return ;
}
int KMP(string &pat,string &text){
	int lps[pat.length()+5];
	compute(lps,pat);
	int i = 0;
	int j = 0;
	bool flag = false;
	vector<int> v;
	v.clear();
	while(i < text.length()){
		if(text[i] == pat[j])
			i++ , j++;
		if(j == pat.length())
			v.push_back(i-j) , j = lps[j-1] , flag = true;
		else if(i < text.length() && pat[j] != text[i])
			if(j != 0)
				j = lps[j-1];
			else
				i++;			 
	}

	if(v.size() == 0)
		cout << "Not Found" << '\n';
	else{
		cout << v.size() << '\n';
		for(int a : v)
			cout << a+1 << " ";
		cout << '\n';
	}

}
int main(int argc,char *argv[]){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;
	//string pat = "na";
	//string text = "banananobano";
	int n;
	cin >> n;
	//while( scanf("%d\n",&n) != EOF){
	while(n--){
		string pat , text;
		//cin >> pat;
		//char a[100009],b[100009];
		//scanf("%s %s",a,b);
		//string pat(b);
		//string text(a);
		//cin >> text;
		cin >> text  >> pat;
		KMP(pat,text);
		cout << '\n';
	}
	return 0;
}
//01100001011010100110000101111001 
