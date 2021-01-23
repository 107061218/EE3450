# Exercise Chapter 5 (Due Jan. 6, 2021)

Please submit your answers with a pdf file to [the Exercise Ch5 google form](https://forms.gle/J9UqhGe9zT4s2RKg8).
Note that no delay will be allowed for this exercise. We will review these question in class after the due day.

## 1. Reading

Textbook: **CODV** Computer Organization and Design, RISC-V Ed. 

1. Chapter 5 of CODV: 5.3, 5.4, 5.7

## 2. Problems 

Credits are weightings of each problem in this exercise.
You can type your answers and submit the pdf, or hand write and scan it.
Please use Apps (e.g. Office Lens) to shoot a quality document.
If there is any issue of the submitted image quality, TA will reject the submission and no credit will be given.
   
1. (65 points) [section 5.3] 
   For a direct-mapped cache design with a 64-bit memory address, 
   the following bit fields of the address are used to access the cache.

   |Tag            |Index          | Offset        |
   |:-------------:|:-------------:|:-------------:|
   |63-22          |21-12          | 11-0          |

   1. ( 5 points) What is the cache block size (in KB)?
   2. ( 5 points) How many blocks does the cache have?
   3. ( 5 points) What is the total cache size (in KB)? 
   4. (10 points) What is the actual SRAM memory size used to implement the cache?
   5. (15 points) Please mark the following memory access references as "hit" or "miss" in the above cache?
      ```
      0x1fffff48
      0x1fffff50
      0x1fffff58
      0x10034dc4
      0x0ffe744c
      0x2fffff80
      0x1fffff6c
      0x10034db4
      0x10034da4
      0x10034dac
      0x10033ee4
      0x2fffff30
      0x2fffff9d
      0x1fffff40
      0x1fffff68
      ```
   Now we would like to change the cache into a 2-way set associative design with the same total size.

   6. (10 points) What is the SRAM memory size used to implement the new cache?
   7. (15 points) Please mark the following memory access references as "hit" or "miss" in the new cache?
      The access sequence is the same as above problem 5.
      ```
      0x1fffff48
      0x1fffff50
      0x1fffff58
      0x10034dc4
      0x0ffe744c
      0x2fffff80
      0x1fffff6c
      0x10034db4
      0x10034da4
      0x10034dac
      0x10033ee4
      0x2fffff30
      0x2fffff9d
      0x1fffff40
      0x1fffff68
      ```

2. (20 points) [section 5.3] 
   Consider the following statistics for a program and its cache behaviors (with write-through and write-allocate policies):
   The base CPI is 2.
   
   |# data reads per 1K instructions |# data writes per 1K instructions |instruction cache miss rate  |data cache miss rate  |Block size (bytes)  | 
   |:-------------------------------:|:--------------------------------:|:---------------------------:|:--------------------:|:------------------:|
   | 250                             | 100                              | 0.3%                        | 2%                   | 64                 | 

   1. (10 points) What is the read bandwidth requirement (measured by bytes per cycle)
      between RAM and the cache? Assume each miss generates a request for one block.  
      *Hint: Read bandwidth include: (1) Miss in I-cache (2) Read miss in D-cache
      (3) Write miss in D-cache (Write-allocate will make a read request to
      RAM when write miss).*
      
   2. (10 points) What is the write bandwidth?  
      *Hint: Write bandwidth includes all writes. Note that write-through policy only write a word (4 bytes).*

3. (25 points) [section 5.4] 
   Consider the following processor with a few possible cache hierarchy choice (L2 designs):
   The base CPI without memory stalls is 1.5. The main memory access delay is 200 cycles.
   
   | Level                                   |access cycle and miss rate                |                  |
   |:---------------------------------------:|:----------------------------------------:|:----------------:|
   | L1                                      |L1 miss rate                              | 7%               |
   | L2 (option 1: direct mapped)            |L2 access cycle                           | 12               |
   | L2 (option 1: direct mapped)            |L2 miss rate                              | 3.5%             |
   | L2 (option 2: 8-way set associative)    |L2 access cycle                           | 28               |
   | L2 (option 2: 8-way set associative)    |L2 miss rate                              | 1.5%             |
   | L3                                      |L3 access cycle                           | 50               |
   | L3                                      |L3 miss rate                              | 1.3%             |

   1. ( 5 points) Calculate the CPI for the processor in the table using only a 1-level cache.
   2. ( 5 points) Calculate the CPI for the processor in the table using a 2-level (L1, L2 direct-mapped) cache.
   3. ( 5 points) Calculate the CPI for the processor in the table using a 2-level (L1, L2 8-way set associative) cache.
   4. ( 5 points) Calculate the CPI for the processor in the table using a 3-level (L1, L2 DM, L3) cache.
   5. ( 5 points) Calculate the CPI for the processor in the table using a 3-level (L1, L2 8-way, L3) cache.

4. (15 points) [section 5.4] 
   Consider the following address (word address) request sequence: 0, 1, 2, 3, 4, 5, 6, 7, 4, 5, 6, 7, 8, 9, 10, 11, 16, 17.
   Please mark each request as hit or miss for a 2-way set associative cache with 4 sets and each block has 2 words (replacement policy is LRU).
   Please also show the final state of the cache after the last memory request.

5. (15 points) [section 5.7] 
   Consider the following page table parameters:

   |Virtual address size     | Page size        | Page table entry size  |
   |:-----------------------:|:----------------:|:----------------------:|
   |32 bits                  | 8K bytes         | 4 bytes                |

   1. ( 5 points) Please calculate the maximum page table size for a system running 5 processes (in MB).
   2. (10 points) Assume we use the 2-level page table as specified by the following table.
      For a system running five applications that each utilize 100M Bytes of the virtual memory,
      please calculate the page table size for a system running 5 processes (in KB).
      Please assume that we have one P1 (first level) table and it also consume 4 bytes for each entry.
      Please also assume that each P2 is fully occupied such that we use only the minimal P2 tables
      for translating 100M bytes of memory space.

      |P1                       | P2               | Offset           |
      |:-----------------------:|:----------------:|:----------------:|
      | 8 bits                  | 11 bits          | 13 bits          |

