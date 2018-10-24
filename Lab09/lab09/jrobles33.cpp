// I used the textbook, lecture notes, cpp.com for list reference, and algolist.com for help creating a skeleton for hash tables. I also used stackoverflow and various other websites for any errors I was encountering 

#include<iostream> 
#include <list> 

using namespace std; 
  
class Hash{ 
int m; //this will be our hash function for k mod m


// pointer to our hash indexes
list<int> *T; 
public: 

Hash(int construct);

int hashFunction(int k){ 
	return (k % m);
	}

void search(int key);

void insertion(int x);

void deletion(int key);

void output();
};

Hash::Hash(int k){ 

this->m = k; 
T = new list<int>[m]; 


} 

void Hash::insertion(int key){

int index = hashFunction(key); 
T[index].push_front(key);

} 
  
void Hash::deletion(int key){

int index = hashFunction(key); 
int check = 0;

list <int> :: iterator i; 
for (i = T[index].begin(); i != T[index].end(); i++) { 
	if (*i == key) {
		check = 1;
		break; 
		} 
	}
	if (check == 1){
		if (i != T[index].end()){
			T[index].erase(i); 
			cout<<key<<" : DELETED"<<endl;
			}
		}
	if (check == 0){
	cout<<key<< " : DELETE FAILED"<<endl;
	}
}
 
void Hash::output(){

for(int count = 0; count <m; count++){
	cout << count <<" : ";
	for(auto j = T[count].begin(); j!= T[count].end(); j++)
		if (j==T[count].begin()){
		cout<<*j;}
		else{
			cout<<"->"<<*j;
		}
	cout<<endl;
	}
}

void Hash::search(int key){
	//cout<<"it might be here";
	int check = 0;
	int index = hashFunction(key);
	list<int>::iterator i;
	int counter = 0;
	for( i = T[index].begin(); i!= T[index].end(); i++){
		if(*i==key){
			cout<<key<<" : FOUND AT "<<index<<","<<counter<<endl;
			check = 1;
			break;
		}
		counter++;
	}
	if (check == 0){
	cout<<key<<" : NOT FOUND"<<endl;
	//make sure formatting is correct here
	}
}

int main(){
int value;
cin >>value;

Hash h(value); 
//need to put in a check for all dis 
int booboo = 0;
int max = 1;
while (booboo < max){
char method;
cin >>method;
switch(method){

	case 'i':
		int num;
		cin >>num;
		h.insertion(num);
		break;
	case 'd':
		int del;
		cin >>del;
		h.deletion(del);
		cout<<"++++++++++++++++++++"<<endl;
		break;
	case 's':
		int s;
		cin>>s;
		h.search(s);
		cout<<"++++++++++++++++++++"<<endl;
		break;
	case 'o':
		h.output();
		cout<<"++++++++++++++++++++"<<endl;
		break;
	case'e':
		booboo = 3; // this will break me out of the switch case loops
		return 0;
	default:
		break;
	}
}
//do i really need to return 0 if im doing it up above? 
return 0; 
} 

