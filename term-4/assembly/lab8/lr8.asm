prgr segment

assume CS:prgr,DS:data     ; соответствие сегментных регистров

begin: mov AX,data
	   mov DS,AX
; очистка экрана
       mov AX,02h
       int 10h

; вывод на экран регистра CS 
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

; нажмите клавишу для продолжения
	   CALL CLRF
	   CALL CLRF
	   mov DX,offset msg2
	   CALL PRINT_STR
	   mov AH,08h  ; ?????????? ???? ??? ???
	   int 21h
	   xor AX,AX
; очистили экран, выдали инфу, вводим адрес
       mov AX,02h
       int 10h
	   mov DX,offset fengsh2
	   call PRINT_STR
	   xor BX,BX
	   mov SI,0
	   CALL inpthex         ; процедура ввода адреса
	   cmp AL,27            ; если мы сюда попали после нажатия ESC
	   je close             ; то завершить программу, пойдём в close
	   mov sg,BX            ; схоронили в переменную сегмент
	   mov DL, 58
	   CALL PUTCH
	   xor BX,BX
	   mov SI,0
	   CALL inpthex
	   cmp AL,27
	   je close
	   mov adr,BX           ; схоронили в переменную смещение по сегменту
	   CALL CLRF
	   CALL CLRF
	   mov AX,sg            ; чтобы указать ES на введённый сегмент
	   mov ES,AX
	   mov BX,adr           ; возможно, кто-то из них лишний,
	   mov AX,adr           ; но я уже не помню, мысль ушла
	   push AX

	   pop AX
	   sub AX,24            ; потому что потом в цикле будем прибавлять по 24,
	                        ; это для вывода в начале каждой строки её адреса
	   CALL dumping         ; процедура вывода дампа по адресу

; тут обработчик нажатия клавиши ESC
close: CALL CLRF
	   mov AH,09h
	   mov DX,offset msg
	   int 21h
       CALL GETCH
	   mov AX,02h
       int 10h
; завершение программы с кодом ошибки 0
       mov AX,4C00h
	   int 21h

hex2hex proc
; для получения кодов одного байта
        mov CX,0
        mov BX,16
		xor DX,DX

		cmp AL,10    ; если там не нули, то есть число больше 16
		jae dvsn     ; то всё нормально
		mov el[1],48 ; иначе впишем ноль и потом всё нормально
		div BX
		mov CX,1
		mov SI,1
		jmp z
dvsn:   div BX       ; делим AX на BX, результат в AX, остаток в DX
	    push DX      ; скинули остаток в стек
	    xor DX,DX    ; обнулили DX, иначе повлияет на деление
	    inc CX       ; увеличили счётчик количества цифр в числе
	    test AX,AX   ; если пока ещё делится нацело,
	    jnz dvsn     ; то делим ещё раз (JUMP IF NOT ZERO)
        mov SI,0
ot:     pop DX       ; подняли первую цифру десятичного числа
; преобразование числа в ASCII-символ
z:      cmp DL,10
		jae letter
		add DX,48    ; получили её ASCII-код
		jmp nx
letter: add DX,55    ; получили ASCII-код буквы
nx:     mov el[SI],DL
        inc SI
	    loop ot      ; повторять CX раз (по количеству цифр)
        RET
hex2hex endp

hex4hex proc
; для получения кодов слова
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
		add AL,48  ; Если цифра меньше 10, к ней просто добавляется ASCII-код '0'
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
; ввод адреса
inpt:   mov AH,08h ; функция ввода символа без его показа
        int 21h
		cmp AL,13  ; если это ENTER,
		je inpt    ; то обломайтунг, введено не 4 символа, по новой
		cmp AL,27  ; если вжали ESC,
		je fin     ; то на завершение
		cmp AL,'0' ; если код введённого символа...
		jb inpt    ; меньше кода 0, то по новой
	    cmp AL,'9' ; если код введённого символа...
	    jbe ok     ; меньше или равен коду 9, то ништяк
	    cmp AL,'F' ; если код введённого символа...
	    ja inpt    ; больше кода F, то по новой
	    cmp AL,'A' ; если код введённого символа...
	    jb inpt    ; меньше кода A, то по новой
ok:     mov AH,02h
        mov DL,AL  ; засчитаем введённое и покажем
	    int 21h
	    cmp AL,'9' ; проверим, что это у нас
	    ja lttr    ; если код больше кода 9, то буква
	    sub AL,'0' ; вычтем из кода 48, получим реально цифру
	    and AX,0Fh ; затрём остальные биты регистра
	    jmp addd
lttr:   sub AL,55  ; а из буквы вычитаем 55
        and AX,0Fh ; тоже потёрли все остальные биты
addd:   mov CL,4   ; умножить на 16,
        sal BX,CL  ; сдвинуть на 4 бита влево,
		or BX,AX   ; добавить новую цифру
		inc SI
		cmp SI,4
		jae fin    ; если уже 4 введено, то всё,
		jmp inpt   ; а если нет, то до победного
fin:    RET
inpthex endp

dumping proc
; получение кодов символов по адресу и вывод дампа на экран
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
	    mov el[0],48      ; fust for на всякий...
	    mov el[1],48      ; ...занулим переменную
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

CLRF proc                   ; процедура переноса строки и возврата каретки
     mov AH,02h
     mov DL,10
	 int 21h
     mov DL,13              ; символ возврата каретки
	 int 21h
	 RET
CLRF endp

GETCH proc                  ; процедура ожидания ввода символа
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
prgr ends                   ; конец сегмента команд
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
data segment                ; начало сегмента данных
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
data ends                   ; конец сегмента данных
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
stk segment stack           ; начало сегмента стека
    db 256 dup (0)          ; резервирование 256 байт для стека
stk ends                    ; конец сегмента стека
; -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
end begin                   ; конец текста программы, установка точки входа