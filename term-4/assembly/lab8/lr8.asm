prgr segment

assume CS:prgr,DS:data     ; ������������ ���������� ���������

begin: mov AX,data
	   mov DS,AX
; ������� ������
       mov AX,02h
       int 10h

; ����� �� ����� �������� CS 
	   mov DX,offset regCS
	   CALL PRINT_STR

	   mov AX,CS
	   CALL PRINT_REGISTER

; -||- DS
	   mov DX,offset regDS
	   CALL PRINT_STR

	   mov AX,DS
	   CALL PRINT_REGISTER
;  SS
	   mov DX,offset regSS
	   CALL PRINT_STR

	   MOV AX, SS
	   CALL PRINT_REGISTER
; ES
	   mov DX, offset regES
	   CALL PRINT_STR

	   mov AX, ES
	   call PRINT_REGISTER
; SP
	   mov DX, offset regSP
	   CALL PRINT_STR

	   mov AX, SP
	   call PRINT_REGISTER
; SI
	   mov DX, offset regSI
	   CALL PRINT_STR

	   mov AX, SI
	   call PRINT_REGISTER
; DI
	   	mov DX, offset regDI
	   	CALL PRINT_STR
	   
		mov AX, DI
	    call PRINT_REGISTER
; BP
       mov DX, offset regBP
	   CALL PRINT_STR

	   mov AX, BP
	   call PRINT_REGISTER

; ������� ������� ��� �����������
	   CALL CLRF
	   CALL CLRF
	   mov DX,offset msg2
	   CALL PRINT_STR
	   mov AH,08h  ; ?????????? ???? ??? ???
	   int 21h
	   xor AX,AX
; �������� �����, ������ ����, ������ �����
       mov AX,02h
       int 10h
	   mov DX,offset fengsh2
	   call PRINT_STR
	   xor BX,BX
	   mov SI,0
	   CALL inpthex         ; ��������� ����� ������
	   cmp AL,27            ; ���� �� ���� ������ ����� ������� ESC
	   je close             ; �� ��������� ���������, ����� � close
	   mov sg,BX            ; ��������� � ���������� �������
	   mov DL, 58
	   CALL PUTCH
	   xor BX,BX
	   mov SI,0
	   CALL inpthex
	   cmp AL,27
	   je close
	   mov adr,BX           ; ��������� � ���������� �������� �� ��������
	   CALL CLRF
	   CALL CLRF
	   mov AX,sg            ; ����� ������� ES �� �������� �������
	   mov ES,AX
	   mov BX,adr           ; ��������, ���-�� �� ��� ������,
	   mov AX,adr           ; �� � ��� �� �����, ����� ����
	   push AX

	   pop AX
	   sub AX,24            ; ������ ��� ����� � ����� ����� ���������� �� 24,
	                        ; ��� ��� ������ � ������ ������ ������ � ������
	   CALL dumping         ; ��������� ������ ����� �� ������

; ��� ���������� ������� ������� ESC
close: CALL CLRF
	   mov AH,09h
	   mov DX,offset msg
	   int 21h
       CALL GETCH
	   mov AX,02h
       int 10h
; ���������� ��������� � ����� ������ 0
       mov AX,4C00h
	   int 21h

hex2hex proc
; ��� ��������� ����� ������ �����
        mov CX,0
        mov BX,16
		xor DX,DX

		cmp AL,10    ; ���� ��� �� ����, �� ���� ����� ������ 16
		jae dvsn     ; �� �� ���������
		mov el[1],48 ; ����� ������ ���� � ����� �� ���������
		div BX
		mov CX,1
		mov SI,1
		jmp z
dvsn:   div BX       ; ����� AX �� BX, ��������� � AX, ������� � DX
	    push DX      ; ������� ������� � ����
	    xor DX,DX    ; �������� DX, ����� �������� �� �������
	    inc CX       ; ��������� ������� ���������� ���� � �����
	    test AX,AX   ; ���� ���� ��� ������� ������,
	    jnz dvsn     ; �� ����� ��� ��� (JUMP IF NOT ZERO)
        mov SI,0
ot:     pop DX       ; ������� ������ ����� ����������� �����
; �������������� ����� � ASCII-������
z:      cmp DL,10
		jae letter
		add DX,48    ; �������� � ASCII-���
		jmp nx
letter: add DX,55    ; �������� ASCII-��� �����
nx:     mov el[SI],DL
        inc SI
	    loop ot      ; ��������� CX ��� (�� ���������� ����)
        RET
hex2hex endp

hex4hex proc
; ��� ��������� ����� �����
        push CX
		xor CX,CX
		mov CL,12
		mov SI,0
ipt:    push AX
		sar AX,CL
		and AX, 1111b
		cmp AL,0
		jne no
		mov hx[SI],48
no:     cmp AL,10  
		jae lr
		add AL,48  ; ���� ����� ������ 10, � ��� ������ ����������� ASCII-��� '0'
		jmp n
lr:     add AL,55
n:      mov hx[SI],AL
        inc SI
		pop AX
		sub CL,4
	    cmp SI,4
		jb ipt
		pop CX
        RET
