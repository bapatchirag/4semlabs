	AREA RESET, CODE
	ENTRY
	
	LDR R0, =NUMS		; Address of first number (both numbers stored together)
	LDR R1, [R0]		; Stores first number (and gcd)
	LDR R2, [R0, #4]	; Stores second number (and gcd)
	
; Calculates GCD of values in R1 and R2 using Euclid's algorithm
GCD CMP R1, R2
	SUBGT R1, R1, R2
	SUBLT R2, R2, R1
	BEQ STOP
	B GCD
	
STOP B STOP

NUMS DCD &F, &14
	END
