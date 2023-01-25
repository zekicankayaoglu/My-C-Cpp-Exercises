#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//definitions of functions that we will use later
void declare(char* arrayName, char* arraySize, char* arrayType);
void read(char* arrayName, char* fileName);
void print(char* arrayName);
void copy(char* firstArray, char* secondArray);
void initialize(char *arrayName, char *value);
void arithmetic(char* firstArray ,char* secondArray, char* thirdArray, char* operation,int select);

//define struct
struct ArrayTable {
      char  name[10];   // array name
      char  size[5];    // array size
      char  type[10];   // int, float, etc.
};
struct ArrayTable AT[20];

   
int main()
{
	FILE *readFile = fopen("preprocessor.txt", "r");
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
    
    char line[50][500],tempLine[50][200];//line keep lines of txt file and templine helps keep data to sparse line easily
    //these variables keep datas of arrays to send them to functions
    char* token;//temporary variable
    char* arrayName;    //keeps name of array
	char* value; //keeps initialize value
    char* nameOfFile; //keeps name of file
	char* firstArray; 
	char* secondArray;
    char* thirdArray;
	char* operation;
    
    int index = 0,i=0,k=0,counter=0,select;
    //reads file line by line
    while(fgets(line[i],sizeof(line[i]),readFile)) {
        
    		if (line[i][4] != 36 || strlen(line[i])==1){     //checks line is not command line prints its same
                FILE *writeToFile = fopen("cCodeExpanded.c", "a");     		
    			fprintf(writeToFile, "%s", line[i]);
                fclose(writeToFile);
			}
			
    		else if (line[i][4] == 36){	//if line is command line 
				if (line[i][5] == 'd'){ //finds declare function
                    k=0;
					for(int j=9;j<strlen(line[i])-1;j++){
                        tempLine[counter][k] = line[i][j]; 
                        k++;
                    }
                    //first takes name of array
                    token = tempLine[counter];
                    counter++;
                    token = strtok(token,",");
                    strcpy(AT[index].name,token);
                    //then finds size of array
                    token =strtok(NULL,",");
                    k=0;
                    for(int j=1;j<strlen(token);j++){
                        AT[index].size[k] = token[j];
                        k++;
                    }
                    //finds type of array
                    token =strtok(NULL,")");
                    k=0;
                    for(int j=1;j<strlen(token);j++){
                        AT[index].type[k] = token[j];
                        k++;
                    }
                    //keeps all these data in struct
                    //then sends infos about array to declare function
					declare(AT[index].name, AT[index].size, AT[index].type);
                    index++;//index counter for struct 
				}
				
				else if (line[i][5] == 'r') { // if line has read function
                    //learns name of the file and name of the array
                    k=0;
					for(int j=10;j<strlen(line[i])-1;j++){
                        tempLine[counter][k] = line[i][j]; 
                        k++;
                    }
                    token = tempLine[counter];
                    counter++;
                    token = strtok(token,",");
                    nameOfFile =token;                    
                    token =strtok(NULL,")");
                    k=0;
                    
                    for(int j=1;j<strlen(token);j++){
                        tempLine[counter][k] = token[j];
                        k++;
                    }
                    token = tempLine[counter];
                    counter++;
                    arrayName = token;
					read(arrayName,nameOfFile);//sends these infos to function
				}

				else if (line[i][5] == 'p' ){ // if line has print function
                //learns name of array to print it
                    k=0;
					for(int j=11;j<strlen(line[i])-1;j++){
                        tempLine[counter][k] = line[i][j]; 
                        k++;
                    }//name of array is between ( and )
                    token = tempLine[counter];
                    counter++;
                    token = strtok(token,")");
                    print(token);	//sends name of array to function			
						
				}
				
				else if (line[i][7] == '=') { // if line has = we checks some situations
					if (line[i][9] >= 48 && line[i][9] <= 57 && line[i][10] ==';'){ // if an array equals number like A = 5;
                        //leanrs number of array and initialize value 
                        k=0;
                        for(int j=5;j<strlen(line[i])-1;j++){
                            tempLine[counter][k] = line[i][j]; 
                            k++;
                        }
                        token = tempLine[counter];
                        counter++;
                        token = strtok(token," =");
                        arrayName = token;

                        k=0;
                        for(int j=9;j<strlen(line[i])-1;j++){
                            tempLine[counter][k] = line[i][j]; 
                            k++;
                        }
                        token = tempLine[counter];
                        counter++;
                        token = strtok(token,";");
                        value = token;
	
						initialize(arrayName,value);//sends these infos to function
					}
					
					else if (line[i][4] == '$' && line[i][9] == '$' && line[i][11] == ';') { // if line is copy line
                        //learns names of two arrays
                        k=0;
                        for(int j=5;j<strlen(line[i])-1;j++){
                            tempLine[counter][k] = line[i][j]; 
                            k++;
                        }
                        token = tempLine[counter];
                        counter++;
                        token = strtok(token," =");
                        firstArray = token;
                        k=0;
                        for(int j=10;j<strlen(line[i])-1;j++){
                            tempLine[counter][k] = line[i][j]; 
                            k++;
                        }
                        
                        token = tempLine[counter];
                        counter++;
                        token = strtok(token,";");
                        secondArray = token;
						copy(firstArray, secondArray);//sends names of arrays to copy function
					}
					
					else if ((line[i][12] =='+' ||  line[i][12] =='-' || line[i][12] =='*' || line[i][12] =='/') && line[i][9]=='$') { // if line has an operation
                            select=1;//if operation is like that: $C = $A + $B; sends select as 1
                            //learns names of arrays and operation
                            k=0;
                            for(int j=5;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            
                            token = tempLine[counter];
                            counter++;
                            firstArray = strtok(token," =");
                            
                        if (line[i][12] == '+') { //if operations is +
							
                            operation = "+";
                            k=0;
                            for(int j=10;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }

                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," +");
                        }
                                              
						else if(line[i][12] == '-') { //if operations is -
						
                            operation = "-";
                            k=0;
                            for(int j=10;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," -");
						}

						else if(line[i][12] == '*') { //if operations is *
							
                            operation = "*";
                            k=0;
                            for(int j=10;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," *");
						}
						else if(line[i][12] == '/') { //if operations is /
							
                            operation = "/";
                            k=0;
                            for(int j=10;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," /");
						}
						if (line[i][14] == '$') { // aritmethic operation with a number or array
							k=0;
                            for(int j=15;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            thirdArray = strtok(token,";");                                                       
						}
                        
                        else{
                            k=0;
                            for(int j=14;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            thirdArray = strtok(token,";");
                            select=3;//if operation is like that: $C = $A + 2; sends select as 3
						}
						arithmetic(firstArray,secondArray,thirdArray,operation,select);//sends these infos to function
					}

					else if ((line[i][11] =='+' ||  line[i][11] =='-' || line[i][11] =='*' || line[i][11] =='/') && line[i][9]!='$') { //another operation situation
						select=2;//if the operation like that: $C = 5 * $B; sends select as 2
                        //learns names of arrays and operation
                        k=0;
                        for(int j=5;j<strlen(line[i])-1;j++){
                            tempLine[counter][k] = line[i][j]; 
                            k++;
                        }                           
                        token = tempLine[counter];
                        counter++;
                        firstArray = strtok(token," =");
						
						if (line[i][11] == '+') { //if operations is +
							
                            operation = "+";
                            k=0;
                            for(int j=9;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }

                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," +");
                        }
                                              
						else if(line[i][11] == '-') { //if operations is -
						
                            operation = "-";
                            k=0;
                            for(int j=9;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," -");
                       
						}
						else if(line[i][11] == '*') { //if operations is *
							
                            operation = "*";
                            k=0;
                            for(int j=9;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," *");
						}
						else if(line[i][11] == '/') { //if operations is /
							
                            operation = "/";
                            k=0;
                            for(int j=9;j<strlen(line[i])-1;j++){
                                tempLine[counter][k] = line[i][j]; 
                                k++;
                            }
                            token = tempLine[counter];
                            counter++;
                            secondArray = strtok(token," /");
						}
                        if(line[i][13]=='$'){
                            k=0;
                            for(int j=14;j<strlen(line[i])-1;j++){
                                    tempLine[counter][k] = line[i][j]; 
                                    k++;
                                    
                            }
                            
                            token = tempLine[counter];
                            counter++;
                            thirdArray = strtok(token,";");
                        }						
                        arithmetic(firstArray,secondArray,thirdArray,operation,select);//sends these infos to function again
					}
				}
			}
	i++;	
	}

    fclose(readFile);
    return 0;
}

void declare(char *arrayName, char *arraySize, char *arrayType){//prints declaration
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
    int index;
    //finds the array from struct
    for(int i=0;i<20;i++){       
        if(strcmp(arrayName,AT[i].name)==0){
            index = i;
        }
    }    
	fprintf(writeToFile,"    %s %s[%s];\n",AT[index].type,AT[index].name,AT[index].size);//prints declaration to file
	fclose(writeToFile);
}

void read(char* arrayName ,char* fileName){//prints reading
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
	char* typeArray;
    int index,i;
    //finds the array from struct
    for(i = 0; i < 20 ; i++){
		if(strcmp(arrayName,AT[i].name)==0){
			index = i;
		}		
	}
    //learns type of array with if statements
    if(strcmp(AT[index].type,"int") == 0){
        typeArray = "%d";
    }
    else if(strcmp(AT[index].type,"char") == 0){
        typeArray = "%c";
    }
    else if(strcmp(AT[index].type,"double") == 0){
        typeArray = "%lf";
    }
    else if(strcmp(AT[index].type,"float") == 0){
        typeArray = "%f";
    }
    //prints reading code into file 
    fprintf(writeToFile,"    FILE *ff = fopen(\"%s\", \"r\");\n",fileName);
    fprintf(writeToFile,"    for (int i=0; i<%s; i++)\n",AT[index].size);
    fprintf(writeToFile,"        fscanf(ff, \"%s\", &%s[i]);\n",typeArray,AT[index].name);
    fprintf(writeToFile,"    close(ff);\n");
	fclose(writeToFile);
}

void print(char* arrayName){//prints printing code
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
	char* d = "%d";
    int index,i=0;
	
    //finds array name from struct
	while(i<=20){
		if(strcmp(arrayName,AT[i].name)==0){
			index = i;
		}
        i++;
	}
    //prints printing code with datas from struct
	fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[index].size);
	fprintf(writeToFile,"        printf(\"%s\", %s[i]);\n",d,AT[index].name);	
	fclose(writeToFile);
}

