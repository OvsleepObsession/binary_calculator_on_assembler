
	 
;*********************************************************************************************************************************
;  alg_4 - ;  ���� ������� ����� � ����-����������
;*********************************************************************************************************************************

alg_4:  
	CLR     F_KL        		; ��������� ����� F_KL	
	mov a, KOD_KL			; �������� 
	mov sbuf, a	
                  


faza0: ;//////////////////////////////////////////////////////////////

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #0, faza1     		; �������� �� 0 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	
;////////........................................
; �������� �� ������������ �������� ��� 1 �������
;///////.........................................

	CJNE A, #0101011b , faza_Proverka1	; �������� �� + � ����
	JMP R_RESTART_R	                         ; ���� 
	
faza_Proverka1:
	CJNE A, #0101101b , faza_Proverka2	; �������� �� - � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka2:
	CJNE A, #0101111b , faza_Proverka3	; �������� �� / � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka3:
	CJNE A, #0101010b , faza_Proverka4	; �������� �� * � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka4:
	CJNE A, #1010010b , faza_Proverka5	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5:
	CJNE A, #1000011b , faza_Proverka6	; �������� �� C � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka6:
	CJNE A, #0111101b , faza0_DO		; �������� �� = � ����
	JMP R_RESTART_R	                         ; ����
	
faza0_DO:

	MOV FAZA, #1			; ��������� ���� � 1
	call clr_buf_txt
	
	
	
	mov	r0,#buf_txt     ;  ��������� ����� �� ������ ������ ������
	
	mov	a,#0dh
	mov     buf_txt,a	
	
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+1,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #1, faza2    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_1	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_1:	
	CJNE A, #0101101b , faza_Proverka2_1	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_1:
	CJNE A, #0101111b , faza_Proverka3_1	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_1:
	CJNE A, #0101010b , faza_Proverka4_1		; �������� �� * � ����
	JMP A_A	                         	; ����
;////////////////////////////////////////////////////////////////	
faza_Proverka4_1:
	CJNE A, #1010010b , faza_Proverka5_1	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_1:
	CJNE A, #1000011b , faza_Proverka6_1	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_1:
	CJNE A, #0111101b , faza1_DO		; �������� �� = � ����
	JMP R_RESTART_R	                         ; ����
	
faza1_DO:

	MOV FAZA, #2			; ��������� ���� � 2
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+2,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #2, faza3    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
		
	CJNE A, #0101011b , faza_Proverka1_2	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_2:	
	CJNE A, #0101101b , faza_Proverka2_2	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_2:
	CJNE A, #0101111b , faza_Proverka3_2	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_2:
	CJNE A, #0101010b , faza_Proverka4_2		; �������� �� * � ����
	JMP A_A	                         	; ����
;////////////////////////////////////////////////////////////////	
faza_Proverka4_2:
	CJNE A, #1010010b , faza_Proverka5_2	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_2:
	CJNE A, #1000011b , faza_Proverka6_2	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_2:
	CJNE A, #0111101b , faza2_DO		; �������� �� = � ����
	JMP R_RESTART_R	                         ; ����
faza2_DO:

	MOV FAZA, #3			; ��������� ���� � 3
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+3,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_2    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #3, faza4    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_3	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_3:	
	CJNE A, #0101101b , faza_Proverka2_3	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_3:
	CJNE A, #0101111b , faza_Proverka3_3	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_3:
	CJNE A, #0101010b , faza_Proverka4_3		; �������� �� * � ����
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_3:
	CJNE A, #1010010b , faza_Proverka5_3	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_3:
	CJNE A, #1000011b , faza_Proverka6_3	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_3:
	CJNE A, #0111101b , faza3_DO		; �������� �� = � ����
	JMP R_RESTART_R	                         ; ����	
faza3_DO:

	MOV FAZA, #4			; ��������� ���� � 4
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+4,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_3    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #4, faza5    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_4	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_4:	
	CJNE A, #0101101b , faza_Proverka2_4	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_4:
	CJNE A, #0101111b , faza_Proverka3_4	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_4:
	CJNE A, #0101010b , faza_Proverka4_4		; �������� �� * � ����
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_4:
	CJNE A, #1010010b , faza_Proverka5_4	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_4:
	CJNE A, #1000011b , faza_Proverka6_4	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_4:
	CJNE A, #0111101b , faza4_DO		; �������� �� = � ����
	JMP R_RESTART_R	                         ; ����		
faza4_DO:

	MOV FAZA, #5			; ��������� ���� � 4
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+5,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_4    ;///// ���� �������� 
	
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

	MOV A , FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #5, faza6    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_5	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_5:	
	CJNE A, #0101101b , faza_Proverka2_5	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_5:
	CJNE A, #0101111b , faza_Proverka3_5	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_5:
	CJNE A, #0101010b , faza_Proverka4_5		; �������� �� * � ����
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_5:
	CJNE A, #1010010b , faza_Proverka5_5	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_5:
	CJNE A, #1000011b , faza_Proverka6_5	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_5:
	CJNE A, #0111101b , faza5_DO		; �������� �� = � ����
	JMP R_RESTART_R	                       
	
