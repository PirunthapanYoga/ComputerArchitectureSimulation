#include <stdio.h>
#include <stdlib.h>

struct process{
		int pid;	//program ID
		int bt;		//burst time
		int wt;		//wait time
		int tt;		//total time
		int pty;	//priority
}p[10], temp;
	

int main(){
	int i,j,n,totwt,tottt;
	float avg1,avg2;
	system("clear");
	printf("\nEnter the number of process:\t");
	scanf("%d", &n);
		
	for(i=1; i<=n; i++){
		p[i].pid=i;
		printf("\nProcess [%d] The brust time:\t", i);
		scanf("%d", &p[i].bt);
		printf("\nProcess [%d] Priority:\t", i);
		scanf("%d", &p[i].pty);
	}
	
	//Process order according to priority
	for(i=1; i<n;i++){
		for(j=i+1;j<=n;j++){
			if(p[i].pty<p[j].pty){
				temp.pid=p[i].pid;
				p[i].pid=p[j].pid;
				p[j].pid=temp.pid;

				temp.bt=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=temp.bt;
				
				temp.pty=p[i].pty;
				p[i].pty=p[j].pty;
				p[j].pty=temp.pty;
			}
		}
	}

	//Set process 1 wait time and total time
	p[1].wt=0;
	p[1].tt=p[1].bt;

	//Calculate Following Processes 
	i=2;
	while(i<=n){
		p[i].wt=p[i-1].bt+p[i-1].wt;
		p[i].tt=p[i].wt+p[i].bt;
		i++;
	}

	// Display Process Detailed View 
	i=1;
	totwt=tottt=0;
	printf("\nProcess_ID\t Priority\t Burst_Time\t Wait_Time\t Total_Time");
	while(i<=n){
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].pty,p[i].bt,p[i].wt,p[i].tt);
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
		
