
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// Este problema en el caso peor tiene coste O(N) siendo N el numero de elementos del vector
// ya que en el peor caso el primer bucle tendria n-1 iterariaciones donde cada una de las iteraciones 
//tienen costes O(1) ya que tanto la condicion como el cuerpo tienen coste O(1). El segundo bucle en este 
// caso solo se recorre una vez. 
// En el peor caso del segundo bucle seria lo mismo a la inversa. Por tanto el problema tiene coste O(N)

/*
{ 0 <= v.size /\ p >= 0   }

fun bienDividido( int v[], int p ) dev ( bool b )

{ b = (para todo i, j, q, t : 0 <= i <= q <= p < j <= t <= N: (v[i] >= v[q] ) and (v[j] <= v[t]) and (v[i] < v[j])) }
*/


bool bienDividido(vector<int> const& v, int p) {

    bool sol= true;

    int min , max;

    if (v.size() == 1 || p == v.size()-1) {
        return true;
    }
    
    min = v[p + 1];
    max = v[p];

    for (int i = 0; i <= p; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }

    for (int i = p + 1; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }

    if (max >= min) sol = false;

    return sol;
}

    void resuelveCaso() {

        int n, p, a;
        bool sol;

        vector<int> v;

        cin >> n >> p; 

        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }

        sol = bienDividido(v, p);

        if (sol) {
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
