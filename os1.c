q1.
#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
//Q2.

#include <stdio.h>

int main() 
{
	int arrival_time[10], burst_time[10], temp[10];
	int i, smallest, count = 0, time, limit;
	double wait_time = 0, turnaround_time = 0, end;
	float average_waiting_time, average_turnaround_time;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d", &limit); 
	printf("\nEnter Details of %d Processes\n", limit);
	for(i = 0; i < limit; i++)
 	{
		printf("\nEnter Arrival Time:\t");
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst Time:\t");
		scanf("%d", &burst_time[i]); 
		temp[i] = burst_time[i];
	}
  	burst_time[9] = 9999;  
 	for(time = 0; count != limit; time++)
 	{
   		smallest = 9;
  		for(i = 0; i < limit; i++)
  		{
   			if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
			{
   				smallest = i;
			}
  		}
  		burst_time[smallest]--;
  		if(burst_time[smallest] == 0)
  		{
   			count++;
   			end = time + 1;
   			wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
   			turnaround_time = turnaround_time + end - arrival_time[smallest];
  		}
 	}
	average_waiting_time = wait_time / limit; 
	average_turnaround_time = turnaround_time / limit;
 	printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    	printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
    	return 0;
    }




