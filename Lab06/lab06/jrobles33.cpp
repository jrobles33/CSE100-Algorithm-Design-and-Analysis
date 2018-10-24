//I used the textbook and lecture notes to complete this lab. 

#include <iostream>
#include <cstdlib>

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


int main(){

int size;
cin>>size;
int arr[size];
for (int i = 0; i < size; i++){
	cin>>arr[i];
	}
Randomized_Quicksort (arr, 0, size-1);
for (int i = 0; i < size; i++){
	cout<<arr[i]<<";";
	}
return 0;
}
