//I used the textbook and lecture notes to complete the lab

#include <iostream>
#include <string>

using namespace std;

struct node 
{
	int key; 
	struct node *left, *right, *parent;
}; 

node *newnode(int value){
	node* temp = new node;
	temp->key = value; 
	temp->left = temp->right = temp->parent=NULL; 
	return temp; 
} 

void preorder(node *x) 
{ 
	if (x != NULL) 
	{	if(x->key != 0){
		cout<<x->key<<endl; 
		}
		preorder(x->left); 
		preorder(x->right); 
	}
}

void postorder(node *x) 
{ 
	if (x != NULL) 
	{	
		postorder(x->left); 
		postorder(x->right); 
		if(x->key != 0){
		cout<<x->key<<endl; 
		}
	}
}

void inorder(node *x) 
{ 
	if (x != NULL) 
	{
		inorder(x->left); 
		if(x->key != 0){
		cout<<x->key<<endl; 
		}
		inorder(x->right); 
	}
}

node* Tree_Insert(node* T, int zee){
	node* y = NULL;
	node* x = T;
	node* z = newnode(zee);
	while( x!= NULL){
		y = x;
		if (z->key < x->key){
			x = x->left;
			}
		else{
			x = x->right;
		}
		}
	z->parent=y;
	if(y==NULL){
		T->key = z->key;
		}
	else if(z->key <= y->key){
		y->left = z;
		}
	else {
		y->right=z;
		}
	return T;
}

node* Tree_Minimum(node* x){
	while(x->left != NULL){
		x=x->left;
	}
	return x;
}

node* Tree_Maximum(node* x){
	while(x->right != NULL){
		x=x->right;
	}
	return x;
}
		

node* Tree_Search(node* x, int k){
	if (x==NULL || k == x->key){
		return x;
		}
	if(k < x->key){
		return Tree_Search(x->left,k);
		}
	else{
		return Tree_Search(x->right,k);
		}
}

bool Deletion_Search(node* x, int k){
	while (x != NULL){
	if (k == x->key){
		//return x;
		return true;
		}
	if(k < x->key){
		return Deletion_Search(x->left,k);
		}
	if (k > x-> key){
		return Deletion_Search(x->right,k);
		}
	}
	return false;
}



node* Transplant(node* T, node* u, node* v){
if (u->parent == NULL){
	T=v;
	}
else if(u==u->parent->left){
	u->parent->left = v;
	}
else{
	u->parent->right = v;
	}
if( v != NULL){
	v->parent = u->parent;
	}
return T;
}



node* Tree_Delete(node* T, int value){
node* z = Tree_Search(T, value);
if (z->left == NULL){
	Transplant(T,z,z->right);
	}
else if(z->right == NULL){
	Transplant(T, z, z->left);
	}
else {
	node *y = Tree_Minimum(z->right);
	if(y->parent != z){
		Transplant(T, y, y->right);
		y->right = z->right;
		y->right->parent = y;
		}
	Transplant(T,z,y);
	y->left = z->left;
	y->left->parent = y;
	}
return T;
}


node* Iterative_Tree_Search(node* x, int k){
	while(x != NULL && k != x->key){
		if (k < x->key){
			x = x->left;
			}
		else {
			x = x->right;
			}
	}
	return x;
}



int main(){

int booboo=0;
int max=1;
int key;
int del;
bool initialize = false;
node* T = new node;
while(booboo<max){

string str; 
cin>>str;

if (str == "i"){
	cin>>key;
	Tree_Insert(T, key);
	booboo = 0;
	
	}
if (str == "d"){
	cin>>del;
	initialize = Deletion_Search(T, del);
	if (initialize != false){
	Tree_Delete(T, del);
	}
	}
if (str == "pre"){
	preorder(T);
	cout<<"++++++++++++++++++++"<<endl;
	
	}
if (str == "post"){
	postorder(T);
	cout<<"++++++++++++++++++++"<<endl;
	
	}
if (str == "in"){
	inorder(T);
	cout<<"++++++++++++++++++++"<<endl;
	
	}
if (str == "e"){
	booboo = 1;
	
	}

}
return 0;
}










