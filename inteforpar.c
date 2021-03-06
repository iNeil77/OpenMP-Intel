#include <stdio.h>
#include <omp.h>
long num_steps=100000;
int main()
{
	int i;
	double step,x,pi,sum=0.0;
	step=1/(double)num_steps;
#pragma omp parallel for private(x) reduction(+:sum)
	for(i=0;i<num_steps;i++)
	{
		x=(i+0.5)*step;
		sum=sum+4.0/(1.0+x*x);
	}
	pi=step*sum;
	printf("%lf\n",pi);
	return 0;
}
