#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 51 

int n=5;
double W=100;			//限重
struct NodeType 
{
	double w,v,p;		//p=v/w
	bool operator<(const NodeType &s)const
	{
		return p>s.p;		//按p递减排序 
	}
} ;
NodeType A[]={{0},{10,20},{20,30},{30,66},{40,40},{50,60}};	//下标为0的元素不用
//求解结果表示
double V;			//最大价值
double x[MAXN];
void Knap()			//求解背包问题并返回总值
{
	V=0;						//V初始化为0 
	double weight=W;			//背包能装下的余下总量 
	memset(x,0,sizeof(x));		//初始化x的向量 
	int i=1;					
	while((A[i].w<weight))		//物品i能装入背包时循环 
	{
		x[i]=1;					//装入物品i 
		weight-=A[i].w;			//减少背包中能装入的剩余重量 
		V+=A[i].v;				//累计总价值 
		i++;					//继续循环 
	}


if(weight>0)					//剩余重量大于0 
{								
	x[i]=weight/A[i].w;			//将物品i的一部分放入 
	V+=x[i]*A[i].v;				//累计总价值 
}
} 
void dispA()				//输出A 
{
	int i;
	printf("\tW\tV\tV/W\n");
	for(i=1;i<=n;i++)
		printf("\t%g\t%g\t%3.1f\n",A[i].w,A[i].v,A[i].p);
		
} 
int main()
{
	printf("求解过程\n");
	for(int i=1;i<=n;i++)
		A[i].p=A[i].v/A[i].w;
	printf("(1)排序前：\n");dispA();
	sort(A+1,A+n+1);
	printf("(2)排序后：\n");dispA();
	Knap();
	printf("(3)求解结果：\n");
	printf("x:[");
	for(int j=1;j<=n;j++)
		printf("%g,",x[j]);
	printf("%g]\n",x[n]);
	printf("总价值=%g\n",V);
	 
} 



















