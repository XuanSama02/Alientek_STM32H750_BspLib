#include "bsp_h750_usart.h"

#pragma import(__use_no_semihosting)

//标准库需要的支持函数
struct __FILE
{
    int handle;
};
FILE __stdout;

//定义_sys_exit()以免使用半主机模式
void _sys_exit(int x)
{
    x = x;
}

//重定义fptuc函数
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}
