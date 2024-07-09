#include <stdio.h>
#include <conio.h>

void main()
{
	int a[50], i, j, temp;
	printf("Enter the number of elements you want:");
	scant ("%d", &n);
	printf("Enter the elements: ");
	for (i=0; i<n; i++)
	{
		scanf("%d", &n);
	}
	for(i=0; i<n-1; itt)
	{
		for(j=0; j<n-i; i++)
	{
		if(a[i]>a[i+1])
		{
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
	printf("\nThe sorted list is: \n");
	for(i=0; i<n; i++)
	{
		printf ("%d", a[i]);
	}
}