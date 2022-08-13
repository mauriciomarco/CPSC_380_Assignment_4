#define PAGE_OFFSET 8
#define MASK 255

unsigned get_page(unsigned address) { /* function to get page from logical address */ 
	return (address >> PAGE_OFFSET)&MASK; /* shift address by 8 bits and mask the last 8 bits */ 
}

unsigned get_offset(unsigned address) { /* function to get offset from logical address */ 
	return address&MASK; /* mask the last 8 bits
}