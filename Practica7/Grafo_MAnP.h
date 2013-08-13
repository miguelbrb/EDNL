#include <vector>
typedef size_t vertice; // un valor entre 0 y Grafo::numVert()-1
class Grafo {
public:
Grafo(size_t n): ady(n, vector<bool>(n, false)) {}
size_t numVert() const {return ady.size();}
const vector<bool>& operator [](vertice v) const {return ady[v];}
vector<bool>& operator [](vertice v) {return ady[v];}
private:
vector<vector<bool> > ady;
};

