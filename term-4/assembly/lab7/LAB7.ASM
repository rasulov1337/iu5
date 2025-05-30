DATASG SEGMENT 'DATA'
TABLHEX DB '0123456789ABCDEF'
WCS DB '������ ��ப� (��� �����襭�� "*"): $'
BUF    DB  100 DUP(0)
DECW   DW  0
DATASG ENDS

STSEG segment stack
    db 100h dup(?)
STSEG ends

MYCODE SEGMENT 'CODE'
    ASSUME CS:MYCODE, DS:DATASG, SS:STSEG
START:
; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
    MOV AX, DATASG
    MOV DS, AX
    MOV CX, 3
INPUTSTR:
	mov DX, offset WCS
	call PRINTSTR
	call CLRF
; ���� ����� ��ப�
    CALL GETCH
    CMP AL, '*'
    JE EXIT
; ���� ��. �᫠ � ����������� � BUF
    ; �����⮢�� 横�� �����
    MOV SI , OFFSET BUF
    MOV CX , 4

REINSERT:
    CMP CX , 4
    JE MC1
    CALL GETCH
    CMP AL, '*'
    JE EXIT
MC1:
; �஢�ઠ ᨬ���� �� �ࠢ��쭮���
    CMP AL , 30H
    JL REINSERT
    CMP AL , 39H
    JLE MBUF
    CMP AL , 65
    JL REINSERT
    CMP AL , 70
    JG REINSERT
; ������ � ���� � �����
MBUF:
    MOV [SI], AL
    INC SI
; ����� ᨬ����
    MOV DL, AL
    CALL PUTCH
LOOP REINSERT

    MOV  BYTE PTR [SI], '$'
    CALL PRINTSPACE
    MOV DL, '='
    CALL PUTCH
    CALL PRINTSPACE
; �뢮� ��⭠����筮�� �᫠
    MOV DX , OFFSET BUF
	CALL PRINTSTR
    CALL PRINTSPACE
    CALL PRINTSPACE
; ��ॢ�� � �����筮� � �����
    CALL DECPRINT
    CALL CLRF
LOOP INPUTSTR

EXIT:
    call CLRF
    call TERMINATE

TERMINATE PROC
    MOV AH, 00H
    MOV AL, 03H
    INT  10H

    MOV AL, 00  ; Return Code
    MOV AH, 4ch  ; 021H: Terminate program
    INT 21H
    RET
TERMINATE ENDP

TONUMBER PROC
    CMP AL , 39H
    JG MS1
    SUB AL , 30H
    JMP MS2
MS1:
	SUB AL , 55
MS2:
       RET
TONUMBER ENDP

DECPRINT PROC
; ��ࢮ� � ��設��� �।�⠢�����
       MOV SI , OFFSET BUF
       MOV BX , 4096
       MOV DECW , 0
       MOV CX , 4
CPER:
       MOV AL , [SI]
       CALL TONUMBER
       MOV AH, 0
       MUL BX	; �������� ���祭�� � ॣ���� AX  �� ���࠭�-���筨� � ��࠭�� १���� � ॣ����� AX
       MOV DX , DECW
       ADD DX , AX
       MOV DECW , DX
       SHR BX , 1
       SHR BX , 1
       SHR BX , 1
       SHR BX , 1
       INC SI
       LOOP  CPER
; ��ॢ�� � �����筮� �।�⠢�����
       MOV CX , 5
       MOV BX , 10000
;
MDEC:
       MOV AX , DECW
       MOV DX , 0
       DIV BX
       MOV DECW , DX
       ADD AL , 30H
       MOV DL , AL
	   CMP DL, 30H
       CALL PUTCH
       MOV AX, BX
       MOV DX , 0
       MOV BX , 10
       DIV BX
       MOV BX , AX
LOOP MDEC
       RET
DECPRINT ENDP

PUTCH PROC
      MOV AH , 2
      INT 21H
      RET
PUTCH ENDP

CLRF proc 
    mov dl, 10 
    call PUTCH 
    mov dl, 13 
    call PUTCH 
    ret 
CLRF endp 

GETCH PROC
    MOV AH, 08H
    INT 21H
    RET
GETCH ENDP

PRINTSTR proc 
    mov ah, 09h ; 09H = Display String
	int 021h 
    ret 
PRINTSTR endp 

PRINTSPACE proc
    mov dx, 32
    call PUTCH
    ret
PRINTSPACE endp

MYCODE ENDS
END START
