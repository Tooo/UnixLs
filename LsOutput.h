#ifndef _LSOUTPUT_H_
#define _LSOUTPUT_H_

#include <stdbool.h>
#include <sys/stat.h>

void printNewLine();

void printDirectory(char * directory);

void printFilename(char * filename);

void printInode(long inode);

void printl(struct stat buf);

void printPermission(mode_t mode);

void printDate(struct timespec time);

#endif