.ORIG x8000

;;TRAP xff
LD R1, VALUE5
TRAP x26
;;ADD R1, R1, #2
TRAP x25
VALUE5 .FILL #5
.END