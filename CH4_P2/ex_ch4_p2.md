# Exercise Chapter 4 Part 2 (Due Dec. 20, 2020)

Please submit your answers with a pdf file to [the Exercise Ch4 P2 google form](https://forms.gle/qVbG63UaLSPRB8QK8).
Note that no delay will be allowed for this exercise. We will review these question in class after the due day.

## 1. Reading

Textbook: **CODV** Computer Organization and Design, RISC-V Ed. 

1. Chapter 4 of CODV: 4.8 ~ 4.10

## 2. Problems 

Credits are weightings of each problem in this exercise.
You can type your answers and submit the pdf, or hand write and scan it.
Please use Apps (e.g. Office Lens) to shoot a quality document.
If there is any issue of the submitted image quality, TA will reject the submission and no credit will be given.
   
1. (20 points) [section 4.8] 
   Assume that we have two branch predictors. One is Always-Not-Taken with an accuracy of 55%.
   And the other 2-bit predictor has an accuracy of 85%.

   And we have benchmark programs with the following mix of instruction types (in percentage):

   |R-type I-type  |ld             | sd            | beqz/bnez     | jal/jalr      |
   |:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |40%            |25%            |  5%           | 25%           |  5%           |

   Assume branch is calculated at ID stage.

   1. (10 points) Please calculate the extra CPI for Always-Not-Taken predictor as compared with a perfect predictor.
   2. (10 points) Please calculate the extra CPI for 2-bit predictor as compared with a perfect predictor. 

2. (80 points) [section 4.10] 
   We would like to run the following codes on a two-issue machine as shown in C (and directly translated as RISC-V assembly codes):

   ```
   for(i=0; i!=j; i+=2){
      b[i]=a[i]-a[i+1]
   }
   ```
   ```
        li x12, 0
        jal ENT
   TOP: slli x5, x12, 3
        add x6, x10, x5
        ld x7, 0(x6)
        ld x29, 8(x6)
        sub x30, x7, x29
        add x31, x11, x5
        sd x30, 0(x31)
        addi x12, x12, 2
   ENT: bne x12, x13, TOP
   ```

   |i              |j              | a             | b             | Temporary     |
   |:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
   |x12            |x13            | x10           | x11           | x5-x7, x29-x31|

   The two-issue, statically scheduled processor has the following properties:

   (1) One instruction must be a memory operation; the other must be an arithmetic/logic instruction or a branch.  
   (2) The processor has all possible forwarding paths between stages (including paths to the ID stage for branch resolution).    
   (3) The processor has a perfect branch predictor.  
   (4) Two instructions may not issue together in a packet if one depends on the other.  
   (5) If a stall is necessary, both instructions in the issue packet must stall.  

   1. (20 points) Please draw a pipeline diagram showing how RISC-V codes above executes on the two-issue processor.
      Illustrate only one iteration of the loop. An excel file `problem_ch4_p2_2.xlsx` is uploaded in the Teams Homework channel for your usage.
      Use '*' to show stalls and no issue.

   2. (30 points) Please rearrange the codes to minimize the cycle count for one iteration.
      Please draw a pipeline diagram showing how the new RISC-V codes above executes on the two-issue processor.

   3. (30 points) Please unroll the loop for two iterations and rearrange the codes to minimize the cycle counts.
      Please draw a pipeline diagram showing how the new RISC-V codes above executes on the two-issue processor.
