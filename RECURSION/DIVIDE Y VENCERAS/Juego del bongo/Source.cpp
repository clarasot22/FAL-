
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

int juegoDelBongo(const vector<int>& v, int cant, int ini, int fin) {

    if(ini-fin==0) {
        if (cant + ini == v[ini]) return v[ini];
        else return -1;
    }
    else {
        int medio = (ini + fin) / 2;
        int sol = cant + medio;
        if (sol == v[medio]) return v[medio];
        if (sol <= v[medio] ) return juegoDelBongo(v, cant, ini, medio);
        else return juegoDelBongo(v, cant, medio + 1, fin);
    }

}

void resuelveCaso() {

    int n, c,a;
    vector<int>v;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    int solucion = juegoDelBongo(v, c, 0, n - 1);

    if (solucion != -1) cout << solucion << endl;
    else cout << "NO" << endl;
    
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
