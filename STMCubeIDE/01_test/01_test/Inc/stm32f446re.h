/*
 * stm32f446re.h
 *
 *  Created on: Jun 1, 2025
 *      Author: Tanishq
 */



#ifndef INC_STM32F446RE_H_
#define INC_STM32F446RE_H_

#define __vo volatile
#include<stdint.h>
#include<stddef.h>



/*
 * ARM CORTEX M4PROCESSOR NVIC ISERx REGISTERS
 *
 */


#define NVIC_ISER0           ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1           ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2           ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3           ((__vo uint32_t*)0xE000E10c)
/*
 * ARM CORTEX NVIC ICERx REGISTERS
 */
#define NVIC_ICER0           ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1           ((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2           ((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3           ((__vo uint32_t*)0XE000E18C)

#define NVIC_PR_BASEADDR     ((__vo uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED       4


#define FLASH_BASEADDR       0x08000000U
#define SRAM1_BASEADDR       0x20000000U
#define SRAM2_BASEADDR       0x20001C00U
#define ROM                  0x1FFF0000U
#define SRAM                 SRAM1_BASEADDR


#define PERIPH_BASE         0x40000000U
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     0x40010000U
#define AHB1PERIPH_BASE     0x40020000U
#define AHB2PERIPH_BASE     0x50000000U


/*GPIO ADDRESS  AHB1*/


#define GPIOA_BASEADDR      (AHB1PERIPH_BASE +0x0000)
#define GPIOB_BASEADDR      (AHB1PERIPH_BASE +0x0400)
#define GPIOC_BASEADDR      (AHB1PERIPH_BASE +0x0800)
#define GPIOD_BASEADDR      (AHB1PERIPH_BASE +0x0C00)
#define GPIOE_BASEADDR      (AHB1PERIPH_BASE +0x1000)
#define GPIOF_BASEADDR      (AHB1PERIPH_BASE +0x1400)
#define GPIOG_BASEADDR      (AHB1PERIPH_BASE +0x1800)
#define GPIOH_BASEADDR      (AHB1PERIPH_BASE +0x1C00)
#define RCC_BASEADDR        (AHB1PERIPH_BASE +0x3800)


/*APB1*/
#define I2C1_BASEADDR       (APB1PERIPH_BASE +0x5400)
#define I2C2_BASEADDR       (APB1PERIPH_BASE +0x5800)
#define I2C3_BASEADDR       (APB1PERIPH_BASE +0x5C00)
#define SPI2_BASEADDR       (APB1PERIPH_BASE +0x3800)
#define SPI3_BASEADDR       (APB1PERIPH_BASE +0x3C00)
#define USART2_BASEADDR     (APB1PERIPH_BASE +0x4400)
#define USART3_BASEADDR     (APB1PERIPH_BASE +0x4800)
#define UART4_BASEADDR      (APB1PERIPH_BASE +0x4C00)
#define UART5_BASEADDR      (APB1PERIPH_BASE +0x5000)


/*APB2*/

#define SPI1_BASEADDR      (APB2PERIPH_BASE +0x3000)
#define SPI4_BASEADDR      (APB2PERIPH_BASE +0x3400)
#define USART1_BASEADDR    (APB2PERIPH_BASE +0x1000)
#define USART6_BASEADDR    (APB2PERIPH_BASE +0x1400)
#define EXTI_BASEADDR      (APB2PERIPH_BASE +0x3C00)
#define SYSCFG_BASEADDR    (APB2PERIPH_BASE +0x3800)

/*peripheral register definition struct */

typedef struct
{__vo uint32_t MODER;
__vo uint32_t OTYPER;
__vo uint32_t OSPEEDER;
__vo uint32_t PUPDR;
__vo uint32_t IDR;
__vo uint32_t ODR;
__vo uint32_t BSRR;
__vo uint32_t LCKR;
__vo uint32_t AFR[2];/*ARRAY*/
}GPIO_RegDef_t;

#define GPIOA   ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*) GPIOH_BASEADDR)

