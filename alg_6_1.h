
  
;*********************************************************************************************************************************
;  alg_6_1 - Математика
;*********************************************************************************************************************************

alg_6_1:  

	mov	buf_result_l,#0        
	mov	buf_result_h,#0
	;//////////обнуление buf_txt
	call	clr_buf_txt


;**********************************************************************************
; БОЛЬШАЯ ПРОВЕРКА НА КОД ОПЕРАЦИИ + - / *
;**********************************************************************************


;***************************
;ПРОВЕРКА НА КОД ОПЕРАЦИИ + 
;***************************

	MOV A, BUF_COP
	
	CJNE A, #0101011b , NEXT_MINUS ;/// ПРОВЕРКА НА +
	JMP GOTO_PLUS 

;***************************
;ПРОВЕРКА НА КОД ОПЕРАЦИИ -
;***************************

NEXT_MINUS:

	CJNE A, #0101101b ,  NEXT_multiplication ;/// ПРОВЕРКА НА -
	JMP GOTO_MINUS
	
;***************************
;ПРОВЕРКА НА КОД ОПЕРАЦИИ *
;***************************
	
NEXT_multiplication:

	CJNE A, #0101010b ,NEXT_DELETE  ;/// ПРОВЕРКА НА *
	JMP GOTO_multiplication

;***************************
;ПРОВЕРКА НА КОД ОПЕРАЦИИ /
;***************************
NEXT_DELETE:
	CJNE A, #0101111b , END_alg_6_1_METKA ;/// ПРОВЕРКА НА /
	JMP GOTO_DELETE

END_alg_6_1_METKA:
	JMP END_alg_6_1
	



;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;+ + + + + + +
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
GOTO_PLUS:
	
	MOV A, BUF_1
	ADD A, BUF_2
	
	MOV BUF_RESULT_L, A
	
	JNC	OUTPUT_1	           
	inc     BUF_RESULT_H

OUTPUT_1:	
	;****************
	; вывод на экран 
	;****************
	
	mov	r0,#buf_txt     ;  указатель места на начало буфера текста
	
	mov	a,#0dh
	mov     buf_txt,a	
	
	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
;//////////////////////////////////////////////////////	
;ПРОВЕРКА НА f_neg И ВЫСТАВЛЕНИЕ ОТРИЦАТЕЛЬОГО ЗНАКА 
;/////////////////////////////////////////////////////
	JB     f_neg, FLAG_MINUS
	
	JNC     ZERO_CAME
	MOV	a,#31h		; перевод в ASCII прибавлением 31
	mov     buf_txt+1,a
	
	JMP PLUS_FAZ_2
	
ZERO_CAME:

	MOV	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+1,a
	
	JMP PLUS_FAZ_2
	
FLAG_MINUS:

	MOV	a,#'-'		; перевод в ASCII прибавлением 31
	mov     buf_txt+1,a
	JMP PLUS_FAZ_2
	
PLUS_FAZ_2:
	
	mov	a,BUF_RESULT_H
	
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_2
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+2,a
	
	JMP PLUS_FAZ_3
	
ZERO_CAME_2:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+2,a
	
	JMP PLUS_FAZ_3
	
PLUS_FAZ_3:	
	mov	a,BUF_RESULT_H
	
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_3
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+3,a
	
	JMP PLUS_FAZ_4
	
ZERO_CAME_3:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+3,a
	
	JMP PLUS_FAZ_4
	
PLUS_FAZ_4:

	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_4
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+4,a
	
	JMP PLUS_FAZ_5
	
ZERO_CAME_4:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+4,a
	
	JMP PLUS_FAZ_5
	
PLUS_FAZ_5:

	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_5
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+5,a
	
	JMP PLUS_FAZ_6
	
ZERO_CAME_5:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+5,a
	
	JMP PLUS_FAZ_6
	
PLUS_FAZ_6:

	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_6
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+6,a
	
	JMP PLUS_FAZ_7
	
ZERO_CAME_6:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+6,a
	
	JMP PLUS_FAZ_7
	
