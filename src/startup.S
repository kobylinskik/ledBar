.syntax unified
.thumb

.global vectorTable
.global resetHandler

.type vectorTable, %object
vector_table:
  .word _estack
  .word resetHandler

.type resetHandler, %function
resetHandler:
  LDR  r0,=_estack
  MOV  sp,r0
  B main
