; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_getPI:function
; LABEL
$_getPI:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
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
; EXTRN
extern	$_prints
; EXTRN
extern	$_printd
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x70
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; CALL
	call	$_getPI
; TRASH
	add	esp, 0
; PUSH
	push	eax
; CALL
	call	$_printd
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i2
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
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
