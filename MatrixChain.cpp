#include <iostream>
#include <array>

using namespace std;

void MatrixChainOrder(int* dim) {
	int n = dim.size() - 1;
	int** m = new int[n];
	for (int i = 0; i < n; i++)
		m[i] = new int[n];
	int** s = new int[n-1];
	for (i = 0; i < n-1; i++)
		s[i] = new int[n];
	for (i = 0; i < n; i++)
		m[i][i] == 0;
	for (int l = 1; l < n; l++){
		for (i = 0; i < n - l + 1; i++){
			int j = i + l - 1;
			m[i][j] = 2147483647;
			for (int k = i; k < j - 1; k++){
				int p = dim[i] * dim[k] * dim[j];
				int q = m[i][k] + m[k + 1][j] + p;
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m << endl;
	printOptimal(s, 0, dim.size());
	for (i = 0; i < n; i++)
		delete [] m[i];
	delete [] m;
	for (i = 0; i < n-1; i++)
		delete [] s[i];
	delete [] s;
}

void printOptimal(int** s, int i, int j){
	if (i = j)
		cout << "A" << i;
	else {
		cout << "(";
		printOptimal(s, i, s[i][j]);
		printOptimal(s, s[i][j]+1, j);
		cout << ")";
	}
}



int main() {
	int num;
	cin >> num;
	int* dim = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> dim[i];
	}
	MatrixChainOrder(dim);
}