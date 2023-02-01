/*
	Disk Scheduling
	First Come First Serve
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
	int i,no_of_requests,initial_head;
	
	printf("Enter initial position of R/W head: ");
	scanf("%d",&initial_head);
	
	printf("Enter the number of requests: ");
	scanf("%d",&no_of_requests);
	
	int request[no_of_requests];
	printf("Enter the requests: ");
	for (i = 0; i < no_of_requests; ++i)
	{
		scanf("%d",&request[i]);              
	}
	
	int seek_time=0;

	printf("%d -> ",initial_head );                         //star from initial head
	for(i=0;i<no_of_requests;i++)                           //iterate for all request
	{
		if(i == no_of_requests-1)
			printf("%d\n", request[i] );                    //laast rquest
		else
			printf("%d -> ", request[i] );                  // curent request
		seek_time += abs(request[i] - initial_head);        // calculate seek time
		initial_head = request[i];                          //move head to initial potion
	}
	printf("Seek Time: %d\n", seek_time);
}