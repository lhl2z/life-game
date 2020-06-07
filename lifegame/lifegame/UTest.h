#ifndef UTEST_H
#define UTEST_H
int ReadMap();
void Print(int thisMap[M][N],int lastMap[M][N]);
void InitPrintMap(int thisMap[M][N]);
void Run();
void Calculate(int nowMap[M][N],int lastMap[M][N]);
void RenewMap();
void Pos(int x, int y);
#endif