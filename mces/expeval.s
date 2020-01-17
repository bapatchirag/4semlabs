	AREA RESET, CODE
	ENTRY
	
	; Coeffients below
	MOV R0, #3
	MOV R1, #4
	MOV R2, #9
	
	; Values to substitute below
	MOV R3, #2
	MOV R4, #3
	MOV R5, #4
	
	; Calculations below
	MLA R6, R0, R3, R6
	MLA R6, R1, R4, R6
	MLA R6, R2, R5, R6
	
STOP B STOP
	END