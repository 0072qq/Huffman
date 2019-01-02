#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Huffman.h"
#include "File.h"

int main(void)
{
	HuffmanTree ht;
	huffmanCode hc;
	int n, i,s,k1;
	int w[100];     //������ȡȨֵ
	char chlist[100];//������ȡ��Ӧ���ַ�

	int cal[128] = { 0 };
	char str[100001];
	char code[10001];
	printf("�����ļ��������ַ������Ա��������\n");
	scanf("%s", &str);
	Writetofile(str);

	//��������ַ����ֵ�Ƶ��
	for (i = 0; i < strlen(str); i++)
		cal[str[i]]++;

	//�������ַ���Ȩֵ������
	int j = 1;
	for (i = 0; i <= 127; i++) {
		//�ո�Ϊ32,zΪ122�����������ֵ��ַ����������Χ��
		if (cal[i] > 0) {
			w[j] = cal[i];
			chlist[j] = i;
			j++;
		}
	}

	//�����ַ�������������������
	n = j - 1;
	CrtHuffmanTree(ht, w, n,chlist);

	//��ȡ����������
	hc =(huffmanCode) malloc(sizeof(char)*(n + 1)*(n + 1));
	CrtHuffmanCode1(ht, hc, n);
	//��ӡ�ַ���Ȩֵ
	printf("�ַ�----->Ȩֵ\n");
	for (int i = 1; i <=2*n-1; i++)
	{
		printf("%c------>%d %d %d %d\n", chlist[i], ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
	}

	//����
	FILE *fp = fopen("C:\\Users\\����˹ ����\\Desktop\\code.txt", "a");
	for (i = 0; i < strlen(str); i++) {
		for (int x = 1; x <= n; x++) {
			if (str[i] == chlist[x]) {
				//printf("%s", hc[x]);
				fprintf(fp, "%s", hc[x]);
				break;
			}
		}
	}
	fclose(fp);
	printf("������д���ļ�\n");
	printf("\n");

	//����
	read_file_1(code);
	FILE *fre = fopen("C:\\Users\\����˹ ����\\Desktop\\decode.txt", "a");


	s =2*n-1;
	k1 = 0;
	while (code[k1] != '\0') {
		if (code[k1] == '0')
		{
			s = ht[s].Lchild;
		}
		else if (code[k1] == '1')
		{
			s = ht[s].Rchild;
		}
		else {
			fprintf(fre, "%c", code[k1]);
		}
		if (ht[s].Lchild == 0) {
			fprintf(fre, "%c", ht[s].ch);
			s =2* n-1;
		}
		k1++;
	}
		printf("������д���ļ��������ļ��鿴\n");
		printf("\n");

		free(hc);

		return 0;
}