DTSEG segment 'DATA'
    HEX_STRING DB '0123456789ABCDEF'
    WELCOME_MSG DB 'Введите строку (для выхода из программы "*"): $' 
    QuitSym DB '*'
	ENTR DB 13; символ перевода строки
	STRING db 21 dup ('$')
	COUNTER db 10
DTSEG ends

STSEG segment stack
    db 100h dup(?)
STSEG ends

MYCODE segment 'CODE'
    ASSUME CS:MYCODE, DS:DTSEG

START:
	mov AX, DTSEG
	mov DS, AX
MAIN:
    ; Вывод начального сообщения 
    mov DX, offset WELCOME_MSG
    call PRINTSTR
	call CLRF

INPUTSTR:
    call GET_STRING
    call PRINTSTR

    mov bl, STRING[1]
    mov string[bx + 2], '$'
    cmp string[2], '*'
    je EXIT
ENDINPUT:
    mov DX, offset STRING
    call PRINTSTR
    call CLRF

    mov si, 2
    mov cx, bx ; ЧИСЛО ИТЕРАЦИЙ
OUTPUTSTR:
    call PRINTSPACE
	mov bl, STRING[si] 
	mov al, bl
	mov BX, offset HEX_STRING 
    call HEX
    inc si
    loop OUTPUTSTR

	call CLRF
	dec COUNTER
	cmp COUNTER, 0
	je exit
	jmp MAIN

EXIT:
    call CLRF
    call TERMINATE


TERMINATE proc
    mov al, 00  ; Return Code
    mov ah, 4ch  ; 021H: Terminate program
    int 021h
    ret
TERMINATE endp

PRINTSPACE proc
    mov dx, 32
    call PUTCH
    ret
PRINTSPACE endp

PRINTSTR proc 
    mov ah, 09h ; 09H = Display String
    int 021h 
    ret 
PRINTSTR endp 

PUTCH proc 
    ; DL = Символ для вывода
    mov ah, 02h 
    int 021h 
    ret 
PUTCH endp 


GET_STRING proc
    mov ah, 0ah
    mov dx, offset STRING
    int 21h
    ret
GET_STRING endp

GETCH proc 
    mov ah, 08h 
    int 021h 
    ret 
    ; AL = Введённый символ
GETCH endp 


CLRF proc 
    mov dl, 10 
    call PUTCH 
    mov dl, 13 
    call PUTCH 
    ret 
CLRF endp 

CLRSCR PROC
    call CLRF
    mov  ah , 0H
    mov  al , 3H
    int  10H
    ret
CLRSCR ENDP


HEX proc 
    push AX
    ; Старшие 4 бита 
    shr al, 4 
    xlat ; Записываем в AL шестнадцатиричный код символа из AL 
    mov dl, al 
    call PUTCH 
           
    pop ax 
    ; Младшие 4 бита
    and al, 00001111b 
    xlat
    mov dl, al 
    call PUTCH
    ret 
HEX endp

MYCODE ends 
end start