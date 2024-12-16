# stm32工程移植LVGL
工程里面要有显示屏幕的驱动文件，触摸屏的驱动文件，寄存器，标准库，hal库，手搓hal都支持

### 1.将此文件夹复制到stm32工程目录下。
在keil中添加工程目录：
**LVGL_conf**
-->lv_conf.h   
-->lvgl.h  
**LVGL_porting**
-->lv_port_disp.c  
-->lv_port_indev.c 
**LVGL_src**
-->添加所有src目录，子目录下的.c 文件，仔细添加，一个不能漏，否则你将会...爽爽的

### 2.添加头文件路径
魔术棒，C/C++,添加以下路径：
**\LVGL**
**\LVGL**
**\LVGL\examples\porting** 
**\VGL\src\下面的一些子目录，自己看那个子目录下面有头文件。或者全部添加进来也可以**

### 3.勾选C99 Mode

### 4.修改代码
**1.在lv_port_disp.c文件，首先include你的显示屏驱动，（每个文件前面的预编译一定要改成#if 1）** 
**2.在define区域设置自己屏幕的宽和高，设置好后可以注释掉#warning语句**
**3.在lv_port_disp_init中注释掉example2和example3的代码，目前只用example1即可，有需要可以在这里选择不同的通道模式**
**4.在example1里面的数组中修改第一个数字为屏幕宽度**
**5.disp_init函数中添加显示屏初始化函数，显示屏显示方向函数。**
**6.在disp_flush函数中添加lcd的区域填充方法。**
**7.在lv_port_indev.c文件，首先include显示屏和触摸的文件**
**8.里面定义了5种交互模式，用到哪个把其他的删掉或者注释掉就行**
**9.以触摸屏为例，在touchpad_is_pressed函数中添加自己的按下检测函数，返回布尔值，别忘了加true条件判断**
**10.在touchpad_get_xy函数中添加自己的位置获取函数**
**11.在main.c中首先include"lvgl.h""lv_port_disp.h""lv_port_indev.h"**
**12.初始化函数lv_init();lv_port_disp_init(); lv_port_indev_init();**
**13.添加定时器作为lvgl时基，配置一个1ms定时器，在中断回调中写入lv_tick_inc(1);**
**14.在主循环中每隔5ms执行一次lv_timer_handler();**

# 就配好啦
