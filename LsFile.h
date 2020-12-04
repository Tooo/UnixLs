#ifndef _LSFILE_H_
#define _LSFILE_H_

int File_setup();

void File_readDirectory(char * dirName);
void File_readFile(char * path, char * fileName);

char * File_getNameFromID(int userID);

void File_runDirectory();

#endif