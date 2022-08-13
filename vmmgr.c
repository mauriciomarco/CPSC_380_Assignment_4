#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "address_translator.c"
#include "table.c"

#define BUFFER_SIZE 8

int main(int argc, char* argv[]) {
	
	int page_faults = 0;
	int TLB_hits = 0;
	int addresses_read = 0; 
	char addresses_arr[1000];
	
	if(argc != 2) { /* check command line arguments */ 
		printf("Error: incorrect number of arguments... {FORMAT: ./vmmgr <textfile.txt>}\n");
		exit(1);
	}
	
	FILE *backing_store = fopen("BACKING_STORE.bin", "r"); /* open BACKING_STORE file stream */
	if(backing_store == NULL) {
		perror("Error: file not found... BACKING_STORE.bin\n");
		exit(1);
	}
	
	FILE *addresses = fopen(argv[1], "r"); /* open address file stream */
	if(addresses == NULL) {
		perror("Error: file not found\n");
		exit(1);
	}
	
	FILE *o_file = fopen("output_report.txt", "w"); /* open output file stream */
	if(o_file == NULL) {
		perror("Error: output file could not be opened\n");
		exit(1);
	}
	
	for(int i = 0; i < NUM_PAGES; i++) { /* initialize page table */ 
		page_table[i] = -1;
	}
	
	char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, addresses)) { /* read until EOF */
		++addresses_read;
		
		unsigned logical = atoi(buffer); /* get logical address */ 
		unsigned page = get_page(logical); /* get page data from logical address */ 
		unsigned offset = get_offset(logical); /* get page offset from logical address */ 
		
		unsigned frame = TLB_check(page); /* check to see if page fault occurs */ 
		if(frame == -1) {
			frame = page_table[page]; /* adds from page table and adds to TLB */ 
			
			if(frame == -1) { /* page fault */ 
				++page_faults;
				frame = next_frame;
				++next_frame;
				
				signed char *page_table_ptr = &mem[frame*FRAME_SIZE]; /* copy data to physcial memory */
				fseek(backing_store, (page*FRAME_SIZE), SEEK_SET);
				fread(page_table_ptr, sizeof(char), FRAME_SIZE, backing_store);
				page_table[page] = frame;
			}
			set_page(page, frame); /* add page and frame to TLB */
		}
		else { /* TLB hit */ 
			++TLB_hits;
		}
		
		/* console output */
		printf("[Logical Address: %d] [Physical Address: %d] [Signed Byte: %c]\n", logical, (frame*FRAME_SIZE + offset), mem[frame*FRAME_SIZE + offset]);
		printf("-----------------------------------------------------------------------\n");
		
		/* file output */
		fprintf(o_file,"[Logical Address: %d] [Physical Address: %d] [Signed Byte: %c]\n", logical, (frame*FRAME_SIZE + offset), mem[frame*FRAME_SIZE + offset]);
		fprintf(o_file,"-----------------------------------------------------------------------\n");
	}
	
	/* statistics output */
	printf("|**********[Statistics Report]**********|\n");
	printf("[Page-fault Rate: %f%]\n", (100 * page_faults/(float)addresses_read));
	printf("[TLB Hit Rate: %f%]\n", (100 * TLB_hits/(float)addresses_read));
	
	/* file statistics output */ 
	fprintf(o_file, "|**********[Statistics Report]**********|\n");
	fprintf(o_file, "[Page-fault Rate: %f%]\n", (page_faults/(float)addresses_read * 100));
	fprintf(o_file, "[TLB Hit Rate: %f%]\n", (TLB_hits/(float)addresses_read * 100));
	
	
	
}