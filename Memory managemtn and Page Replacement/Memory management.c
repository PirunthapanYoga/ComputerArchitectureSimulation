#include<stdio.h>

#include<conio.h>

#define max 25

void main()

{

    int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;

    static int bf[max],ff[max];
    
    printf("\n\tMemory Managemnt Scheme-First Fit");

    printf("\nEnter the number of blocks:");

    scanf("%d",&nb);

    printf("Enter the number of files:");

    scanf("%d",&nf);
    
    

    printf("\nEnter the size of the blocks:-\n");
    
    for(i=1;i<=nb;i++)                                  //Assign block size for each block

    {

        printf("Block %d:",i);

        scanf("%d",&b[i]);

    }

    printf("Enter the size of the files:-\n");
    
    for(i=1;i<=nf;i++)                                  //Assign size for each files

    {

        printf("File %d:",i);

        scanf("%d",&f[i]);

    }
    
    // check each file, which can be put in certain block , 
    // And tell how much available fragment in the particular block


    for(i=1;i<=nf;i++)

    {

        for(j=1;j<=nb;j++)              //check for all block

        {

            if(bf[j]!=1)                //if bf(j) is not allocated

            {

                temp=b[j]-f[i];         //take difference of block size and page size

                if(temp>=0 && highest<temp)     // if fragment s are grater than 0 and previous 
                                                // highere is less than current fragment

                {

                    ff[i]=j;
                    highest=temp;       // assign fragment to highest

                }

            }

        }

    frag[i]=highest;            //assign highest fragment 

    bf[ff[i]]=1;
    highest=0;

    }
    

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");

    for(i=1;i<=nf;i++)

    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);

    getch();

}