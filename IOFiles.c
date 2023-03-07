//there are 3 streams,  std input:  keyboard/file
//                      std output: display/screen
//                      std error:  display/screen

#include <stdio.h>

int main(){             //if we rename the file to binFile.txt then the programme will rename it and open it
    FILE *pFile = NULL;
    char oldFileName[] = "binFile.txt";
    char fileName[] = "binaryFile.txt";
   
    int sucess = rename(oldFileName,fileName); //the int returned will be 1 for successfully renaming
    if(!sucess){
        printf("File name changed\n");
    }else{
        printf("File name not changed\n");
    }
    
    pFile = fopen(fileName,"r");
    if(!pFile){
        printf("failed to open %s\n", fileName);
        return -1;
    }



    char fileLocation = fgetc(pFile);    //gets value of first character, if run again it will get the second
    printf("Position in file is: %c\n", fileLocation);
    rewind(pFile);//moves the current state in the file back to the start

    int c;
    // the fgetc get single characters from the file, this prints the whole file
    while( ( c = fgetc(pFile) ) != EOF)         //  ! = is not the same as !=
        printf("%c",c);

    rewind(pFile);

    // char *fgets(char *storageLocation, int nchars, FILE * stream)   //this will read n chars or until it reaches the end of the line
        // if no error it returns pointer, str. If there is then it returns NULL. Reading EOF counts as an error

    //this will print until the end of the liune since \n on the first line is "NULL"
    char testString[60];
    if (fgets(testString,60,pFile) != NULL)
    {
        printf("fgets: %s",testString);
    }

    //to read data with a specific data format we will use fscanf, the spacs between the %s says that the file is a ssv
    rewind(pFile);
    char str1[10], str2[10], str3[10], str4[10], str5[10];
    fscanf(pFile, "%s %s %s %s %s", str1, str2, str3, str4, str5);

    printf("Read String1 |%s|\n", str1);
    printf("Read String1 |%s|\n", str2);
    printf("Read String1 |%s|\n", str3);
    printf("Read String1 |%s|\n", str4);
    printf("Read String1 |%s|\n", str5);
    
    fclose(pFile);   //returns EOF (end of file) if error occurs, usually -1 or a 0 if successful
    pFile = NULL;
    //-------------------------------------------------writing-------------------------------------------------
    //to write one character you use the function fputc(int ch, FILE * pointer)
    //we will use w+ to write and read

    FILE * pWriteFile;
    pWriteFile = fopen("WriteFile.txt","w+");

    fputs("Hello, here is some sample text\nAnd another line of sample text\n",pWriteFile);
    int printReturn = fprintf(pWriteFile, "%i %i", 10, 15);    //returns number of characters written or -ve on a fail
    printf("The output of fprintf is the number of characters written: %i\n", printReturn);

    //fprintf seems better if you want to specify the data type of what you are writing, e.g. char or asci of char


    //====================================================position in file=========================================
    //ftell(),fgetpos()

    // pWriteFile = fopen("WriteFile.txt","w+");
    fseek(pWriteFile, 8, SEEK_SET); //moves current position to the end
                                    //options are set (beginning), cur (current) and end 
    int filePosition = ftell(pWriteFile);
    printf("Boo will be written to the file starting from the index: %i\n",filePosition);
    fputs("BOO!",pWriteFile);   //this replaces the data that was there in the file
    filePosition = ftell(pWriteFile);
    printf("Position in file is %i\n",filePosition);

    fpos_t positionWriteFile;       //this is a position variable
    int position1 = fgetpos(pWriteFile, &positionWriteFile);    //returns 0 if successful and stores the location in the second argument
    printf("Current position using fgetpos is: %i\n", positionWriteFile);
    fpos_t positionWriteFile1;
    fgetpos(pWriteFile, &positionWriteFile1);

    fseek(pWriteFile, 4, SEEK_SET);
    fgetpos(pWriteFile, &positionWriteFile);
    printf("Current position using fgetpos is: %i\n", positionWriteFile);

    // fgetpos(pWriteFile, &positionWriteFile);
    fsetpos(pWriteFile, &positionWriteFile1);       //can only use this to go to a position that we have been to before and stored
    printf("Current position using fgetpos is: %i\n", positionWriteFile1);
    fclose(pWriteFile);
    pWriteFile = NULL;

    errorBreakout: printf("\n\n\n\n");
    return 0;
}