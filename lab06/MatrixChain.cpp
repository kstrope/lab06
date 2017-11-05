#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void printOptimal(vector< vector<int> > &s, int i, int j){
//	cout << "test" << endl;
	if (i == j){
//		cout << "test2" << endl;
		cout << "A" << i-1;
	}
	else {
//		cout << "test3 i = " << i << " j = " << j << endl;
		cout << "(";
		printOptimal(s, i, s[i][j]);
//		cout << "test4" << endl;
		printOptimal(s, s[i][j]+1, j);
		cout << ")";
	}
//	cout << "i = " << i << "j = " << j << endl;
}

void MatrixChainOrder(vector<int> dim) {
	int n = dim.size();
	int m[n][n];
	vector< vector<int> > s(n-1, vector<int>(n-1, 0));
	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l < n; l++){
		for (int i = 1; i < n - l + 1; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++){
				int p = dim[i-1] * dim[k] * dim[j];
				int q = m[i][k] + m[k + 1][j] + p;
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m[1][n-1] << endl;
	printOptimal(s, 1, dim.size()-1);
	cout << endl;
}


int main() {
	int num;
	cin >> num;
	int input;
	vector<int> dim;
	for (int i = 0; i < num+1; i++) {
		cin >> input;
		dim.push_back(input);
	}
//	cout << dim.size() << endl;
	MatrixChainOrder(dim);
}
