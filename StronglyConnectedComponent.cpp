/*Author -- AJAY KUMAR*/
#include <bits/stdc++.h>
using namespace std;
#define N 100
vector<int> g1[N];
vector<int> g2[N];
bool visited[N];
stack<int> s;

void dfs(int v ){
	visited[v] = true;
	for(int i=0;i<g1[v].size();i++){
		int c = g1[v][i];
		if(!visited[c])
			dfs(c);
	}
	s.push(v);
}

void dfsAgain(int v){
	visited[v] = true;
	for(int i=0;i<g2[v].size();i++){
		int c = g2[v][i];
		if(!visited[c])
			dfsAgain(c);
	}
}


bool func(int V){

	memset(visited,false,sizeof(visited));
	/*if graph is not reachable from the current root, choose the otherone*/
	for(int i = 0; i < V;i++)
		if(!visited[i])
			dfs(i);

	/*cnt keeps track of the number of strongly connected components*/
	int cnt = 0;
	memset(visited,false,sizeof(visited));
	while(!s.empty()){
		/* Find the node with the highest time, have not been visited yet */
		if(!visited[s.top()]){
			dfsAgain(s.top());
			s.pop();
			++cnt;
		}
		else
			s.pop();
	}

	printf("\nTotal number of strongly connected components :  %d\n",cnt);
	/* If cnt = 1, means that the given graph is the strongly connected graph */
	if(cnt == 1)
		return true;
	/* More than one strongly connected components */
	return false;
}

void edge(int u,int v){
	/*Add this edge to the graph*/
	g1[u].push_back(v);
	/*Reverse this edge, and add this to another graph*/
	g2[v].push_back(u);
}

int main(){
	edge(0,1);
	edge(1,2);
	edge(2,4);
	edge(4,2);
	edge(3,0);
	edge(2,3);
	//edge(2,3);
	//edge(4,2);
	//edge(3,0);
	if(func(5))
		printf("Strongly Connected Graph\n");
	else
		printf("Not a Strongly Connected Graph\n");
	return 0;
}
