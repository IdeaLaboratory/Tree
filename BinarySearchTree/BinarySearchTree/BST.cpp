#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node *left;
	Node *right;
};

Node* CreateNode(int p_val)
{
	Node *newNode = new Node();
	newNode->val = p_val;
	newNode->left = newNode->right = NULL;
	return newNode;
}
void InsertNode(Node **p_root, int p_val)
{
	if (*p_root == NULL)
	{
		*p_root = CreateNode(p_val);
		return;
	}

	if ((*p_root)->val >= p_val)
		InsertNode(&(*p_root)->left, p_val);
	else
		InsertNode(&(*p_root)->right, p_val);
}

Node* Search(Node* p_root, int p_val)
{
	if (p_root == NULL)
		return NULL;
	else if (p_root->val == p_val)
		return p_root;
	else if (p_root->val > p_val)
		Search((p_root)->left, p_val);
	else
		Search((p_root)->right, p_val);
}
Node* findMin(Node* p_root)
{
	if (!p_root)
		return NULL;
	while (p_root->left)
	{
		p_root = p_root->left;
	}

	return p_root;
}

Node* Delete(Node* p_root)
{
	if (p_root && !p_root->left && !p_root->right)	//Node do not have child
		free(p_root);
	else if (p_root->left && !p_root->right)	//Node have left child
	{
		Node* temp = p_root;
		p_root = p_root->left;
		free(temp);
	}
	else if (!p_root->left && p_root->right)	//Node have right child
	{
		Node* temp = p_root;
		p_root = p_root->right;
		free(temp);
	}
	else  //Node have both left and right child
	{
		Node* temp = findMin(p_root->right); //Node* temp = FindMax(p_root->left);
		p_root->val = temp->val;
		Delete(temp);
	}
	return p_root;
}



//Inorder traversal
void GetInorder(Node* p_root)
{
	if (p_root == NULL)
		return;

	if (p_root->left != NULL)
		GetInorder(p_root->left);
	cout << p_root->val << endl;
	if (p_root->right != NULL)
		GetInorder(p_root->right);
}

//Very first step and Simplest c++ code
int main()
{
	Node *root;
	root = NULL;
	InsertNode(&root, 25);
	InsertNode(&root, 10);
	InsertNode(&root, 35);
	root = Delete(root);
	/*
	InsertNode(&root, 5);

	GetInorder(root);*/
	//Node *expNode = Search(root, 10);
}