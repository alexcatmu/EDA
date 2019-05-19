#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Adyacencias {
    int distancia, destino;
    Adyacencias(int Distancia, int Destino){
        distancia = Distancia;
        destino = Destino;
    }
    inline bool operator >(const Adyacencias& a){
        return a.distancia > distancia;
    }
};

int initDistance = -1;
int dijkstra(vector<vector<Adyacencias> >& g, int start, int end, vector<int>& path){
    int n = g.size();

    vector<bool> mark(n, false);
    vector<int> distances(n, initDistance);
    distances[start] = 0;
    path = vector<int>(n, -1);//la ruta maxima posible serian todos los vertices, la iniciamos a -1 para saber por que vértices no pasaremos
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0,start));
    while(!q.empty()){
        int vertice_actual = q.top().second;
        q.pop();
        if(!mark[vertice_actual]){
            mark[vertice_actual] = true;
            for(Adyacencias ady : g[vertice_actual]){
                int vertice_adyacente = ady.destino;
                int distancia = ady.distancia;
                if((distances[vertice_adyacente] > distances[vertice_actual] + distancia) or distances[vertice_adyacente] == initDistance){
                    distances[vertice_adyacente] = distances[vertice_actual] + distancia;
                    path[vertice_adyacente] = vertice_actual;
                    q.push(make_pair(distances[vertice_adyacente], vertice_adyacente));
                }
            }
        }
    }
    return distances[end];
}

void print (const vector <int> &path , int end)
{
    stack <int> s;
    bool found = false;
    int i = end;
    while (not found)
    {
        s.push(i);
        i = path[i];
        found = i == -1;//encontrado el elemento inicial
    }

    //imprimimos la pila
    bool first = true;
    while (not s.empty())
    {
        if (first) first = false;
        else cout << ' ';
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main(){
    int vertices, arcos;
    while(cin >> vertices >> arcos){
        vector<vector<Adyacencias> > g(vertices, vector<Adyacencias>());
        for(int i = 0; i < arcos; i++){
            int origen, destino, distancia;
            cin >> origen >> destino >> distancia;
            g[origen].push_back(Adyacencias(distancia,destino));
        }
        int start, end;
        cin >> start >> end;
        vector<int> path;
        int distancia_minima = dijkstra(g, start, end, path); 
        if(distancia_minima == -1) cout << "no path from " << start << " to " << end << endl;
        else print(path, end);
    }
}