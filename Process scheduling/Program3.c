#include <stdio.h>
#include <stdlib.h>

struct process{
		int pid;
		int bt;
		int wt;
		int tt;
}p[10];
	

int main(){
	int i,j,n,totwt,tottt,avg1,avg2;
	system("clear");
	printf("\nEnter the number of process:\t");
	scanf("%d", &n);
		
	for(i=1; i<=n; i++){
		p[i].pid=i;
		printf("\nEnter the brust time:\t");
		scanf("%d", &p[i].bt);
	}
	
	p[1].wt=0;
	p[1].tt=p[1].bt+p[1].wt;
	i=2;
	
	
	while(i<=n){
		p[i].wt=p[i-1].bt+p[i-1].wt;
		p[i].tt=p[i].bt+p[i].wt;
		i++;
	}
	
	i=1;
	totwt=tottt=0;
	printf("\nProcess ID\t Burst_Time\t Wait_Time\t Total_Time");
	
	while(i<=n){
	printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
	totwt=p[i].wt+totwt;
	tottt=p[i].tt+tottt;
	i++;
	}
	
	avg1=totwt/n;
	avg2=tottt/n;
	printf("\n\nAverage wait Time=%d\nAverage Total Time=%d\n\n",avg1,avg2);

	getchar();

	return 0;
}
		
