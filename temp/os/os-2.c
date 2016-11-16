/* 
    Implement FCFS and SJFS algorithm
*/
#include<stdio.h>
 
int main(void)
{
    int burst[20], process[20], wait[20], turn[20], sort_burst[20];
    int temp, n, min, i, j;
    float total = 0, avg_wait = 0, avg_turn = 0;
    
    printf("Enter total number of processes:");
    scanf("%d",&n);
 
    printf("Enter Process Burst Time\n");
    
    for(i = 0; i < n; i++)
    {
        printf("Process[%d]: ", i + 1);
        process[i] = i + 1;
        scanf("%d", &burst[i]);
        sort_burst[i] = burst[i];
    }
    
    // implementation of SJF algorithm
    printf("==============\nSJF ALGORITHM\n==============\n");	

    // sorting the array to choose the shortest job
	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(sort_burst[min] > sort_burst[j])
			{
				temp = sort_burst[min];
				sort_burst[min] = sort_burst[j];
				sort_burst[j] = temp;
			}
		}
	}
	
	wait[0] = 0; // waiting time for first process is zero
    // calculate waiting time
    for(i = 1; i < n; i++)
    {
        wait[i] = 0;
        for(j = 0; j < i; j++) {
            wait[i] += sort_burst[j];
        }
        total += wait[i];
    }
 
    avg_wait = (float) total / (float) n;      //average waiting time
    total = 0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn[i] = sort_burst[i] + wait[i];     //calculate turnaround time
        total += turn[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],sort_burst[i],wait[i],turn[i]);
    }
 
    avg_turn=(float)total/n;     //average turnaround time
    printf("\nAverage Waiting Time=%f",avg_wait);
    printf("\nAverage Turnaround Time=%f\n",avg_turn);
	


	// implementation of FCFS
	printf("\n==============\nFCFS ALGORITHM \n==============\n");	
    wait[0] = 0;
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait[i] = 0;
        for(j = 0; j < i; j++)
            wait[i]+=burst[j];
        total+=wait[i];
    }
 
    avg_wait = (float) total/ (float) n;      //average waiting time
    total = 0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn[i]=burst[i]+wait[i];     //calculate turnaround time
        total+=turn[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],burst[i],wait[i],turn[i]);
    }
 
    avg_turn=(float)total/n;     //average turnaround time
    printf("\nAverage Waiting Time=%f",avg_wait);
    printf("\nAverage Turnaround Time=%f\n",avg_turn);
}