
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

// El coste del problema en el caso peor es O(n) respecto al numero de puntuaciones ya que el numero de iteraciones es n
// y el coste de cada iteración es costante ya que tanto la condición como el cuerpo son constantes.

/*
{ 0 <= N <= INT_MAX  }

fun problema(int v[]) dev ( )

{ s1 = #i: 0 <= i < N: para todo j: 0<= j <= i <= N: v[i] >= v[j]
  s2 = v[i]}

*/

void resuelveCaso() {

    int n, max, cont = 0;

    cin >> n;
    max = n;
  
    while (n != 0) {

        if (n > max) {
            max = n;
            cont = 1;
        }
        else if (n == max) cont++;

        cin >> n;

    }

    cout << max << " " << cont << endl;

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
