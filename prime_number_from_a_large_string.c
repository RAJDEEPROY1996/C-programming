//given a string of integer.
//slpit them into m groups with n no of elements in a group.
//discard the no of elements which are not equal to n.
// find whether n is prime or not
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char num[80];
	int i,m,n,j,temp,rem=0,primey,num1,s,k;
	printf("enter the number\n");
	scanf("%s",num);
	temp=strlen(num);
	printf("enter the number of element to be in 1 group\n");
	scanf("%d",&n);
	if(temp%n!=0)
		temp = temp - temp%n;
	j=0,num1=0,rem=0;
	for(i=0;num[i]!='\0';i++)
	{
		j++;
		if(temp == i)
			break;
		num1=num1*10+num[i]-'0';
		if(j==n){
			j=0;
			primey=0;
			for(k=2; k<=num1/2;k++){
				if(num1%k==0)
					primey=1;
			}
		if(primey==0){
			rem=1;
			printf("prime %d\n",num1);
		}
		num1=0;
		}
	}
	if(rem==0)
		printf("No prime found \n");
}


