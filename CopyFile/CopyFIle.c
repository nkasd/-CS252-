/*Assignment 2.24
program that copies the contents of one file to a destination file
include all necessary error checking, including ensuring that the source file exists*/

#include <stdio.h>
#include<sys/stat.h> //functions that have arguments or return values of type mode_t
#include<malloc.h>   //for performing dynamic memory allocation
#include<fcntl.h>    //define the flock structure describing a file lock
#include<unistd.h>   //provides access to the POSIX operating system API

// define the Function "CopyFile" to execute

int CopyFile(char *source,char *destination)
{
    int fd_source, fd_destination; // file descripter
    struct stat buffer;            // source file buffer

    if ( ( fd_source=open(source,O_RDONLY) )==-1 ) // For Errors in Source File
    {
        printf("ERROR(Souce File Unreadable)\n");
        return -1;
    }
    
     if( ( fd_destination = creat(destination, 0600) ) == -1) //permission, memory, etc. errors
     {
         printf("ERROR (Can't Create Copy");
         close (fd_source);
         return -1;
     }

     stat(source,&buffer);
     char *code;

    // copy+paste the data 
     read(fd_source,code,buffer.st_size);
     write(fd_destination,code,buffer.st_size);

     close(fd_source);
     close(fd_destination);

     return 0;
}

int main()
{
    // define variable and inout necessary data for source and location
    char *source=malloc(128), *destination = malloc(128);
    printf("Source File:\n");
    scanf("%s",source);
    printf("Copy to:\n");
    scanf("%s", destination);

    if (CopyFile(source,destination) != -1)
    {
        printf("File Copy Done!\n");
    }
}

