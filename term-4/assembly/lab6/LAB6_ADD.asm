DTSEG segment 'DATA'
	no_param_msg DB 'Нет параметра!$'
	loop_iters_num DB 10d
DTSEG ends

STSEG segment stack
    db 100h dup(?)
STSEG ends

MYCODE segment 'CODE'
    ASSUME CS:MYCODE, DS:DTSEG



; ДОП: Вводятся два числа в качестве аргументов командной строки
; Нужно умножить их на 10 и вывести


start:
	mov AX, DTSEG
	mov DS, AX

	mov di, 80h
	mov cl, es:[di] ; кол-во байт в командной строке. читаем из PSP
	mov di, 82h  ; В первых двух байтах было количество, а мы хотим читать строку
	
	; Проверка на пустой аргумент
	cmp cl, 0
	je NO_PARAM

	; ЗАПОЛНЕНИЕ AL ДВУМЯ ЦИФРАМИ
	xor ax, ax
	mov al, byte ptr es:[di]
	sub al, '0'
	mov bl, 10
	mul bl
	mov dl, al

	mov al, byte ptr es:[di + 1]
	sub al, '0'
	add dl, al
	mov al, dl
	; КОНЕЦ ЗАПОЛНЕНИЯ

	CALL CONVERT
	push ax

	; ВЫВОД ЦИФРЫ
	call PRINT_DECIMAL
	CALL TERMINATE



	PRINT_DECIMAL proc
		; Сохраняем регистры, которые будем использовать
		push ax
		push bx
		push cx
		push dx

		; Инициализация счетчика
		mov cx, 03
		mov bx, 10

		; Печать числа в обратном порядке
	print_loop:
		; Деление AX на 10
		xor dx, dx
		div bx

		; Помещение остатка в DL
		; DL теперь содержит текущую цифру
		add dl, '0'  ; Преобразование в символ ASCII
		push dx  ; Сохраняем текущую цифру в стеке
		loop print_loop  ; Повторяем для оставшихся цифр

		; Печать цифр в прямом порядке
		mov cx, 03
	print_digits:
		pop dx  ; Получаем цифру из стека
		call PUTCH  ; Выводим цифру в консоль
		loop print_digits  ; Повторяем для остальных цифр

		; Восстанавливаем сохраненные регистры
		pop dx
		pop cx
		pop bx
		pop ax
		ret
	PRINT_DECIMAL endp

	CONVERT proc
		mov bx, 10d
		mul bx
		ret
	CONVERT endp

	PRINT_AND_EXIT:
		call PRINTSTR
		call TERMINATE

	NO_PARAM:
		mov dx, offset no_param_msg
		call PRINTSTR
		call TERMINATE
	

	TERMINATE proc
		; Выходим с норм return code
		mov al, 00  ; Return Code
		mov ah, 4ch  ; 021H: Terminate program
		int 021h
		ret
	TERMINATE endp

	PRINTSTR proc 
		mov ah, 09h ; 09H = Display String
		int 021h 
		call CRLF
		ret 
	PRINTSTR endp 

	PUTCH proc 
		; DL = Символ для вывода
		mov ah, 02h 
		int 021h 
		ret 
	PUTCH endp 

	CRLF proc 
		mov dl, 10 
		call PUTCH 
		mov dl, 13 
		call PUTCH 
		ret 
	CRLF endp 



mycode ENDS
END start