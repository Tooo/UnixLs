#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#include "LsOutput.h"
#include "LsFile.h"

/*
    LsOutput
    Handles all screen outputs
*/

void printNewLine() {
    printf("\n");
}

void printError(char * error) {
    printf("%s failed\n", error);
}

void printDirectory(char * directory) {
    printf("%s:\n", directory);
}

void printFilename(char * fileName) {
    printf("%s", fileName);
}

void printNoFile(char * fileName) {
    printf("UnixLs: cannot access '%s': No such file or directory\n", fileName);
}

void printInode(unsigned long long inode) {
    printf("%llu ", inode);
}

void printl(struct stat buf) {
    printPermission(buf.st_mode);
    printf("%2ld ", buf.st_nlink);
    printf("%s ", File_getNameFromID(buf.st_uid));
    printf("%s ", File_getGroupFromID(buf.st_gid));
    printf("%6ld ", buf.st_size);
    printDate(buf.st_mtim);
}

void printPermission(mode_t mode) {
    if (S_ISDIR(mode)) {
        printf("d");
    } else if (S_ISLNK(mode)) {
        printf("l");
    } else {
        printf("-");
    }

    char rwx[9] = "rwxrwxrwx";
    int permission[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    for (int i = 0; i < 9; i++) {
        if (mode & permission[i]) {
            printf("%c", rwx[i]);
        } else {
            printf("-");
        }
    }
    printf(" ");
}

void printDate(struct timespec time) {
    time_t seconds = time.tv_sec;
    struct tm * local = localtime(&seconds);

    char * months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%s %2d ", months[local->tm_mon], local->tm_mday);
    printf("%d ", local->tm_year+1900);
    printf("%02d:%02d ", local->tm_hour, local->tm_min);
}

void printLink(char * link) {
    printf(" -> %s", link);
}