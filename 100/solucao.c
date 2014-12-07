#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MIN(a, b)	((a) < (b) ?  (a) : (b))
#define MAX(a, b)	((a) > (b) ?  (a) : (b))
#define ABS(a)		((a) <  0  ? -(a) : (a))
#define IMPAR(a)	((a)&1)
#define CTOI(a)		((a) - '0')
#define ITOC(a)		((a) + '0')

#define TRUE	1
#define FALSE	0

int main()
{
	int A, B, maior, custo, i;
	long long int N;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &A, &B) != EOF)
	{
		maior = 0;
		
		for(i = (A < B ? A : B); i <= (A > B ? A : B); i++)
		{
			N = i;
			custo = 1;
			
			while(N > 1)
			{
				if(N % 2)
					N = N * 3 + 1;
				else
					N /= 2;
				
				custo++;
			}
			
			if(custo > maior)
				maior = custo;
		}
		
		printf("%d %d %d\n", A, B, maior);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}