PLUS_FAZ_7:

	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_7
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+7,a
	
	JMP PLUS_FAZ_8
	
ZERO_CAME_7:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+7,a
	
	JMP PLUS_FAZ_8
	
PLUS_FAZ_8:

	mov	a,BUF_RESULT_H
	RLC A
	mov	BUF_RESULT_H,A
	
	JNC     ZERO_CAME_8
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+8,a
	
	JMP PLUS_FAZ_9
	
ZERO_CAME_8:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+8,a
	
	JMP PLUS_FAZ_9
	
PLUS_FAZ_9:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_9
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+9,a
	
	JMP PLUS_FAZ_10
	
ZERO_CAME_9:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+9,a
	
	JMP PLUS_FAZ_10
	
PLUS_FAZ_10:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_10
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+10,a
	
	JMP PLUS_FAZ_11
	
ZERO_CAME_10:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+10,a
	
	JMP PLUS_FAZ_11

PLUS_FAZ_11:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_11
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+11,a
	
	JMP PLUS_FAZ_12
	
ZERO_CAME_11:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+11,a
	
	JMP PLUS_FAZ_12

PLUS_FAZ_12:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_12
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+12,a
	
	JMP PLUS_FAZ_13
	
ZERO_CAME_12:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+12,a
	
	JMP PLUS_FAZ_13
	
PLUS_FAZ_13:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_13
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+13,a
	
	JMP PLUS_FAZ_14
	
ZERO_CAME_13:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+13,a
	
	JMP PLUS_FAZ_14

PLUS_FAZ_14:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_14
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+14,a
	
	JMP PLUS_FAZ_15
	
ZERO_CAME_14:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+14,a
	
	JMP PLUS_FAZ_15
	
PLUS_FAZ_15:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_15
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+15,a
	
	JMP PLUS_FAZ_16
	
ZERO_CAME_15:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+15,a
	
	JMP PLUS_FAZ_16
	
PLUS_FAZ_16:	

	mov	a,BUF_RESULT_L
	RLC A
	mov	BUF_RESULT_L,A
	
	JNC     ZERO_CAME_16
	mov	a,#31h		; перевод в ASCII прибавлением 30
	mov     buf_txt+16,a
	
	JMP PLUS_FAZ_17
	
ZERO_CAME_16:

	mov	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+16,a
	
	JMP PLUS_FAZ_17
	
PLUS_FAZ_17:	

	call wiw_8
	JMP END_alg_6_1
	
;----------------------------------------------------------------
;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
;----------------------------------------------------------------
GOTO_MINUS:
	
	MOV A, BUF_1	 ; кладем в A первое числа 
	CLR	C	 ; сброс бита с!!! 
	SUBB A, BUF_2    ; вычитаем  второе число
	
	mov	BUF_RESULT_L,a    ; результат в младший байт результата
	jnc	OUTPUT_1_MINUS	           ; если есть перенос - число отрицательное
	cpl	a                 ;  инверсия и + 1 
	inc	a
	mov	BUF_RESULT_L,a    ; результат в младший байт результата

	setb	f_neg            ; установить флаг отрицательного результата
	
	jmp	OUTPUT_1

OUTPUT_1_MINUS:

	JMP OUTPUT_1


;**************************************************************************
;* * * * * * * * * * * * * * * * * * * * * * * * * 
;**************************************************************************	
GOTO_multiplication:

	mov	a,buf_1
	mov	b,buf_2
	
	mul	ab
	
	mov	buf_result_l,a    ;  
	mov	buf_result_h,b    ;  
	
	jmp	OUTPUT_1
	
;/////////////////////////////////////////////////////////////////////////////
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
;/////////////////////////////////////////////////////////////////////////////
GOTO_DELETE:
	mov a, buf_2
	CJNE a, #0, cont_div
	call clr_buf_txt
	call wiw_err
	JMP 0
	
cont_div:

	mov	a,buf_1
	mov	b,buf_2
	
	div	ab
	
	mov	buf_result_l,a    ;  


	jmp	OUTPUT_1
	
END_alg_6_1:

	ret
