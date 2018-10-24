//I used my textbook, lecture notes to create radix sort. I also got help from Miguels office hours and cpp.org to learn how vectors work and how to use them

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;


/*
VectorCreation(size);
cout << "Does it make it here";

for(auto ir = v.begin(); ir != v.end(); ir++){
cout << *ir << " ";
}
//cout<<endl;
*/

void Counting_Sort(vector<int>** A, int d, int size){

int Carr[size];
vector<int>* j = new vector<int>[size];

int Count[10];
memset(Count, 0, 10*sizeof(int));
int i = 0;
while(i < size){
	Count[(*A)[i][d]]++;
	i++;
	}
int jay = 1;
while(jay < 10){
	Count[jay] += Count[jay-1];
	jay++;
	}
int k = size-1;
while(k>=0){
	Carr[Count[(*A)[k][d]]-1] = k;
	Count[(*A)[k][d]]--;
	k--;
}
int l = 0;
while(l<size){
	j[l] = (*A)[Carr[l]];
	l++;
}

delete[] *A;
*A = j;
}

//go from least significant digit Right -> Left
void Radix_Sort(vector<int>** Vec, int size){
	for (int i = 9; i >= 0; i--){	
		Counting_Sort(Vec, i, size);
	}
}

int main(){

//vector<int> v;
//vector<int>v2;
//for(int i = 0; i < size; i++){
//v.push_back(i);
//}

int size;
cin>>size;
vector<int>* Vec = new vector<int>[size];

int input;
int i = 0;

while(i<size){
	int j = 0;
	while(j<10){
		cin>>input;
		Vec[i].push_back(input);
		j++;
		}
		i++;
	}

Radix_Sort(&Vec, size);

int k = 0;
while( k < size){
	//what does auto mean lol 
	for (auto yeet = Vec[k].begin(); yeet != Vec[k].end(); yeet++){
		cout << *yeet << ';';	
		}

		k++;
		cout << endl;
		
	}

return 0;
}

/*
for(int i = 0; i < size; i++){
	for(int i = 0; i < 10; i ++)
	
	}
*/



/*
vector<int> v;
vector<int>v2;
for(int i = 0; i < size; i++){
v.push_back(i);
}
int counter = 0;
while (counter < size){
for(int i = 0; i < 10; i++){
	int x;
	cin>>x;
	v.push_back(x);
}
counter++;
}
for(auto ir = v.begin(); ir != v.end(); ir++){
cout << *ir << " ";
}
cout<<endl;
for(int i = 0; i < 10; i++){
	int x;
	cin>>x;
	v.push_back(x);
}


VectorCreation(size);
cout << "Does it make it here";

for(auto ir = v.begin(); ir != v.end(); ir++){
cout << *ir << " ";
}
cout<<endl;


Ask miguel about this 

typedef vector<vector<double>>matrix;
matrix name(sizeX, vector<double>(sizeY));


for(int i = 0; i < size; i++){
	for(int i = 0; i < 10; i ++)
	
	}
return 0;
}
*/
