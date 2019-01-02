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

void Select(HuffmanTree ht, int j, int *s1, int *s2);//�ҳ�ɭ�ּ����и�Ȩֵ��С������
void CrtHuffmanTree(HuffmanTree ht, int w[], int n,char *chlist);//������������
void CrtHuffmanCode1(HuffmanTree ht, huffmanCode hc, int n);//����������
int find_code(huffmanCode hc, int n, char *dest, int *result);//�����ɵĹ����������в�ѯĿ��