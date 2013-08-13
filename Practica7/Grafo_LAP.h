#include <vector>
#include "listaenla.h"
#include <limits>
typedef size_t vertice; // un valor entre 0 y GrafoP::numVert()-1
template <typename tCoste> class GrafoP {
public:
struct vertice_coste {
vertice v;
tCoste c;
};
static const tCoste INFINITO;
GrafoP(size_t n): ady(n) {}
size_t numVert() const {return ady.size();}
const Lista<vertice_coste>& adyacentes(vertice v) const {return ady[v];}
Lista<vertice_coste>& adyacentes(vertice v) {return ady[v];}
private:
vector<Lista<vertice_coste> > ady; // vector de listas de vértice-coste
};

