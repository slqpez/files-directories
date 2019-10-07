#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#define _POSIX_SOURCE
#include <unistd.h>
#undef _POSIX_SOURCE

int main(int argc, char *argv[])
{

    if (argc == 1)
    {

        DIR *dir = opendir(".");
        struct dirent *ent;
        if (dir == NULL)
        {
            printf("No se puede abrir ");
        }
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
   
    if (argc == 2 && strcmp(argv[1], "-l") == 0)
    {
        DIR *dir = opendir(".");
        struct dirent *ent;
        if (dir == NULL)
        {
            printf("No se puede abrir ");
        }
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
            archivoa(ent->d_name);
        }
        closedir(dir);
    }
    if (argc == 3 && strcmp(argv[1], "-l") == 0)
    {
        char cwd[256];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {

            const size_t len1 = strlen(cwd);
            const size_t len2 = strlen(argv[2]);
            char *result = malloc(len1 + len2 + 1);

            memcpy(result, cwd, len1);
            memcpy(result + len1, argv[2], len2 + 1);

            printf("Current working directory is: %s\n", result);

            DIR *dir = opendir(result);
            struct dirent *ent;
            if (dir == NULL)
            {
                printf("No se puede abrir el directorio");
            }
            while ((ent = readdir(dir)) != NULL)
            {
                printf("%s\n", ent->d_name);
                archivoa(ent->d_name);
            }
            closedir(dir);
        }
        else
        {
            perror("getcwd() error");
        }
    }

    return 0;
}
void archivoa(char *archivo)
{

    struct stat st;
    printf("File: %s\n", archivo);
    stat(archivo, &st);
    if (stat(archivo, &st) < 0)
        return 1;

    printf("Information for %s\n", archivo);

    printf("File Size: \t\t%d bytes\n", st.st_size);
    printf("Number Blocks: \t\t%d \n", st.st_blocks);
    printf("Number of Links: \t%d\n", st.st_nlink);
    printf("File inode: \t\t%d\n", st.st_ino);

    printf("File Permissions: \t");
    printf((S_ISDIR(st.st_mode)) ? "d" : "-");
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf((st.st_mode & S_IRGRP) ? "r" : "-");
    printf((st.st_mode & S_IWGRP) ? "w" : "-");
    -printf((st.st_mode & S_IXGRP) ? "x" : "-");
    printf((st.st_mode & S_IROTH) ? "r" : "-");
    printf((st.st_mode & S_IWOTH) ? "w" : "-");
    printf((st.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
    printf("The file %s a symbolic link\n", (S_ISLNK(st.st_mode)) ? "is" : "is not");
    printf("------------------------------------\n");
}
