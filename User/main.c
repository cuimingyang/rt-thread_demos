/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ƶ����ˮ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  STM32 F429 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
#include "board.h"
#include "rtthread.h"



/* 定义线程控制块 */
static struct rt_thread led1_thread;

/* 定义线程控栈时要求 RT_ALIGN_SIZE 个字节对齐 */
ALIGN(RT_ALIGN_SIZE)

/* 定义线程栈 */
static rt_uint8_t rt_led1_thread_stack[1024];


static void led1_thread_entry(void* parameter);


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{ 
	/*
	* 开发板硬件初始化， RTT 系统初始化已经在 main 函数之前完成，
	* 即在 component.c 文件中的 rtthread_startup()函数中完成了。
	* 所以在 main 函数中，只需要创建线程和启动线程即可。
	*/

	rt_thread_init(&led1_thread, /* 线程控制块 */
					"led1", /* 线程名字 */
					led1_thread_entry, /* 线程入口函数 */
					RT_NULL, /* 线程入口函数参数 */
					&rt_led1_thread_stack[0], /* 线程栈起始地址 */
					sizeof(rt_led1_thread_stack), /* 线程栈大小 */
					3, /* 线程的优先级 */
					20); /* 线程时间片 */
	rt_thread_startup(&led1_thread); /* 启动线程，开启调度 */	
}

static void led1_thread_entry(void* parameter)
{
	while(1){
		LED1_ON;
		rt_thread_delay(500); 

		LED1_OFF;
		rt_thread_delay(500);
	}
}

/*********************************************END OF FILE**********************/

