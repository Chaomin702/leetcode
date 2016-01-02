#pragma once
#include <vector>
#include "graph.h"
using std::vector;

template <typename Tv> struct Vertex{
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	Vertex(const Tv& d = (Tv)0) :
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(-1), fTime(-1){}
};
template <typename Te> struct Edge{
	Te data;
	int weight;
	EType type;
	Edge(const Te& d, int w) :data(d), weight(w), type(UNDETERMINED){}
};
template <typename Tv,typename Te>
class GraohMatrix :public Graph<Tv,Te>{
private:
	vector< Vertex<Tv> > V;
	vector< vector< Edge<Te> *> > E;
public:
	GraohMatrix(){ n = e = 0; }
	~GraohMatrix(){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++)
				delete E[j][k];
		}
	}
	virtual Tv& vertex(int i){ return V[i].data; }
	virtual void insert(const Tv& vertex){
		for (int j = 0; j < n; j++)
			E[j].insert(E[j].end(),NULL);
		n++;
		E.insert(E.end(),vector< Edge<Tv> *>(n, (Edge<Te>*) NULL));
		V.insert(V.end(),Vertex<Tv>(vertex));
	}
	virtual Tv remove(int i){
		for (int j = 0; j < n; j++){
			if (exists(i, j)){
				delete E[i][j];
				V[j].inDegree--;
			}
		}
		E.erase(E.begin() + i);
		Tv vBak = vertex(i); 
		V.erase(V.begin() + i);
		for (int j = 0; j < n; j++){
			Edge<Te> * e = E[j][i];
			E[j].erase(E[j].begin() + i);
			if (e){
				delete e;
				V[j].outDegree--;
			}
		}
		return vBak;
	}
	virtual int firstNbr(int i){
		return nextNbr(i, n);
	}
	virtual int nextNbr(int i, int j){
		while ((-1 < j) && (!exists(i, --j)));
		return j;
	}
	virtual VStatus& status(int i){ return V[i].status; }

	virtual bool exists(int i, int j){
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}
	virtual Te& edge(int i, int j){
		return E[i][j]->data;
	}
	virtual void insert(const Te& edge, int w, int i, int j){
		if (exists(i, j)) return;
		E[i][j] = new Edge<Te>(edge, w);
		e++; V[i].outDegree++; V[j].inDegree++;
	}
	virtual Te remove(int i, int j){
		Te eBak = edge(i, j);
		delete E[i][j]; E[i][j] = NULL;
		e--; V[i].outDegree--; V[j].inDegree--;
		return eBak;
	}
	virtual EType& type(int i, int j){
		return E[i][j]->type;
	}

};