#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define M 20
#define N 20

//ȫ�ֱ���
int Map1[M][N] = {0};
int Map2[M][N] = {0};
int thisFlag = 1;

//��������
int ReadMap();
void Print(int thisMap[M][N],int lastMap[M][N]);
void InitPrintMap(int thisMap[M][N]);
void Run();
void Calculate(int nowMap[M][N],int lastMap[M][N]);
void RenewMap();
void Show(int x, int y);


int main(void)
{
	Run();
	system("pause");
	return 0;
}

int ReadMap()
{
	FILE *fp; //����ָ�������׼���õ��ı��ļ�
	int i = 0,j = 0;
	char ch = '\0';

	//���жϵ�ͼ�ļ��Ƿ���ڣ����������������ֱ�ӷ���-1
	if(access("LifeGameMap.txt",0))
	{
		printf("��ͼ�ļ�������\n");
		return -1;
	}

	fp = fopen("LifeGameMap.txt","r");

	for(i = 0;i < M;i++)
	{
		//����һ����
		for(j = 0;j < N;j++)
		{
			fscanf(fp,"%c",&ch);
			if('*' != ch)
			{
				Map1[i][j] = 0;
				Map2[i][j] = 0;
			}
			else
			{//����Ϊ1��������ڼ�����Χ��ϸ��������ֱ���ۼӾ��У�
				Map1[i][j] = 1;
				Map2[i][j] = 1;
			}
		}
		//һ�������һ�����з�
		fscanf(fp,"%c",&ch);
	}
	return 0;
}

void RenewMap()
{
	//������ǰ�ĵ�ͼ����,���μ���ÿ�����ӵĺ�һ��״̬���������µĵ�ͼ
	if(1 == thisFlag)
	{
		Calculate(Map1,Map2);
		thisFlag = 2;
	}
	else
	{
		Calculate(Map2,Map1);
		thisFlag = 1;
	}	
}