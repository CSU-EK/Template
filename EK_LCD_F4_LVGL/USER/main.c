#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "touch.h"
#include "lvgl.h"               
#include "lv_port_disp.h"        // LVGL的显示支持
#include "lv_port_indev.h"       // LVGL的触屏支持
#include "timer.h"



int main(void)
{ 
	
    HAL_Init();                   	//初始化HAL库    
    Stm32_Clock_Init(336,8,2,7);  	//设置时钟,168Mhz
	delay_init(168);               	//初始化延时函数
	uart_init(115200);             	//初始化USART
	usmart_dev.init(84); 		    //初始化USMART  
	
	lv_init();                             // LVGL 初始化
	lv_port_disp_init();                   // 注册LVGL的显示任务
	lv_port_indev_init();                  // 注册LVGL的触屏检测任务
	
	TIM3_Init(1000-1,84-1);
	
	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj,60,30);
	lv_obj_align(switch_obj,LV_ALIGN_CENTER,0,0);
	
		while(1)
		{
			HAL_Delay(1-1);
			static uint8_t msLVGL = 0;
			if(msLVGL++>=5)
			{
				lv_timer_handler();
				msLVGL = 0;
			}
		}
}

