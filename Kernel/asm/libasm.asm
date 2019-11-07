GLOBAL cpuVendor
GLOBAL segundos
GLOBAL minutos
GLOBAL horas
GLOBAL getKey

section .data
	amount db 0

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid

	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

obtenerCantidad:
	push rbp
	mov rbp, rsp

	out 70h, al
	in al, 71h
	mov bl, al    ; hago un backup de la cantidad
	and al, 00001111b
	mov [amount], al

	mov al, bl
	and al, 11110000b	; PERO ES UN NUMERO EN BINARIO, DEBO DIVIDIR POR 16
	shr al, 4
	mov cl, 10
	mul cl			; multiplico cl por al. El resultado se deja en al
	add [amount], al

	mov al, [amount]		;muevo la cantidad a AL para retornar
	
	mov rsp, rbp
	pop rbp
	ret

segundos:
	push rbp
	mov rbp, rsp

	mov al, 0
	call obtenerCantidad

	mov rsp, rbp
	pop rbp
	ret

minutos:
	push rbp
	mov rbp, rsp

	mov al, 2
	call obtenerCantidad

	mov rsp, rbp
	pop rbp
	ret

horas:
	push rbp
	mov rbp, rsp

	mov al, 4
	call obtenerCantidad

	mov rsp, rbp
	pop rbp
	ret

getKey:
	push rbp
	mov rbp, rsp
	mov rax,0
loop:    
	in al,0x64       
    mov cl,al
    and al,0x01       
    cmp al,0
    je loop
    
    in al,0x60

	mov rsp, rbp
	pop rbp
	ret