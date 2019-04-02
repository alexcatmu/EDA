#include <iostream>
#include <vector>

using namespace std;

int inversions = 0;

void print_vector(const vector<int>& v){
    for(int i = 0; i < v.size(); i++) cout << v[i];
    cout << endl;
}

void merge(vector<int>& v, int l, int middle, int r){
    int i = l;
    int j = middle+1;
    vector<int> aux(r-l+1);
    int k = 0;
    while(i <= middle and j <= r){
        if(v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
            k++;
        } else {
            aux[k] = v[j];
            j++;
            k++;
            inversions += middle + 1 - i;
        }
    }
    while(i <= middle) {
        aux[k] = v[i];
        i++;
        k++;
    }
    while(j <= r){
        aux[k] = v[j];
        j++;
        k++;
    }
    for(k = 0; k < r-l+1; k++){
        v[l+k] = aux[k];
    }
}

void mergeSort(vector<int>& v, int l, int r){
    if(l < r) {
        int m = (l+r) / 2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v, l, m, r);
    }
}

int main(){
    int n;
    int number;

    while(cin >> n){
        vector<int> v(n);
        inversions = 0;
        for(int i = 0; i < n; ++i){
            cin >> number;
            v[i] = number;
        }
        mergeSort(v, 0, v.size()-1);
        //print_vector(v);
        cout << inversions << endl;
    }
}