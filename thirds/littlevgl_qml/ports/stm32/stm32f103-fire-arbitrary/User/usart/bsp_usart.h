#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include <stdio.h>

/** 
  * ���ں궨�壬��ͬ�Ĵ��ڹ��ص����ߺ�IO��һ������ֲʱ��Ҫ�޸��⼸����
	* 1-�޸�����ʱ�ӵĺ꣬uart1���ص�apb2���ߣ�����uart���ص�apb1����
	* 2-�޸�GPIO�ĺ�
  */
	
// ����1-USART1
#define  DEBUG_USART1                   USART1
#define  DEBUG_USART1_CLK                RCC_APB2Periph_USART1
#define  DEBUG_USART1_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  DEBUG_USART1_BAUDRATE           115200

// USART GPIO ���ź궨��
#define  DEBUG_USART1_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  DEBUG_USART1_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART1_TX_GPIO_PORT       GPIOA   
#define  DEBUG_USART1_TX_GPIO_PIN        GPIO_Pin_9
#define  DEBUG_USART1_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART1_RX_GPIO_PIN        GPIO_Pin_10

#define  DEBUG_USART1_IRQ                USART1_IRQn
#define  DEBUG_USART1_IRQHandler         USART1_IRQHandler


// ����2-USART2
#define  DEBUG_USART2                    USART2
#define  DEBUG_USART2_CLK                RCC_APB1Periph_USART2
#define  DEBUG_USART2_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART2_BAUDRATE           115200

//// USART GPIO ���ź궨��
#define  DEBUG_USART2_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define  DEBUG_USART2_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART2_TX_GPIO_PORT         GPIOA   
#define  DEBUG_USART2_TX_GPIO_PIN          GPIO_Pin_2
#define  DEBUG_USART2_RX_GPIO_PORT       GPIOA
#define  DEBUG_USART2_RX_GPIO_PIN        GPIO_Pin_3

#define  DEBUG_USART2_IRQ                USART2_IRQn
#define  DEBUG_USART2_IRQHandler         USART2_IRQHandler

// ����3-USART3
#define  DEBUG_USART3                   USART3
#define  DEBUG_USART3_CLK                RCC_APB1Periph_USART3
#define  DEBUG_USART3_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART3_BAUDRATE           115200

//// USART GPIO ���ź궨��
#define  DEBUG_USART3_GPIO_CLK           (RCC_APB2Periph_GPIOB)
#define  DEBUG_USART3_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART3_TX_GPIO_PORT         GPIOB   
#define  DEBUG_USART3_TX_GPIO_PIN          GPIO_Pin_10
#define  DEBUG_USART3_RX_GPIO_PORT       GPIOB
#define  DEBUG_USART3_RX_GPIO_PIN        GPIO_Pin_11

#define  DEBUG_USART3_IRQ                USART3_IRQn
#define  DEBUG_USART3_IRQHandler         USART3_IRQHandler

// ����4-UART4
#define  DEBUG_USART4                   UART4
#define  DEBUG_USART4_CLK                RCC_APB1Periph_UART4
#define  DEBUG_USART4_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART4_BAUDRATE           115200

//// USART GPIO ���ź궨��
#define  DEBUG_USART4_GPIO_CLK           (RCC_APB2Periph_GPIOC)
#define  DEBUG_USART4_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART4_TX_GPIO_PORT       GPIOC   
#define  DEBUG_USART4_TX_GPIO_PIN        GPIO_Pin_10
#define  DEBUG_USART4_RX_GPIO_PORT       GPIOC
#define  DEBUG_USART4_RX_GPIO_PIN        GPIO_Pin_11

#define  DEBUG_USART4_IRQ                UART4_IRQn
#define  DEBUG_USART4_IRQHandler         UART4_IRQHandler


// ����5-UART5
#define  DEBUG_USART5                   UART5
#define  DEBUG_USART5_CLK                RCC_APB1Periph_UART5
#define  DEBUG_USART5_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART5_BAUDRATE           115200

//// USART GPIO ���ź궨��
#define  DEBUG_USART5_GPIO_CLK           (RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD)
#define  DEBUG_USART5_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART5_TX_GPIO_PORT         GPIOC   
#define  DEBUG_USART5_TX_GPIO_PIN          GPIO_Pin_12
#define  DEBUG_USART5_RX_GPIO_PORT       GPIOD
#define  DEBUG_USART5_RX_GPIO_PIN        GPIO_Pin_2

#define  DEBUG_USART5_IRQ                UART5_IRQn
#define  DEBUG_USART5_IRQHandler         UART5_IRQHandler

#define  UART_BUFFER_LEN	             512

typedef struct uart_buffer_t
{
    uint16_t head;           
    uint16_t tail;
    uint16_t len;
    uint8_t  buf[UART_BUFFER_LEN];
}uart_buffer_t;

int uart_write_buffer(uart_buffer_t * buffer, uint8_t data);
int uart_read_buffer(uart_buffer_t * buffer, uint8_t * data);

void uart_write(int port, uint8_t * buf, int len);
int uart_read(int port, uint8_t * buf, int len);
int uart_any(int port);
void uart_deinit(int port);

int uart_init(int port, int baudrate, int databits, float stopbits, char * parity);

void DEBUG_USART_Config(void);

#endif /* __USART_H */