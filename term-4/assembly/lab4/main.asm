MYCODE SEGMENT 'CODE' 
    ASSUME CS:MYCODE, DS:MYCODE

    HEX_STRING DB '0123456789ABCDEF'
    WELCOME_STRING DB 'Enter symbol: $' 
    QUIT_PROMPT_TEXT DB 'q - QUIT CODE$' 
    QUIT_SYMBOL DB 'q' 

start:
    push CS
    pop DS
    mov BX, offset HEX_STRING 
    ; Регистр BX -- Указатель на данные

main:
    ; Выводим строку приветствия
    mov DX, offset WELCOME_STRING ; На вывод пихаем строку Welcome
    call PRINTSTR
    call CLRF
    ;

    ; Пользователь вводит символ
    call GETCH  ; ЗАПИСЫВАЕТ В AL

    mov CX, 10 ; CX = Число итераций
cycle: 
    push AX 
    push AX 

    ; Тупо выводим введенный символ
    mov DL, AL 
    call PUTCH 

    ; ' - ' 
    call PRINTSPACE
    mov DL, '-'
    call PUTCH
    call PRINTSPACE

    ; Тут начинается суета
    pop AX
    call HEX

    ; '\n' 
    call CLRF 

    pop AX
    inc AX

    loop cycle 

    ; После цикла

    ; Выводим строку
    mov DX, offset QUIT_PROMPT_TEXT ; Записываем в DX адрес строки
    call PRINTSPACE
    call CLRF
    call GETCH
    cmp AL, QUIT_SYMBOL
    je exit ; Если пользователь ввел q, переходим к exit
    jmp main

exit:
    call TERMINATE


TERMINATE proc
    ; Выходим с норм return code
    mov al, 00  ; Return Code
    mov ah, 4ch  ; 021H: Terminate program
    int 021h
    ret
TERMINATE endp


; Этот код настолько часто вызывался, что я решил вынести его в отдельную функцию
PRINTSPACE proc
    mov dx, 32
    call PUTCH
    ret
PRINTSPACE endp


PRINTSTR proc 
; print string 
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


GETCH proc 
    mov ah, 08h 
    int 021h 
    ret 
    ; AL = Введенный символ
GETCH endp 


; /n/r 
CLRF proc 
    mov dl, 10 
    call PUTCH 
    mov dl, 13 
    call PUTCH 
    ret 
CLRF endp 

HEX proc 
    ; Старшие 4 бита
    push AX 
    shr al, 4 
    ;sub teste, al 
    ;mov al, teste 
    ;add al, al 
    xlat 
    ;mov teste, 15 
    mov dl, al 
    call PUTCH 
    
    ; Младшие 4 бита
    pop ax 
    and al, 00001111b 
    ;sub teste, al 
    ;mov al, teste 
    ;add al, al 
    xlat ; Записывает в AL код символа для AL
    mov dl, al 
    ;mov teste, 15 
    call PUTCH

    ; Выводим h 
    mov dx, 104 
    call PUTCH 
    ret 
HEX endp 


MYCODE ends 
end start 