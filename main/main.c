/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "esp_system.h"
#include "nvs_flash.h"
#include <rtthread.h>
#include <board.h>
#include <shell.h>
#include <msh.h>

extern long list_thread(void);
extern int cmd_time(int argc, char **argv);

void app_main()
{
    nvs_flash_init();
    //
    rt_hw_board_init();
    rt_show_version();
    //
#ifdef RT_USING_FINSH
    cmd_time(0,0);
    finsh_system_init();
    finsh_set_device(FINSH_DEVICE_NAME);
#endif
    //
    while (1)
    {
        rt_thread_delay(rt_tick_from_millisecond(1000));
    }
}
