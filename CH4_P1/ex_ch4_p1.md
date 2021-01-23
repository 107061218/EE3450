# Exercise Chapter 4 Part 1 (Due Dec. 3, 2020)

Please submit your answers with a pdf file to [the Exercise Ch4 P1 google form](https://forms.gle/92iDhHYxcc2R5vGTA).
Note that no delay will be allowed for this exercise. We will review these question in class after the due day.

## 1. Reading

Textbook: **CODV** Computer Organization and Design, RISC-V Ed. 

1. Chapter 4 of CODV: 4.3 ~ 4.7

## 2. Problems 

Credits are weightings of each problem in this exercise.
You can type your answers and submit the pdf, or hand write and scan it.
Please use Apps (e.g. Office Lens) to shoot a quality document.
If there is any issue of the submitted image quality, TA will reject the submission and no credit will be given.

1. (20 points) [section 4.4] 
   For the single-cycle processor model (page 33 of `Chapter_04_1_single_cycle.pdf`), the CPU execute 0x00c6ba23
   fetched at 0x4000ffd0 address. Please answer the following questions:  

   1. (5 points) What is the ALU function with the decoded instruction?  
   2. (5 points) What is the new PC after this instruction is executed?  
   3. (5 points) Please specify the control signals when executing this instruction.
      The list of control signals are RegWrite, ALUSrc, Branch, MemWrite, MemRead, MemtoReg.
   4. (5 points) What are the ALU inputs? Specify the value of a register by `Reg[x10]` if x10 is used.  
   
2. (40 points) [section 4.4] 
   The following table lists the latency of each block in the single-cycle processor model:

   |I-Mem/D-Mem    | Register File | PC            | Mux           | ALU           | Adder         | Single gate   | Sign extension| Control unit  |
   |:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |250ps          | 170ps         | 70ps          | 25ps          | 200ps         | 150ps         | 5ps           | 50ps          | 50ps          |

   When calculating the latency for the following instruction types, please consider ALL necessary stages including PC and write-back, etc.

   1. (5  points) What is the latency of an R-type instruction? (i.e., the clock period to execute R-type correctly).
   2. (10 points) What is the latency of `ld` instruction? 
   3. (10 points) What is the latency of `sd` instruction? 
   4. (5  points) What is the latency of `beq` instruction? 
   5. (5  points) What is the latency of an I-type instruction? 
   6. (5  points) What is the clock period of the processor considering all above instruction types? 

3. (20 points) [section 4.4] 
   The following table lists the latency of each block in the single-cycle processor model (same as previous problem):

   |I-Mem/D-Mem    | Register File | PC            |  Mux           | ALU           | Adder         | Single gate   | Sign extension| Control unit  |
   |:-------------:|:-------------:|:-------------:| :-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |250ps          | 170ps         | 70ps          |  25ps          | 200ps         | 150ps         | 5ps           | 50ps          | 50ps          |

   The following table lists the cost (area) of each block in the single-cycle processor model:

   |I-Mem          |D-Mem          | Register File | PC or register|  Mux           | ALU           | Adder         | Single gate   | Sign extension| Control unit  |
   |:-------------:|:-------------:|:-------------:|:-------------:| :-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |1000           |2000           | 200           | 5             |  10            | 100           | 30            | 1             | 100           | 500           |

   And we have benchmark programs with the following mix of instruction types (in percentage):

   |R-type I-type  |ld             | sd            | branch        |
   |:-------------:|:-------------:|:-------------:|:-------------:|
   |52%            |25%            | 11%           | 12%           |

   Assume we have a new architecture. In the new processor, we double registers from 32 to 64. As a result, the number of ld and st is reduced by 12 percent at the cost of register file latency increased to 180ps and cost (area) increased to 400.
   
      1. (10 points) What is the speedup of the new processor with the above benchmark programs? When calculating the performance, please consider both number of instructions and the clock periods (Hint: related to CPU time definition).
      2. (10 points) What is the cost of the new processor as compared with the original one?
   
4. (50 points) [section 4.4 and 4.5] For the following problems, you may use data path files in pptx to draw the new ones in the Teams channel.
   1. (20 points) Please draw a new data path in the single-cycle processor to support a new swap instruction: swap rs1, rs2. 
      The function of the instruction can be represented as follows: Reg[rs2]=Reg[rs1] and Reg[rs1]=Reg[rs2].  
      Can we use the original register file to support single cycle operation (finish all works in one cycle)?  
      If not, how do we modify the register file to support single cycle operation?

   2. (30 points) Please modify and draw a new pipeline data path for this instruction.
      Here we only use the original register file (2 read ports and 1 write ports). That means we will need two cycles to write two registers. 
      Please also draw a pipeline diagram as in the original 5 stages (with IF, ID, EX, MEM, WB) for this new instruction. 
      Please add extra stages if necessary. For example, we need extra stage at EX: EX1 and EX2 will denote the stages. 
      

5. (25 points) [section 4.5] 
   We will examine the clock cycle time in a pipelined design with stage latency listed in the following table:

   |IF             |ID             | EX            | MEM           | WB            |
   |:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |250ps          |350ps          | 150ps         | 300ps         | 200ps         |

   Also assume the percentage of instructions in the benchmark as follows:

   |R-type I-type  |ld             | sd            | branch        |
   |:-------------:|:-------------:|:-------------:|:-------------:|
   |45%            |20%            | 15%           | 20%           |

   1. (5  points) What is the clock cycle time of the pipelined processor?
   2. (10 points) Assume we split one of the original stages into two stages. What stage should be split? And what is the new cycle time?
   3. (10 points) Assume there is no stall or hazard, what is the utilization of the data memory? Utilization is defined as the percentage of cycles when a data memory is actually used.

6. (10 points) [section 4.5] 
   Please add `nop` instruction to the following codes such that the results will be correct for a pipeline processor without forwarding support:

   ```
   addi x11, x12, 5 
   add x13, x11, x12
   addi x14, x11, 15
   add x15, x13, x12
   ```

7. (20 points) [section 4.5] 
   1. (10 points) Assume that a pipelined processor without forwarding can run at 250ps, but with an additional 10% of instructions (nops).
      The processor with forwarding will run at 300ps. Please compare the performance of the two designs.
   2. (10 points) For the two pipelined processors in the above problem, at what percentage of nop instructions do we have a faster processor with forwarding?

8. (10 points) [section 4.5] 
   Assume we have only one memory for both instruction and data. Please draw the pipeline diagram (5-stage processor and stages are IF, ID, EX, MEM, WB) for the following codes.
   Please specify the stall cycle by `**`. Note that for this processor with structural hazard, IF will have to stall for MEM if the instruction actually access the memory for data.

   ```
   sd  x29, 12(x16)  
   ld  x29, 8(x16)
   sub x17, x15, x14
   bez x17, label
   add x15, x11, x14
   sub x15,x30,x14
   ```

9. (20 points) [section 4.7] 
   1. (10 points) Please draw the pipeline diagram (5-stage processor) for the following codes for the first two iterations.
      The processor has a perfect branch prediction (meaning you can simply expand the loop twice) and full forwarding support.
      Please specify the stall cycle by `**`. Also mark the stage without useful work with `!`.

      ```
      ld x10, 0(x13)
      ld x11, 8(x13)
      add x12, x10, x11
      addi x13, x13, -16
      bnez x12, LOOP
      ```
   2. (10 points) Please calculate how many cycles in the diagram that all stages are doing useful work.

10. (50 points) [section 4.7] 
    For all the following 5 code segments, please fix the data dependency with `nop` for the following 4 different processors:   
    (1) Add `nop` so that for processors without forwarding , the execution results are correct. 
    (2) Add `nop` so that for processors with forwarding from EX/MEM only, the execution results are correct.  
    (3) Add `nop` so that for processors with forwarding from MEM/WB only, the execution results are correct.   
    (4) Add `nop` so that for processors with full forwarding (both EX/MEM and MEM/WB), the execution results are correct.   

    1. (10 points) Case with dependency from ALU to the following 1st instruction.

       ```
       add x11, x12, x13 
       add x14, x11, x15
       add x5, x6, x7
       ```

    2. (10 points) Case with dependency from data memory to the following 1st instruction.

       ```
       ld x11, 0(x12)
       add x15, x11, x13       
       add x5, x6, x7
       ```

    3. (10 points) Case with dependency from ALU to the following 2nd instruction.

       ```
       add x11, x12, x13 
       add x5, x6, x7 
       add x14, x11, x12
       ```

    4. (10 points) Case with dependency from data memory to the following 2nd instruction.

       ```
       ld x11, 0(x12)
       add x5, x6, x7
       add x14, x11, x13
       ```

    5. (10 points) Case with dependency from ALU to the following 1st and 2nd instructions.

       ```
       add x11, x12, x13
       add x5, x11, x15
       add x16, x11, x12
       ```

11. (20 points) [section 4.7] 
    For the following code segment, please list variables to check and generate the ForwardA and ForwardB selection conditions.
    For example, x15 is written by 1st add instruction and read by 2nd ld instruction. When "add" is at MEM stage, we know that RegWrite==1,
    and EX/MEM.rd == ID/EX.RS1 == x15, such that ForwardA=2 (forwarding from EX/MEM.ALU_Result to 1st input of ALU).

    ```
    add x15, x12, x11 
    ld x13, 4(x15) 
    ld x12, 0(x2)
    or x13, x15, x13 
    sd x13, 0(x15)
    ```
