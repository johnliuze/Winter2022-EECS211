.ORIG x3000

;; START PROGRAM (1)
;TRAP xff

LD R3, MPU_MAIN
;TRAP xff
STI R3, MR_MPU
LD R2, READY
;TRAP xff
STI R2, STATUS_PROCESS1
STI R2, STATUS_PROCESS2
STI R2, STATUS_PROCESS3
STI R2, STATUS_PROCESS4
STI R2, STATUS_PROCESS5
;TRAP xff
TRAP x0025

READY .FILL #1
STATUS_PROCESS1 .FILL x0200
STATUS_PROCESS2 .FILL x0201
STATUS_PROCESS3 .FILL x0202
STATUS_PROCESS4 .FILL x0203
STATUS_PROCESS5 .FILL x0204
MR_MPU .FILL xfe06
MPU_MAIN .FILL #1
.END