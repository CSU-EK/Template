#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "touch.h"
#include "lvgl.h"               
#include "lv_port_disp.h"        // LVGL����ʾ֧��
#include "lv_port_indev.h"       // LVGL�Ĵ���֧��
#include "timer.h"



int main(void)
{ 
	
    HAL_Init();                   	//��ʼ��HAL��    
    Stm32_Clock_Init(336,8,2,7);  	//����ʱ��,168Mhz
	delay_init(168);               	//��ʼ����ʱ����
	uart_init(115200);             	//��ʼ��USART
	usmart_dev.init(84); 		    //��ʼ��USMART  
	
	lv_init();                             // LVGL ��ʼ��
	lv_port_disp_init();                   // ע��LVGL����ʾ����
	lv_port_indev_init();                  // ע��LVGL�Ĵ����������
	
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

