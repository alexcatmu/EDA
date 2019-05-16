// #include <howarto>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

// Este ejercicio lo har� con matrices de adyacencias...
// EDITO: No, mejor listas porque si no hay que hacer un mayor n�mero de pasadas por los bucles.
// Si lo haces con la matriz el jutge te mete un EE de l�mite de tiempo.


// Los dos mapas los uso como sistema de traducci�n numero-string.
// apuntados es un vector que representa en cada �ndice una de las strings introducidas al principio y el valor
// de ese �ndice marca el n�mero de aristas desde otros nodos hacia ella.
// Grafo es simplemente la forma de guardar los datos que nos pasan al principio, cada �ndice representa un nodo y cada columna
// tiene el valor n�merico del nodo hacia donde tiene una arista.
void task_ordering(map<string, int> &mapeado_a_numero, map<int, string> &mapeado_a_string, vector< vector<int> > &grafo, vector<int> &apuntados) {
    priority_queue<string, vector<string>,  greater<string> > cola;
    map<string, int>::const_iterator it = mapeado_a_numero.begin();
    while (it != mapeado_a_numero.end()) {
        if (apuntados[it->second] == 0) {
            cola.push(it->first);
        }
        ++it;
    }

    queue<string> cola_aux;
    while (not cola.empty()) {
        string u = cola.top();
        cola.pop();
        cola_aux.push(u);
        for (int v : grafo[mapeado_a_numero[u]]) {  // Para cada v�rtice v adyacente a u...
            if (--apuntados[v] == 0) {
                cola.push(mapeado_a_string[v]);
            }
        }
    }

    int n = grafo.size();
    if (cola_aux.size() != n) {
        cout << "NO VALID ORDERING" << endl;
    }
    else {
        while (not cola_aux.empty()) {
            cout << cola_aux.front();
            cola_aux.pop();
        }
        cout << endl;
    }
}

int main () {
    int n;
    while (cin >> n) {
        map<string, int> mapeado_a_numero;
        map<int, string> mapeado_a_string;
        for (int i = 0; i < n; i++) {
            string entrada;
            cin >> entrada;
            mapeado_a_numero.insert(make_pair(entrada, i));
            mapeado_a_string.insert(make_pair(i, entrada));
        }

        int m;
        cin >> m;
        vector<int> apuntados(n, 0);
        vector< vector<int> > grafo(n);
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            grafo[mapeado_a_numero[u]].push_back(mapeado_a_numero[v]);
            apuntados[mapeado_a_numero[v]]++;
        }

        task_ordering(mapeado_a_numero, mapeado_a_string, grafo, apuntados);
    }
}
