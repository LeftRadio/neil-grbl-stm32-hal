/**
  ******************************************************************************
  * @file    platform.c
  * @author  leftradio
  * @version 1.0.0
  * @date
  * @brief
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "platform.h"
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "f_eeprom.h"
#include "hal_abstract.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define NGRBL_TIMER_BASE            (&htim2)
#define NGRBL_TIMER_PULSE           (&htim3)

/* Private macro -------------------------------------------------------------*/
#define NGRBL_TIMER_BASE_INIT()		(MX_TIM2_Init())
#define NGRBL_TIMER_PULSE_INIT()	(MX_TIM2_Init())

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Extern function -----------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/* CRITICAL SECTION ----------------------------------------------------------*/
void ngrbl_hal_critical_enter(void) { __disable_irq(); }
void ngrbl_hal_critical_exit(void) { __enable_irq(); }

/* INTERRUPT -----------------------------------------------------------------*/
void ngrbl_hal_enable_interrupts(void) { __disable_irq(); }
void ngrbl_hal_disable_interrupts(void) { __enable_irq(); }

/* STEPPER ------------------------------------------------------------------*/

void ngrbl_hal_stepper_init(void) { /* */ }

void ngrbl_hal_stepper_set_driver_state(ngrbl_hal_state_t state) {
    /* set EN PIN to logic 1 or 0 */
    if (state != NGRBL_HAL_DISABLE) {
        STEPPER_XY_EN_GPIO_Port->BSRR = STEPPER_XY_EN_Pin;
    }
    else {
        STEPPER_XY_EN_GPIO_Port->BSRR = (uint32_t)STEPPER_XY_EN_Pin << 16u;
    }
}

void ngrbl_hal_stepper_set_dir(uint8_t dir_mask, uint8_t dir_bits) {
	/* */
	dir_bits &= dir_mask;
	/* */
	STEPPER_XD_GPIO_Port->BSRR = (dir_bits & 0x01)? (uint32_t)STEPPER_XD_Pin : (uint32_t)STEPPER_XD_Pin << 16u;
	STEPPER_YD_GPIO_Port->BSRR = (dir_bits & 0x02)? (uint32_t)STEPPER_YD_Pin : (uint32_t)STEPPER_YD_Pin << 16u;
	STEPPER_ZD_GPIO_Port->BSRR = (dir_bits & 0x04)? (uint32_t)STEPPER_ZD_Pin : (uint32_t)STEPPER_ZD_Pin << 16u;
}

void ngrbl_hal_stepper_set_step(uint8_t step_mask, uint8_t step_bits) {
	/* */
	step_bits &= step_mask;
	/* */
	STEPPER_XP_GPIO_Port->BSRR = (step_bits & 0x01)? (uint32_t)STEPPER_XP_Pin : (uint32_t)STEPPER_XP_Pin << 16u;
	STEPPER_YP_GPIO_Port->BSRR = (step_bits & 0x02)? (uint32_t)STEPPER_YP_Pin : (uint32_t)STEPPER_YP_Pin << 16u;
	STEPPER_ZP_GPIO_Port->BSRR = (step_bits & 0x04)? (uint32_t)STEPPER_ZP_Pin : (uint32_t)STEPPER_ZP_Pin << 16u;
}

void ngrbl_hal_stepper_timer_base_init(float usec) {
	/* */
	NGRBL_TIMER_BASE_INIT();
}

void ngrbl_hal_stepper_timer_base_irq_start(void) {
	/* */
	if (HAL_TIM_Base_Start_IT(NGRBL_TIMER_BASE) != HAL_OK)	{
    	Error_Handler();
  	}
}

void ngrbl_hal_stepper_timer_base_stop(void) {
	/* */
	if (HAL_TIM_Base_Stop_IT(NGRBL_TIMER_BASE) != HAL_OK)	{
    	Error_Handler();
  	}
}

void ngrbl_hal_stepper_timer_base_set_reload(uint32_t val) {
	/* */
	__HAL_TIM_SET_AUTORELOAD(NGRBL_TIMER_BASE, val);
}

void ngrbl_hal_stepper_timer_base_set_prescaler(uint32_t val) {
	/* */
	__HAL_TIM_SET_PRESCALER(NGRBL_TIMER_BASE, val);
}

void ngrbl_hal_stepper_timer_pulse_init(float usec) {
	/* */
	NGRBL_TIMER_PULSE_INIT();
}

void ngrbl_hal_stepper_timer_pulse_irq_start(void) {
	/* */
	if (HAL_TIM_Base_Start_IT(NGRBL_TIMER_PULSE) != HAL_OK)	{
    	Error_Handler();
  	}
}

