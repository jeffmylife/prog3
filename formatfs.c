// Michael Cole & Justin Guillory

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "softwaredisk.h"


// access mode for open_file() and create_file()
typedef enum {
    READ_ONLY, READ_WRITE
    } FileMode;

// main private file type
typedef struct FileInternals {
	int Dir;
	int FATblock;
	int FATblockPosition;
	FileMode mode;
	int currentPosition;
	int currentBlock;
} FileInternals;

// file type used by user code
typedef FileInternals* File;

typedef struct DirectoryEntry{
	char Filename[255];
	int StartBlock;
	int EndBlock;
	int Size;
	int Used;
	int isOpen;
	//File fileRef;
	char emptySpace[257-5*sizeof(int)/*-sizeof(File)*/];	
} DirectoryEntry;

typedef struct FATentry{
	int Next;
	int Used;
} FATentry;

DirectoryEntry Directory[100];

int main(){
        DirectoryEntry dirBuf;
	int FATEntriesPerBlock = 512/sizeof(FATentry);
	FATentry FATBuf[FATEntriesPerBlock];	

	init_software_disk();
	for (int i = 0; i < 100; i++)
	{
		strcpy(Directory[i].Filename,"\0");
		Directory[i].StartBlock = -1;
		Directory[i].EndBlock = -1;
		Directory[i].Size = -1;
		Directory[i].Used = 0;
		Directory[i].isOpen = 0;
		//Directory[i].fileRef = (File)-1;
		strcpy(Directory[i].emptySpace,"\0");
		int ret = write_sd_block(&Directory[i],i);
//		printf("Return value was %d.\n", ret);
	}
	for (int j = 100; j < 103; j++)
	{
		if (j!= 102)
		{
			for (int z = 0; z < FATEntriesPerBlock; z++)
			{	
				FATBuf[z].Next = -1;
				FATBuf[z].Used = 1;	
			}
		}
		else
		{
			for (int z = 0; z < FATEntriesPerBlock - 28; z++)
			{	
				FATBuf[z].Next = -1;
				FATBuf[z].Used = 1;	
			}
		}
		int ret = write_sd_block(&FATBuf,j);
//		printf("Return value was %d for block %i \n\n", ret,j);
	}
	for (int j = 102; j < 164; j++)
	{
		if (j!= 102)
		{
			for (int z = 0; z < FATEntriesPerBlock; z++)
			{	
				FATBuf[z].Next = -1;
				FATBuf[z].Used = 0;	
			}
		}
		else
		{
			for (int z = 36; z < FATEntriesPerBlock; z++)
			{	
				FATBuf[z].Next = -1;
				FATBuf[z].Used = 0;	
			}
		}
		int ret = write_sd_block(&FATBuf,j);
//		printf("Return value was %d for block %i \n\n", ret,j);
	}
/*
	printf("Reading directory\n");
	for (int k = 0; k < 100; k++)
	{
		bzero(&dirBuf,SOFTWARE_DISK_BLOCK_SIZE);
		int ret2 = read_sd_block(&dirBuf,(unsigned long)k);
		printf("Directory entry %i : read returned %i\n",k,ret2);
		printf("Directory entry: %s\n %i\n %i\n %i\n %i\n %s\n\n",
		dirBuf.Filename,
		dirBuf.StartBlock,
		dirBuf.EndBlock,
		dirBuf.Size,
		dirBuf.Used,
		dirBuf.emptySpace);
	}

	printf("Reading FAT\n");
	for (int k = 100; k < 105; k++)
	{
		bzero(&FATBuf,SOFTWARE_DISK_BLOCK_SIZE);
		int ret2 = read_sd_block(&FATBuf,(unsigned long)k);
		for (int z = 0; z < FATEntriesPerBlock; z++)
		{
			printf("FAT entry block%i : read returned %i\n",k-100,ret2);
			printf("FAT entry %i %i:\n %i\n %i\n\n",
			k,z,		
			FATBuf[z].Next,
			FATBuf[z].Used);
		}
	}
*/	
	return 0;
}
