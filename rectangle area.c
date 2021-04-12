#include<stdio.h>
#include<math.h>

struct points{
	float x, y;
};
typedef struct points points;

struct vertices{
    float ans;
	points p[3];
};
typedef struct vertices vertices;

vertices input_one_point()
{
    vertices ver;
	for(int i=0 ; i<3 ; i++)
	{
		scanf("%f%f", &ver.p[i].x, &ver.p[i].y);
	}
	return ver;
}

void input_n_vertices(int n, vertices ver[n])
{
	for(int i=0 ; i<n ; i++)
		ver[i] = input_one_point();
}

float fin(float x, float y, float z)
{
	float final;
	if(x>y)
	    
	    if(x>z)
	        final = y*z;
	    else
	        final = x*y;
	        
	else if(y>z)
	    final = x*z;
	    
	else
	    final = x*y;
	
	return final;
}

void compute_one_rectangle(vertices *ver)
{
	float a, b, c;
	a = sqrt( ((ver->p[1].y - ver->p[0].y)*(ver->p[1].y - ver->p[0].y))+ ((ver->p[1].x-ver->p[0].x)*(ver->p[1].x-ver->p[0].x))  );
	b = sqrt( ((ver->p[1].y - ver->p[2].y)*(ver->p[1].y - ver->p[2].y))+ ((ver->p[1].x-ver->p[2].x)*(ver->p[1].x-ver->p[2].x))  );
	c = sqrt( ((ver->p[2].y - ver->p[0].y)*(ver->p[2].y - ver->p[0].y))+ ((ver->p[2].x-ver->p[0].x)*(ver->p[2].x-ver->p[0].x))  );
	ver->ans = fin(a, b, c);
}

void compute_n_vertices(int n, vertices ver[n])
{
	for(int i=0 ; i<n ; i++)
	{
		compute_one_rectangle(&ver[i]);
	}
}

void print_one_vertex(vertices ver)
{
	printf("Area of rectangle with vertices ");
	printf("(%.1f,%.1f), (%.1f,%.1f), (%.1f,%.1f) is %.1f\n", ver.p[0].x, ver.p[0].y, ver.p[1].x, ver.p[1].y, ver.p[2].x, ver.p[2].y,  ver.ans);
}

void print_n_vertices(int n, vertices ver[n])
{
	for(int i=0 ; i<n ; i++)
		print_one_vertex(ver[i]);
}

int main()
{
	int nr;
	scanf("%d", &nr);
	vertices ver[nr];
	input_n_vertices(nr, ver);
	//printf("%f", ver[1].p[1].y);
	
	compute_n_vertices(nr, ver);
	print_n_vertices(nr, ver);
	return 0;
}
