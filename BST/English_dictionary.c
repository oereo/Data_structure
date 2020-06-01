#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200
#define MAX(a,b) a>b?a:b

typedef struct {
	char word[MAX_WORD_LENGTH];
	char mean[MAX_MEAN_LENGTH];
} element;

typedef struct TreeNode {
	element key;
	int height;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

TreeNode* searchBST(TreeNode* root, element key) {
	TreeNode* p; 
	int compare;
	p = root;

	while (p != NULL) {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0) {
			p = p->left;
		}
		else if (compare > 0) {
			p = p->right;

		}
		else {
			printf("\n찾은 단어 : %s", p->key.word);
			return p;
		}
	}
}

TreeNode* insertKey(TreeNode* p, element key) {
	TreeNode* newNode;
	int compare;
	if (p == NULL) {
		newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0) {
			p->left = insertKey(p->left, key);
			return p;
		}
		else if (compare > 0) {
			p->right = insertKey(p->right, key);
			return p;
		}
		else {
			printf("\n 이미 같은 단어가 있습니다.");
			return p;
		}
	}

}

void insert(TreeNode** root, element key) {
	*root = insertKey(*root, key);
}

void deleteNode(TreeNode* root, element key) {
	TreeNode* parent, * p, * succ, * succ_parent;
	TreeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (strcmp(p->key.word, key.word) != 0)) {
		parent = p;
		if (strcmp(key.word, p->key.word) < 0)
			p = p->left;
		else p = p->right;

	}
	succ_parent = p;
	if (p == NULL) {
		printf("\n 찾는 키가 이진트리에 없습니다!");
		return;
	}
	
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;

		}
		else root = NULL;
	}
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;
		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}
	else {
		succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;

		}
		if (succ_parent->left == succ)
			succ_parent->left = succ->right;
		else succ_parent->right = succ->right;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : 입력");
	printf("\n\t2 : 삭제");
	printf("\n\t3 : 검색");
	printf("\n\t4 : 출력");
	printf("\n\t5 : 트리높이");
	printf("\n\t6 : node의 개수");
	printf("\n\t7 : 모든 node 삭제");
	printf("\n\t8 : 종료");

	printf("\n*---------------------------*\n");
}

inorderDisplay(TreeNode* root) {
	if (root) {
		inorderDisplay(root->left);
		printf("\n%s : %s", root->key.word, root->key.mean);
		inorderDisplay(root->right);
	}
}

int get_height(TreeNode* node) {
		int height = 0;
		if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
	
}

void delete_node(TreeNode* root) {
	if (root != NULL) {
		delete_node(root->left);
		delete_node(root->right);
		free(root);
	}
}

int get_node_count(TreeNode* root)
{
	int count = 0;
	if (root != NULL) 
	count = 1+ get_node_count(root->left) + get_node_count(root->right);
	
	return count;
}

void main() {
	char choice;
	element e;
	TreeNode* root = NULL, * temp;

	do {
		menu();
		choice = getchar(); getchar();

		switch (choice - '0') {
		case 1:
			printf("\n[단어입력] 단어를 입력하세요 : "); gets(e.word);
			printf("\n[단어입력] 단어 뜻을 입력하세요 : "); gets(e.mean);
			insert(&root, e);
			break;

		case 2:
			printf("\n[단어삭제] 삭제할 단어 : "); gets(e.word);
			deleteNode(root, e);
			break;

		case 3:
			printf("\n[단어검색] 검색할 단어 : "); gets(e.word);

			temp = searchBST(root, e);
			if (temp != NULL)
				printf("\n단어 뜻 : %s", temp->key.mean);
			else printf("\n사전에 없는 단어입니다.");
			break;
		case 4:
			printf("\t[사전출력]");
			inorderDisplay(root); printf("\n\t[사전 끝]\n");
			break;
		case 5:
			printf("\t[높이]");
			int num = 0;
			num = get_height(root);
			printf("\n%d", num);
			break;
		case 6:
			printf("\t[노드개수]");
			int cnt = 0;
			cnt = get_node_count(root);
			printf("\n%d", cnt);
			break;
		case 7:
			printf("\t[전체노드삭제]");
			delete_node(root);
			root = NULL;
			break;
		}
	} while ((choice - '0') != 8);
}
