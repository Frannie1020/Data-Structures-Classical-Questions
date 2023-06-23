//随机置换数最终提交代码

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
 
int RandInt(int a, int b);

void RandomPermutation1(int n);
void RandomPermutation2(int n);
void RandomPermutation3(int n);

int main()
{
	RandomPermutation3(10);
	return 0;
 } 

void RandomPermutation1(int n)
{  	
	if(n<=0){
		printf("error");  
	}         
	
	int* a = NULL;
	a = (int*)malloc(n*sizeof(int)); 
	int i,k=0,randnum;
	int t;                    //保存生成的随机数 
	int chongfu;              //判断是否重复 
	a[0] = RandInt(1,n+0.1);      //生成数组的第一个数 
	
	 while(1)
    {
        randnum = RandInt(1, n + 0.1);
        for(i = 0; i < k + 1; i++)
        {
            if(randnum == a[i])
            {
                break;
            }
        }
        if(i == k + 1)
        {
             k++;
            a[k] = randnum;
        }
        if(k + 1 == n)
            break;
    }    

	
	for (i=0; i<n; i++)
	{
		printf("%d,",a[i]);
	}
	printf("0\n"); 

} 

void RandomPermutation2(int n)
{              

	if(n<=0){
		printf("error");  
	}  
	
	int* a = NULL;
	a = (int*)malloc(n*sizeof(int));
	int* Used = NULL;
	Used = (int*)malloc( (n+1)*sizeof(int) );
	
	int i;
	for(i=0; i<n; i++)
	{
		a[i]=0;
	}
	for(i=0; i<n+1; i++)
	{
		Used[i] = 0;
	}
	
	int t;                    //保存生成的随机数 
	int chongfu;              //判断是否重复 
	
	i=0;
	while(i!=n)
	{
		t = RandInt(1,n);
		//判断是否有重复 
		if(Used[t] != 1)
		{
			a[i] = t;
			Used[t] = 1;
			i++;
		}	
 
	}
	
		for (i=0; i<n; i++)
		{
			printf("%d,",a[i]);
		}
			printf("0\n");

} 

void RandomPermutation3(int n)
{	             
	
	if(n<=0){
		printf("error");  
	}  
	
	int* a = NULL;
	a = (int*)malloc(n*sizeof(int));
	int i=0;
	
	for (i=0; i<n; i++)       //生成 1,2,3,4,5,   ,n 
	{
		a[i] = i+1; 
	}
	
	int temp,t;				 //遍历顺序表，每个元素随机交换 
	for (i=1; i<n; i++)
	{
		temp = a[i];
		t = RandInt(0,i);
		a[i] = a[t];
		a[t] = temp;
	}
	 
	for (i=0; i<n; i++)
	{
		printf("%d,",a[i]);
	}
	printf("0");
}   

int RandInt(int a, int b)
{
    int c;
    srand((unsigned)time(NULL));
    c = a + rand() % (b - a + 1);
    return c;
}
