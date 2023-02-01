#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty=3,x=0;
 
int main()
{
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");      //Available operation   
	while(1)
	{
		printf("\nEnter your choice:");             //User operation selection
		scanf("%d",&n);                             //Take n as operation selection
		switch(n) 
		{
			case 1:	if((mutex==1)&&(empty!=0))      //check buffer if full or free
						producer();                 //Product if buffer free
					else
						printf("Buffer is full!!"); //notify buffer full and not produce any
					break;
			case 2:	if((mutex==1)&&(full!=0))       //check buffer have any item
						consumer();                 //if buffer have any consume it
					else
						printf("Buffer is empty!!");//notify buffer is empty
					break;
			case 3:
					exit(0);                        //exit the application 
					break;
		}
	}
	
	return 0;
}
 
int wait(int s)
{
	return (--s);                                   // Decremnet s by 1                          
}
 
int signal(int s)
{
	return(++s);                                    // incremnet s by 1
}
 
void producer()
{
	mutex=wait(mutex);                              //decrease mutex by 1 (mutex =0) 
	full=signal(full);                              //increment used buffer space 
	empty=wait(empty);                              //Decremnet empty buffer space
	x++;                                            //incremnet produced item
	printf("\nProducer produces the item %d",x);
	mutex=signal(mutex);                            // increase mutex by 1 (mutex =1) 
}
 
 
void consumer()
{
	mutex=wait(mutex);                              //decrease mutex by 1 (mutex =0) 
	full=wait(full);                                //Decremnet used buffer space
	empty=signal(empty);                            //incremnet empty buffer space
	printf("\nConsumer consumes item %d",x);
	x--;                                            //Decremnet item
	mutex=signal(mutex);                            //increase mutex by 1 (mutex =1) 
}

