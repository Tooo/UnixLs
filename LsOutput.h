#ifndef _LSOUTPUT_H_
#define _LSOUTPUT_H_

#include <stdbool.h>
#include <sys/stat.h>

void printNewLine();

void printError(char * error);

void printDirectory(char * directory);

void printFilename(char * fileName);

void printNoFile(char * fileName);

void printInode(long inode);

void printl(struct stat buf);

void printPermission(mode_t mode);

void printDate(struct timespec time);

void printLink(char * link);

#endif