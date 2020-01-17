	AREA RESET, CODE
	ENTRY
	
	LDR R0, =LIST	; Address of first element of list
	LDR R1, [R0]	; First/Current element of list
	MOV R2, #0x69	; Search element
	MOV R3, #8		; Length of LIST 
	MOV R4, #0		; Number of current occurences
	
LOOP CMP R2, R1
	ADDEQ R4, R4, #1
	LDR R1, [R0, #4]!
	SUB R3, R3, #1
	CMP R3, #0
	BGT LOOP
	
STOP B STOP

LIST DCD &69, &69, &54, &BDC, &A91, &420, &29, &69
	END