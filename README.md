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

* https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
* https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
* https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
* https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
* https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
* https://www.clivemaxfield.com/coolbeans/masking-and-the-c-c-bitwise-operators/
	
## Known Errors

* na

## Build Instructions

* <code> gcc vmmgr.c -o vmmgr </code>
	
## Execution Instructions

* <code> ./vmmgr {textfile.txt} </code>
