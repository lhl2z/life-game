#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define M 20
#define N 20

//全局变量区
int Map1[M][N] = {0};
int Map2[M][N] = {0};
int thisFlag = 1;

//对函数进行声明
int ReadMap();//初始地图读取函数
void Print(int thisMap[M][N],int lastMap[M][N]);//打印当前地图函数
void InitPrintMap(int thisMap[M][N]);//初始化打印地图
void Run();//保持运行的函数
void Calculate(int nowMap[M][N],int lastMap[M][N]);//把RenewMap传过来的地图根据规则计算新的地图
void RenewMap();//根据地图编号，调用计算函数，传入当前的地图，并更新当前的地图编号
void Show(int x, int y);//设置光标位置，决定要在什么位置输出


int main(void)
{
	Run();
	system("pause");
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