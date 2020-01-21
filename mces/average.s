	AREA RESET, CODE
	ENTRY
	
	LDR R0, =LIST	; Address of first element in list
	MOV R1, #5	; Number of elements in list
	MOV R2, R1	; Copy of R1
	LDR R3, [R0]	; First element of list
	
; Sums up all numbers in list
LOOP ADD R4, R4, R3	; R4 = Sum of list elements
	LDR R3, [R0, #4]!
	SUB R2, R2, #1
	CMP R2, #0
	BGT LOOP
	B DIVIDE

; Restore quotient and dividend if repeated subtraction result is negative
_RESTORE SUB R5, R5, #1
	ADD R4, R4, R1
	B STOP

; Division = Repeated Subtraction
DIVIDE SUB R4, R4, R1
	ADD R5, R5, #1	; Quotient of R4 / R1
	CMP R4, #0
	BGT DIVIDE
	BLT _RESTORE

; Stops execution of code
STOP B STOP

; Test list of numbers
LIST DCD &2, &1, &2, &3, &2
	END
