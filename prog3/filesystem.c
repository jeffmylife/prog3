//
//  filesystem.c
//  prog3
//
//  Created by Michael Cole on 11/3/17.
//  Copyright © 2017 Michael Cole. All rights reserved.
//  Copyright © 2017 Justin Guillory. All rights reserved.
//

#include "filesystem.h"
#include <stdio.h>

DirectoryEntry Directory[100];
FATentry FAT[5000];

// functions for filesystem API

// open existing file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File open_file(char *name, FileMode mode)
{
    File fileToOpen;
    //TODO: use the name and mode to either open the file or deny permission
    return fileToOpen;
};

// create and open new file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File create_file(char *name, FileMode mode)
{
    //TODO: if error, fileToCreate = NULL
    //
    File fileToCreate; //may need to malloc, may need constructor
    //TODO: handle error, set current file position to 0
    open_file(name,mode);
    
    return fileToCreate;
};

// close 'file'.  Always sets 'fserror' global.
void close_file(File file)
{
    //TODO: ???
};

// read at most 'numbytes' of data from 'file' into 'buf', starting at the
// current file position.  Returns the number of bytes read. If end of file is reached,
// then a return value less than 'numbytes' signals this condition. Always sets
// 'fserror' global.
unsigned long read_file(File file, void *buf, unsigned long numbytes)
{
    unsigned long numReadBytes = 0;
    //TODO: check for EOF
    //TODO: start reading at current position
    //TODO: if ! EOF, numReadBytes ++, read next Position, else return;
    return numReadBytes;
};

// write 'numbytes' of data from 'buf' into 'file' at the current file position.
// Returns the number of bytes written. On an out of space error, the return value may be
// less than 'numbytes'.  Always sets 'fserror' global.
unsigned long write_file(File file, void *buf, unsigned long numbytes)
{
    unsigned long numBytesWritten = 0;
    //TODO: check if out of space (OOS)
    //TODO: start writing at current position
    //TODO: if ! OOS, numBytesWritten ++, write next position,else return;
    return numBytesWritten;
};

// sets current position in file to 'bytepos', always relative to the beginning of file.
// Seeks past the current end of file should extend the file. Always sets 'fserror'
// global.
void seek_file(File file, unsigned long bytepos)
{
    //TODO: check if bytepos is past end of file
    //TODO: if it is, extend the file
    //TODO: set the current position to bytepos
};

// returns the current length of the file in bytes. Always sets 'fserror' global.
unsigned long file_length(File file)
{
    unsigned long lengthOfFile;
    //TODO: get the length of the file;
    return lengthOfFile;
};

// deletes the file named 'name', if it exists and if the file is closed.
// Fails if the file is currently open. Returns 1 on success, 0 on failure.
// Always sets 'fserror' global.
int delete_file(char *name)
{
    int success = 0;
    //TODO: check if file exists
    //      if not, return 0
    //      if it exists, check if file is open
    //      if it is open, return 0
    //      else, close the file and set success = 1;
    return success;
};

// determines if a file with 'name' exists and returns 1 if it exists, otherwise 0.
// Always sets 'fserror' global.
int file_exists(char *name)
{
    int exists = 0;
    //TODO: check if the file exists
    if (exists == 0)
        fserror = FS_NONE;
    else fserror = FS_FILE_ALREADY_EXISTS;
    return exists;
};

// describe current filesystem error code by printing a descriptive message to standard
// error.
void fs_print_error(void)
{
    printf("FS ERROR: ");
    switch(fserror){
        case FS_NONE:
            puts("NONE");
        case FS_OUT_OF_SPACE:
            puts("OUT_OF_SPACE");
        case FS_FILE_NOT_OPEN:
            puts("FILE_NOT_OPEN");
        case FS_FILE_OPEN:
            puts("FILE_OPEN");
        case FS_FILE_NOT_FOUND:
            puts("FILE_NOT_FOUND");
        case FS_FILE_READ_ONLY:
            puts("FILE_READ_ONLY");
        case FS_FILE_ALREADY_EXISTS:
            puts("FILE_ALREADY_EXISTS");
        default: puts("UNKNOWN ERROR");
    };
};

// filesystem error code set (set by each filesystem function)
extern FSError fserror;
