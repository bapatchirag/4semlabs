	AREA RESET, CODE
	ENTRY
	; Move addresses of numbers to registers
	LDR R0, =NUM1
	LDR R1, =NUM2
	LDR R9, =RES
	
	; Move first words to registers and add
	LDR R2, [R0, #4]
	LDR R3, [R1, #4]
	ADDS R4, R2, R3
	STR R4, [R9, #4]
	
	; Move second words to registers and add
	LDR R2, [R0]
	LDR R3, [R1]
	ADCS R4, R2, R3
	STR R4, [R9]
	
STOP B STOP
			
NUM1 DCD &BBBBBBBB, &AAAAAAAA
NUM2 DCD &CCCCCCCC, &FFFFFFFF
	AREA MEMORY, DATA
RES DCD &0, &0
	END