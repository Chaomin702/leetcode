#pragma once
typedef enum{UNDISCOVERED,DISCOVERED,VISITED} VStatus;
typedef enum{UNDETERMINED,TREE,CORSS,FORWARD,BACKWARD} EType;

template <typename Tv,typename Te>
class Graph{
public:
	int n;
	virtual Tv& vertex(int) = 0;
	virtual void insert(const Tv&) = 0;
	virtual Tv remove(int) = 0;
	virtual int firstNbr(int) = 0;
	virtual int nextNbr(int, int) = 0;
	virtual VStatus& status(int) = 0;

	int e;
	virtual Te& edge(int, int) = 0;
	virtual bool exists(int, int) = 0;
	virtual void insert(const Te&, int, int, int) = 0;
	virtual Te remove(int, int) = 0;
	virtual EType& type(int, int) = 0;

	void bfs(int);
	void BFS(int, int&);

};