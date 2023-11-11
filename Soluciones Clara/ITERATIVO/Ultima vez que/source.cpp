
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

//Este problema en su peor caso tiene un coste O(N) siendo N el numero de pais en el vector
//ya que el bucle tiene N iteraciones donde cada una de ellas tiene coste O(1) ya que tanto su 
// condicion como su cuerpo tienen coste O(1)



/*
{  0 <= n <= 100 000 }
fun ultimoGanador ( string v[], int n, string p) dev (int s)
{ s = (n - i: (exist i: 0 <= i <= n: (v[i] = p) ^ (para todo j: 0 <= j <= i <= n))) or ( -1) }
*/
int ultimoGanador(vector <string> const& ganadores, int n, string pais) {

    int cont= 1, i=n-1;

    while (ganadores[i] != pais && i > 0) {
        cont++;
        i--;
    }

    if (cont == n && ganadores[0] != pais) cont = -1;

    return cont;
}

bool resuelveCaso() {

    int n;
    string pais, a;
    vector <string> ganadores;

    cin >> n;
    if (n==0)
        return false;

    cin >> pais;

    for (int i = 0; i < n; i++) {
        cin >> a;
        ganadores.push_back(a);
    }

    int solucion;

    solucion = ultimoGanador(ganadores, n, pais);

    if (solucion == -1) cout << "NUNCA" << endl;
    else cout << solucion << endl;

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
