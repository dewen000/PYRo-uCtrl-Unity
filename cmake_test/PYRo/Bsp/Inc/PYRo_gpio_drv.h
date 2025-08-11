#ifndef __PYRO_GPIO_DRV_H__
#define __PYRO_GPIO_DRV_H__

#include "stm32h7xx_hal.h"      // IWYU pragma: keep
#include "stm32h7xx_hal_gpio.h" // IWYU pragma: keep

#include "PYRo_core_def.h"

#include <functional>

class pyro_gpio_drv_t
{
public:
    enum state_t
    {
        RESET = 0,
        SET   = 1,
    };
    pyro_gpio_drv_t(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
    state_t read(void);
    void write(state_t);
    void toogle(void);
private:    
    GPIO_TypeDef *_port;
    uint32_t      _pin;
    state_t       _state;

    static void port_callback(void);  
};


#endif
