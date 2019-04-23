/***********************************************************
 * �ļ���       ��main.c
 * ˵��         ���û�Ӧ�ó���
 * ����         ��landzo ������
 * �Ա���       ��http://landzo.taobao.com/
 * ��˾��վ     ��http://www.landzo.com/
 *��̳          ��http://www.landzo.cn
 * ��汾       ��V1.0
 *ʱ��          ��15.5.26
************************************************************/


#include "include.h" // Include.h �����û��Զ����ͷ�ļ� 


/***********************��������***************************/
extern uint8 TIME0flag_5ms   ;
extern uint8 TIME0flag_10ms  ;
extern uint8 TIME0flag_20ms  ;
extern uint8 TIME0flag_50ms  ;
extern uint8 TIME0flag_80ms  ;
extern uint8 TIME0flag_100ms ;
extern uint8 TIME0flag_1s ;
/***********************��������***************************/


/************************������****************************/
void main(void)
{
  uint8 Flag=0;
  DisableInterrupts; //��ֹ���ж� 
  gpio_init (PTB0, GPO, 1);//LED GPIO���ų�ʼ������ ������� ���Ϊ�ߵ�ƽ
  OLED_Init();  //OLED��ʼ�� 
  OLED_Print_Str(0,0,"�������landzo.cn"); //���� �ַ�����ʾ
  Draw_Landzo();//��ʾ����LOGO
  delay_ms(2000);//��ʱ2000ms
  OLED_Fill(0x00);//���� ���� 
  EnableInterrupts ;
  while(1)
  {
    OLED_Print_Str(0,Flag,"�������landzo.cn"); //���� �ַ�����ʾ
    delay_ms(500);
    OLED_Fill(0x00);//���� ����
    Flag+=2;
    if(Flag>6) Flag=0;
    PTB0_OUT = ~PTB0_OUT; //LED���״̬ȡ������������״̬ ����������
  }
}