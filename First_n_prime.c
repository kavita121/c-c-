#include<stdio.h>
 
int main()
{
	int n,i=2,x=0,j,count=1;
	printf ("Enter the number\n");
	scanf ("%d",&n);
	if (n<=0)
		printf("Invalid");
	else
	{
	while (count<=n)
	{
		for (j=1;j<=i;j++)
		{
			if(i%j==0)
			x++;
		}
		if (x==2)
		{	
		printf ("%d ",i);
		count++;
		}
		x=0;
		i++;
	}
	}
}