void copy(char* firstArray, char* secondArray){//prints copy code
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
	int index1,index2,i=0;
    //finds first and second arrays from struct
	while(i<=20){
		if(strcmp(firstArray,AT[i].name)==0){
			index1 = i;
		}
		else if(strcmp(secondArray,AT[i].name)==0){
			index2 = i;
		}	
        i++;	
	}
	fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[index1].size);
	fprintf(writeToFile,"        %s[i] = %s[i];\n",AT[index1].name,AT[index2].name);	
	fclose(writeToFile);
}

void initialize(char *arrayName, char *value){
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
    int index,i;
    //finds the array from struct
	for(i=0;i <20 ; i++){
		if(strcmp(arrayName,AT[i].name)==0){
			index = i;
		}
	}
    //prints the code with datas from struct
    fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[index].size);
    fprintf(writeToFile,"        %s[i] = %s;\n",AT[index].name,value);
	fclose(writeToFile);
}

void arithmetic(char* firstArray ,char* secondArray, char* thirdArray, char* operation, int flag){//prints arithmetic operation code
	FILE *writeToFile = fopen("cCodeExpanded.c", "a");
    int firstIndex,secondIndex,thirdIndex,i;
    //first checks flag value which coming from reading part
    if(flag==1){      //means operations is like that: $C = $A + $B 
        for(i=0;i <20 ; i++){//finds arrays from struct
            if(strcmp(firstArray,AT[i].name)==0){
                firstIndex = i;
            }
            else if(strcmp(secondArray,AT[i].name)==0){
                secondIndex = i;
            }
            else if(strcmp(thirdArray,AT[i].name)==0){
                thirdIndex = i;
            }
        }
        //prints c code to file according to data
        fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[firstIndex].size);
        fprintf(writeToFile,"        %s[i] = %s[i] %s %s[i];\n",AT[firstIndex].name,AT[secondIndex].name,operation,AT[thirdIndex].name);
        
    }

    else if(flag == 2){//means operation is like that $C = 3 + $B;
        for(i=0;i < 20 ; i++){//finds arrays from struct
            if(strcmp(firstArray,AT[i].name)==0){
                firstIndex = i;
            }
            
            else if(strcmp(thirdArray,AT[i].name)==0){
                thirdIndex = i;
            }
        }
        //prints c code to file according to data
        fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[firstIndex].size);
        fprintf(writeToFile,"        %s[i] = %s %s %s[i];\n",AT[firstIndex].name,secondArray,operation,AT[thirdIndex].name);
    }

    else if(flag == 3){//means operation is like that $C = $A * 5;
        for(i=0;i <20 ; i++){//finds arrays from struct
            if(strcmp(firstArray,AT[i].name)==0){
                firstIndex = i;
            }
            
            else if(strcmp(secondArray,AT[i].name)==0){
                secondIndex = i;
            }
        }
        //prints c code to file according to data
        fprintf(writeToFile,"    for(int i=0; i<%s; i++)\n",AT[firstIndex].size);
        fprintf(writeToFile,"        %s[i] = %s[i] %s %s;\n",AT[firstIndex].name,secondArray,operation,thirdArray);
    }
    fclose(writeToFile);
}