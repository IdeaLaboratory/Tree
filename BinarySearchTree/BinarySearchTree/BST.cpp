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

//Inorder traversal
void GetInorder(Node* p_root)
{
	if (p_root == NULL)
		return;

	if (p_root->left != NULL)
		GetInorder(p_root->left);
	cout << p_root->val <<endl;
	if(p_root->right!=NULL)
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
	InsertNode(&root, 5);

	GetInorder(root);
	//Node *expNode = Search(root, 10);
}