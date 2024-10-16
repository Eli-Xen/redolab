// Author: Eliza Malyshev 
// KUID: 3122318
// Date: 10/10/2024 
// Lab: #5.2
// Purpose: make and manipulate 2D arrays 
#include <stdio.h> 
#define SIZE 5 //this makes so that every time SIZE is used its always 5, like global variable kinda 

int (*addMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] //this declaration will return a pointer of SIZE; add corresponding entries of two matricies and return matrix of added matricies 
{
    static int added[SIZE][SIZE]; 
    printf("matrix 1 looks like:\n"); //prints 2D array in pretty format 
    for (int i=0; i<SIZE; i++) 
    {
        for (int j=0; j<SIZE; j++) 
        {
            added[i][j]=m1[i][j]+m2[i][j]; //add corresponding entries and put them into added array 
        }
    }  
    return added; //returns pointer to added matrix 
}

int (*multMx(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] //function that a pointer is pointing to that returns a pointer to multiplied matrix 
{
    static int mult[SIZE][SIZE]; 
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            mult[i][j]=0; //initlize to 0 to clear garbage values 
            for (int k=0; k<SIZE; k++) //dot product of the i row of m1 and j column of m2; goes through k times
            {
                // printf("we are current at k %d\n", k); 
                mult[i][j]+=m1[i][k]*m2[k][j]; //keeps adding result for each k iteration as it goes through k row and k column in common 
                // printf("mult[%d][%d] += m1[%d][%d] * m2[%d][%d] --> mult[%d][%d] = %d\n", i, j, i, k, k, j, i, j, mult[i][j]);
            }
        }
    }

    return mult; //returns pointer to multiplied matrix 
}

int (*transMx(int m[SIZE][SIZE]))[SIZE]
{
    static int trans[SIZE][SIZE]; 
    for (int i=0; i<SIZE; i++) 
    {
        int temp[SIZE]; //temporary row where we will put transposed elements 
        for (int j=0; j<SIZE; j++) 
        {
            trans[j][i]=m[i][j];
        }
    }  
    return trans; //returns pointer to transpose matrix    
}

int printMx(int (*m)[SIZE]) //takes pointer to matrix as parameter 
{
    for (int i=0; i<SIZE; i++) 
    {
        printf("|");
        for (int j=0; j<SIZE; j++) 
        {
            printf("%d ", m[i][j]);
        }
        printf("|\n");
    }  
    return 0;    
}


int main()
{
    int m1[SIZE][SIZE]; 
    int m2[SIZE][SIZE]; 
    for (int i=0; i<SIZE; i++) //goes through each row of matrix 1... 
    {
        printf("give row %d of matrix 1, with each integer seperated by spaces: ", i+1); 

        for (int j=0; j<SIZE; j++) //...and for every column...
        {
            while (scanf("%d", &m1[i][j])!=1)  //checks if valid input; user input has to be able to be scanned as int otherwise gives error 
            {
                printf("invalid input, re-enter row %d of matrix 1 with ints separated by spaces: ", i+1);  // **Change**: Prompt re-entry if invalid input
                while (getchar()!='\n'); //this has to be here to clear input so we can scan again 
            }
        }
    }
    printf("\n"); 
    for (int i=0; i<SIZE; i++) //goes through each row of matrix 2... 
    {
        printf("give row %d of matrix 2, with each integer seperated by spaces: ", i+1); 
        for (int j=0; j<SIZE; j++) //...and for every column...
        {
           while (scanf("%d", &m2[i][j])!=1)  //checks if valid input; user input has to be able to be scanned as int otherwise gives error 
            {
                printf("invalid input, re-enter row %d of matrix 2 with ints separated by spaces: ", i+1);  // **Change**: Prompt re-entry if invalid input
                while (getchar()!='\n'); //this has to be here to clear input so we can scan again 
            }
        }

    }

    //print each matrix  in pretty format 
    printf("matrix 1 looks like: \n"); 
    printMx(m1); 
    printf("matrix 2 looks like: \n"); 
    printMx(m2);

    //show adding of matricies 
    int (*added)[SIZE]=addMx(m1, m2); //makes a pointer that will point to result of return pointer 
    printf("matricies added together look like: \n"); 
    printMx(added); //pass pointer of matrix to be printed 
    
    //show multiplication of matricies 
    printf("matricies multiplied together look like: \n"); 
    int (*multiplied)[SIZE]=multMx(m1, m2); 
    printMx(multiplied); 

    //show transpose of matricies 
    printf("matrix 1 transpose looks like: \n"); 
    int (*transpose1)[SIZE]=transMx(m1); 
    printMx(transpose1); 
    printf("matrix 2 transpose looks like: \n"); 
    int (*transpose2)[SIZE]=transMx(m2); 
    printMx(transpose2); 

    return 0; 
}