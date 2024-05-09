DTSEG segment 'DATA'
	no_param_msg DB '��� ��ࠬ���!$'
	loop_iters_num DB 10d
DTSEG ends

STSEG segment stack
    db 100h dup(?)
STSEG ends

MYCODE segment 'CODE'
    ASSUME CS:MYCODE, DS:DTSEG



; ���: �������� ��� �᫠ � ����⢥ ��㬥�⮢ ��������� ��ப�
; �㦭� 㬭����� �� �� 10 � �뢥��


start:
	mov AX, DTSEG
	mov DS, AX

	mov di, 80h
	mov cl, es:[di] ; ���-�� ���� � ��������� ��ப�. �⠥� �� PSP
	mov di, 82h  ; � ����� ���� ����� �뫮 ������⢮, � �� �⨬ ���� ��ப�
	
	; �஢�ઠ �� ���⮩ ��㬥��
	cmp cl, 0
	je NO_PARAM

	; ���������� AL ����� �������
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
	; ����� ����������

	CALL CONVERT
	push ax

	; ����� �����
	call PRINT_DECIMAL
	CALL TERMINATE



	PRINT_DECIMAL proc
		; ���࠭塞 ॣ�����, ����� �㤥� �ᯮ�짮����
		push ax
		push bx
		push cx
		push dx

		; ���樠������ ���稪�
		mov cx, 03
		mov bx, 10

		; ����� �᫠ � ���⭮� ���浪�
	print_loop:
		; ������� AX �� 10
		xor dx, dx
		div bx

		; ����饭�� ���⪠ � DL
		; DL ⥯��� ᮤ�ন� ⥪���� ����
		add dl, '0'  ; �८�ࠧ������ � ᨬ��� ASCII
		push dx  ; ���࠭塞 ⥪���� ���� � �⥪�
		loop print_loop  ; �����塞 ��� ��⠢���� ���

		; ����� ��� � ��אַ� ���浪�
		mov cx, 03
	print_digits:
		pop dx  ; ����砥� ���� �� �⥪�
		call PUTCH  ; �뢮��� ���� � ���᮫�
		loop print_digits  ; �����塞 ��� ��⠫��� ���

		; ����⠭�������� ��࠭���� ॣ�����
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
		; ��室�� � ��� return code
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
		; DL = ������ ��� �뢮��
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