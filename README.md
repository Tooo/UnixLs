# UnixLs
Emulates the Ls Commmand in Unix.
Allows multiple directories and a few options.

## Installation
1. Clone the repository
```bash
git clone https://github.com/Tooo/UnixLs.git
```
2. Make the objects and executable file: 
```bash
make
```
3. Run the executable:
```bash
UnixLs
```

## Options
| Options | Description |
| :------ | :---------- |
| -i | List file's inode's number |
| -l | List with long format |
| -R | Recursively list directory tree |

## Sample Run
### UnixLs
```
list.c
UnixLs.o
README.md
UnixLs
LsOutput.h
list.h
UnixLs.c
LsFile.o
LsFile.h
LsOutput.o
LsOutput.c
test
UnixLs.h
list.o
makefile
LsFile.c
```
### UnixLs *.c
```
LsFile.c
LsOutput.c
UnixLs.c
list.c
```

### UnixLs -i
```
46295 list.c
46371 UnixLs.o
46291 README.md
46383 UnixLs
46290 LsOutput.h
46296 list.h
46293 UnixLs.c
46377 LsFile.o
46288 LsFile.h
46372 LsOutput.o
46289 LsOutput.c
46298 test
46294 UnixLs.h
46378 list.o
46297 makefile
46287 LsFile.c
```

### UnixLs -i -l . test
```
.:
46295 -rw-r--r--  1 root root  14674 Dec 22 2020 14:25 list.c
46371 -rw-r--r--  1 root root   5672 Dec 22 2020 17:20 UnixLs.o
46291 -rw-r--r--  1 root root     11 Dec 22 2020 14:25 README.md
46383 -rwxr-xr-x  1 root root  36408 Dec 22 2020 17:20 UnixLs
46290 -rw-r--r--  1 root root    441 Dec 22 2020 14:25 LsOutput.h
46296 -rw-r--r--  1 root root   4988 Dec 22 2020 14:26 list.h
46293 -rw-r--r--  1 root root   1477 Dec 22 2020 14:25 UnixLs.c
46377 -rw-r--r--  1 root root  15448 Dec 22 2020 17:20 LsFile.o
46288 -rw-r--r--  1 root root    330 Dec 22 2020 14:25 LsFile.h
46372 -rw-r--r--  1 root root  13096 Dec 22 2020 17:20 LsOutput.o
46289 -rw-r--r--  1 root root   1862 Dec 22 2020 14:25 LsOutput.c
46298 drwxr-xr-x  4 root root   4096 Dec 22 2020 14:25 test
46294 -rw-r--r--  1 root root    103 Dec 22 2020 14:25 UnixLs.h
46378 -rw-r--r--  1 root root  17896 Dec 22 2020 17:20 list.o
46297 -rw-r--r--  1 root root    375 Dec 22 2020 14:25 makefile
46287 -rw-r--r--  1 root root   3271 Dec 22 2020 14:25 LsFile.c

test:
46299 drwxr-xr-x  2 root root   4096 Dec 22 2020 14:25 link
46303 drwxr-xr-x  2 root root   4096 Dec 22 2020 14:25 perm
```

### UnixLs -Rli
```
.:
46295 -rw-r--r--  1 root root  14674 Dec 22 2020 14:25 list.c
46371 -rw-r--r--  1 root root   5672 Dec 22 2020 17:20 UnixLs.o
46291 -rw-r--r--  1 root root     11 Dec 22 2020 14:25 README.md
46383 -rwxr-xr-x  1 root root  36408 Dec 22 2020 17:20 UnixLs
46290 -rw-r--r--  1 root root    441 Dec 22 2020 14:25 LsOutput.h
46296 -rw-r--r--  1 root root   4988 Dec 22 2020 14:26 list.h
46293 -rw-r--r--  1 root root   1477 Dec 22 2020 14:25 UnixLs.c
46377 -rw-r--r--  1 root root  15448 Dec 22 2020 17:20 LsFile.o
46288 -rw-r--r--  1 root root    330 Dec 22 2020 14:25 LsFile.h
46372 -rw-r--r--  1 root root  13096 Dec 22 2020 17:20 LsOutput.o
46289 -rw-r--r--  1 root root   1862 Dec 22 2020 14:25 LsOutput.c
46298 drwxr-xr-x  4 root root   4096 Dec 22 2020 14:25 test
46294 -rw-r--r--  1 root root    103 Dec 22 2020 14:25 UnixLs.h
46378 -rw-r--r--  1 root root  17896 Dec 22 2020 17:20 list.o
46297 -rw-r--r--  1 root root    375 Dec 22 2020 14:25 makefile
46287 -rw-r--r--  1 root root   3271 Dec 22 2020 14:25 LsFile.c

./test:
46299 drwxr-xr-x  2 root root   4096 Dec 22 2020 14:25 link
46303 drwxr-xr-x  2 root root   4096 Dec 22 2020 14:25 perm

./test/perm:
46305 -rw-r--r--  1 root root      0 Dec 22 2020 14:25 group.txt
46307 -rw-r--r--  1 root root      0 Dec 22 2020 14:25 other.txt
46304 -rwxr-xr-x  1 root root      0 Dec 22 2020 14:25 all.txt
46306 -rw-r--r--  1 root root      0 Dec 22 2020 14:25 noperm.txt
46308 -rwxr-xr-x  1 root root      0 Dec 22 2020 14:25 owner.txt
46309 -rw-r--r--  1 root root      0 Dec 22 2020 14:25 read.txt

./test/link:
46302 lrwxrwxrwx  1 root root      5 Dec 22 2020 14:25 c.txt -> a.txt
46300 -rw-r--r--  1 root root     15 Dec 22 2020 14:25 a.txt
46301 lrwxrwxrwx  1 root root      5 Dec 22 2020 14:25 b.txt -> a.txt
```
