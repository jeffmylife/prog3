#include "filesystem.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "softwaredisk.h"

int main(){
	for (int i = 0; i < 100; i++)
	{
		strcpy(Directory[i].Filename,"dude");
		Directory[i].StartBlock = -1;
		Directory[i].EndBlock = -1;
		Directory[i].Size = -1;
		Directory[i].Used = -1;
	}
	for (int j = 0; j < 5000; j++)
	{
		FAT[j].Next = -1;
		FAT[j].Used = -1;
	}
	init_software_disk();
	return 0;
}
