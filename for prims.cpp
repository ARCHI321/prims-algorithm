#include<stdio.h>
#include<stdlib.h>

int **a,*prims,n,*nodes;

int getPos(int s)
{
	int i=0,pos=0;
	
	for(i=0;i<n;i++)
	{
		if(nodes[i] == s)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

int getminwt(int pos)
{
	int i=0,min=51,j=0;
	for(i=0;i<n;i++)
	{
		if(a[pos][i]<min && a[pos][i] != 0)
		{
			min = a[pos][i];
			j = i;
		}
	}
	
	
	
	return min;
}

int getnode(int min,int pos)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		if(a[pos][i] == min)
		{
			j=i;
			break;
		}
		
	}
	
	a[pos][j] = 0;
	a[j][pos] = 0;
	
	return j+1;
}


int main()
{
	int i,j,s,c=0,min,val=0,pos=0,pos1=0,sum = 0;
	scanf("%d",&n);
	scanf("%d",&s);
	a = (int**)malloc(n*sizeof(int*));
	prims = (int*)malloc(n*sizeof(int));
	nodes = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i] = (int*)malloc(n*sizeof(int));
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	    { 
		   	scanf("%d",&a[i][j]);	
	    }
	}
	
	for(i=0;i<n;i++)
	{
		nodes[i] = i+1;
	}
	
	min = 51;	
	prims[c++] = s;
	while(c<n)
    {
    	for(i=0;i<c;i++)
     	{
     		pos = getPos(prims[i]);
     		val = getminwt(pos);
     		
     		if(val<=min)
     		{
     			min = val;
     			pos1 = pos;  			
			}
		}     
		s =  getnode(min,pos1);
		sum = sum + min;
     	prims[c++] = s; 
		min = 51; 
     	
	}	
    printf("%d\n",sum);
	for(i=0;i<c;i++)
	{
	  printf("%d ",prims[i]);
	}
	return 0;
}

