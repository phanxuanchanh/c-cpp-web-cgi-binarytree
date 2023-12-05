#include "BinaryTree.h"

BTree initBTree(){
	BTree btree;
	btree.root = nullptr;
	return btree;
}

int isEmpty(BTree btree){
	return (btree.root == nullptr) ? 1 : 0;
}

TNode* createTNode(int x){
	TNode* node = (TNode*)malloc(sizeof(TNode));
	if(node == nullptr)
		return nullptr;
	node->info = x;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void showTNode(TNode* node){
	printf("%4d", node->info); 
}

void traverseNLR(TNode* root){
	if(root == nullptr)
		return;
	showTNode(root);
	traverseNLR(root->left);
	traverseNLR(root->right);
}

void traverseNRL(TNode* root){
	if(root == nullptr)
		return;
	showTNode(root);
	traverseNLR(root->right);
	traverseNLR(root->left);
}

void traverseLNR(TNode* root){
	if(root == nullptr)
		return;
	traverseNLR(root->left);
	showTNode(root);
	traverseNLR(root->right);
}

void traverseLRN(TNode* root){
	if(root == nullptr)
		return;
	traverseNLR(root->left);
	traverseNLR(root->right);
	showTNode(root);
}

void traverseRNL(TNode* root){
	if(root == nullptr)
		return;
	traverseNLR(root->right);
	showTNode(root);
	traverseNLR(root->left);
}

void traverseRLN(TNode* root){
	if(root == nullptr)
		return;
	traverseNLR(root->right);
	traverseNLR(root->left);
	showTNode(root);
}

int insertTNode(TNode** root, TNode* add){
	if(add == nullptr)
		return 0;
	if(*root == nullptr){
		*root = add;
		return 1;
	}
	if((*root)->info == add->info)
		return 0;
	else if((*root)->info < add->info)
		insertTNode(&(*root)->right, add);
	else
		insertTNode(&(*root)->left, add);
}

BTree createBTreeFromFile(char* fileName){
	BTree btree = initBTree();
	FILE* file;
	errno_t err = fopen_s(&file, fileName, "r");
	if(err != 0 || file == nullptr)
		return btree;
	int x;
	while (!feof(file)){
		fscanf_s(file, "%d", &x);
		insertTNode(&btree.root, createTNode(x));
	}
	fclose(file);
	return btree;
}

int countTNode(TNode* root){
	if(root == nullptr)
		return 0;
	return 1 + countTNode(root->left) + countTNode(root->right);
}

int countTNodeIsLeaf(TNode* root){
	if(root == nullptr)
		return 0;
	if(root->left == nullptr && root->right == nullptr)
		return 1 + countTNodeIsLeaf(root->left) + countTNodeIsLeaf(root->right);
	return countTNodeIsLeaf(root->left) + countTNodeIsLeaf(root->right);
}

int countTNodeHaveTwoChild(TNode* root){
	if(root == nullptr)
		return 0;
	if(root->left != nullptr && root->right != nullptr)
		return 1 + countTNodeHaveTwoChild(root->left) + countTNodeHaveTwoChild(root->right);
	return countTNodeHaveTwoChild(root->left) + countTNodeHaveTwoChild(root->right);
}

int countTNodeHaveOneChild(TNode* root){
	if(root == nullptr)
		return 0;
	if((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
		return 1 + countTNodeHaveOneChild(root->left) + countTNodeHaveOneChild(root->right);
	return countTNodeHaveOneChild(root->left) + countTNodeHaveOneChild(root->right);
}

int sumTNode(TNode* root){
	if(root == nullptr)
		return 0;
	return root->info + sumTNode(root->left) + sumTNode(root->right);
}

int sumTNodeIsLeaf(TNode* root){
	if(root == nullptr)
		return 0;
	if(root->left == nullptr && root->right == nullptr)
		return root->info + sumTNodeIsLeaf(root->left) + sumTNodeIsLeaf(root->right);
	return sumTNodeIsLeaf(root->left) + sumTNodeIsLeaf(root->right);
}

int sumTNodeHaveOneChild(TNode* root){
	if(root == nullptr)
		return 0;
	if((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
		return root->info + sumTNodeHaveOneChild(root->left) + sumTNodeHaveOneChild(root->right);
	return sumTNodeHaveOneChild(root->left) + sumTNodeHaveOneChild(root->right);
}

int sumTNodeHaveTwoChild(TNode* root){
	if(root == nullptr)
		return 0;
	if(root->left != nullptr && root->right != nullptr)
		return root->info + sumTNodeHaveTwoChild(root->left) + sumTNodeHaveTwoChild(root->right);
	return sumTNodeHaveTwoChild(root->left) + sumTNodeHaveTwoChild(root->right);
}