// �������IN1=0��IN2=1ʱΪ��ת��IN1=1��IN2=0ʱΪ��ת��������ȫΪ0��ɲ����ȫΪ1
// �ұ�����IN3=1��IN4=0ʱΪ��ת��IN3=0��IN4=1ʱΪ��ת

// ���⴫���������ź�Ϊ1  û���ź�Ϊ0	 ������û�к��ߣ������к���
# include <reg51.h>

// ����
sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit ENA = P2^2;

// �ҵ��
sbit IN3 = P2^3;
sbit IN4 = P2^4;
sbit ENB = P2^5;

// ���⴫����
sbit LEFT_2 = P1^3;
sbit LEFT_1 = P1^4;
sbit CENTER = P1^5;
sbit RIGHT_1 = P1^6;
sbit RIGHT_2 = P1^7;

void delay(int t);

// �����˶�״̬
void forward(void);
void backward(void);
void right(void);
void left(void);
void idle(void);

// ����������״̬
int isLeft(void);
int isRight(void);

void main(void)
{
	ENA = 1;
	ENB = 1;
	if(isLeft()){
		right();
		delay(1);
	}
	else if(isRight()){
		left();
		delay(1);
	}
	else if(isLeft()&&isRight()){
		idle();
	}
	else{
		forward();
	}
}

// �Ȳ���PWM
void forward()
{// ��������
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}

void right()
{// ������ͣ
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 0;
}

void left()
{// ��ͣ����
	IN1 = 0;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}

void backward()
{// ���ҷ�
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
}

void idle()
{// ��ͣ��ͣ
	IN1 = 0;
	IN2 = 0;
	IN3 = 0;	
	IN4 = 0;
}

void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<120;j++);	// 1ms
	}
}

int isLeft()
{
	int chk = 0;
	if(RIGHT_1==1 && LEFT_1==0){	 // �ұ߲��ߣ���ƫ
		chk = 1;	
	}else chk = 0;
	return chk;
}

int isRight()
{
	int chk = 0;
	if(RIGHT_1==0 && LEFT_1==1){	 // ��߲��ߣ���ƫ
		chk = 1;	
	}else chk = 0;
	return chk;
}


//����һ��git-hwc