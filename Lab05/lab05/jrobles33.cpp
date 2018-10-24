#include <iostream>


using namespace std;



void Max_Heapify(int arr[], int n, int i){
int root = arr[0];
int largest = i;
int left = 2*i;
int right = 2*i + 1;


if (left < n && arr[left] > arr[largest]) {
	largest = left; 
	}

else largest = i;

if (right < n && arr[right] > arr[largest]){
	largest = right; 
	}

if (largest != i) { 
	int t = arr[i];
	arr[i] = arr[largest];
	arr[largest] = t;
	Max_Heapify(arr, n, largest); 
	}

}

void Build_Max_Heap(int arr[], int n){
int parent = (n/2);
for ((parent-1); parent >=0; parent--){
	Max_Heapify(arr, n, parent);
}
}

void Heapsort(int arr[], int heapsize){
Build_Max_Heap(arr, heapsize);
for (int i =heapsize-1; i>=0; i--){
	int t = arr[i];
	arr[i] = arr[0];
	arr[0] = t;
	Max_Heapify(arr, i, 0);
}
}

int main(){

int size;
//cout<<"Please insert the size of the array"<<endl;

cin>>size;
int arr[size];

//cout<<"Beginning to fill array"<<endl;

for(int i = 0; i < size; i++){
	cin>>arr[i];
	}
//cout<<"Array filled"<<endl;
//cout<<"Print unsorted array :"<<endl;
//for(int i = 0; i < size; i++){
//	cout<<arr[i]<<"; ";
//	}
//cout<<endl;
int n = size;
int heapsize = size;
Heapsort(arr, n);
//cout<<"Print sorted array :"<<endl;
for(int i = 0; i < size; i++){
	cout<<arr[i]<<";";
	}

}