faza5_DO:

	
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+6,a	
	
	MOV FAZA, #6			; ��������� ���� � 4
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_5    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #6, faza7    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_6	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_6:	
	CJNE A, #0101101b , faza_Proverka2_6	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_6:
	CJNE A, #0101111b , faza_Proverka3_6	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_6:
	CJNE A, #0101010b , faza_Proverka4_6		; �������� �� * � ����
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_6:
	CJNE A, #1010010b , faza_Proverka5_6	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_6:
	CJNE A, #1000011b , faza_Proverka6_6	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_6:
	CJNE A, #0111101b , faza6_DO		; �������� �� = � ����
	JMP R_RESTART_R	 
	
faza6_DO:

	MOV FAZA, #7			; ��������� ���� � 4
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+7,a	
	
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_6    ;///// ���� �������� 
	
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

	MOV A ,FAZA   	   	        ; �������� ���� � ����� 
	CJNE A, #7, faza8    		; �������� �� 1 faza, ���� �� �� ������ 
	
	MOV A, KOD_KL
	
	CJNE A, #0101011b , faza_Proverka1_7	; �������� �� + � ����
	JMP A_A                         	; ���� 	
faza_Proverka1_7:	
	CJNE A, #0101101b , faza_Proverka2_7	; �������� �� - � ����
	JMP A_A	                         	; ����
faza_Proverka2_7:
	CJNE A, #0101111b , faza_Proverka3_7	; �������� �� / � ����
	JMP A_A		                        ; ����
faza_Proverka3_7:
	CJNE A, #0101010b , faza_Proverka4_7		; �������� �� * � ����
	JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_7:
	CJNE A, #1010010b , faza_Proverka5_7	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_7:
	CJNE A, #1000011b , faza_Proverka6_7	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_7:
	CJNE A, #0111101b , faza7_DO		; �������� �� = � ����
	JMP R_RESTART_R	
	
faza7_DO:
	
	mov	a,kod_kl      		; ���������� ����� � BUF_TXT
	
	add	a,#30h		; ������� � ASCII ������������ 30
	mov     buf_txt+8,a	
	MOV FAZA, #8			; ��������� ���� � 8
	
	;///////////////////////
	; �������� �� 30 ��� 31
	;///////////////////////
	
	mov	a,kod_kl      		; ���������� � ����
	
	CJNE A, #0, IDEL_31_7    ;///// ���� �������� 
	
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
	
	;CJNE A, #0101011b , faza_Proverka1_8	; �������� �� + � ����
	;JMP A_A                         	; ���� 	
;faza_Proverka1_8:	
	;CJNE A, #0101101b , faza_Proverka2_8	; �������� �� - � ����
	;JMP A_A	                         	; ����
;faza_Proverka2_8:
	;CJNE A, #0101111b , faza_Proverka3_8	; �������� �� / � ����
	;JMP A_A		                        ; ����
;faza_Proverka3_8:
	;CJNE A, #0101010b , faza_Proverka4_8		; �������� �� * � ����
	;JMP A_A	  
;////////////////////////////////////////////////////////////////	
faza_Proverka4_8:
	CJNE A, #1010010b , faza_Proverka5_8	; �������� �� R � ����
	JMP R_RESTART_R	                         ; ����
faza_Proverka5_8:
	CJNE A, #1000011b , faza_Proverka6_8	; �������� �� C � ����
	MOV FAZA, #0
	MOV BUF_1, #0
	JMP main	                         ; ����
faza_Proverka6_8:
	CJNE A, #0111101b , faza_Proverka7_8	; �������� �� = � ����
	JMP R_RESTART_R	
faza_Proverka7_8:
	CJNE A, #0 , faza_Proverka8_8
	JMP main
faza_Proverka8_8:
	CJNE A, #1 , A_A
	JMP main	


A_A: 
	MOV FAZA, #9 	; ��������� ���� � 9
	mov	a,kod_kl
	mov 	BUF_COP, A
	CLR RI		; ��������� ����� ���������� ���������
	CLR EA		; ������ �� ���������� (��������� ����-����������)
	SETB ren	; ��������� ����� ���������� ������ UART
	call	clr_buf_txt
	call wiw_pc
	JMP END_END_4

;////////////////////////////	
R_RESTART_R:
	
	JB FISP,R_RESTART_R	; ������� ���������
	JMP 0 

;///////////////////////////	
END_FULL_4:
	call	wiw_8
	call	clr_buf_txt
	jmp END_END_4
	
END_alg_4:	
	call	wiw_8   ; ����� ���� �� �������
	
END_END_4:

reti