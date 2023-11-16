
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;



/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

// El coste del problema en el caso peor es O(n) respecto al numero de puntuaciones ya que el numero de iteraciones es n
// y el coste de cada iteraci�n es costante ya que tanto la condici�n como el cuerpo son constantes.

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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