typedef struct
{
__vo uint32_t CR;
__vo uint32_t PLLCFGR;
__vo uint32_t CFGR;
__vo uint32_t CIR;
__vo uint32_t AHB1RSTR;
__vo uint32_t AHB2RSTR;
__vo uint32_t AHB3RSTR;
__vo uint32_t APB1RSTR;
__vo uint32_t APB2RSTR;
__vo uint32_t AHB1ENR;
__vo uint32_t AHB2ENR;
__vo uint32_t AHB3ENR;
__vo uint32_t APB1ENR;
__vo uint32_t APB2ENR;
__vo uint32_t AHB1LPENR;
__vo uint32_t AHB2LPENR;
__vo uint32_t AHB3LPENR;
__vo uint32_t APB1LPENR;
__vo uint32_t APB2LPENR;
__vo uint32_t BDCR;
__vo uint32_t CSR;
__vo uint32_t SSCGR;
__vo uint32_t PLLI2SCFGR;
__vo uint32_t PLLSAICFGR;
__vo uint32_t DCKCFGR;
__vo uint32_t CKGATENR;
__vo uint32_t DCKCFGR2;
}RCC_RegDef_t;

#define RCC          ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI         ((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG        ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
	__vo uint32_t RESERVED2[2];
	__vo uint32_t CFGR;
}SYSCFG_RegDef_t;
//spi peripheral register definition
typedef struct
		{__vo uint32_t CR1;
		__vo uint32_t CR2;
		__vo uint32_t SR;
		__vo uint32_t DR;
		__vo uint32_t CRCPR;
		__vo uint32_t RXCRCR;
		__vo uint32_t TXCRCR;
		__vo uint32_t I2SCFGR;
		__vo uint32_t I2SPR;

		}SPI_RegDef_t;


typedef struct		{
		__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	  __vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	  __vo uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */		  __vo uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
		  __vo uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
		  __vo uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
		  __vo uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
		  __vo uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
		  __vo uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
		  __vo uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
		}I2C_RegDef_t;

typedef struct
{		__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
		__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
			__vo uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
			__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
			__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
			__vo uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
			__vo uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
		} USART_RegDef_t;

#define USART1  			((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASEADDR)



#define SPI1      ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2      ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3      ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4      ((SPI_RegDef_t*)SPI4_BASEADDR)

#define I2C1    ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2    ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3    ((I2C_RegDef_t*)I2C3_BASEADDR)

/*CLOCK ENABLE MACROS FOR GPIOS*/
#define GPIOA_PCLK_EN()   (RCC->AHB1ENR|=(1<<0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR|=(1<<1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR|=(1<<2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR|=(1<<3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR|=(1<<4))
#define GPIOF_PCLK_EN()   (RCC->AHB1ENR|=(1<<5))
#define GPIOG_PCLK_EN()   (RCC->AHB1ENR|=(1<<6))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR|=(1<<7))


/*CLOCK ENABLE MACROS FOR I2CX*/
#define I2C1_PCLK_EN()    (RCC->APB1ENR|=(1<<21))
#define I2C2_PCLK_EN()    (RCC->APB1ENR|=(1<<22))
#define I2C3_PCLK_EN()    (RCC->APB1ENR|=(1<<23))


/*CLOCK MACROS FOR SPI*/

#define  SPI1_PCLK_EN()   (RCC->APB2ENR|=(1<<12))
#define  SPI2_PCLK_EN()   (RCC->APB1ENR|=(1<<14))
#define  SPI3_PCLK_EN()   (RCC->APB1ENR|=(1<<15))
#define  SPI4_PCLK_EN()   (RCC->APB2ENR|=(1<<13))

/* CLOCK MACROS ENABLE FOR USART */

#define USART1_PCLK_EN()  (RCC->APB2ENR|=(1<<4))
#define USART2_PCLK_EN()  (RCC->APB1ENR|=(1<<17))
#define USART3_PCLK_EN()  (RCC->APB1ENR|=(1<<18))
#define USART6_PCLK_EN()  (RCC->APB2ENR|=(1<<5))
#define UART4_PCLK_EN()  (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()  (RCC->APB1ENR |= (1 << 20))

