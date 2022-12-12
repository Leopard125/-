// ��ﲿ��
// �������IN1=0��IN2=1ʱΪ��ת��IN1=1��IN2=0ʱΪ��ת��������ȫΪ0��ɲ����ȫΪ1
// �ұ�����IN3=1��IN4=0ʱΪ��ת��IN3=0��IN4=1ʱΪ��ת
# include <reg51.h>

// ����
sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit ENA = P2^2;

// �ҵ��
sbit IN3 = P2^3;
sbit IN4 = P2^4;
sbit ENB = P2^5;

// �����˶�״̬
void forward(void);
void backward(void);
void right(void);
void left(void);
void stop(void);

void delay100ms(int t);

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

void stop()
{
	// ��ͣ��ͣ
	IN1 = 1;
	IN2 = 1;
	IN3 = 1;	
	IN4 = 1;
	delay100ms(100);	   // ͣ10s
}

void delay100ms(int t)
{
	int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<12000;j++);	// 0.1s
	}
}