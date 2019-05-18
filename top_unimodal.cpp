#include<iostream>
#include<vector>
using namespace std;

int top_unimodal(vector<int>& v, int n){
	if(v[n] > v[n-1] and v[n] > v[n+1]) {
		//cout << "if top" << endl;
		return v[n];
	}
	else if(v[n] > v[n-1]) {
		//cout << "if derecha" << endl;
		return top_unimodal(v, n+(n/2));	
	}
	else {
		//cout << "if izda" << endl;
		return top_unimodal(v,n-(n/2));	
	}
}

int main(){
	vector<int> v{1,2,4,8,12,20,30,20,10};
	cout << top_unimodal(v, v.size()/2) << endl;
	
	
	vector<int> v2{1,2,4,1};
	cout << top_unimodal(v2, v2.size()/2) << endl;
	
	
	vector<int> v3{1,2,0};
	cout << top_unimodal(v3, v3.size()/2) << endl;
	
	
	vector<int> v4{1,2,4,8,12,20,30,20,10,9,8,7,6,5,4,3,2,1,0};
	cout << top_unimodal(v4, v4.size()/2) << endl;
	
	
	vector<int> v5{1,2,4,8,12,20,21,22,23,24,25,26,27,30,20,10};
	cout << top_unimodal(v5, v5.size()/2) << endl;

	return 0;
}

