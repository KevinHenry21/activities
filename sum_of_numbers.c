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
int* input(int a[], int n)
{
	printf("Enter the integers: ");
	for(int i = 0; i<n ; i++)
	{
		scanf("%d", &a[i]);
	}
	return a;
}
void output(int a[], int n)
{
	printf("The sum of %d different numbers is %d.\n", n, Sum(a, n));
}
int main()
{
	int a[100], n;
	printf("Enter n: ");
	scanf("%d", &n);
	input(a, n);
	output(a, n);
	return 0;
}