hex4hex endp

inpthex proc
; ���� ������
inpt:   mov AH,08h ; ������� ����� ������� ��� ��� ������
        int 21h
		cmp AL,13  ; ���� ��� ENTER,
		je inpt    ; �� �����������, ������� �� 4 �������, �� �����
		cmp AL,27  ; ���� ����� ESC,
		je fin     ; �� �� ����������
		cmp AL,'0' ; ���� ��� ��������� �������...
		jb inpt    ; ������ ���� 0, �� �� �����
	    cmp AL,'9' ; ���� ��� ��������� �������...
	    jbe ok     ; ������ ��� ����� ���� 9, �� ������
	    cmp AL,'F' ; ���� ��� ��������� �������...
	    ja inpt    ; ������ ���� F, �� �� �����
	    cmp AL,'A' ; ���� ��� ��������� �������...
	    jb inpt    ; ������ ���� A, �� �� �����
ok:     mov AH,02h
        mov DL,AL  ; ��������� �������� � �������
	    int 21h
	    cmp AL,'9' ; ��������, ��� ��� � ���
	    ja lttr    ; ���� ��� ������ ���� 9, �� �����
	    sub AL,'0' ; ������ �� ���� 48, ������� ������� �����
	    and AX,0Fh ; ����� ��������� ���� ��������
	    jmp addd
lttr:   sub AL,55  ; � �� ����� �������� 55
        and AX,0Fh ; ���� ������ ��� ��������� ����
addd:   mov CL,4   ; �������� �� 16,
        sal BX,CL  ; �������� �� 4 ���� �����,
		or BX,AX   ; �������� ����� �����
		inc SI
		cmp SI,4
		jae fin    ; ���� ��� 4 �������, �� ��,
		jmp inpt   ; � ���� ���, �� �� ���������
fin:    RET
inpthex endp

dumping proc
; ��������� ����� �������� �� ������ � ����� ����� �� �����
        mov CX,16
dump:   add AX,24
        push AX
        push BX
        push CX
		CALL hex4hex
		mov AH,40h
		mov CX,4
		mov BX,1
		mov DX,offset hx
		int 21h
		mov AH,09h
		mov DX,offset def
		int 21h
		pop CX
		pop BX
        push CX
	    mov CX,24
dmp:    xor AX,AX
        push BX
	    mov AL,ES:BX
        push AX
	    push CX
	    CALL hex2hex
	    mov AH,40h
	    mov BX,1
	    mov CX,2
	    mov DX,offset el
	    int 21h
	    mov el[0],48      ; fust for �� ������...
	    mov el[1],48      ; ...������� ����������
	    mov AH,02h
	    mov DL,32
	    int 21h
	    pop CX
	    pop AX
	    inc AX
	    pop BX
	    inc BX
	    loop dmp
	    push AX
	    CALL CLRF
	    pop AX
	    pop CX
		pop AX
	    loop dump
dumping endp

CLRF proc                   ; ��������� �������� ������ � �������� �������
     mov AH,02h
     mov DL,10
	 int 21h
     mov DL,13              ; ������ �������� �������
	 int 21h
	 RET
CLRF endp

GETCH proc                  ; ��������� �������� ����� �������
	  mov AH,08h
	  int 21h
	  RET
GETCH endp

PUTCH proc
	mov AH, 02h
	int 21h
	ret
PUTCH endp

CLEAR_SCREEN PROC
	mov AX,02h
	int 10h
	ret
CLEAR_SCREEN ENDP

; Prints the register at AX
PRINT_REGISTER PROC
	;    mov AX,BP
	CALL hex4hex
	mov AH,40h
	mov CX,4
	mov BX,1
	mov DX,offset hx
	int 21h
	CALL CLRF
	ret
PRINT_REGISTER ENDP

PRINT_STR proc 
    mov ah, 09h ; 09H = Display String
	int 021h 
    ret 
PRINT_STR endp 

; ------------------------------------------------------------------------------
prgr ends                   ; ����� �������� ������
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
data segment                ; ������ �������� ������
	 msg     db 'Press any key to exit... $'
	 msg2    db 'press any key to continue...$'
	 el      db 2 dup ('0')
	 hx      db 4 dup (32)
	 sg      dw 0
	 adr     dw 0
	 def     db ' - $'
	 fengsh2 db 'Now, enter the adress (in HEX, type FAR): $'
	 fengsh3 db 'Dump of memory from $'
	 fengsh4 db ' till $'
	 regCS   db 'CS: $'
	 regDS   db 'DS: $'
	 regSS   db 'SS: $'
	 regES   db 'ES: $'
	 regSP   db 'SP: $'
	 regSI   db 'SI: $'
	 regDI   db 'DI: $'
	 regBP   db 'BP: $'
data ends                   ; ����� �������� ������
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
stk segment stack           ; ������ �������� �����
    db 256 dup (0)          ; �������������� 256 ���� ��� �����
stk ends                    ; ����� �������� �����
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
end begin                   ; ����� ������ ���������, ��������� ����� �����