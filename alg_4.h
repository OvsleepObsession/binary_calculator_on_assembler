
	 
;*********************************************************************************************************************************
;  alg_4 - ;  ввод первого числа с мини-клавиатуры
;*********************************************************************************************************************************

alg_4:  
	CLR     F_KL        		; обнуление флага F_KL	
	mov a, KOD_KL			; перегруз 
	mov sbuf, a	
                  


faza0: ;//////////////////////////////////////////////////////////////

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #0, faza1     		; проверка на 0 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	
;////////........................................
; ПРОВЕРКА НА НЕДОПУСТИМЫЕ ЗНАЧЕНИЯ ПРИ 1 НАЖАТИИ
;///////.........................................

	CJNE A, #0101011b , faza_Proverka1	; проверка на + и уход
	JMP R_RESTART_R	                         ; уход 
	
faza_Proverka1:
	CJNE A, #0101101b , faza_Proverka2	; проверка на - и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka2:
	CJNE A, #0101111b , faza_Proverka3	; проверка на / и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka3:
	CJNE A, #0101010b , faza_Proverka4	; проверка на * и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka4:
	CJNE A, #1010010b , faza_Proverka5	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5:
	CJNE A, #1000011b , faza_Proverka6	; проверка на C и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka6:
	CJNE A, #0111101b , faza0_DO		; проверка на = и уход
	JMP R_RESTART_R	                         ; уход
	
faza0_DO:

	MOV FAZA, #1			; переводим фазу в 1
	call clr_buf_txt
	
	
	
	mov	r0,#buf_txt     ;  указатель места на начало буфера текста
	
	mov	a,#0dh
	mov     buf_txt,a	
	
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+1,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31    ;///// сама проверка 
	
IDEL_30:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4
	                   
	
faza1: ;//////////////////////////////////////////////////////////////

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #1, faza2    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_1	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_1:	
	CJNE A, #0101101b , faza_Proverka2_1	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_1:
	CJNE A, #0101111b , faza_Proverka3_1	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_1:
	CJNE A, #0101010b , faza_Proverka4_1		; проверка на * и уход
	JMP A_A	                         	; уход
;////////////////////////////////////////////////////////////////	
faza_Proverka4_1:
	CJNE A, #1010010b , faza_Proverka5_1	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_1:
	CJNE A, #1000011b , faza_Proverka6_1	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_1:
	CJNE A, #0111101b , faza1_DO		; проверка на = и уход
	JMP R_RESTART_R	                         ; уход
	
faza1_DO:

	MOV FAZA, #2			; переводим фазу в 2
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+2,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31    ;///// сама проверка 
	
IDEL_30_1:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_1:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4

	
faza2: ;//////////////////////////////////////////////////////////////

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #2, faza3    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
		
	CJNE A, #0101011b , faza_Proverka1_2	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_2:	
	CJNE A, #0101101b , faza_Proverka2_2	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_2:
	CJNE A, #0101111b , faza_Proverka3_2	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_2:
	CJNE A, #0101010b , faza_Proverka4_2		; проверка на * и уход
	JMP A_A	                         	; уход
;////////////////////////////////////////////////////////////////	
faza_Proverka4_2:
	CJNE A, #1010010b , faza_Proverka5_2	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_2:
	CJNE A, #1000011b , faza_Proverka6_2	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_2:
	CJNE A, #0111101b , faza2_DO		; проверка на = и уход
	JMP R_RESTART_R	                         ; уход
faza2_DO:

	MOV FAZA, #3			; переводим фазу в 3
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+3,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_2    ;///// сама проверка 
	
IDEL_30_2:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_2:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4

	
faza3: ;//////////////////////////////////////////////////////////////

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #3, faza4    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_3	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_3:	
	CJNE A, #0101101b , faza_Proverka2_3	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_3:
	CJNE A, #0101111b , faza_Proverka3_3	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_3:
	CJNE A, #0101010b , faza_Proverka4_3		; проверка на * и уход
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_3:
	CJNE A, #1010010b , faza_Proverka5_3	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_3:
	CJNE A, #1000011b , faza_Proverka6_3	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_3:
	CJNE A, #0111101b , faza3_DO		; проверка на = и уход
	JMP R_RESTART_R	                         ; уход	
faza3_DO:

	MOV FAZA, #4			; переводим фазу в 4
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+4,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_3    ;///// сама проверка 
	
IDEL_30_3:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_3:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4

	
faza4: ;//////////////////////////////////////////////////////////////	

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #4, faza5    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_4	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_4:	
	CJNE A, #0101101b , faza_Proverka2_4	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_4:
	CJNE A, #0101111b , faza_Proverka3_4	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_4:
	CJNE A, #0101010b , faza_Proverka4_4		; проверка на * и уход
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_4:
	CJNE A, #1010010b , faza_Proverka5_4	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_4:
	CJNE A, #1000011b , faza_Proverka6_4	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_4:
	CJNE A, #0111101b , faza4_DO		; проверка на = и уход
	JMP R_RESTART_R	                         ; уход		
faza4_DO:

	MOV FAZA, #5			; переводим фазу в 4
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+5,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_4    ;///// сама проверка 
	
