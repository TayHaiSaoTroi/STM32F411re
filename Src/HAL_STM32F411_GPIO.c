/*
 * ETP_STM32F401_GPIO.c
 *
 *  Created on: Nov 15, 2024
 *      Author: Admins
 */


#include <HAL_STM32F411_GPIO.h>


void GPIO_INIT(GPIO_t *GPIOx, GPIO_Config_t *GPIO_Config)
{
    // 1. Cấu hình chế độ (Input, Output, Alternate, Analog)
    GPIOx->MODER &= ~(0x3U << (GPIO_Config->PinNumber * 2)); // Xóa các bit hiện tại
    GPIOx->MODER |= (GPIO_Config->Mode << (GPIO_Config->PinNumber * 2)); // Đặt chế độ mới

    // 2. Cấu hình Output type (Push-pull hoặc Open-drain)
    GPIOx->OTYPER &= ~(0x1U << GPIO_Config->PinNumber); // Xóa bit hiện tại
    GPIOx->OTYPER |= (GPIO_Config->Otype << GPIO_Config->PinNumber); // Đặt kiểu mới

    // 3. Cấu hình tốc độ (Low, Medium, Fast, High)
    GPIOx->OSPEEDR &= ~(0x3U << (GPIO_Config->PinNumber * 2)); // Xóa các bit hiện tại
    GPIOx->OSPEEDR |= (GPIO_Config->Speed << (GPIO_Config->PinNumber * 2)); // Đặt tốc độ mới

    // 4. Cấu hình Pull-up / Pull-down
    GPIOx->PUPDR &= ~(0x3U << (GPIO_Config->PinNumber * 2)); // Xóa các bit hiện tại
    GPIOx->PUPDR |= (GPIO_Config->Pull_up_down << (GPIO_Config->PinNumber * 2)); // Đặt giá trị mới

    // 5. Cấu hình chức năng Alternate Function (nếu cần)
    if (GPIO_Config->Mode == 2) // Alternate function mode
    {
        if (GPIO_Config->PinNumber < 8)
        {
            GPIOx->AFR[0] &= ~(0xFU << (GPIO_Config->PinNumber * 4)); // Xóa bit hiện tại
            GPIOx->AFR[0] |= (GPIO_Config->AltMode << (GPIO_Config->PinNumber * 4)); // Đặt chức năng thay thế
        }
        else
        {
            GPIOx->AFR[1] &= ~(0xFU << ((GPIO_Config->PinNumber - 8) * 4)); // Xóa bit hiện tại
            GPIOx->AFR[1] |= (GPIO_Config->AltMode << ((GPIO_Config->PinNumber - 8) * 4)); // Đặt chức năng thay thế
        }
    }
}

uint8 GPIO_ReadPin(GPIO_t *GPIOx, uint8 PinNumber)
{
	uint8 value;
	value = ((GPIOx->IDR >> PinNumber) &0x01);
	return value;
}

void GPIO_WritePin(GPIO_t *GPIOx, uint8 PinNumber, uint8 State)
{
	if(State==GPIO_PIN_SET)
	{
		GPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
		GPIOx->ODR &=~ (1<<PinNumber);
	}

}

void GPIO_TogglePin(GPIO_t *GPIOx, uint8 PinNumber)
{
	GPIOx->ODR ^= (1<<PinNumber);
}
