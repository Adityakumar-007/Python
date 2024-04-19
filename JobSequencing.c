/* JOB SEQUENCING WITH DEADLINES
 Greedy Algorithms / (Assignment - 3)

 Time Complexity:- O(n) [excluding the time for sorting]
 Space Complexity:- O(n)
=============================================================
 Program Code Written by:- KAUSTAV
=============================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Job
{
 int deadline;
 int profit;
 int id;
};
void printArray(int *arr, int n);
int main()
{
 clock_t start, end;
 double cpu_time;
 start = clock();

 int n;
 printf("Enter no. of jobs ");
 scanf("%d",&n);
 Job* jobs = (struct Job*)malloc(n * sizeof(struct Job));

 for(int i=0;i<n;i++)
 {
 printf("\nEnter deadline for job %d ",(i+1));
 scanf("%d",&jobs[i].deadline);
 printf("Enter profit for job %d ",(i+1));
 scanf("%d",&jobs[i].profit);
 jobs[i].id = i;
 }

 printf("\nOriginal Input:-\n");
 for(int i=0; i<n; i++)
 {
 printf("\nJob %d :- {%d, %d}",(i+1),jobs[i].deadline,jobs[i].profit);
 }
 printf("\n\n");

 for(int i=0; i<(n-1); i++)
 {
 for(int j=0; j<(n-i-1); j++)
 {
 if(jobs[j].profit < jobs[j+1].profit)
 {
 struct Job temp = jobs[j];
 jobs[j] = jobs[j+1];
 jobs[j+1] = temp;
 }
 }
 }

 int* solution = (int*)calloc(n, sizeof(int));
 int time = 0;
 int count = 0;
 int totalProfit = 0;
 for(int i=0; i<n ;i++)
 {
 struct Job current = jobs[i];
 if(current.deadline > time)
 {
 solution[i]++;
 count++;
 time++;
 totalProfit += current.profit;
 }
 }
 printf("\nSolution Set:- \t");
 printf("< ");
 for(int i=0; i<n; i++)
 {
 printf("%d ",solution[i]);
 }
 printf(">");
 printf("\nSequence of Jobs:- \t");
 printf("( ");
 for(int i=0; i<n; i++)
 {
 if(solution[i] == 1)
 {
 printf("J%d ",(jobs[i].id + 1));
 }
 }
 printf(")");

 printf("\nMaximum Jobs = %d",count);
 printf("\nProfit = %d",totalProfit);
 printf("\n\n");

 end = clock();
 cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
 printf("\nCPU Time = %lf",cpu_time);
 printf("\n\n");

 free(jobs);
 free(solution);

 return 1;
}
