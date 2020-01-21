	AREA RESET, CODE
	ENTRY
	
	LDR R0, =NUM	; Address of number
	LDR R1, [R0]	; Number
	MOVS R2, #0		; Number of ones
	
LOOP LSRS R1, #1
	ADC R2, R2, #0
	CMP R1, #0
	BGT LOOP
	
STOP B STOP
NUM DCD &F0123
	END