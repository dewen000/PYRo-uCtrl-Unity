#ifndef __PYRO_CORE_DEF_H__
#define __PYRO_CORE_DEF_H__

enum pyro_status_t
{
    PYRO_ERROR   = 0x00,
    PYRO_OK      = 0x01,
    PYRO_BUSY    = 0X02,
    PYRO_TIMEOUT = 0X03,
};

#define CHECK_HAL_RET(ret)        if(HAL_OK != ret)           \
                                  {                           \
                                    return PYRO_ERROR;        \
                                  }                                    

#define CHECK_OS_RET(ret)         if(pdPASS != ret)           \
                                  {                           \
                                    return PYRO_ERROR;        \
                                  }    

#ifdef USE_LOG
#define PYRO_ASSERT_RET(expr)((expr) ? PYRO_OK : log((uint8_t *)__FILE__, __LINE__))
#else
#define PYRO_ASSERT_RET(expr) ((void)0U
#endif
#define PYRO_ASSERT_RET_BLOCK(expr) ((expr) ? PYRO_OK : do{}while(1))
                                  
#endif
