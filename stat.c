#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>


int main(int argc, char **argv)
{
    if(argc != 2) 
        return 1;
 
    struct stat fileStat; 
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("Informacion para %s\n",argv[1]);
    printf("---------------------------\n");
    printf("Tamaño archivo: \t\t%d bytes\n",fileStat.st_size);
    printf("Numero de Links: \t\t%d\n",fileStat.st_nlink);
    printf("Numero de Bloques Asig: \t%d\n",fileStat.st_blocks);
    printf("Archivo node-i: \t\t%d\n",fileStat.st_ino);
 
    printf("Permisos del Archivo: \t\t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

   
    return 0;
}
