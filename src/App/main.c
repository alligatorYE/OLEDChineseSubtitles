/***********************************************************
 * 文件名       ：main.c
 * 说明         ：用户应用程序
 * 作者         ：landzo 蓝电子
 * 淘宝店       ：http://landzo.taobao.com/
 * 公司网站     ：http://www.landzo.com/
 *论坛          ：http://www.landzo.cn
 * 库版本       ：V1.0
 *时间          ：15.5.26
************************************************************/


#include "include.h" // Include.h 包含用户自定义的头文件 


/***********************参数定义***************************/
extern uint8 TIME0flag_5ms   ;
extern uint8 TIME0flag_10ms  ;
extern uint8 TIME0flag_20ms  ;
extern uint8 TIME0flag_50ms  ;
extern uint8 TIME0flag_80ms  ;
extern uint8 TIME0flag_100ms ;
extern uint8 TIME0flag_1s ;
/***********************参数定义***************************/


/************************主函数****************************/
void main(void)
{
  uint8 Flag=0;
  DisableInterrupts; //禁止总中断 
  gpio_init (PTB0, GPO, 1);//LED GPIO引脚初始化配置 推挽输出 输出为高电平
  OLED_Init();  //OLED初始化 
  OLED_Print_Str(0,0,"蓝宙电子landzo.cn"); //汉字 字符串显示
  Draw_Landzo();//显示蓝宙LOGO
  delay_ms(2000);//延时2000ms
  OLED_Fill(0x00);//清屏 黑屏 
  EnableInterrupts ;
  while(1)
  {
    OLED_Print_Str(0,Flag,"蓝宙电子landzo.cn"); //汉字 字符串显示
    delay_ms(500);
    OLED_Fill(0x00);//清屏 黑屏
    Flag+=2;
    if(Flag>6) Flag=0;
    PTB0_OUT = ~PTB0_OUT; //LED输出状态取反，呈现亮灭状态 程序在运行
  }
}