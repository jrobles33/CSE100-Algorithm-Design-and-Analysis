#include <iostream>
#include <limits.h>

using namespace std;

void Print_Optimal_Parens(int i, int j, int n, int *s){
if (i == j){
	cout<<"A"<<i-1;
	}
else {
	cout<<"(";
	Print_Optimal_Parens(i, *((s+i*n)+j),n,s);
	cout<<".";
	Print_Optimal_Parens(*((s+i*n)+j)+1,j,n,s);
	cout<<")";
}
}

void Exp_Print_Optimal_Parens(int s[][]){
if (i == j){
	cout<<"A"<<i-1;
	}
else {
	cout<<"(";
	Print_Optimal_Parens(i, *((s+i*n)+j),n,s);
	cout<<".";
	Print_Optimal_Parens(*((s+i*n)+j)+1,j,n,s);
	cout<<")";
}
}

int Matrix_Chain_Order(int p[], int n){

//int n = deltasize-1;
int m[n][n];
int s[n][n];
for (int i = 1; i < n; i++){
	m[i][i] = 0;
	}
for(int l = 2; l < n; l++){
	for(int i = 1; i <n - l + 1; i++){
		int j = i+l-1;
		m[i][j] = INT_MAX;
		for(int k = i; k <= j-1; k++){
			int q = m[i][k]+ m[k+1][j]+p[i-1]*p[k]*p[j];
			if(q < m[i][j]){
				m[i][j]=q;
				s[i][j]=k;
				}
			}
		}
	}

int key = m[1][n-1];
cout<<key<<endl;
Print_Optimal_Parens(1,n-1,n, (int *)s);

return key;
}


int main(){

int first;
cin>>first;

int size = first+1;
int p[size];

for(int i = 0; i <size; i++){
cin>>p[i];
}

int value = Matrix_Chain_Order(p,size);
//cout<<"value is "<<value;
cout<<endl;
return 0;
}
