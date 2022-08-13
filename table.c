#define TLB_SIZE 16
#define NUM_PAGES 256
#define NUM_FRAMES 256
#define FRAME_SIZE 256

struct TLB_entry {
	int page; /* virtual mem addr */
	int frame; /* physcial mem addr */ 
};

struct TLB_entry TLB[TLB_SIZE]; /* 16 TLB entries */
int TLB_idx = 0;

int TLB_check(unsigned page) { /* function to check is page is in TLB */ 
	for(int i = 0; i < TLB_SIZE; ++i) {
		if(TLB[i].page == page) {
			return TLB[i].frame; /* if in TLB return frame */ 
		}
	}
	return -1; /* is not in TLB return -1 */ 
}

void set_page(unsigned page, unsigned frame) { /* function to add page to TLB */ 
	TLB[TLB_idx].page = page; /* set page value */
	TLB[TLB_idx].frame = frame; /* set frame value */
	TLB_idx = (TLB_idx + 1) % TLB_SIZE; /* increment */ 
}

int page_table[NUM_PAGES]; /* 2^8 table entires */

signed char mem[NUM_FRAMES*FRAME_SIZE]; /* signed byte value stored at translated physical address */

int next_frame = 0;

