	AREA RESET, CODE
	ENTRY
	
	LDR R0, NUM		; Number for which factorial is to be calculated
	MOV R1, #1		; Factorial to be stored here
	
; Sub-routine FACT called iteratively until R0 becomes 0
LOOP BL FACT
	CMP R0, #0
	BGT LOOP

; Stops execution of program
STOP B STOP

; Sub-routine call which multiplies R0 and value at R1
FACT MUL R1, R0, R1
	SUB R0, R0, #1
	BX LR

NUM DCD &A
	END
