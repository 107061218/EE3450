.section .data
# There are two global variables:
#  1. list: Store the input numbers.
#  2. size: the number of the list
# You can modify the following two lines to test your program,
# but DO NOT change the line number
array: .dword 15, 20, 6, 35, 70, 7, 14, 36, 1, 21, 13, 3, 24, 5, 22, 2, 4, 10, 8, 12
size: .dword 20

.section .text
.global main
main:

  # save return pointer
  addi sp, sp, -8
  sd ra, 0(sp)

  la a0, array      # assign array address to a0
  ld s0, size       # assign array size to s0

  li s1, 0          # low
  addi s2, s0, -1   # high

  #jump to function
  jal quickSort

  li a0, 0          # assign 0 to a0

  ld ra, 0(sp)
  addi sp, sp, 8

  ret               # return (jump to the addr stored in register ra)

partition:
  # a0 = &array
  # s1 = low
  # s2 = high
  # s5 = pivot
  # s6 = i
  # s7 = j
  # s10 = arr[j]
  # t3, t4, t5, t6 are the temp reg

  slli s3, s2, 3    # s3 = s2 * 8
  add s4, s3, a0    # s4 = &arr[high]
  ld s5, 0(s4)      # s5 = arr[high]

  addi s6, s1, 0    # initialize i = low
  addi s7, s1, 0    # initialize j = low
  # beq zero, zero, exit_for
  for_loop:
    bge s7, s2, exit_for # if s7 >= s2 then exit_for  
    
    # get the value of arr[i]
    slli s11, s6, 3   # s11 = s6 * 8
    add s11, a0, s11  # s11 = &arr[i]
    ld a1, 0(s11)     # a1 = arr[i]

    if_statement:      
      # get the value of arr[j]
      slli s8, s7, 3  # s8 = s7 * 8
      add s9, s8, a0 # s9 = &arr[j]
      ld s10, 0(s9)   # s10 = arr[j]

      bge s10, s5, exit_if # if s10 >= s5 then exit_if
         
      # swap(&arr[i], arr[j])
      addi t3, a1, 0    # t3 = a1 = arr[i]
      addi a1, s10, 0   # a1 = s10
      addi s10, t3, 0   # s10 = t3
      sd a1, 0(s11)
      sd s10, 0(s9)

      # increment i
      addi s6, s6, 1
      
    exit_if:

    # increment j
    addi s7, s7, 1
    beq x0, x0, for_loop

  exit_for:



  slli t4, s6, 3
  add t4, t4, a0
  ld t5, 0(t4)    # t5 = arr[i]
  slli t6, s2, 3
  add t6, t6, a0
  ld a3, 0(t6)    # a3 = arr[high]
  # swap(arr[i], arr[high])
  addi a4, t5, 0
  addi t5, a3, 0
  addi a3, a4, 0
  sd t5, 0(t4)
  sd a3, 0(t6)

  ret


quickSort:
  bge s1, s2, exit_if_2
    addi sp, sp, -24
    sd s1, 16(sp) #save low
    sd s2, 8(sp)  #save high
    sd ra, 0(sp)

    jal partition
    addi a2, s6, 0  # a2 = pivot

    addi a5, a2, -1 # a5 = pivot - 1
    addi s2, a5, 0  # high = pivot - 1
    jal quickSort

    addi a6, a2, 1  # a6 = pivot + 1
    addi s1, a6, 0  # low = pivot + 1
    ld s2, 8(sp)
    jal quickSort

    ld s1, 16(sp) #save low
    ld s2, 8(sp)  #save high
    ld ra, 0(sp)
    addi sp, sp, 24

  exit_if_2:
  ret

