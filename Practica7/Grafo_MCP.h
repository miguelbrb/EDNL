#include <vector>
#include <limits>
typedef size_t vertice; // un valor entre 0 y GrafoP::numVert()-1
template <typename tCoste> class GrafoP {// Grafo ponderado
public:
static const tCoste INFINITO;
GrafoP(size_t n): costes(n, vector<tCoste>(n, INFINITO)) {}
size_t numVert() const {return costes.size();}
const vector<tCoste>& operator [](vertice v) const {return
costes[v];}
vector<tCoste>& operator [](vertice v) {return costes[v];}
private:
vector<vector<tCoste> > costes;
};
// Definición de INFINITO
template <typename tCoste>
const tCoste GrafoP<tCoste>::INFINITO = std::numeric_limits<tCoste>::max();

