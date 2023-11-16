
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
void resolver(const vector<int>& v,int n, long long int& suma,int& cont) {

    int min = v[0];

    suma = v[0];

    for (int i = 1; i < n; i++)
    {
        suma += v[i];
        if (v[i] < min) {
            min = v[i];
            cont = 1;
        }
        else if (v[i] == min) cont++;
    }
    suma = suma - (cont * min);
    cont = n - cont;
}


void resuelveCaso() {

    int n, a, cont = 1;
   long long int sum = 0;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    resolver(v, n, sum, cont);

    cout << sum << " " << cont << endl;

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
