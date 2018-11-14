#include <iostream>


using namespace std;

/*
int Bottom_Up_Cut_Rod(int p[], int n){
int r[n];
r[0]=0;
for (int j = 0; j < n; j++){
	int q = min();
	for (int i = 0; i < j; i++){
		q = max(q, p[i] + r[j-i]);
		}
	r[j] = q;
	}
return r[n];
} */

int Extended_Bottom_Up_Cut_Rod(int p[], int n){

int r[n];
int s[n];
r[0] = 0;

for (int j = 1; j <= n; j++){
	int q = -9999;
	for (int i = 1; i <= j; i++){
		if (q < (p[i] + r[j-i])){
		q =(p[i] + r[j-i]);
		s[j] = i;
		}
		}
	r[j] = q;
	}
cout<<r[n]<<endl;
while( n > 0){
	cout<<s[n]<<" ";
	n = n-s[n];
	}
cout<<"-1"<<endl;
return r[n];
return s[n];

}
/*
void Print_Cut_Rod_Solution(int p[], int n){
int r[n];
int s[n];
(r,s) = Extended_Bottom_Up_Cut_Rod(p, n);
while (n > 0){
	cout <<s[n]<< " ";
	n = n-s[n];
	}
}
*/





int main(){

int rod_length;
cin>>rod_length;

int prices[rod_length];

for(int i = 1; i <= rod_length; i ++){
cin>>prices[i];
}

Extended_Bottom_Up_Cut_Rod(prices, rod_length);
//Print_Cut_Rod_Solution(prices, rod_length);


}