IDEL_30_4:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_4:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4

	
faza5: ;//////////////////////////////////////////////////////////////	

	MOV A , FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #5, faza6    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_5	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_5:	
	CJNE A, #0101101b , faza_Proverka2_5	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_5:
	CJNE A, #0101111b , faza_Proverka3_5	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_5:
	CJNE A, #0101010b , faza_Proverka4_5		; проверка на * и уход
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_5:
	CJNE A, #1010010b , faza_Proverka5_5	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_5:
	CJNE A, #1000011b , faza_Proverka6_5	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_5:
	CJNE A, #0111101b , faza5_DO		; проверка на = и уход
	JMP R_RESTART_R	                       
	
faza5_DO:

	
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+6,a	
	
	MOV FAZA, #6			; переводим фазу в 4
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_5    ;///// сама проверка 
	
IDEL_30_5:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_5:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4


faza6: ;//////////////////////////////////////////////////////////////	

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #6, faza7    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_6	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_6:	
	CJNE A, #0101101b , faza_Proverka2_6	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_6:
	CJNE A, #0101111b , faza_Proverka3_6	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_6:
	CJNE A, #0101010b , faza_Proverka4_6		; проверка на * и уход
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_6:
	CJNE A, #1010010b , faza_Proverka5_6	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_6:
	CJNE A, #1000011b , faza_Proverka6_6	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_6:
	CJNE A, #0111101b , faza6_DO		; проверка на = и уход
	JMP R_RESTART_R	 
	
faza6_DO:

	MOV FAZA, #7			; переводим фазу в 4
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+7,a	
	
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_6    ;///// сама проверка 
	
IDEL_30_6:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	
	JMP END_alg_4

IDEL_31_6:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_alg_4


faza7: ;//////////////////////////////////////////////////////////////	

	MOV A ,FAZA   	   	        ; загрузка фазы в аккум 
	CJNE A, #7, faza8    		; проверка на 1 faza, если да то уходим 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_7	; проверка на + и уход
	JMP A_A                         	; уход 	
faza_Proverka1_7:	
	CJNE A, #0101101b , faza_Proverka2_7	; проверка на - и уход
	JMP A_A	                         	; уход
faza_Proverka2_7:
	CJNE A, #0101111b , faza_Proverka3_7	; проверка на / и уход
	JMP A_A		                        ; уход
faza_Proverka3_7:
	CJNE A, #0101010b , faza_Proverka4_7		; проверка на * и уход
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_7:
	CJNE A, #1010010b , faza_Proverka5_7	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_7:
	CJNE A, #1000011b , faza_Proverka6_7	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_7:
	CJNE A, #0111101b , faza7_DO		; проверка на = и уход
	JMP R_RESTART_R	
	
faza7_DO:
	
	mov	a,kod_kl      		; записываем цифру в BUF_TXT
	
	add	a,#30h		; перевод в ASCII прибавлением 30
	mov     buf_txt+8,a	
	MOV FAZA, #8			; переводим фазу в 8
	
	;///////////////////////
	; проверка на 30 или 31
	;///////////////////////
	
	mov	a,kod_kl      		; записываем в акум
	
	CJNE A, #0, IDEL_31_7    ;///// сама проверка 
	
IDEL_30_7:	

	mov	a,BUF_1
	CLR C
	RLC A
	mov	BUF_1,A
	JMP END_FULL_4
	;JMP END_alg_4

IDEL_31_7:
	
	mov	a,BUF_1
	SETB C
	RLC A
	mov	BUF_1,A
	JMP END_FULL_4
	;JMP END_alg_4

	
faza8: ;////////////////////////////////////////////////////////////////
	MOV A, KOD_KL
	
	;CJNE A, #0101011b , faza_Proverka1_8	; проверка на + и уход
	;JMP A_A                         	; уход 	
;faza_Proverka1_8:	
	;CJNE A, #0101101b , faza_Proverka2_8	; проверка на - и уход
	;JMP A_A	                         	; уход
;faza_Proverka2_8:
	;CJNE A, #0101111b , faza_Proverka3_8	; проверка на / и уход
	;JMP A_A		                        ; уход
;faza_Proverka3_8:
	;CJNE A, #0101010b , faza_Proverka4_8		; проверка на * и уход
	;JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_8:
	CJNE A, #1010010b , faza_Proverka5_8	; проверка на R и уход
	JMP R_RESTART_R	                         ; уход
faza_Proverka5_8:
	CJNE A, #1000011b , faza_Proverka6_8	; проверка на C и уход
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; уход
faza_Proverka6_8:
	CJNE A, #0111101b , faza_Proverka7_8	; проверка на = и уход
	JMP R_RESTART_R	
faza_Proverka7_8:
	CJNE A, #0 , faza_Proverka8_8
	JMP main
faza_Proverka8_8:
	CJNE A, #1 , A_A
	JMP main	


A_A: 
	MOV FAZA, #9 	; переводим фазу в 9
	mov	a,kod_kl
	mov 	BUF_COP, A
	CLR RI		; обнуление флага готовности приемника
	CLR EA		; запрет на прерывания (выключаем мини-клавиатуру)
	SETB ren	; установка флага разрешение приема UART
	call	clr_buf_txt
	call wiw_pc
	JMP END_END_4

;////////////////////////////	
R_RESTART_R:
	
	JB FISP,R_RESTART_R	; рестарт программы
	JMP 0 

;///////////////////////////	
END_FULL_4:
	call	wiw_8
	call	clr_buf_txt
	jmp END_END_4
	
END_alg_4:	
	call	wiw_8   ; вывод цифр на дисплей
	
END_END_4:

reti