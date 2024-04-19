#include<stdio.h>
#include<conio.h>
void maxheapify(int a[],int,int);
void maxheap(int a[],int beg,int end){
	int i;
	for(i=end/2;i>=beg;i--)
	maxheapify(a,i,end);
}
void maxheapify(int a[],int f,int size)
{
	int max=f,l=f*2,r=f*2+1,t;
	if(l<=size&& a[l]>a[max])
		max=l;
		if(r<=size&&a[r]>a[max])
			max=r;
			if(f!=max)
			{
				t=a[f];
				a[f]=a[max];
				a[max]=t;
				maxheapify(a,max,size);
			}
}
void heapsort(int a[],int size)
{
	int i,t;
	for(i=size;i>=2;i--)
	{
		t=a[1];
		a[1]=a[i];
		a[i]=t;
		maxheapify(a,1,i-1);
	}
}
void main()
{
	int a[10],i;
	int n;
	printf("Enter the number of array of an element: ");
	scanf("%d",&n);
	
	printf("Enter array elements: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	maxheap(a,1,n-1);
	heapsort(a,n-1);
	printf("\nSorted array:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	
}
