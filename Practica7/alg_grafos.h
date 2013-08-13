#include "listadoble.h"

template <typename tCoste>
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G, vertice origen, vector<vertice>& P)
{
	const size_t n = G.numVert();
	vector<bool> S(n, false);
	// Conjunto de vértices vacío.
	S[origen] = true;
	// Incluir vértice origen en S.
	vector<tCoste> D = G[origen];
	// Iniciar con caminos directos
	P = vector<vertice>(n, origen);
	// desde el vértice origen.
	// Calcular caminos de coste mínimo hasta cada vértice.
	for (int i = 0; i < n-1; i++) {
		vertice w;
		tCoste costeMin = GrafoP<tCoste>::INFINITO;
		for (vertice v = 0; v < n; v++)
		// Localizar vértice w
			if (!S[v] && D[v] < costeMin) {
				// no incluido en S
				costeMin = D[v];
				// con coste mínimo.
				w = v;
			}
		S[w] = true;
		// Incluir vértice w en S.
		// Recalcular coste hasta cada v no incluido en S, a través de w.
		for (vertice v = 0; v < n; v++) {
			tCoste Owv = suma(D[w], G[w][v]);
			if (!S[v] && Owv < D[v]) {
				D[v] = Owv;
				P[v] = w;
			}
		}
	}
	return D;
}
// Suma de costes
template <typename tCoste>
tCoste suma(tCoste x, tCoste y)
{
	if (x == GrafoP<tCoste>::INFINITO || y == GrafoP<tCoste>::INFINITO)
		return GrafoP<tCoste>::INFINITO;
	else
		return x + y;
}

typedef Lista<vertice> tCamino;
tCamino camino(vertice orig, vertice i, const vector<vertice>& P)
// Reconstruye el camino de orig a i a partir de un vector
// P obtenido mediante la función Dijkstra().
{
	tCamino c;
	c.insertar(i, c.primera());
	do {
		c.insertar(P[i], c.primera());
		i = P[i];
	} while (i != orig);
	return c;
}


template <typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G, matriz<vertice>& P)
{
	const size_t n = G.numVert();
	matriz<tCoste> A(n);
	P = matriz<vertice>(n);
	for (vertice i = 0; i < n; i++) {
		// copia costes del grafo
		A[i] = G[i];
		A[i][i] = 0;
		// diagonal a 0
		P[i] = vector<vertice>(n, i);
		// caminos directos
	}
	// Calcular costes mínimos y caminos correspondientes
	// entre cualquier par de vértices i, j
	for (vertice k = 0; k < n; k++)
		for (vertice i = 0; i < n; i++)
			for (vertice j = 0; j < n; j++) {
				tCoste ikj = suma(A[i][k], A[k][j]);
				if (ikj < A[i][j]) {
					A[i][j] = ikj;
					P[i][j] = k;
				}
			}
	return A;
}


typedef Lista<vertice> tCamino;
tCamino caminoAux(vertice i, vertice j, const matriz<vertice>& P)
// Reconstruye el camino entre i y j, excluidos estos, a
// partir de una matriz P obtenida mediante la función Floyd().
{
	tCamino c1, c2;
	vertice k = P[i][j];
	if (k != i) {
		c1 = caminoAux(i, k, P);
		c1.insertar(k, c1.fin());
		c2 = caminoAux(k, j, P);
		c1 += c2; // Lista<vertice>::operator +=(), concatena c1 y c2
	}
	return c1;
}
tCamino camino(vertice i, vertice j, const matriz<vertice>& P)
// Reconstruye el camino de i a j a partir de una matriz P
// obtenida mediante la función Floyd().
{
	tCamino c = caminoAux(i, j, P);
	c.insertar(i, c.primera());
	c.insertar(j, c.fin());
	return c;
}


matriz<bool> Warshall(const Grafo& G)
{
	const size_t n = G.numVert();
	vertice i, j, k;
	// Inicializar A con la matriz de adyacencia de G
	matriz<bool> A(n);
	for (vertice i = 0; i < n; i++)
		A[i] = G[i];
	// Comprobar camino entre cada par de vértices i, j
	// a través de cada vértice k
	for (vertice k = 0; k < n; k++)
		for (vertice i = 0; i < n; i++)
			for (vertice j = 0; j < n; j++)
				if (!A[i][j])
					A[i][j] = A[i][k] && A[k][j];
	return A;
}

