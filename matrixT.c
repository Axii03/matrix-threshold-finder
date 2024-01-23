#include <stdio.h>
#include <stdbool.h>
int main()
{
    int N,M,value,i,j,k;
    int uniqueCount=0; //to keep a count of values of the array that will hold the values(unique)
    int X=0; // The maximum possible number 
    printf("Enter Number of Rows: ");
    scanf("%d", &N);
    printf("Enter Number of Columns: ");
    scanf("%d", &M);
    int matrix[N][M]; //declare 2d array of size N M
    int maxArr[N*M]; //declare an array of size N*M 
    
    printf("Input the matrix values respectively: \n");
    for(i=0;i<N;i++) //nested loop start to get the input to 2d array and to the 1d unique value array
    {
    	for(j=0;j<M;j++)
    	{
    		scanf("%d",&value);
    		bool isUnique=true;
    		for(k=0;k<uniqueCount;k++) //check if the value already exists inside the maxArr
    		{
    			if(maxArr[k]==value)
				{
    				isUnique=false;
    				break;
				}
	 		}
	 		
	 		if(isUnique)
			{
	 			maxArr[uniqueCount]=value; //add to maxArr if the value doesnt exist in it
	 			uniqueCount++;
			}
			matrix[i][j]=value; //add the value to the matrix
		}
	}
	
	printf("\nThe matrix you inputted:\n");
	for (i = 0; i < N; i++)  //Loop to print the matrix
	{
    	for (j = 0; j < M; j++) 
		{
        	printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
	}
	
	for (i = 1; i < uniqueCount; i++)  //insertion sort to order the maxArr in descending order
	{
        int key = maxArr[i];
        int j = i - 1;
        while (j >= 0 && maxArr[j] < key)
		{
            maxArr[j + 1] = maxArr[j];
            j--;
        }
        maxArr[j + 1] = key;
    }
    
    for (i = 0; i < uniqueCount; i++) //Check the maxArr values against rows and columns to find our 'X'
	{
        int value = maxArr[i];
        int rowCheck = 0;
        int colCheck = 0;

        
        for (j = 0; j < N; j++) //Loop to Check if all elements in the row are >= value
		{
            int rowValid = 1;
            for (k = 0; k < M; k++) 
			{
                if (matrix[j][k] < value)
				{
                    rowValid = 0;
                    break;
                }
            }
            
            if (rowValid) {
                rowCheck = 1;
                break;
            }
        }

        
        for (j = 0; j < M; j++)//Loop to Check if all elements in the column are >= value
		{
            int colValid = 1;
            for (k = 0; k < N; k++) 
			{
                if (matrix[k][j] < value)
				{
                    colValid = 0;
                    break;
                }
            }
            if (colValid) 
			{
                colCheck = 1;
                break;
            }
        }

        
        if (rowCheck==1 && colCheck==1) //If both the rowCheck and colCheck is equal to 1(true),Save the value to X and break 
		{
            X = value;
            break;
        }
    }

    printf("The maximum possible value X is: %d\n",X); 

    return 0;
}
    

