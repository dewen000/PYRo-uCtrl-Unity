#include "PYRo_gpio_drv.h"

pyro_gpio_drv_t::pyro_gpio_drv_t(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    _port = GPIOx;
    _pin  = GPIO_Pin;
}

pyro_gpio_drv_t::state_t pyro_gpio_drv_t::read(void)
{
    _state = (state_t)HAL_GPIO_ReadPin(_port, _pin);
    return _state;
}

void pyro_gpio_drv_t::write(pyro_gpio_drv_t::state_t state)
{
    HAL_GPIO_WritePin(_port, 
                   _pin,
                  (GPIO_PinState)state);
}

void pyro_gpio_drv_t::toogle(void)
{
    HAL_GPIO_TogglePin(_port, _pin);
}