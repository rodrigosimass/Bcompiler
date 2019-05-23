; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_factorial:function
; LABEL
$_factorial:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 1
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; LABEL
$_i2:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; DECR
	pop	eax
	sub	dword [eax], 1
; IMM
	push	dword 1
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i3
; JMP
	jmp	dword $_i2
; LABEL
$_i3:
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
