#include<stdio.h>
main(){

int a,b,c,d,e,f;

for(a=1;a<=9;a++)
	for(b=1;b<=9;b++)
		for(c=1;c<=9;c++)
			for(d=1;d<=9;d++)
				for(e=1;e<=9;e++)
					for(f=1;f<=9;f++)
					if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f
					&&b!=c&&b!=d&&b!=e&&b!=f
					&&c!=d&&c!=e&&c!=f
					&&d!=e&&d!=f
					&&e!=f
					&&a+b+c==c+d+e&&a+b+c==e+f+a)
					{
					printf("%d+%d+%d ",a,b,c);
 					printf("%d+%d+%d ",c,d,e);
 					printf("%d+%d+%d \n",a,e,f);
					}
					 
 					}
