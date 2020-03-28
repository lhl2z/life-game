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

//根据规则计算新地图
void Calculate(int nowMap[M][N],int lastMap[M][N])
{
	int i = 0,j = 0,count = 0;
	for(i = 0;i < M;i++)
	{
		for(j = 0;j < N;j++)
		{
			//因为活细胞是1，所以直接将自己周围对应的地图数字相加就是活细胞个数
			count = 0;
			//列举出几种边界情况，特殊计算，否则计算四周
			//第一排   最后一排  左边中间  右边中间  正中间
			if(0 == i)
			{
				//在第一排
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
				//要注意，前面已经计算过的不用再考虑，所以这个时候，考虑的是靠左边中间的
				count = nowMap[i-1][j]+nowMap[i-1][j+1]+nowMap[i][j+1]+nowMap[i+1][j+1]+nowMap[i+1][j];
			else if(N-1 == j)
				count = nowMap[i-1][j]+nowMap[i-1][j-1]+nowMap[i][j-1]+nowMap[i+1][j-1]+nowMap[i+1][j];
			else
				count = nowMap[i-1][j]+nowMap[i-1][j-1]+nowMap[i][j-1]+nowMap[i+1][j-1]+nowMap[i+1][j]+nowMap[i-1][j+1]+nowMap[i][j+1]+nowMap[i+1][j+1];
			//根据count的结果来判断新的地图中细胞的生死
			if(3 == count)
				lastMap[i][j] = 1;
			else if(2 == count)
				lastMap[i][j] = nowMap[i][j];
			else
				lastMap[i][j] = 0;
		}
	}
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

//保持细胞的运行
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
