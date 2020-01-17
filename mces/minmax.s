	AREA RESET, CODE
	ENTRY
	
	LDR R0, =LIST	; Address of first element
	LDR R1, [R0]	; First (temporary) element
	MOV R9, #5		; Number of elements
	MOV R8, #0		; Counter to R9
	MOV R7, #0		; Result stored in R7
	MOV R6, #4		; Size of each element


; Moves element from R1 to R7 if it is a valid move
NEWMOVE CMP R8, #5
	MOVNE R7, R1
	BNE CONTINUE
	BEQ STOP
	
; Actual loop through list
LOOP MUL R5, R8, R6	; R5 is the index to jump to in list
	LDR R1, [R0, R5]
	CMP R1, R7
	BGT NEWMOVE
	
; Continue loop if required, from appropriate position
CONTINUE ADD R8, R8, #1
	CMP R8, R9
	BLT LOOP
	
STOP B STOP

; List of elements
LIST DCD &10, &20, &34, &A5, &69
	END