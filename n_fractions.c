#include<stdio.h>
#include<stdio.h>
struct sum
{
    int num, den;
};
typedef struct sum sum;

struct fractions
{
    int k;
	int num[100], den[100];
	sum sum;
};
typedef struct fractions fractions;

int gcd(int a, int b)
{
	int gcd=1;
	for(int i=2; i <= a && i <= b; ++i)
    {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    } 
    return gcd;
}

fractions input_one_fraction()
{
    fractions af;
    scanf("%d", &af.k);
    for(int i=0 ; i<af.k ; i++)
    {
        scanf("%d%d", &af.num[i], &af.den[i]);
    }
    return af;
}

void input_n_fraction(int n, fractions a[n])
{
    for(int i=0 ; i<n ; i++)
    {
        a[i] = input_one_fraction();
    }
}

void compute_two_fractions(fractions *cf)
{
    cf->sum.num = 0;
    cf->sum.den = cf->den[0];
    for(int i=0 ; i<cf->k ; i++)
    {
        cf->sum.den = (cf->den[i] * cf->sum.den);
    }
    for(int i=0 ; i<cf->k ; i++)
    {
        cf->sum.num = cf->sum.num + (cf->num[i]*(cf->sum.den / cf->den[i]));
    }
    
    int GCD = gcd(cf->sum.num, cf->sum.den);
    
    cf->sum.num = cf->sum.num / GCD;
    cf->sum.den = cf->sum.den / GCD;
}

void compute_n_fractions(int n, fractions af[n])
{
    for(int i=0 ; i<n ; i++)
    {
        compute_two_fractions(&af[i]);
    }
}

void print_one_fraction(fractions pf)
{
    for(int i=0 ; i<pf.k ; i++)
    {
        printf("%d/%d + ", pf.num[i], pf.den[i]);
    }
    printf(" = %d/%d \n", pf.sum.num, pf.sum.den);
}

void print_n_fractions(int n, fractions af[n])
{
    for(int i=0 ; i<n ; i++)
    {
        print_one_fraction(af[i]);
    }
}

int main()
{
    struct fractions a[100];
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    input_n_fraction(n, a);
    compute_n_fractions(n, a);
    print_n_fractions(n, a);
    return 0;
}
