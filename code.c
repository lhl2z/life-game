#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

//对函数进行声明
int ReadMap();//初始地图读取函数
void Print(int thisMap[M][N],int lastMap[M][N]);//打印当前地图函数
void InitPrintMap(int thisMap[M][N]);//初始化打印地图
void Run();//保持运行的函数
void Calculate(int nowMap[M][N],int lastMap[M][N]);//把RenewMap传过来的地图根据规则计算新的地图
void RenewMap();//根据地图编号，调用计算函数，传入当前的地图，并更新当前的地图编号
void Show(int x, int y);//设置光标位置，决定要在什么位置输出

