
/*@ <answer>
 *
 * Nombre y Apellidos: Clara Sotillo Sotillo
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

bool esApto(const vector<int>& v, int d, int n) {

    bool apto = true;
    int ini= 0, fin= 0;
    int i = 0;
    
    while (apto && (i < n)) {

        if (v[i] < v[i + 1] ) {

            if (ini == 0) {
                ini = v[i];
                fin = v[i + 1];
            }
            else {
                fin = v[i + 1];
            }
        }
        else if (v[i] >= v[i + 1]) {

            if (fin != 0) {

                if (fin - ini > d) apto = false;
                ini = 0;
                fin = 0;
            }
        }
       
        i++;

    }
    
    if (ini != 0) {
        if (fin - ini > d) apto = false;
    }

    return apto;
}

bool resuelveCaso() {

    int d, n, a;
    vector<int> v;
    cin >> d >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    if (esApto(v, d, n))cout << "APTA" << endl;
    else cout << "NO APTA" << endl;
    

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
