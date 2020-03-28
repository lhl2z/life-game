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
				Map1[i][j] = 0;//nowmap[][]
				Map2[i][j] = 0;//lastmap[][]
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

//��ʼ����ͼ
void InitShowMap(int thisMap[M][N])
{
	int i = 0,j = 0;
	for(i = 0;i < M;i++)
	{
		for(j = 0;j < N;j++)
		{
			if(0 == thisMap[i][j])
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
	printf("�밴Y(y)����������");
}

/*���ݹ�������µ�ͼ*/
void Calculate(int nowMap[M][N],int lastMap[M][N])
{
	int i = 0,j = 0,count = 0;
	for(i = 0;i < M;i++)
	{
		for(j = 0;j < N;j++)
		{
			count = 0;
			//�����������һ�š����һ�š�����м䡢�ұ��м䡢���м䣩������㣬�����������
			if(0 == i)
			{
				//�ڵ�һ��
				if(0 == j)
				{
					count = nowMap[i][j+1]+nowMap[i+1][j]+nowMap[i+1][j+1];
				}
				else if(j == N-1)
				{
					count = nowMap[i][j-1]+nowMap[i+1][j]+nowMap[i+1][j-1];
				}
				else
				{
					count = nowMap[i][j-1]+nowMap[i+1][j-1]+nowMap[i][j+1]+nowMap[i+1][j]+nowMap[i+1][j+1];
				}
			}
			else if(M-1 == i)
			{
				if(0 == j)
				{
					count = nowMap[i][j+1]+nowMap[i-1][j]+nowMap[i-1][j+1];
				}
				else if(j == N-1)
				{
					count = nowMap[i][j-1]+nowMap[i-1][j]+nowMap[i-1][j-1];
				}
				else
				{
					count = nowMap[i][j-1]+nowMap[i-1][j-1]+nowMap[i][j+1]+nowMap[i-1][j]+nowMap[i-1][j+1];
				}
			}
			else if(0 == j)
				//����м�����
				count = nowMap[i-1][j]+nowMap[i-1][j+1]+nowMap[i][j+1]+nowMap[i+1][j+1]+nowMap[i+1][j];
			else if(N-1 == j)
				count = nowMap[i-1][j]+nowMap[i-1][j-1]+nowMap[i][j-1]+nowMap[i+1][j-1]+nowMap[i+1][j];
			else
				count = nowMap[i-1][j]+nowMap[i-1][j-1]+nowMap[i][j-1]+nowMap[i+1][j-1]+nowMap[i+1][j]+nowMap[i-1][j+1]+nowMap[i][j+1]+nowMap[i+1][j+1];
			//����count�Ľ�����ж��µĵ�ͼ��ϸ��������
			if(3 == count)
				lastMap[i][j] = 1;
			else if(2 == count)
				lastMap[i][j] = nowMap[i][j];
			else
				lastMap[i][j] = 0;
		}
	}
}

//������ǰ�ĵ�ͼ����,���μ���ÿ�����ӵĺ�һ��״̬���������µĵ�ͼ
void RenewMap()
{
	if(1 == thisFlag)//nowmap
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

//����ϸ��������
void Run()
{
	int i = 0,j = 0;
	if(-1 == ReadMap())
		return;
	InitShowMap(Map1);
	while(1)
	{
		switch(getch())
		{
			case 'y':RenewMap();break;
			case 27:return ;
		}
		//Sleep(500);
		if(1 == thisFlag)
			Print(Map2,Map1);
		else
			Print(Map1,Map2);
	}	
}

void Pos(int x, int y)//���ù��λ��
{//Ҫע�������x��y�����������x��y�Ƿ���
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��
	SetConsoleCursorPosition(hOutput, pos);
}

int main(void)
{
	Run();
	system("pause");
	return 0;
}