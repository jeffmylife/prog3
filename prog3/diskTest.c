//
//  diskTest.h
//  prog3
//
//  Created by Michael Cole on 11/3/17.
//  Copyright © 2017 Michael Cole. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "softwaredisk.h"
#include "filesystem.h"
// Justin added to diskTest
// justin created on branch

char poetry[]="Do not go gentle into that good night,"
"Old age should burn and rave at close of day;"
"Rage, rage against the dying of the light."
""
"Though wise men at their end know dark is right,"
"Because their words had forked no lightning they"
"Do not go gentle into that good night."
""
"Good men, the last wave by, crying how bright"
"Their frail deeds might have danced in a green bay,"
"Rage, rage against the dying of the light."
""
"Wild men who caught and sang the sun in flight,"
"And learn, too late, they grieved it on its way,"
"Do not go gentle into that good night."
""
"Grave men, near death, who see with blinding sight"
"Blind eyes could blaze like meteors and be gay,"
"Rage, rage against the dying of the light."
""
"And you, my father, there on the sad height,"
"Curse, bless, me now with your fierce tears, I pray."
"Do not go gentle into that good night."
"Rage, rage against the dying of the light.";

int main() {
    //char buf[SOFTWARE_DISK_BLOCK_SIZE];
    //int i,j, ret;
    //init_software_disk();
    
    unsigned long read, written, length,
    int delete, exists;
    //Full block of data size
    int fblock = 508;
    // File object
    File testfile;
    
    //Full Data buffer 
    char fdbuf[fblock];
    
    // Testing create_file function 
    char file_name[] = "file1.txt"
    testfile = create_file(file_name, READ_WRITE);
    fs_print_error();

    // Testing write_file function
    memset(fdbuf, "Justin the Best!", fblock); 
    written = write_file(testfile, fdbuf, fblock);
    fs_print_error();
    printf("%lu Bytes was written to %s\n", written, file_name);

    // Testing close_file
    close_file(testfile);
    fs_print_error();

    // Testing file_exists
    exists = file_exists(file_name);

    

    for (int i = 0; i < 100; i++){
    	strcpy(Directory[i].Filename,"\0");
    }

    char test[] = "Does this work?";

    strcpy(first[0].Filename,test);

    for (int z = 0; z < 3; z++){
    	printf("%s\n",first[z].Filename);
    }
   /* printf("Size of software disk in blocks: %lu\n", software_disk_size());
    sd_print_error();
    printf("Writing a block of A's to block # 3.\n");
    memset(buf, 'A', SOFTWARE_DISK_BLOCK_SIZE);
    ret=write_sd_block(buf, 3);
    printf("Return value was %d.\n", ret);
    sd_print_error();
    printf("Reading block # 3.\n");
    bzero(buf, SOFTWARE_DISK_BLOCK_SIZE);
    ret=read_sd_block(buf, 3);
    printf("Return value was %d.\n", ret);
    sd_print_error();
    printf("Contents of block # 3:\n");
    for (j=0; j < SOFTWARE_DISK_BLOCK_SIZE; j++) {
        printf("%c", buf[j]);
    }
    printf("\n");
    printf("Reading block # 7.\n");
    bzero(buf, SOFTWARE_DISK_BLOCK_SIZE);
    ret=read_sd_block(buf, 7);
    printf("Return value was %d.\n", ret);
    sd_print_error();
    printf("Contents of block # 7:\n");
    for (j=0; j < SOFTWARE_DISK_BLOCK_SIZE; j++) {
        printf("%c", buf[i]);
    }
    printf("\n");
    printf("Trying to write a block of B's to block # %lu.\n", software_disk_size());
    memset(buf, 'B', SOFTWARE_DISK_BLOCK_SIZE);
    ret=write_sd_block(buf, software_disk_size());
    printf("Return value was %d.\n", ret);
    sd_print_error();
    printf("Writing a block of poetry to blocks #5-7.\n");
    memcpy(buf, poetry, SOFTWARE_DISK_BLOCK_SIZE);
    for (i=5; i <= 7; i++) {
        ret=write_sd_block(buf, (unsigned long)i);
        printf("Return value was %d.\n", ret);
        sd_print_error();
    }
    printf("Reading blocks # 5-7.\n");
    for (i=5; i <= 7; i++) {
        bzero(buf, SOFTWARE_DISK_BLOCK_SIZE);
        ret=read_sd_block(buf, (unsigned long)i);
        printf("Return value was %d.\n", ret);
        sd_print_error();
        printf("Contents of block # %d:\n", i);
        for (j=0; j < SOFTWARE_DISK_BLOCK_SIZE; j++) {
            printf("%c", buf[j]);
        }
        printf("\n");
    }
    */
    return 0;
}
