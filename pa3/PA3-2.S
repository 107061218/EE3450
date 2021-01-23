# Computer architecture
# Programming assignment 3
# 107061218 謝霖泳
# This example demonstrates an implementation on data dependencies
# 5 stage pipeline
# processor w/o forwarding and hazard detection enabled

.data
aa: .word 2, 3, 4, 5

.text
.global _start

.text
_start:
# initialize a0, a1 = 2, 3

auipc t0, 0x1
nop
nop
addi t0, t0, 116
nop
nop

lw a0, 0(t0)        # a0 = aa[0] = 2
lw a1, 4(t0)        # a1 = aa[1] = 3
nop
nop

# (1) R-types RAW at following 1st instruction 
sub a4, a1, a0      # a4 = a1 - a0 = 3 - 2 = 1
nop
nop
add a5, a4, a1      # a5 = a4 + a1 = 1 + 3 = 4

# (2) R-types RAW at following 2nd instruction 
add a6, x0, x0      # a6 = x0 + x0 = 0 + 0 = 0
nop
add a0, a5, a1      # a0 = a5 + a1 = 4 + 3 = 7

# (3) Load RAW at following 1st instruction 
lw a7, 0(t0)        # a7 = aa[0] = 2
nop
nop
add a1, a7, a7      # a1 = a7 + a7 = 2 + 2 = 4

# (4) Load RAW at following 2nd instruction 
lw a4, 12(t0)       # a4 = aa[3] = 5
add a0, x0, x0      # a0 = x0 + x0 = 0 + 0 = 0
nop
mul a5, a4, a4      # a5 = a4 * a4 = 5 * 5 = 25

# (5) branch instruction (control hazard)
bne a6, a7, branch  # if a6 != a7 then branch

end:
add a0, x0, x0
add a0, x0, x0

branch:
add a1, a1, a1      # a1 = a1 + a1 = 4 + 4 = 8
