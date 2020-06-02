	AREA RESET, CODE
	ENTRY
	
	LDR R0, =LIST						; Load list address
	LDMIA R0, {R1-R9}					; Load list elements in registers
	MOV SP, #0x40000000					; Point to memory location to store list elements at
	STMIA SP, {R1-R9}					; Store list elements at consecutive memory locations
	MOV R10, #0x40000000				; Point to current list location
	LDR R1, LISTSIZE					; Load size of list

; Initialises start of every pass of the algorithm
STARTPASS
	MOV R2, R1							; Inner loop counter initialisation
	MOV R3, R10							; Start address location reset

; Every iteration of loop
STARTITER
	LDR R4, [R3]						; Loads first element (of current iteration)
	LDR R5, [R3, #4]					; Loads next element
	CMP R4, R5							; Compares the two
	BLS WHERENEXT						; If R4 < R5, decides upon next course of action: to continue with current pass or to go to next pass
	
	; Swap if R4 > R5
	MOV R6, R4
	MOV R4, R5
	MOV R5, R6
	
	; Store correctly swapped elements back to the right places in memory
	STR R4, [R3]
	STR R5, [R3, #4]!
	
; Decides to continue to next pass or stay with the current pass
WHERENEXT
	SUBS R2, #1
	BNE STARTITER						; If current pass had less than minimum required comparisons, continue with current iteration
	SUBS R1, #1
	BNE STARTPASS						; If current pass had enough comparisons, move to next pass
	
STOP
	B STOP
	
LIST
	DCD 9, 8, 7, 6, 5, 4, 3, 2, 1
LISTSIZE
	DCD 9

	END