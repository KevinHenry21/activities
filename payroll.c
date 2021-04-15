#include<stdio.h>
#include<string.h>

struct employee{
	char name[100];
	float hrly_wage;
	float mins;
    float hrs;
	float total_pay;
};
typedef struct employee employee;

void input_n_employees(int n, employee em[n])
{
	for(int i=0 ; i<n ; i++)
	{
		scanf("%s", em[i].name);
		scanf("%f", &em[i].hrly_wage);
	}
}

int name_compare(int n, employee em[n], char a[])
{
	for(int i=0 ; i<n ; i++)
		if(!strcmp(a, em[i].name))
			return i;
	return 0;
}

void hours_input(int n, employee em[n])
{
	int m, t_mins, in;
	char a[100];
	scanf("%d", &m);
	for(int i=0 ; i<m ; i++)
	{
	    scanf("%s", a);
    	in = name_compare(n, em, a);
    	scanf("%d", &t_mins);
    	em[in].mins += t_mins;
	}
}

void input_dets(int n, employee em[n])
{
    input_n_employees(n, em);
	hours_input(n, em);
}

void compute_total_pay(int n, employee em[n])
{
	for(int i=0 ; i<n ; i++)
	{
		em[i].hrs = (em[i].mins)/ 60;
		if(em[i].hrs <= 40)
			em[i].total_pay = (em[i].hrly_wage)*(em[i].hrs);
		else
		    em[i].total_pay = (40*em[i].hrly_wage)+((em[i].hrs-40)*em[i].hrly_wage*1.5);
	}
}

void print_one_employee(char name[], float hrs, float total_pay)
{
	printf("%s: %.2f hours, $%.2f\n ", name, hrs, total_pay);
}

void print_n_employees(int n, employee em[n])
{
	for(int i=0 ; i<n ; i++)
	{
		if(em[i].hrs)
			print_one_employee(em[i].name, em[i].hrs, em[i].total_pay);
	}
}

int main()
{
	int n;
    scanf("%d", &n);
	employee em[n];
	input_dets(n, em);
	compute_total_pay(n, em);
	print_n_employees(n, em);
	return 0;
}