/*SYSCFG*/

#define  SYSCFG_PCLK_EN() (RCC->APB2ENR|=(1<<14))

/*CLOCK DISABLE MACROS FOR GPIOS*/

#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()   (RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()   (RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &=~(1<<7))


/*CLOCK DISABLE FOR I2C*/

#define I2C1_PCLK_DI()    (RCC->APB1ENR&=~(1<<21))
#define I2C2_PCLK_DI()    (RCC->APB1ENR&=~(1<<22))
#define I2C3_PCLK_DI()    (RCC->APB1ENR&=~(1<<23))

/*CLOCK DISABLE FOR SPI*/
#define  SPI1_PCLK_DI()   (RCC->APB2ENR&=~(1<<12))
#define  SPI2_PCLK_DI()   (RCC->APB1ENR&=~(1<<14))
#define  SPI3_PCLK_DI()   (RCC->APB1ENR&=~(1<<15))
#define  SPI4_PCLK_DI()   (RCC->APB2ENR&=~(1<<13))

/*USARTX*/

#define USART1_PCLK_DI()  (RCC->APB2ENR&= ~(1<<4))
#define USART2_PCLK_DI()  (RCC->APB1ENR&= ~(1<<17))
#define USART3_PCLK_DI()  (RCC->APB1ENR&= ~(1<<18))
#define USART6_PCLK_DI()  (RCC->APB2ENR&= ~(1<<5))
#define UART4_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()  (RCC->APB1ENR &= ~(1 << 20))

#define  SYSCFG_PCLK_DI() (RCC->APB2ENR&=~(1<<14))


#define GPIOA_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<0)); (RCC->AHB1RSTR &=~(1<<0));}while(0)
#define GPIOB_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<1)); (RCC->AHB1RSTR &=~(1<<1));}while(0)
#define GPIOC_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<2)); (RCC->AHB1RSTR &=~(1<<2));}while(0)
#define GPIOD_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<3)); (RCC->AHB1RSTR &=~(1<<3));}while(0)
#define GPIOE_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<4)); (RCC->AHB1RSTR &=~(1<<4));}while(0)
#define GPIOF_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<5)); (RCC->AHB1RSTR &=~(1<<5));}while(0)
#define GPIOG_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<6)); (RCC->AHB1RSTR &=~(1<<6));}while(0)
#define GPIOH_REG_RESET()      do{(RCC->AHB1RSTR|=(1<<7)); (RCC->AHB1RSTR &=~(1<<7));}while(0)


/* RETURNSPORT CODE FOR GPIOX BASE ADDRESS
 *
 */
#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
								        (x == GPIOE)?4:\
								        (x == GPIOF)?5:\
								        (x == GPIOG)?6:\
								        (x == GPIOH)?7:0 )

//IRQ REQUEST NUMBER

#define IRQ_NO_EXTI0      6
#define IRQ_NO_EXTI1      7
#define IRQ_NO_EXTI2      8
#define IRQ_NO_EXTI3      9
#define IRQ_NO_EXTI4      10
#define IRQ_NO_EXTI9_5      23
#define IRQ_NO_EXTI15_10      40
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4         84






//general macros
#define ENABLE  1
#define DISABLE 0
#define SET      ENABLE
#define RESET    DISABLE
#define FLAG_RESET RESET
#define FLAG_SET SET



#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

