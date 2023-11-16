
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
bool degradado(const vector<int>& v, int ini, int fin) {
    if (fin - ini == 1) {
        if (v[ini] < v[fin]) return true;
        else return false;
    }
    else {
        int medio = (ini + fin) / 2;
        if (degradado(v, ini, medio) < degradado(v, medio + 1, fin)) return true;
        else return false;
    }
}
bool esDegrado(const vector<vector<int>> m, int ini, int fin) {

    bool d = true;
    int i = 0;
    while (i < m.size() && d) {
        d = degradado(m[i], 0, m[i].size() - 1);
        i++;
    }

    return d;

}
bool resuelveCaso() {

    int n, m, a;
    
    cin >> n >> m;
    if (!cin)
        return false;

    vector<vector<int>> matriz(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;

            matriz[i][j]=a;
            
        }
    }

    if (esDegrado(matriz, 0, n)) cout << "SI" << endl;
    else cout << "NO" << endl;


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
