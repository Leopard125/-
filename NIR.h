// ���⴫��������
# include<reg51.h>

// ���⴫���������ź�Ϊ1  û���ź�Ϊ0	 ������û�к��ߣ������к���	���߷���0��û�߷���1
sbit LEFT_2 = P1^3;
sbit LEFT_1 = P1^4;
sbit CENTER = P1^5;
sbit RIGHT_1 = P1^6;
sbit RIGHT_2 = P1^7;

int isLeft(void);
int isRight(void);
int isArrive(void);

int isLeft()
{
	int chk = 0;
	if((RIGHT_1==0 || RIGHT_2==0) && (LEFT_1==1 || LEFT_2==1)){	 // �ұ߲��ߣ���ƫ
		chk = 1;	
	}else chk = 0;
	return chk;
}

int isRight()
{
	int chk = 0;
	if((RIGHT_1==1 || RIGHT_2==1) && (LEFT_1==0 || LEFT_2==0)){	 // ��߲��ߣ���ƫ
		chk = 1;	
	}else chk = 0;
	return chk;
}

int isArrive()
{
	int chk = 0;
	if(RIGHT_1==0 && LEFT_1==0){
		chk = 1;
	}else chk = 0;
	return chk;
}