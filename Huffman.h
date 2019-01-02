#pragma once

#define N 30
#define M 2*N-1
typedef struct {
	char ch;
	int weight;
	int parent;
	int Lchild;
	int Rchild;
}HTNode, HuffmanTree[M + 1];

typedef char** huffmanCode;

void Select(HuffmanTree ht, int j, int *s1, int *s2);//找出森林集合中根权值最小的两个
void CrtHuffmanTree(HuffmanTree ht, int w[], int n,char *chlist);//构建哈夫曼树
void CrtHuffmanCode1(HuffmanTree ht, huffmanCode hc, int n);//哈夫曼编码
int find_code(huffmanCode hc, int n, char *dest, int *result);//在生成的哈夫曼编码中查询目标