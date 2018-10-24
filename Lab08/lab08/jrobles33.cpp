//I used the textbook, lecture notes, and cpp.com website for vector references and help sorting them

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(int arr[], int p, int r){

int pivot = arr[r];
int i = 0;
i = p-1;

for (int j = p; j <= r-1; j++){
	if (arr[j]<=pivot){
	i = i+1;
	swap(arr[i], arr[j]);
	//cout<<"is this the culprit? :"<<arr[i]<<endl;
	}
	}
	swap(arr[i+1], arr[r]);
	//	cout<<"is this the culprit 2? :"<<arr[i]<<endl;
	return(i+1);
}

int Randomized_Partition(int arr[], int p, int r){
srand(time(NULL));
int i = p + rand() % (r-p);
swap(arr[i], arr[r]);
return Partition(arr, p, r);
}

void Randomized_Quicksort(int arr[], int p, int r){

if (p < r){
	int q = Randomized_Partition(arr, p, r);
	Randomized_Quicksort(arr, p, q-1);
	Randomized_Quicksort(arr, q+1, r);
}
}

void Insertion_Sort(int arr[], int n){
int size;
cin>>size;
for (int i = 0; i < size; i++){
	int j = i;

	while ( j > 0 && arr[j] > arr[j-1]){	
	int k = arr[j];
		arr[j] = arr[j-1];
		arr[j-1] = k;
		j--;
		}


}
for (int i = 0; i < size; i++){

cout << arr[i] << ";";
}
}

void Bucket_Sort(float arr[], int n){ 

vector<float> b[n]; 
     
int i = 0;
while(i<n){
	int in = n*arr[i]; 
	b[in].push_back(arr[i]); 
	i++;
	}
for(int i=0; i<n; i++){
	sort(b[i].begin(), b[i].end()); 
	}

int conc = 0;
i = 0;

while(i<n){
        for (int j = 0; j < b[i].size(); j++) {        
 		arr[conc] = b[i][j]; 
		conc = conc+1; 
		}
	i++;
	}
}


int main(){

int size;
cin>>size;

float arr[size];

int i = 0;
while(i < size){
	cin>>arr[i];
	i++;
	}

Bucket_Sort(arr, size);

i = 0;
while(i < size){
	cout<<arr[i]<<endl;
	i++;
	}
return 0;
}
