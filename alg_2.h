
;*********************************************************************************************************************************

; ��������  2.    �.�. ���������� �� �������.  

;*********************************************************************************************************************************

alg_2:

	push psw
	mov	r6,a
	
	setb 	PSW.3   ; ������� � ���� 1

; ��������� ���������� ��������� ������� �0 ��� ��������� ������� ���������� 5 ��
  
 
    mov TH0, #HIGH(-3000)  ;��������� ������� ���� ������� T0
    mov TL0, #LOW(-3000)   ;��������� ������� ���� ������� T0 
    
    
	
	
; ������ ����� ��������� 	

al_2_1:		

	INC KOD_ST_4  		; ��������� 1 � ���� ����������� ���� ����������
	MOV A, KOD_ST_4         ; ����� ������� �� 4�	
	
	CJNE A, #100b, alg_2_2  ;  ���� ��� 4 �� ��������, ���� ��� ������� �� �����
	MOV KOD_ST_4, #0
	
alg_2_2:
			   		; ������ ������� ������ ����?
			   
	JNB F_KLD, alg_2_3 		; ��������� � �������� 3 ���� F_KLD=0
	
			   	  	 ; ���� �� �������� �� ����� ���
	MOV A, KOD_ST_4
	CJNE A, KOD_DOP,en_alg_2  	 ; ��������� KOD_DOP = KOD_ST_4 ?
	JMP alg_2_2_1
	
alg_2_2_1: 
	
	call alg_3        ; ��������� � �������� 3 � �������� ������� ��� �
	JB BITC, alg_2_5  ; ���� ��� � 1 �� ���������
	JMP alg_2_3_3     ; ���� ��� � 0 �� ���������
	
alg_2_3:
	
	call alg_3	  ; ��������� � �������� 3 � �������� ������� ��� �
	JB BITC, alg_2_4  ; ���� ��� � 1 �� ���������
			  ; ���� ��� � 0 �� ���������
alg_2_3_3:	

	CLR FISP    ;������� ����� � ������ � ����� ��������� 2
	CLR F_KLD
	JMP en_alg_2
	
alg_2_4:
	  SETB F_KLD        ; ������������� ���� 
	  MOV A, KOD_ST_4   ; ���������� � KOD_DOP ����� �����������
	  MOV KOD_DOP, A
	  JMP en_alg_2

alg_2_5:

	JB FISP,en_alg_2    ; ������� ������ ���� ������������?
	call tab_m_k        ; ����� ��������� 10 
	SETB FISP	    ; ������������� 1 � ������ ����� 		
	SETB F_KL 
	
	JMP en_alg_2
	
en_alg_2:       ;  ����� ��������� ���������� 
	
	
	clr	PSW.3   ; ��������� � ���� 0
	mov	a,r6
	pop	psw

	reti