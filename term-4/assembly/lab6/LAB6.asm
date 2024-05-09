DTSEG segment 'DATA'
	f_param DB '���� ��ࠬ��� �ࠢ���� = ���㫮�$'
	no_f_param DB '���� ��ࠬ��� ���ࠢ����$'
	s_param DB '��ன ��ࠬ��� ����!$' 
	no_s_param DB '��ன ��ࠬ��� ���������!$'
	p_name DB '���㫮�$'
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
	mov cl, es:[di] ; ���-�� ���� � ��������� ��ப�. �⠥� �� PSP
	mov di, 82h  ; � ����� ���� ����� �뫮 ������⢮, � �� �⨬ ���� ��ப�
	mov si, offset p_name
	get_param:
		mov al, es:[di]    ; ��६ �� ᨬ����
		cmp al, byte ptr [si]
		je equal
		
		cmp byte ptr [si], '$'  ; �᫨ ��⪭㫨�� �� ����� ��ப�
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
		first_ok:  ; �᫨ ���� ��ࠬ��� ��������� ᮢ���
			cmp al, 13
			je ok_ok
			cmp al, ' '
			jne m_no_f_param
		ok_ok:  ; �뢮� ᮮ�饭�� � ⮬, �� ���� ��ࠬ��� �ࠢ����
			push ax
		    mov DX, offset f_param
			call PRINTSTR
			pop ax
		pre_ex:  ; �஢��塞, ���������� �� ��ࠬ���� �� ��ࢮ�
			mov DX, offset no_s_param
			cmp al, 13
			je no_second
			cmp al, 0
			je no_second
		next_word:  ; �� ⨯� ��� �த� ��� � � ��諮� �㭪� �஢��塞 �
			inc di
			mov al, es:[di]
			cmp al, 13
			je no_second
			mov DX, offset s_param  ; ������ �뢮��� ᮮ�饭�� � ������⢨� ��ண� ��ࠬ���

		no_second:  ; �㯮 �뢮��� ᮮ�饭�� � ⮬, �� ��� ��ண� ��ࠬ���
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