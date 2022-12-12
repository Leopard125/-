// main
# include <reg51.h>
# include <servo.h>
# include <NIR.h>

// void delay(int t);

typedef unsigned char uchar;
typedef unsigned int uint;

#define out P0
sbit E=P1^2;
sbit RW=P1^1;
sbit RS=P1^0;

//12Mhz��83us
void delay(uint j); //��ʱ
void delay_ms(uchar t); //ms����ʱ
void check_busy(); //��æ
void write_command(uchar com); //д����
void write_data(uchar wdata); //д����
void lcd_initial(); //LCD��ʼ��
void string(uchar address,uchar *s); //���ַ�����ʾ��LCD��ָ��λ��



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
		string(0x80,"turn right"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
		delay(1);
	}
	else if(isRight()){
		left();
		string(0x80,"turn left"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
		delay(1);
	}
	else if(isArrive()){
		stop();
		string(0x80,"stop"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
		forward();
		string(0x80,"forward"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
		delay(500);	 // ֱ��0.3s��ʻ��ͣ����
	}
	else{
		forward();
		string(0x80,"forward"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
	}
}

void delay(uint t)
{
	int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<120;j++);	// 1ms
	}
}








// void main(){
	// lcd_initial();
	// while(1){
		// string(0x80,"Hello world!"); //�ӵ�һ�е�һ����ʼ��ʾ��80H + 00H��
		// string(0xc0,"Welcome ZZULI!"); //�ӵڶ��е�һ����ʼ��ʾ��80H + 40H��
		// delay(100);
	// }
// }



void delay_ms(uchar t){
	uchar j;
	for(;t!=0; t--){
	  for (j=0;j<225;j++);
  }
}

void check_busy(){
	uchar flag=0xff;
	do{
		E=0;
		RS=0;
		RW=1;
		E=1; //E��0��1�������ض�ȡ����LCD״̬
		flag=out;//��lcd�������ȡ״̬��
	}while(flag&0x80); //���BF��ֱ��flag��D7=0�����Խ��ж�д
	E=0;
}

void write_command(uchar com){
	check_busy();
	E=0;
	RS=0;
	RW=0;
	out=com;
	delay_ms(5);
	E=1; //�������ص���ʱ��д��״̬��
	delay_ms(5);
	E=0;
	delay(1);
}

void write_data(uchar wdata){
	check_busy();
	E=0;
	RS=1;
	RW=0;
	out=wdata;
	delay_ms(5);
	E=1; //�������ص���ʱ��д������
	delay_ms(5);
	E=0;
	delay(1);
}

void lcd_initial(){
	write_command(0x38);//8λ����,˫����ʾ��5X7�ĵ����ַ�
	write_command(0x0C);//��������ʾ,���أ�����˸  0000_1100
	write_command(0x06);//�������  0000_0110
	write_command(0x01);//����
	delay(1);
}

// void string(uchar address,uchar *s){
	// write_command(address); //����ʾ����RAM��ַ
	// while(*s>0) write_data(*s++); //ѭ��д������
// }

void string(uchar address,uchar *s){
	uchar i=0;
	while(*s!='\0') 
	{
		write_command(address+i); //����ʾ����RAM��ַ
		write_data(*s++); //ѭ��д������
		i++;
	}
	i=0;
}