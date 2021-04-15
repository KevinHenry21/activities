#include<stdio.h>
struct fraction{
    int num;
    int den;
};
typedef struct fraction fraction;

struct egyptian_frac{
    int k;
    int den[100];
    fraction sum;
};
typedef struct egyptian_frac egyptian_fraction;

egyptian_fraction input_one_fraction()
{
    egyptian_fraction ef;
    scanf("%d", &ef.k);
    for(int i=0; i<ef.k ; i++)
    {
        scanf("%d", &ef.den[i]);
    }
    return ef;
}

void input_n_fractions(int n, egyptian_fraction aef[n])
{
    for(int i=0; i<n ; i++)
    {
        aef[i] = input_one_fraction();
    }
}

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

void compute_one_fraction(egyptian_fraction *pef)
{
    pef->sum.num = 0;
    pef->sum.den = pef->den[0];
    for(int i=0 ; i<pef->k ; i++)
    {
        pef->sum.den = (pef->den[i]*pef->sum.den);
    }
    for(int i=0 ; i<pef->k ; i++)
    {
        pef->sum.num = pef->sum.num + (1 *(pef->sum.den / pef->den[i]));
    }
    int cf = gcd(pef->sum.num, pef->sum.den);
    pef->sum.num = pef->sum.num / cf;
    pef->sum.den = pef->sum.den / cf;

}

void compute_n_fractions(int n, egyptian_fraction aef[n])
{
    for(int i=0 ; i<n ; i++)
    {
       compute_one_fraction(&aef[i]);
    }
}

void print_one_fraction(egyptian_fraction ef)
{
    for(int i=0 ; i< ef.k ; i++)
    {
       printf("%d/%d + ", 1, ef.den[i]);
    }
    printf("= %d/%d\n", ef.sum.num, ef.sum.den);
}

void print_n_fractions(int n, egyptian_fraction aef[n])
{
    for(int i=0 ; i<n ; i++)
    {
        print_one_fraction(aef[i]);
    }
}

int main()
{
    egyptian_fraction ef[100];
    int n;
    scanf("%d", &n);
    input_n_fractions(n, ef);
    compute_n_fractions(n, ef);
    print_n_fractions(n, ef);
    return 0;
}
