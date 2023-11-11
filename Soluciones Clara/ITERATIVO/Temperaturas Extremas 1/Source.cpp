//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// El coste del problemas en el caso peor es O(N) lineal respecto al tamaño del vector (temperaturas) ya que el numero de  
// iteraciones es n y el coste de cada iteración es constante. Porque tanto el coste de la condicion como del cuerpo es constante.

/*

{        }

fun picosValles ( vector<int> t, int n) 

{ picos = ( #i: 0 <= i <= v.size - 1: (v[i - 1] < v [i]) /\ ( v[i] > v [i+1]))
  valles = (#j: 0 <= j <= v.size - 1: (v[i - 1] > v [i] /\ ( v[i] < v [i + 1]) }

*/
vector <int> picosValles(vector <int> const& temperaturas, int const& n) {

    vector <int> solucion;
    bool ascendente = true, meseta = false;
    int contP = 0, contV = 0;

    if (temperaturas[0] > temperaturas[1]) ascendente = false;

    for (int i = 1; i < n - 1; i++) { // O(N) respecto al numero de temperaturas.
                                      // Ya que el contenido del bucle se ejecuta de manera constante.

        if((temperaturas[i] > temperaturas[i-1]) && (temperaturas[i] > temperaturas[i+1])) contP++; // O(1)
        if((temperaturas[i] < temperaturas[i-1]) && (temperaturas[i] < temperaturas[i+1])) contV++; // O(1)

    }

    solucion.push_back(contP);
    solucion.push_back(contV);

    return solucion;
}

void resuelveCaso() {
    int n, a;
    vector <int> temperaturas, solucion;


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        temperaturas.push_back(a);
    }

    solucion = picosValles(temperaturas, n);

    cout << solucion[0] << " " << solucion[1] << endl;


}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
