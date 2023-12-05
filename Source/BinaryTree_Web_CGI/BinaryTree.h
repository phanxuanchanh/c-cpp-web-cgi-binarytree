#pragma once
#include <stdio.h>
#include <stdlib.h>

struct TNode {
	int info;
	TNode* left;
	TNode* right;
};

struct BTree{
	TNode* root;
};

BTree initBTree();
int isEmpty(BTree btree);
TNode* createTNode(int x);
void showTNode(TNode* node);
void traverseNLR(TNode* root);
void traverseNRL(TNode* root);
void traverseLNR(TNode* root);
void traverseLRN(TNode* root);
void traverseRNL(TNode* root);
void traverseRLN(TNode* root);
int insertTNode(TNode** root, TNode* add);
BTree createBTreeFromFile(char* fileName);
int countTNode(TNode* root);
int countTNodeIsLeaf(TNode* root);
int countTNodeHaveTwoChild(TNode* root);
int countTNodeHaveOneChild(TNode* root);
int sumTNode(TNode* root);
int sumTNodeIsLeaf(TNode* root);
int sumTNodeHaveOneChild(TNode* root);
int sumTNodeHaveTwoChild(TNode* root);