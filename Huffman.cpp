#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<String.h>
#include "Huffman.h"

//�ҳ�Ȩֵ��С������
void Select(HuffmanTree ht, int j, int *s1, int *s2)
{
	int i;
	//intռ4���ֽڣ����Ϊ2147483647
	int min = 2147483647;
	for (i = 1; i <= j; i++) {
		if ((ht[i].parent == 0) && ht[i].weight < min) {
			min = ht[i].weight;
			*s1 = i;
		}

	}
	int lessmin = 2147483647;
	for (i = 1; i <= j; i++) {
		if ((ht[i].parent == 0) && ht[i].weight < lessmin && i != *s1) {
			//�±겻����ͬ
			lessmin = ht[i].weight;
			*s2 = i;
		}
	}
}

//������������
void CrtHuffmanTree(HuffmanTree ht, int w[], int n,char *chlist)
{
	int m, i;
	m = 2 * n - 1;
	for (i = 1; i <= n; i++) {
		ht[i].ch = chlist[i];
		ht[i].weight = w[i];//��ʼ��ǰn��Ԫ�س�Ϊ�����
		ht[i].parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
	for (i = n + 1; i <= m; i++) {    //��ʼ����n-1��Ԫ��
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
	for (i = n + 1; i <= m; i++)    //�ӵ�n+1��Ԫ�ؿ�ʼ�����½��
	{
		int s1, s2;
		//��ht��ǰi-1����ѡ��˫��Ϊ0��ȫֵ��С�������s1,s2
		Select(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;//�����½�㣬��Ȩֵ
		ht[i].Lchild = s1;
		ht[i].Rchild = s2;  //���½�����Һ��ӵ�ָ��
		ht[s1].parent = i;
		ht[s2].parent = i;  //��s1,s2��˫��ָ��
	}
}

//����������
void CrtHuffmanCode1(HuffmanTree ht, huffmanCode hc, int n)
{
	//��Ҷ�ӵ������������Ҷ�ӽ��ı���
	char *cd;
	int start, i, c, p;
	cd = (char *)malloc(n * sizeof(char));//��ʱ��������
	cd[n - 1] = '\0';          //�Ӻ���ǰ��λ����룬���ȷ��ý�����
	for (i = 1; i <= n; i++)        //��ÿ��Ҷ�ӿ�ʼ������Ӧ�Ĺ���������
	{
		start = n - 1;
		c = i;
		p = ht[i].parent;    //cΪ��ǰ�ڵ㣬pΪ��˫��
		while (p != 0) {
			--start;
			if (ht[p].Lchild == c)
				cd[start] = '0';//���֧Ϊ'0'
			else
				cd[start] = '1';//�ҷ�֧Ϊ'1'
			c = p;
			p = ht[p].parent;   //����һ�� 
		}
		hc[i] = (char *)malloc((n - start) * sizeof(char)); //��̬�������ռ�
		strcpy(hc[i], &cd[start]);                       //���Ʊ���
	}
	free(cd);
}

//�����ɵĹ����������в�ѯĿ��
int find_code(huffmanCode hc, int n, char *dest, int *result)
{
	int i;
	for (i = 1; i <= n; i++) {
		if (strcmp(dest, hc[i]) == 0) {
			*result = i;
			return 1;
		}
	}
	return 0;
}
