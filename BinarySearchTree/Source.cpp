#include<iostream>
#include <queue>
using namespace std;

struct BstNode {
	int data;
	BstNode * right;
	BstNode * left;
};

BstNode* GetNewNode(int data)
{
	BstNode * newNode = new BstNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

BstNode * Insert(BstNode* root, int data)
{
	if (root == nullptr)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}

	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == nullptr) return false;
	if (root->data == data) return true;
	else if (data <= root->data)
	{
	 Search(root->left, data);
	}
	else
	{
		 Search(root->right, data);
	}
}

int FindMin(BstNode * root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty";
		return -1;
	}
	else
	{
		while (root->left != nullptr)
			root = root->left;
		return root->data;
	}


}

int FindMax(BstNode * root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty";
		return -1;
	}
	else
	{
		while (root->right != nullptr)
			root = root->right;
		return root->data;
	}
}

int FindMaxRecursive(BstNode *root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty";
			return -1;
	}
	else if (root->right == nullptr)
		return root->data;
	else
		return FindMaxRecursive(root->right);
}

int FindMinRecursive(BstNode *root)
{
	if (root == nullptr)
	{
		cout << "Tree is empty";
		return -1;
	}
	else if (root->left == nullptr)
		return root->data;
	else
		return FindMinRecursive(root->left);
}

int FindHeight(BstNode *root)
{
	int leftHeight, rightHeight;
	if (root == nullptr)
		return -1;

	leftHeight = FindHeight(root->left);
	rightHeight = FindHeight(root->right);

	if (leftHeight >= rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;

}


void LevelOrderTraversal(BstNode * root)
{
	if (root == nullptr) return;
	queue<BstNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BstNode *current = q.front();
		cout << current->data <<" ";
		if(current->left!=nullptr) q.push(current->left);
		if(current->right != nullptr) q.push(current->right);
		q.pop();
	}

}

void PreOrderTraversal(BstNode * root)
{
	if (root == nullptr)
		return;
	cout << root->data << " ";
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

void InOrderTraversal(BstNode * root)
{
	if (root == nullptr)
		return;
	
	InOrderTraversal(root->left);
	cout << root->data << " ";
	InOrderTraversal(root->right);
}

void PostOrderTraversal(BstNode * root)
{
	if (root == nullptr)
		return;

	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	cout << root->data << " ";
	
}



int main()
{
	int searchData;
	BstNode * root = nullptr;
	root = Insert(root, 15);
	root = Insert(root, 20);
	root = Insert(root, 12);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 18);
	root = Insert(root, 29);

	cout << "Insert data to be found";
	cin >> searchData;
	if (Search(root, searchData)) 
		cout << searchData << "found"<<endl;
	else
		cout << searchData << "not found" << endl;
	

	int min = FindMin(root);
	cout << "Min element in tree is" << min<<endl;

	int max = FindMax(root);
	cout << "Max element in tree is" << max << endl;


	int minRec = FindMinRecursive(root);
	cout << "Min element in tree is (Recursively) :" << minRec << endl;

	int maxRec = FindMaxRecursive(root);
	cout << "Max element in tree is (Recursively) :" << maxRec << endl;

	int htOfTree = FindHeight(root);
	cout << "Height/Depth of tree is: " << htOfTree << endl;


	cout << "Level Order Traversal / Breadth First Traversal of Binary Tree :  ";
	LevelOrderTraversal(root);

	cout <<endl <<"PreOrder Traversal (Depth First Traversal) of Binary Tree :  ";
	PreOrderTraversal(root);

	cout << endl << "InOrder Traversal (Depth First Traversal) of Binary Tree :  ";
	InOrderTraversal(root);

	cout << endl << "PostOrder Traversal (Depth First Traversal) of Binary Tree :  ";
	PostOrderTraversal(root);

	return 0;


}