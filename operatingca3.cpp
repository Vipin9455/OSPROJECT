#include<stdio.h>
#include<stdlib.h>
void vipin(int numb_process,int arrival_time[],int burst_time[])
{
	int i,t,sum=0,priority[numb_process],flag,max=0,wait_time[numb_process];
	int avg_waiting_time=0,arr[numb_process];
	for(i=0;i<numb_process;i++)       //copying the burst time of all the processes in separate array for calculating average waiting time
	{
		arr[i]=burst_time[i];
	}
	for(i=0;i<numb_process;i++)      //initially assigning 0 priority to all the processes
	{
		priority[i]=0;
	}
	for(i=0;i<numb_process;i++)      //finding sum of all the burst time so that total iteration can be known 
	{
		sum=sum+burst_time[i];
	}
	for(t=0;t<sum;t++)
	{   flag=0;
		for(i=0;i<numb_process;i++)
	    {
		    if(t>=arrival_time[i] && flag==0 && priority[i]==max && burst_time[i]>0)  //when process is running i.e. in running queue
			{
				printf("Process %d is executed at time %d\n",i+1,t);
				priority[i]+=1;
				flag=1;
				burst_time[i]-=1;
				if(burst_time[i]==0)
				{
					wait_time[i]=(t+1)-arrival_time[i]-arr[i];
			    }
			}
			else if(t>=arrival_time[i] && burst_time[i]>0)   //when process is in ready queue
			priority[i]+=2;	
		}
		if(flag==0)      //calculating the maximum priority process
		sum+=1;
		max=priority[0];
		for(i=1;i<numb_process;i++)
		{    if(priority[i]>max)
	               max=priority[i];
}
	}
	for(i=0;i<numb_process;i++)      //loop to calculate average waiting time of the  process 
	{
		avg_waiting_time=avg_waiting_time+wait_time[i];
	}
	printf("\n\nProcess No.\t\tArrival Time\t\tBurst Time\t\t Waiting Time\n");
	for(i=0;i<numb_process;i++)     //final table printing
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d",(i+1),arrival_time[i],arr[i],wait_time[i]);
		printf("\n");
	}
	printf("\nAverage waiting time is %d",avg_waiting_time/numb_process);
}
int main()
{
	//taking the number of processes their arrival and burst time from the user
	int i,numb_process;
	printf("Enter number of processess : ");
	scanf("%d",&numb_process);
	int arrival_time[numb_process],burst_time[numb_process];
	printf("\n");
	for(i=0;i<numb_process;i++)
	{
		printf("Enter arrival time of Process %d = ",i+1);
		scanf("%d",&arrival_time[i]);
		printf("Enter burst time of Process %d = ",i+1);
		scanf("%d",&burst_time[i]);
	}
	vipin(numb_process,arrival_time,burst_time);    	//sending all the values to the function defined as vipin
}
