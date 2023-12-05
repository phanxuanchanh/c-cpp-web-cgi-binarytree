#include <stdio.h>
#include <conio.h>
#include "CGI.h"
#include "BinaryTree.h"

int main() {

	char* path = CGI_FILEPATH();
	char* file = strcat_ext(path, "file/binary_tree.txt");
	char* htmlPath = strcat_ext(path, "html/_template.html");

	printf("Content-type: text/html \n\n\r");


	char* method_post = CGI_POST("select=");
	if (method_post == nullptr) {
		char* str = file_get_contents(htmlPath);
		printf("%s", str);
	}
	else {
		int select_int = atoi(method_post);
		switch (select_int)
		{
		case 0: {
			FILE* f;
			errno_t err = fopen_s(&f, file, "r");
			if (err != 0 || f == nullptr)
				printf("Empty");
			int x;
			printf("<p class=\"text-warning\">");
			while (!feof(f)) {
				fscanf_s(f, "%d", &x);
				printf("%d ", x);
			}
			printf("</p>");
			fclose(f);
			break;
		}
		case 1: {
			BTree btree = createBTreeFromFile(file);
			printf("<p>TraverseNLR: </p><p class=\"text-success\">");
			traverseNLR(btree.root);
			printf("</p><br/><p>TraverseNRL: </p><p class=\"text-success\">");
			traverseNRL(btree.root);
			printf("</p><br/><p>TraverseLNR: </p><p class=\"text-success\">");
			traverseLNR(btree.root);
			printf("</p><br/><p>TraverseLRN: </p><p class=\"text-success\">");
			traverseLRN(btree.root);
			printf("</p><br/><p>TraverseRNL: </p><p class=\"text-success\">");
			traverseRNL(btree.root);
			printf("</p><br/><p>TraverseRLN: </p><p class=\"text-success\">");
			traverseRLN(btree.root);
			printf("</p>");
			break;
		}
		case 2: {
			BTree btree = createBTreeFromFile(file);
			printf("<p>CountTNode: %d</p>", countTNode(btree.root));
			printf("\n<p>CountTNodeIsLeaf: %d</p>", countTNodeIsLeaf(btree.root));
			printf("\n<p>CountTNodeHaveOneChild: %d</p>", countTNodeHaveOneChild(btree.root));
			printf("\n<p>CountTNodeHaveTwoChild: %d</p>", countTNodeHaveTwoChild(btree.root));
			break;
		}
		case 3: {
			BTree btree = createBTreeFromFile(file);
			printf("<p>SumTNode: %d</p>", sumTNode(btree.root));
			printf("\n<p>SumTNodeIsLeaf: %d</p>", sumTNodeIsLeaf(btree.root));
			printf("\n<p>SumTNodeHaveOneChild: %d</p>", sumTNodeHaveOneChild(btree.root));
			printf("\n<p>SumTNodeHaveTwoChild: %d</p>", sumTNodeHaveTwoChild(btree.root));
			break;
		}
		default:
			printf("<p>Not Found</p>");
			break;
		}
	}

	return 1;
}