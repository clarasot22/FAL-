
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

bool indicePastoso(const vector<int>& v,int& indice) {

    bool pastoso = false;
    int sum=0, i= v.size()-1;

    while (!pastoso && i >= 0){
        if (v[i] == sum) {
            indice = i;
            pastoso = true;
        }
        sum += v[i];
        i--;
    }

    return pastoso;
}

void resuelveCaso() {

    int n, a;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    int indice = n;
    if (indicePastoso(v, indice)) cout << "Si " << indice << endl;
    else cout << "No" << endl;

   
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
