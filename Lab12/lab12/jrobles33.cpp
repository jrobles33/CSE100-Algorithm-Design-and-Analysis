#include <iostream>
using namespace std;

int Extended_Bottom_Up_Cut_Rod(int p[], int n){

int rev[n];
int slice[n];
rev[0] = 0;
for (int j = 1; j <= n; j++){
	int max = -9999;
	for (int i = 1; i <= j; i++){
		int comparison = (p[i] + rev[j-i]);
		if (max < comparison){
		max = comparison;
		slice[j] = i;
		}
		
		}
	rev[j] = max;
	}
cout<<rev[n]<<endl;
while( n > 0){
	cout<<slice[n]<<" ";
	n = n-slice[n];
	}
cout<<"-1"<<endl;
return rev[n];
return slice[n];

}


int main(){

int rod_length;
cin>>rod_length;

int prices[rod_length];

for(int i = 1; i <= rod_length; i ++){
cin>>prices[i];
}

//testing for any changes
/*cout<<endl;
cout<<"Prices check"<<endl;
for(int i = 1; i <= rod_length; i ++){
cout<<prices[i];
}*/
//end test

Extended_Bottom_Up_Cut_Rod(prices, rod_length);
//Print_Cut_Rod_Solution(prices, rod_length);


}
