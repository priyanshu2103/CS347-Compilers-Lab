.data
endline: .asciiz "\n"
.text
main:
subu $sp, $sp, 104
sw $ra, 100($sp)
sw $fp, 96($sp)
move $fp, $sp
li $t0, 5
sw $t0, 8($sp)
li $t0, 3
sw $t0, 4($sp)
li $t0, 2
sw $t0, 0($sp)
li $t0, 3
sw $t0, 4($sp)
lw $t0, 8($sp)
li $t1, 4
seq $t2, $t0, $t1
beq $t2, 0, L18
li $t1, 0
sw $t1, 4($sp)
beq $t1, 0, L18
li $t0, 1
j L20
L18:
li $t0, 0
L20:
j L24
L22:
li $t0, 1
L24:
beq $t0, 0, L28
li $t0, 2
sw $t0, 8($sp)
L28:
lw $t0, 8($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
lw $t0, 4($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
li $t0, 0
move $v0, $t0
j end_main
end_main:
move $sp, $fp
lw $ra, 100($sp)
lw $fp, 96($sp)
addu $sp, $sp, 104
j $ra
