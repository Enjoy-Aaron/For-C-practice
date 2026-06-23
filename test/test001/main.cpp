#include <iostream>
#include <cstdio>
#define MaxInt 32767
#define MVNum 100
using namespace std;

typedef char vertexType;
typedef int ArcType;
typedef struct AMGraph {
	vertexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	int dist;
}ArcNode;
typedef struct VNode {
	vertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MVNum];
typedef struct ALGrap {
	AdjList vertices;
	int vexnum, arcnum;
}ALGrap;

int main() {

	return 0;
}