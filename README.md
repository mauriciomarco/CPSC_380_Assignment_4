# CPSC_380_Assignment_4
The objective of this assignment consists of writing a C/C++ program that translates logical to  physical addresses for a virtual address space of size 216 = 65,536 bytes. Your program will read  from a file containing logical addresses and, using a TLB as well as a page table, will translate  each logical address to its corresponding physical address and output the value of the byte stored  at the translated physical address. The goal behind this project is to simulate the steps involved in  translating logical to physical addresses.

## Idendifying Information

* Name: Marco Mauricio
* StudentID: 2344979
* Email: mauricio@chapman.edu
* Course: CPSC 380
* Assignment: 4

## Source Files

* vmmgr.c
* address_translator.c
* table.c
	
## References

* https://www.geeksforgeeks.org/posix-shared-memory-api/
* https://linux.die.net/man/2/ftruncate
* https://man7.org/linux/man-pages/man2/mmap.2.html
* https://docs.oracle.com/cd/E19683-01/806-6867/6jfpgdcnj/index.html
* https://linux.die.net/man/3/pthread_mutex_init
* https://pubs.opengroup.org/onlinepubs/007908799/xsh/pthread_mutex_lock.html
	
## Known Errors

* na

## Build Instructions

* <code> gcc vmmgr.c -o vmmgr </code>
	
## Execution Instructions

* <code> ./vmmgr {textfile.txt} </code>