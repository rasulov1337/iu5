DTSEG segment 'DATA'
	f_param DB 'Первый параметр правильный = Расулов$'
	no_f_param DB 'Первый параметр неправильный$'
	s_param DB 'Второй параметр есть!$' 
	no_s_param DB 'Второй параметр отсутствует!$'
	p_name DB 'Расулов$'
DTSEG ends

STSEG segment stack
    db 100h dup(?)
STSEG ends

MYCODE segment 'CODE'
    ASSUME CS:MYCODE, DS:DTSEG

start:
	mov AX, DTSEG
	mov DS, AX
	mov di, 80h
	mov cl, es:[di] ; кол-во байт в командной строке. читаем из PSP
	mov di, 82h  ; В первых двух байтах было количество, а мы хотим читать строку
	mov si, offset p_name
	get_param:
		mov al, es:[di]    ; берем по символу
		cmp al, byte ptr [si]
		je equal
		
		cmp byte ptr [si], '$'  ; Если наткнулись на конец строки
		je first_ok

		m_no_f_param:
			push ax
			mov dx, offset no_f_param
			call PRINTSTR
			pop ax
			cmp al, 0
			je pre_ex
			space_enter_search:
				cmp al, 13
				je pre_ex
				cmp al, ' '
				je next_word
				inc di
				mov al, es:[di]
			loop space_enter_search
		first_ok:  ; Если первый параметр полностью совпал
			cmp al, 13
			je ok_ok
			cmp al, ' '
			jne m_no_f_param
		ok_ok:  ; Вывод сообщения о том, что первый параметр правильный
			push ax
		    mov DX, offset f_param
			call PRINTSTR
			pop ax
		pre_ex:  ; Проверяем, завершаются ли параметры на первом
			mov DX, offset no_s_param
			cmp al, 13
			je no_second
			cmp al, 0
			je no_second
		next_word:  ; Ну типа тут вроде как и в прошлом пункте проверяем хз
			inc di
			mov al, es:[di]
			cmp al, 13
			je no_second
			mov DX, offset s_param  ; Теперь выводим сообщение о присутствии второго параметра

		no_second:  ; Тупо выводим сообщение о том, что нет второго параметра
			call PRINTSTR
			jmp exit
		equal:
			inc di
			inc si
	loop get_param
	
	EXIT:
		call TERMINATE

	TERMINATE proc
		mov al, 00  ; Return Code
		mov ah, 4ch  ; 021H: Terminate program
		int 021h
		ret
	TERMINATE endp

	PRINTSTR proc 
		mov ah, 09h ; 09H = Display String
		int 021h 
		call crlf
		ret 
	PRINTSTR endp 

	clrf proc
		MOV AH,02
		MOV DL,13
		INT 21H
		MOV AH,02
		MOV DL,10
		INT 21H
		RET
	clrf endp

mycode ENDS
END start