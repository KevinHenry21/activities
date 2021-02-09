#include<stdio.h>
int Sum(int a[], int n)
{
    int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	return sum;
}
int main()
{
	int a[100], n;
	printf("Enter the number of integers to be added: ");
	scanf("%d", &n);
	
	printf("Enter the integers: ");
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("The sum of %d different numbers is %d.\n", n, Sum(a, n));
	return 0;
}
