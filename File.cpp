
#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"
#include "File.h"

void Writetofile(char result[])
{
	FILE *fp;
	int i=0;
	if ((fp = fopen("C:\\Users\\����˹ ����\\Desktop\\source.txt", "w+")) == NULL)
	{
		printf("�ļ�д����ִ���");
		exit(0);
	}
	while (result[i]!='\0') {
		fprintf(fp,"%c",result[i]);
		i++;
	}
	fclose(fp);
}

void read_file(char result[])
{
	FILE *fpread;
	int i = 0;
	if ((fpread = fopen("C:\\Users\\����˹ ����\\Desktop\\source.txt", "r+")) == NULL)
	{
		printf("�ļ���ȡ����");
	}
	while (result[i] != '\0') {
		fscanf(fpread, "%c", &result[i]);
		i++;
	}
	fclose(fpread);
}

void read_file_1(char result[]) 
{
	FILE *fpread;
	int i = 0;
	if ((fpread = fopen("C:\\Users\\����˹ ����\\Desktop\\code.txt", "r+")) == NULL)
	{
		printf("�ļ���ȡ����");
	}
	while (result[i] != '\0') {
		fscanf(fpread, "%s", &result[i]);
		i++;
	}
	fclose(fpread);
}

void Writetofile_2(char result[])
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("C:\\Users\\����˹ ����\\Desktop\\decode.txt", "w+")) == NULL)
	{
		printf("�ļ�д����ִ���");
		exit(0);
	}
	while (result[i] != '\0') {
		fprintf(fp, "%c", result[i]);
		i++;
	}
	fclose(fp);
}
void read_file_2(char result[])
{
	FILE *fpread;
	int i = 0;
	if ((fpread = fopen("C:\\Users\\����˹ ����\\Desktop\\decode.txt", "r+")) == NULL)
	{
		printf("�ļ���ȡ����");
	}
	while (result[i] != '\0') {
		fscanf(fpread, "%c", &result[i]);
		i++;
	}
	fclose(fpread);
}