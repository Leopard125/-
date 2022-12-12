// main
# include <reg51.h>
# include <servo.h>
# include <NIR.h>

void delay(int t);

// ����������״̬

void main(void)
{
	// Init
//	IE = 0x81;	// ����INT 0�жϣ�����stop
//	TCON = 0x01;	// �½��ش���
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
	else if(isArrive()){
		stop();
		forward();
		delay(500);	 // ֱ��0.3s��ʻ��ͣ����
	}
	else{
		forward();
	}
}

void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<120;j++);	// 1ms
	}
}