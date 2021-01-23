# Programming Assignment #4 Cache Simulation (Due Jan. 7, 2020)

In this assignment, we will use a RISC-V pipeline simulator (Ripes) to observe the working of the cache.

## 1. Write a C Code

1. Please follow `kernelcomp.c` to write your own kernel function `void kernelcomp()`.  
   For the implementation in  `kernelcomp.c`, please refer to page 1 of `PA4_data_pattern.pptx`.

   Please also use the following rules:  

   (1) The kernel matrix is of size 2X2.  
   (2) Kernel matrix operates on a 3X3 sub-matrix of the input matrix.   
   (3) The size of input matrix A should be at least 128 words. 
       Note that once the dimension of A is determined, the dimension of output matrix B is also determined.
       For example, if A is 8X16, B will be (8-2)X(16-2)=6X14.
   (4) In `kernelcomp.c`, we use the scan pattern A described on page 2 of `PA4_data_pattern.pptx`.
       Please keep this data flow or use scan pattern B as your base version.

   All dimensions of matrices are fixed in the program.

2. Please run your program with Ripes to make sure it's correct.
   Another `kernelcomp_gcc.c` is also provided for you to design and debug under regular C environment.
   It's not required to write and submit your kernel design in this C file.

## 2. Setup and Simulate Cache

1. Please cross-compile your above C codes (command line options are the same as in PA3), and load it in Ripes.
   Note that there will be a warning message `warning: cannot find entry symbol _start; defaulting to 0000000000010054`.
   You can ignore this warning, since the compiler tells us that it try to guess the entry function address, which is usually correct.
2. In the left panel, click "Memory" tab.
3. Design the cache with 4 indexes (2^2), 4 ways (2^2) and each block has 4 words (2^2). 
   So the total cache size is 4X4X4=64 words.
   Please leave other default options.
4. Please run simulation to show the following conditions with the captured cache status.
   For each case, please show the ld/st instruction and the parts of memory address as tag, index and offset, 
   cache status before and after the ld/st instruction, etc.

   (1) One case of cache insertion at an index with at least one way already occupied. Please also show how LRU bits change.
   (2) One case of replacement (a new block is requested at an index of which all four ways are occupied by other blocks).   
   (3) One case of write back (a block is replaced and has been written; D=1).   

   Please show above cases only inside the kernel function. 
   You can use the "Editor" panel in Ripes to find the function and setup a breakpoint by clicking the left scroll bar.

## 4. Code with a Block-based flow

1. Please write another C codes to compute kernel with a scan pattern C (page 4 of `PA4_data_pattern.pptx`).
   Please design your own scan block size. Try to choose a block size to simplify your codes as possible.

2. Please compare the cache hit rates of your new data flow implementation with the base version.

## 6. Submit your report

Please submit your codes and report files in pdf to the [following google form](https://forms.gle/3mHDY99WxpfEJPig8).
