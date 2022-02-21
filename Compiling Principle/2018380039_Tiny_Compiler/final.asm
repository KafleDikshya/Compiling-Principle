.data
ah: .word 0
.text
move $fp $sp
j main
add:
lw $s7 0($sp)
subi $sp $sp 8
sw $s7 0($sp)
addi $sp $sp 12
move $s7 $fp
move $fp $sp
subi $fp $fp 4
sw $s7 0($fp)
sw $ra -4($fp)
subi $sp $sp 16
li $t0 3
lw $t1 -8($fp)
mul $t0 $t0 $t1
sw $t0 -12($fp)
lw $t0 -12($fp)
move $v0 $t0
lw $ra -4($fp)
addi $sp $fp 4
lw $fp 0($fp)
jr $ra
main:
move $s7 $fp
move $fp $sp
subi $fp $fp 4
sw $s7 0($fp)
sw $ra -4($fp)
subi $sp $sp 56
li $t0 0
sw $t0 -48($fp)
lw $t0 -48($fp)
li $t1 0
bge $t0 $t1 LABEL1
sw $zero -52($fp)
j LABEL2
LABEL1:
li $t2 1
sw $t2 -52($fp)
LABEL2:
lw $t0 -52($fp)
beq $t0 $zero LABEL0
lw $t0 -48($fp)
lw $t1 -48($fp)
li $s6 4
mul $s6 $s6 $t1
subi $s7 $fp 44
add $s7 $s7 $s6
sw $t0 0($s7)
LABEL0:
li $v0 10
syscall
li $v0 10
syscall