void ngrbl_hal_stepper_timer_pulse_stop(void) {
	/* */
	if (HAL_TIM_Base_Stop_IT(NGRBL_TIMER_PULSE) != HAL_OK)	{
    	Error_Handler();
  	}
}

void ngrbl_hal_stepper_timer_pulse_set_reload(uint32_t val) {
	/* */
	__HAL_TIM_SET_AUTORELOAD(NGRBL_TIMER_PULSE, val);
}

void ngrbl_hal_stepper_timer_pulse_set_prescaler(uint32_t val) {
	/* */
	__HAL_TIM_SET_PRESCALER(NGRBL_TIMER_PULSE, val);
}

void ngrbl_hal_stepper_timer_pulse_set_compare(uint32_t val) {
	/* */
	__HAL_TIM_SET_COMPARE(NGRBL_TIMER_PULSE, TIM_CHANNEL_1, val);
}


/* SPINDLE -------------------------------------------------------------------*/
static volatile ngrbl_hal_state_t spindle_state = NGRBL_HAL_DISABLE;

void ngrbl_hal_spindle_init(ngrbl_hal_spindle_mode_t pwm_mode) { /* */ }
uint8_t ngrbl_hal_spindle_get_state(void) { return spindle_state; }
void ngrbl_hal_spindle_start(void) { spindle_state = NGRBL_HAL_ENABLE; }
void ngrbl_hal_spindle_stop(void) { spindle_state = NGRBL_HAL_DISABLE; }
void ngrbl_hal_spindle_set_pwm(uint8_t val) { /* */ }

/* COOLANT -------------------------------------------------------------------*/
static volatile ngrbl_hal_state_t coolant_state = NGRBL_HAL_DISABLE;

void ngrbl_hal_coolant_init(void) { /* */ }
void ngrbl_hal_coolant_start(ngrbl_hal_coolant_flood_mist_t flood_mist) { coolant_state = NGRBL_HAL_ENABLE; }
void ngrbl_hal_coolant_stop(ngrbl_hal_coolant_flood_mist_t flood_mist) { coolant_state = NGRBL_HAL_DISABLE; }
ngrbl_hal_state_t ngrbl_hal_coolant_get_state(ngrbl_hal_coolant_flood_mist_t flood_mist) { return coolant_state; }

/* SYS CONTROL ---------------------------------------------------------------*/
void ngrbl_hal_sys_control_init(void) { /* */ }
uint8_t ngrbl_hal_sys_control_get_state(void) { return 0; }

/* LIMITS --------------------------------------------------------------------*/
static volatile ngrbl_hal_state_t limits_state = NGRBL_HAL_DISABLE;

void ngrbl_hal_limits_init(void) { /* */ }
void ngrbl_hal_limits_set_state(ngrbl_hal_state_t state) { limits_state = state; }
uint8_t ngrbl_hal_limits_get_state(void) { return limits_state; }
void ngrbl_hal_limits_disable(void) { limits_state = NGRBL_HAL_DISABLE; }

/* PROBES --------------------------------------------------------------------*/
void ngrbl_hal_probe_init(void) { /* */ }
uint8_t ngrbl_hal_probe_get_state(void) { return NGRBL_HAL_DISABLE; }

/* EEPROM --------------------------------------------------------------------*/
uint8_t ngrbl_hal_eeprom_read_byte(uint16_t addr) {
	uint16_t rdata = 0;
	EE_ReadVariable(addr, &rdata);
	return (uint8_t)rdata;
}
void ngrbl_hal_eeprom_write_byte(uint16_t addr, uint8_t new_value) {
	/* */
	EE_WriteVariable(addr, new_value);
}

/* SERIAL --------------------------------------------------------------------*/
static volatile ngrbl_hal_state_t serial_rx_buf[64];

void ngrbl_hal_serail_init(uint32_t baudrate) { HAL_UART_Receive_IT(&huart1, (uint8_t*)serial_rx_buf, 1);
}

void ngrbl_hal_serial_write_byte(uint8_t data) {
	HAL_UART_Transmit_IT(&huart1, &data, 1);
}

void ngrbl_hal_serail_stop_tx(void) {
	HAL_UART_AbortTransmit(&huart1);
}

/* SERIAL CALLBACKS */

// void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
// 	ngrbl_hal_serial_tx_callback();`
// }
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
// 	ngrbl_hal_serial_rx_callback( huart->pRxBuffPtr, huart->RxXferSize );
// }

/* UTILS ---------------------------------------------------------------------*/
void ngrbl_hal_delay_ms(uint16_t val) { /* */ }


/******************************************************************************
      END FILE
******************************************************************************/