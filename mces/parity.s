	AREA RESET, CODE
	ENTRY
	
	LDR R0, NUM	; Number
	MOVS R1, #0	; Number of ones
	
; Right shifts number by one bit, and adds it to R1, computing answer
LOOP LSRS R0, #1
	ADC R1, R1, #0
	CMP R0, #0
	BGT LOOP
	
STOP B STOP
NUM DCD &F0123
	END
