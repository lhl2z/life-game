#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define M 20
#define N 20

//全局变量
int Map1[M][N] = {0};
int Map2[M][N] = {0};
int thisFlag = 1;

//函数声明
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
	FILE *fp; //利用指针打开事先准备好的文本文件
	int i = 0,j = 0;
	char ch = '\0';

	//先判断地图文件是否存在，存在则继续，否则直接返回-1
	if(access("LifeGameMap.txt",0))
	{
		printf("地图文件不存在\n");
		return -1;
	}

	fp = fopen("LifeGameMap.txt","r");

	for(i = 0;i < M;i++)
	{
		//读完一整行
		for(j = 0;j < N;j++)
		{
			fscanf(fp,"%c",&ch);
			if('*' != ch)
			{
				Map1[i][j] = 0;
				Map2[i][j] = 0;
			}
			else
			{//设置为1，方便后期计算周围活细胞个数（直接累加就行）
				Map1[i][j] = 1;
				Map2[i][j] = 1;
			}
		}
		//一行最后有一个换行符
		fscanf(fp,"%c",&ch);
	}
	return 0;
}

void RenewMap()
{
	//遍历当前的地图数组,依次计算每个格子的后一个状态，并更新新的地图
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