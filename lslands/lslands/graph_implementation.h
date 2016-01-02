#include "graph.h"
#include <queue>
using std::queue;
template <typename Tv,typename Te>
void Graph<Tv, Te>::bfs(int s){
	int clock = 0; int v = s;
	do 
	if (UNDISCOVERED == status(v))
		BFS(v, clock);
	while (s != (v = (++v%n)));
}
template <typename Tv,typename Te>
void Graph<Tv, Te>::BFS(int v, int&clock){
	queue<int> Q;
	status(v) = DISCOVERED;
	Q.push(v);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		
	}
}