#include <stdio.h>
#include <string.h>
#define MAXLEN 100
void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{   //求最长公共子序列函数 
	int i, j;     
	for(i = 0; i <= m; i++)   
    	c[i][0] = 0;   //把c[1][0] 置为0 ，边界条件 
	for(j = 1; j <= n; j++)    
		c[0][j] = 0;   //把c[0][j] 置为0 ，边界条件 
	for(i = 1; i<= m; i++)  
	{      
		for(j = 1; j <= n; j++)  //两重for循环处理a.b的所有字符 
		{         
			if(x[i-1] == y[j-1])//情况1  
				{        
					c[i][j] = c[i-1][j-1] + 1;    
					b[i][j] = 0;   
			   }       
			   else if(c[i-1][j] >= c[i][j-1])        
			    {              
					c[i][j] = c[i-1][j]; 
					b[i][j] = 1; 
	            }          
				else  
			 {  
				c[i][j] = c[i][j-1];         
				b[i][j] = -1;  
			 }   
	   }  
	}
}
								 
void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{    //回溯法输出 
	if(i == 0 || j == 0)        
		return;   
	if(b[i][j] == 0) 
   	{       
    	PrintLCS(b, x, i-1, j-1);  
	    printf("%c ", x[i-1]);    
	}  
	else if(b[i][j] == 1)     
		PrintLCS(b, x, i-1, j); 
	else       
		PrintLCS(b, x, i, j-1);
 }
int main(int argc, char **argv)
{    
	char x[MAXLEN] = {"ABCBDAB"}; 
	char y[MAXLEN] = {"BDCABA"};  
	int b[MAXLEN][MAXLEN];  
	int c[MAXLEN][MAXLEN];   
	int m, n;        
	m = strlen(x); //m的长度  
	n = strlen(y); //n的长度 
	LCSLength(x, y, m, n, c, b); //调用LCSlength（）函数 
	PrintLCS(b, x, m, n);    //调用PrintfLCS函数 
	return 0;
}