//peripheral macros for spi
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8

		/******************************************************************************************
		 *Bit position definitions of I2C peripheral
		 ******************************************************************************************/
		/*
		 * Bit position definitions I2C_CR1
		 */
		#define I2C_CR1_PE						0
		#define I2C_CR1_NOSTRETCH  				7
		#define I2C_CR1_START 					8
		#define I2C_CR1_STOP  				 	9
		#define I2C_CR1_ACK 				 	10
		#define I2C_CR1_SWRST  				 	15

		/*
		 * Bit position definitions I2C_CR2
		 */
		#define I2C_CR2_FREQ				 	0
		#define I2C_CR2_ITERREN				 	8
		#define I2C_CR2_ITEVTEN				 	9
		#define I2C_CR2_ITBUFEN 			    10

		/*
		 * Bit position definitions I2C_OAR1
		 */
		#define I2C_OAR1_ADD0    				 0
		#define I2C_OAR1_ADD71 				 	 1
		#define I2C_OAR1_ADD98  			 	 8
		#define I2C_OAR1_ADDMODE   			 	15

		/*
		 * Bit position definitions I2C_SR1
		 */

		#define I2C_SR1_SB 					 	0
		#define I2C_SR1_ADDR 				 	1
		#define I2C_SR1_BTF 					2
		#define I2C_SR1_ADD10 					3
		#define I2C_SR1_STOPF 					4
		#define I2C_SR1_RXNE 					6
		#define I2C_SR1_TXE 					7
		#define I2C_SR1_BERR 					8
		#define I2C_SR1_ARLO 					9
		#define I2C_SR1_AF 					 	10
		#define I2C_SR1_OVR 					11
		#define I2C_SR1_TIMEOUT 				14

		/*
		 * Bit position definitions I2C_SR2
		 */
     	#define I2C_SR2_MSL						0
		#define I2C_SR2_BUSY 					1
		#define I2C_SR2_TRA 					2
		#define I2C_SR2_GENCALL 				4
		#define I2C_SR2_DUALF 					7

		/*
		 * Bit position definitions I2C_CCR
		 */
		#define I2C_CCR_CCR 					 0
		#define I2C_CCR_DUTY 					14
		#define I2C_CCR_FS  				 	15

		/*
		 * Bit position definitions USART_CR1
		 */
		#define USART_CR1_SBK					0
		#define USART_CR1_RWU 					1
		#define USART_CR1_RE  					2
		#define USART_CR1_TE 					3
		#define USART_CR1_IDLEIE 				4
		#define USART_CR1_RXNEIE  				5
		#define USART_CR1_TCIE					6
		#define USART_CR1_TXEIE					7
		#define USART_CR1_PEIE 					8
		#define USART_CR1_PS 					9
		#define USART_CR1_PCE 					10
		#define USART_CR1_WAKE  				11
		#define USART_CR1_M 					12
		#define USART_CR1_UE 					13
		#define USART_CR1_OVER8  				15



		/*
		 * Bit position definitions USART_CR2
		 */
		#define USART_CR2_ADD   				0
		#define USART_CR2_LBDL   				5
		#define USART_CR2_LBDIE  				6
		#define USART_CR2_LBCL   				8
		#define USART_CR2_CPHA   				9
		#define USART_CR2_CPOL   				10
		#define USART_CR2_STOP   				12
		#define USART_CR2_LINEN   				14


		/*
		 * Bit position definitions USART_CR3
		 */
		#define USART_CR3_EIE   				0
		#define USART_CR3_IREN   				1
		#define USART_CR3_IRLP  				2
		#define USART_CR3_HDSEL   				3
		#define USART_CR3_NACK   				4
		#define USART_CR3_SCEN   				5
		#define USART_CR3_DMAR  				6
		#define USART_CR3_DMAT   				7
		#define USART_CR3_RTSE   				8
		#define USART_CR3_CTSE   				9
		#define USART_CR3_CTSIE   				10
		#define USART_CR3_ONEBIT   				11

		/*
		 * Bit position definitions USART_SR
		 */

		#define USART_SR_PE        				0
		#define USART_SR_FE        				1
		#define USART_SR_NE        				2
		#define USART_SR_ORE       				3
		#define USART_SR_IDLE       			4
		#define USART_SR_RXNE        			5
		#define USART_SR_TC        				6
		#define USART_SR_TXE        			7
		#define USART_SR_LBD        			8
		#define USART_SR_CTS        			9





#endif /* INC_STM32F446RE_H_ */
