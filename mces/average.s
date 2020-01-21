	AREA RESET, CODE
	ENTRY
	
	LDR R0, =NUMS	; Address of list of numbers
	LDR R1, [R0]	; First number
	MOV R2, #5		; Number of numbers in list
	MOV R3, #0		; Counter
	MOV R4, #0		; Average to be stored
	
; Calculates sum of numbers in list
SUM ADD R5, R5, R1
	ADD R3, R3, #1
	CMP R3, R2
	BLT SUM
	
; Division = Repeated subtraction
DIVIDE SUB R5, R5, R2
	ADD R4, R4, #1
	CMP R5, #0
	BGT DIVIDE
	
STOP B STOP

NUMS DCD &2, &1, &2, &3, &2
	END
