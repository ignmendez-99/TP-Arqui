global loader
extern main
extern initializeKernelBinary

loader:
	call initializeKernelBinary	; Set up the kernel binary, and get thet stack address
	mov rsp, rax				; Set up the stack with the returned address
	call main
	; DEJO AL PROCESADOR EN UN ESTADO DE PAUSA HASTA QUE RECIBA UNA INSTRUCCION
hang:
	cli
	hlt	; halt machine should kernel return
	jmp hang
