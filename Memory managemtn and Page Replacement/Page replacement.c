//FIFO page replacement algorithm
#include<stdio.h>
#include<conio.h>
#define max 25

void main()
{
    int frame[10];                                      // assign maximum memory frame size
    int i,j,k,nf,np=0,page[max],temp;
    int flag=0,pf=0,top=0;
 
    printf("Enter no. of Frames:");
    scanf("%d",&nf);                                    // take user input frame size
 
    for(i=0;i<nf;i++)
        frame[i]=-1;                                    // set all frames values to -1
        
        printf("Enter pages (press -999 to exit):\n");  // set a exit limit for endless loop
    
    for(i=0;i<max;i++)                                  // take upto 25 page
    {
        scanf("%d",&temp);                              // take user pages entry
        
        if(temp==-999) break;                           // break user input
        
        page[i]=temp;                                   // assign page array                                  
        np++;                                           // page counter
    }
    
    //check one by one for required page value. if found it will be hit 
    //if not found top frame will be replaced with required page. then increment to next position
    for(i=0;i<np;i++)
    {
        flag=0;
        for(j=0;j<nf;j++)
        {
            if(frame[j]==page[i])
            {
                printf("\n\t");
                flag=1;break;                           // break frame checking loop if page hits
            }
        }
        
        if(flag==0)
        {
            frame[top]=page[i];                         // assign top frame if fault occur
            top++;                                      // increment top frame posititon
            printf("\nFault:  ");
            pf++;
            if(top>=nf)                                 // if top at the end of frame go back to initial frame
            top=0;
        }
        for(k=0;k<nf;k++)
        printf("%d\t",frame[k]);
    }
    
    printf("\nNumber of page faults is: %d ",pf);
    getch();
}