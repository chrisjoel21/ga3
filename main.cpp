#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
using namespace std;


struct Node {
	int data;
     Node *left;
     Node *right;
};


Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
//insert into bst
Node* Insert(Node* root, int value)
{
    if (!root) {
        //insert the first node, if root is NULL.
        return newNode(value);
    }
 
    //insert data.
    if (value > root->data) {
 
        //process right nodes.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
 
        root->left = Insert(root->left, value);
    }
 
    return root;
}


void printPreorder(struct Node* node, string location,ofstream &ben)
{
	if (node == NULL){
		return;
    }

	ben << location + "]"  << " " << node->data << endl;


	printPreorder(node->left,location + "l",ben);


	printPreorder(node->right,location + "r",ben);
}







int main(int argc, char *argv[]){
ArgumentManager am (argc, argv);

ifstream input(am.get("input"));
ofstream output(am.get("output"));
//ifstream input("input1.txt");
//ofstream output("output1.txt");
string data;

input >> data;
int firstData = stoi(data);
	struct Node* root = newNode(firstData);
    //insert data into bst
    while(input >> data){
        int ben = stoi(data);
        Insert(root,ben);
    }

    //call preOrder func bc bst is made
    string location = "[x";
	printPreorder(root,location,output);

	return 0;
}
