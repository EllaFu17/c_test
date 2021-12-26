#include<stdio.h>

int GetMax (int a[], int n)
{
    int i=0,m=a[0];
    for(i;i<n;i++)
{
	if(a[i]>m)
	m=a[i+1];
}
return m;
}

int main()
{
	int A[] = { 2, 1, 5, 3, -1, 4, 78, 45, 0, 9};

	int max,len;

	len = sizeof(A) / sizeof(A[0]);
	max = GetMax(A, len);
	printf("max: %d", max);

}
