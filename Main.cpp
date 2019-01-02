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
	int w[100];     //用来存取权值
	char chlist[100];//用来存取相应的字符

	int cal[128] = { 0 };
	char str[100001];
	char code[10001];
	printf("请向文件中输入字符串用以编码和译码\n");
	scanf("%s", &str);
	Writetofile(str);

	//计算各个字符出现的频度
	for (i = 0; i < strlen(str); i++)
		cal[str[i]]++;

	//将各个字符及权值存下来
	int j = 1;
	for (i = 0; i <= 127; i++) {
		//空格为32,z为122，题中所出现的字符都在这个范围中
		if (cal[i] > 0) {
			w[j] = cal[i];
			chlist[j] = i;
			j++;
		}
	}

	//计算字符个数并构建哈夫曼树
	n = j - 1;
	CrtHuffmanTree(ht, w, n,chlist);

	//存取哈夫曼编码
	hc =(huffmanCode) malloc(sizeof(char)*(n + 1)*(n + 1));
	CrtHuffmanCode1(ht, hc, n);
	//打印字符和权值
	printf("字符----->权值\n");
	for (int i = 1; i <=2*n-1; i++)
	{
		printf("%c------>%d %d %d %d\n", chlist[i], ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
	}

	//编码
	FILE *fp = fopen("C:\\Users\\加雷斯 贝尔\\Desktop\\code.txt", "a");
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
	printf("编码已写入文件\n");
	printf("\n");

	//译码
	read_file_1(code);
	FILE *fre = fopen("C:\\Users\\加雷斯 贝尔\\Desktop\\decode.txt", "a");


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
		printf("译码已写入文件，进入文件查看\n");
		printf("\n");

		free(hc);

		return 0;
}