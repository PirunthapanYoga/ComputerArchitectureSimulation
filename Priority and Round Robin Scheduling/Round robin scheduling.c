#include <stdio.h>
#include <stdlib.h>

struct process{
		int pid;	//program ID
		int bt;		//burst time
		int wt;		//wait time
		int rembt;	//remaining Waiting time
		int tt;		//total time
		int it;		//last intrupt time
}p[10], temp;
	

int main(){
	int timer,i,j,n,totwt,tottt,quantum;
	float avg1,avg2;
	int count_rembt=0;

	system("clear");
	printf("\nEnter the number of process:\t");
	scanf("%d", &n);
	printf("\nEnter the time Quantum :\t");
	scanf("%d", &quantum);
		
	for(i=1; i<=n; i++){
		p[i].pid=i;
		p[i].it=0;
		p[i].wt=0;
		p[i].tt=0;
		printf("\nProcess [%d] Enter the brust time:\t", i);
		scanf("%d", &p[i].bt);
		p[i].rembt=p[i].bt;
	}
	
	timer=0;
	//Calculate Following Processes 
	i=2;

	while(count_rembt<n){
		for(i=1;i<=n;i++){
			if(p[i].rembt>0){
				if(p[i].rembt<=quantum){

					if(p[i].bt==p[i].rembt){
						p[i].wt=p[i].wt+timer-p[i].it;
					}else{
						p[i].wt=p[i].wt+timer-p[i].it-quantum;
					}
					p[i].tt=p[i].wt+p[i].bt;
					timer=timer+p[i].rembt;
					p[i].rembt=0;
					count_rembt++;

				}else{
					if(p[i].bt==p[i].rembt){
						p[i].wt=p[i].wt+timer-p[i].it;
					}else{
						p[i].wt=p[i].wt+timer-p[i].it-quantum;
					}

					p[i].it=timer;
					timer=timer+quantum;
					p[i].rembt=p[i].rembt-quantum;

				}

			}
		}
	}

	// Display Process Detailed View 
	i=1;
	totwt=tottt=0;
	printf("\nProcess_ID\t Burst_Time\t Wait_Time\t Total_Time");
	while(i<=n){
	printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
	totwt=p[i].wt+totwt;
	tottt=p[i].tt+tottt;
	i++;
	}


	//Display Total Wait time and Total Total time
	avg1=totwt/(float) n;
	avg2=tottt/(float) n;
	printf("\n\nAverage wait Time=%f\nAverage Total Time=%f\n\n",avg1,avg2);

	return 0;
}
		
