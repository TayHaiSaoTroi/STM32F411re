#include <HAL_STM32F411_GPIO.h>
#include <HAL_STM32F411_RCC.h>
#include <stdio.h>
#include <stdint.h>


int main(void)
{

	HAL_GPIOA_ENABLE_CLOCK();

	GPIO_Config_t pinConfig;
	pinConfig.PinNumber = GPIO_PIN_5;      // Sử dụng chân số 5
	pinConfig.Mode = GPIO_OUTPUT;           // Output mode
	pinConfig.Speed = HIGH_SPEED;          // High speed
	pinConfig.Pull_up_down = NO_PULL;   // No pull-up/pull-down
	pinConfig.Otype = OUPUT_PUSHPULL;          // Push-pull
	pinConfig.AltMode = 0;        // Không dùng chế độ thay thế

	GPIO_INIT(GPIOA, &pinConfig);

	GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_SET);
}
