#include <stdio.h>
#include<stdlib.h>
void insert(int matrix[][10], int row, int column) {

   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
}

void add(int first[][10],int second[][10],int result[][10],int r1, int c1) {
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            result[i][j]=first[i][j]+second[i][j];
        }
        
    }
}

void sub(int first[][10],int second[][10],int result[][10],int r1, int c1) {
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            result[i][j]=first[i][j]-second[i][j];
        }
        
    }
}

void trans(int first[][10],int result[][10],int r1, int c1) {
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            result[i][j]=first[i][j];
        }
        
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            if(i<j)
            {
                int temp=result[i][j];
                result[i][j]=result[j][i];
                result[j][i]=temp;
            }
        }
        
    }
}


void mult(int first[][10],int second[][10],int result[][10],int r1, int c1, int r2, int c2) {
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }


   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}


void display(int result[][10], int row, int column) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
   printf("Enter rows and column  matrix: ");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and column  matrix: ");
   scanf("%d %d", &r2, &c2);
   insert(first, r1, c1);
   insert(second, r2, c2);

while(1)
{
    int choice;
   printf("Enter the Choice:");
   scanf("%d",&choice);
    switch(choice) {
    case 1: 
        add(first,second,result,r1,c1);
        display(result,r1,c1);
        break;
    case 2: 
        sub(first,second,result,r1,c1);
        display(result,r1,c1);
        break;
    case 3: 
        mult(first, second, result, r1, c1, r2, c2);
        display(result, r1, c2);
        break;
    case 4:
        trans(first,result,r1,c1);
        display(result,r1,c1);
        break;
    default:
        exit(0);
}}

   return 0;
}