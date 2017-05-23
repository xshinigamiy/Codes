/*Author -- AJAY KUMAR*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

/* Rank is the approximate height of the representative of that group */
struct node {
	int rank;
	int parent;
};

struct node a[MAX];

/* Creates the set with the single node */
void makeSet(int node){
	a[node].parent = node;
	a[node].rank = 0;
}

/* returns the representative of the set, from this node belongs to */
int findSet(int node){
	if(a[node].parent == node)
		return node;
	/*Path Compression*/
	return (a[node].parent = findSet(a[node].parent));	
}

/*Merges the two sets Using the path compression Optimisation technique*/
void Union(int A , int B){
	int pa = findSet(A);
	int pb = findSet(B);

	printf("%d %d\n",pa,pb);
	if(pa == pb)
		return ;

	if(a[pa].rank == a[pb].rank){
		a[pa].rank = a[pa].rank + 1;
		a[pb].parent = pa;
		return ;
	}
	else{
		if(a[pa].rank > a[pb].rank){
			a[pb].parent = pa;
			return ;
		}
		else{
			a[pa].parent = pb;
			return ;
		}
	}
}


int main(){
	for(int i = 0; i < 5 ; i++)
		makeSet(i);

	Union(1,2);
	Union(3,2);
	Union(1,3);
	Union(3,4);
	Union(0,4);
	for(int i=0;i<5;i++)
		printf("%d\n",findSet(i));
}
