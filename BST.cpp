//including library
#include<iostream>
using namespace std;

class node{
		//type
		public:

		int data;
		//pointer pointing to the left node
		node *left;
		//pointer pointing to the right node
		node *right;

		//constructor
		node(int value){
					data=value;
					left=NULL;
					right=NULL;
		}
};

class BST
{
		//type
		public:
		
		node *root;
		//consrtuctor
		BST(){
			root=NULL;
	}

	//insert
	void insert(int value){
			inserthelper(root,value);
	}
	
	//insert helper
	void inserthelper(node *current,int value)
	{
			
			//if root is NULL, create a new node and make it root
			if(root==NULL){
					root=new node(value);
			}
			
			//else move to left if value is less than data stored where current is pointing
			else if(value<current->data){

					//if left is NULL, create a new node and link it.
					if(current->left==NULL){
							current->left=new node(value);
					}

					//if left is not NULL, move the pointer to current left and insert there
					else{
						inserthelper(current->left,value);
					}

			}
			
			//same goes for right
			else{
				if(current->right==NULL){current->right=new node(value);}
				else{inserthelper(current->right,value);}
			
		}
	}

	//display
	void display(){
				displayhelper(root);
	}

	//display helper
	void displayhelper(node *temp)
	{
			if(temp==NULL)
				{return;}
			

			//print left
			displayhelper(temp->left);
			
			//printing self
			cout<<temp->data<<" , ";
			
			//print right
			displayhelper(temp->right);
									

			
	
		

		
	}

//search
node *search(int value){
		return searchhelper(root,value);
	}

node *searchhelper(node *current,int value){
		//check the value
		if(current==NULL || current->data==value){return current;}
		
		//else search in right or left
		//left
		else if(value<current->data){return searchhelper(current->left,value);}
		//right
		else return searchhelper(current->right,value);
	}


};


int main(){
		BST b;
		
		b.insert(5);b.insert(2);b.insert(8);b.insert(3);b.insert(9);b.insert(4);b.insert(1);b.insert(6);
		b.display();
		


		if(b.search(6)!=NULL){
					cout<<endl<<b.search(6)->data<<endl;
		}
	
}
			
					

				
