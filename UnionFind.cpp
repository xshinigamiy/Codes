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

class UnionSet {
public:
    UnionSet(int size) {
        for (int i = 0; i < size; ++i) {
            par.push_back(i);
            rank.push_back(1);
        }
    }
    
    //Merge using Rank
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return ;
        if (rank[rootX] == rank[rootY]) {
            par[rootY] = rootX;
        } else if (rank[rootX] > rank[rootY]) {
            par[rootY] = rootX;
        } else {
            par[rootX] = rootY;
        }
    }
    
    //Find using path compression
    int find(int node) {
        if (node == par[node]) return node;
        return par[node] = find(par[node]);
    }
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> par, rank;
};

//Create UnionSet class object using
//UnionSet us(1e5);


int main(){
	for(int i = 0; i < 5 ; i++)
		makeSet(i);
	Union(1, 2);
	Union(3, 2);
	Union(1, 3);
	Union(3, 4);
	Union(0, 4);
	for(int i = 0; i < 5; i++)
		printf("%d\n", findSet(i));
}
