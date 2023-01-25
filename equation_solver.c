#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float matrix[10][10],variable[10],one_equation[2];
    float p = 0,f=0,total=0;
    int numberEquation,i,x,j,y;   
    
    printf("How many equations will you enter?: ");
    scanf("%d",&numberEquation);
    printf("\n");
    printf("===You will enter coefficients and results for %d equation===",numberEquation);
    printf("\n\n");
    
    for(i=1;i <= numberEquation;i++){
        for(j=1;j <= numberEquation+1;j++){
            if(numberEquation == 1){
                printf("Enter the coefficient of the %d. variable of the %d. equation: ",j,i);
                scanf("%f",&one_equation[j]);
            }
            else{
                if(j==numberEquation+1){
                    printf("Enter result of the %d. equation: ",i);
                    scanf("%f",&matrix[i][j]);
                }
                else{
                    printf("Enter the coefficient of the %d. variable of the %d. equation: ",j,i);
                    scanf("%f",&matrix[i][j]);
                }
            }
        }
        printf("\n");

    }

    printf("\n\n");

    if(numberEquation == 1){ 
        printf("The equation is:\n\n");
        printf("%.1fa = %.1f\n\n",one_equation[1],one_equation[2]);  
        printf("Value of a is: %.2f",(one_equation[2]/one_equation[1]));
        printf("\n");    
    }

    else{   
        printf("The equations are:\n\n");
        for(i=1;i <= numberEquation;i++){
            for(j=1;j <= numberEquation+1;j++){   
                if(j == numberEquation+1){
                    printf(" = %1.f",matrix[i][j]);
                }
                else{
                    if(j == 1){
                        printf("%.1fa",matrix[i][j]);
                    }
                    else if(j==2){
                        if(matrix[i][j]>0 || matrix[i][j] == 0){
                            printf(" + %.1fb ",matrix[i][j]);
                        }
                        else {
                            printf(" %.1fb ",matrix[i][j]);
                        }
                    }
                    else if(j == 3){
                        if(matrix[i][j]>0 || matrix[i][j] == 0){
                            printf(" + %.1fc ",matrix[i][j]);
                        }
                        else {
                            printf(" %.1fc ",matrix[i][j]);
                        }
                    }
                }
            }
            printf("\n\n");

        }

        for(x=1;x<=numberEquation-1;x++){
            p = matrix[x][x];
            for(i=x;i<=numberEquation+1;i++)
                matrix[x][i]= matrix[x][i]/p; 

            for(j=x+1;j<=numberEquation;j++){
                f = matrix[j][x];

                for(i = x;i<=numberEquation+1;i++){
                    matrix[j][i] = matrix[j][i] - f * matrix[x][i];
                }
            } 
            variable[numberEquation] = matrix[numberEquation][numberEquation+1]/matrix[numberEquation][numberEquation];

            for(i=numberEquation-1;i >= 1;i--){
                total = 0;
                for(y=i+1;y <= numberEquation;y++)
                    total = total + matrix[i][y] * variable[y];
                    variable[i]= (matrix[i][numberEquation+1]-total) / matrix[i][i];
            }

        } 
            
        for(i=1; i <= numberEquation;i++){
            if(i == 1){
                printf("Value of a variable is = %.2f",variable[i]); 
                printf("\n");
            }
            if(i == 2){
                printf("Value of b variable is = %.2f",variable[i]); 
                printf("\n");
            }
            if(i == 3){
                printf("Value of c variable is = %.2f",variable[i]); 
                printf("\n");
            }
        }
    }         
    return 0;

}
