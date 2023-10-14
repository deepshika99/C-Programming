/********************************************************************************************************************
Question Given:
Write a C program to create 50 files with names filei.txt (ie. file1.txt to file50.txt)
Each file contains numbers from 0 to i (write these numbers into the file) - 10 Marks
For example:
file1.txt contains 0 1
file2.txt contains 0 1 2
file3.txt contains 0 1 2 3
.
.
file50.txt contains 0 1 2 3 4 .... ...... ...... ....50
Contents of filei.txt should be copied to file(i-1).txt and file1.txt should be copied to file50.txt.
For example:
After the contents are copied
file1.txt contains 0 1 2
file2.txt contains 0 1 2 3
.
.
file49.txt contains 0 1 2 3 .... .... ...... ....50
file50.txt contains 0 1
Display the content of each file before and after copying
For Example
BEFORE COPYING
Filename: file1.txt Content: 0 1
FileName: file2.txt Content: 0 1 2
AFTER COPYING
Filename: file1.txt Content 0 1 2
Filename: file2.txt Content 0 1 2 3
*********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*function to create a new file with the file name given and insert into it integers from 0 to n*/
void create_new_file_and_insert(char *new_file, int n)
{
    FILE *fptr;
    int i;
    fptr = fopen(new_file,"w");
    assert(fptr !=NULL);
    for(i = 0;i<=n;i++)
    {
        fprintf(fptr,"%d\t",i);
    }
    fclose(fptr);
}
/* function to print contents of the file given*/
void print_file(char *file_name)
{
    FILE *fptr = fopen(file_name,"r");
    char c;
    printf("Filename: %s contains: ",file_name);
  
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    printf("\n\n");
    fclose(fptr);
}
/* function to copy contents of one file to another */
void copy_file_to_file(char *file_name_dest,char *file_name_src)
{
    FILE *fptr_dest = fopen(file_name_dest,"w");
    FILE *fptr_src = fopen(file_name_src,"r");

    char c;
    while ((c = fgetc(fptr_src)) != EOF) {
        fputc(c, fptr_dest);
    }
    fclose(fptr_dest);
    fclose(fptr_src);

}
//main function
int main()
{
    char file_name1[20],file_name2[20];
    int j;

    printf("BEFORE COPYING\n");

    for(j = 1;j<=50;j++) //create 50 files with file name as "filei.txt
    {
        sprintf(file_name1, "file%d.txt", j);
        create_new_file_and_insert(file_name1,j); //creating a file and inserting numbers from 0-i
        print_file(file_name1); //print the file contents
    }

    printf("AFTER COPYING\n");

    copy_file_to_file("file1.txt","file50.txt"); //only for file1.txt, file50.txt is copied into it

    for(j = 2;j<50;j++) //from file2.txt to file50.txt update them
    {
        sprintf(file_name1, "file%d.txt",j);
        sprintf(file_name2, "file%d.txt",j+1);
        copy_file_to_file(file_name1,file_name2);
    }
  
    for(j = 1;j<=50;j++) //print the files after copying
    {
        sprintf(file_name1, "file%d.txt",j);
        print_file(file_name1);
    }
    return 0;
}
