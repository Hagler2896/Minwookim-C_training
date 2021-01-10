#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)


int main()
{
	/*
		Flexible array member (struct hack in GCC)
	*/
	struct flex
	{
		size_t count;
		double average;
		double values[];	// flexible array member(last member!)
	};

	const size_t n = 3;

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));

	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	pf->average = 0.0;

	for (unsigned int i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);
	return 0;
}
