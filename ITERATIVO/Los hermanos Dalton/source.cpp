
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
 // 
// El coste en el caso peor es O(N) siendo n el numero de personajes que aparecen en la vi�eta
//ya que el numero de iteraciones es n y cada iteracion tiene coste constante ya que tanto la condion como el 
// cuerpo son de coste constante

/*

 { para todo i: 0 <= i <= v.size v[i] >= 1 /\ v[i] <= 10^6 /\ v.size > 0 }
  fun esDalton ( vector <int> v) dev (bool b)

  { b = (para todo i: 0 <= i <= v.size -1: v[i] > v[i +1 ] \/ v [ i ] < v[i + 1] }


  invariante: 

  funcion de cota

*/

// dividir en dos funciones es creciente o decreciente y especifica ambas
bool esDalton(vector <int> const& alturas, int const& n) {
    bool solucion = true, ascendente= true;
    int i=1;
    if (n == 1 ) return true;
    if (alturas[0] > alturas[1]) ascendente = false;
    if (alturas[0] == alturas[1]) return false;

    while (i < n-1 && solucion == true) {
        if (ascendente) {
           if (alturas[i] >= alturas[i + 1]) solucion = false;
        }
        else {
            if (alturas[i] <= alturas[i + 1]) solucion = false;
        }

        i++;
    
    }

   return solucion;
}



bool resuelveCaso() {

    int n, a;
    vector<int> alturas;
    bool solucion;
    
    cin >> n;
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> a;
        alturas.push_back(a);
    }

    solucion = esDalton(alturas, n);

    if (solucion) cout << "DALTON" << endl;
    else cout << "DESCONOCIDOS" << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
