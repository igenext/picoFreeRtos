#include<stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void Task1(void* param);
void Task2(void* param);


int main()
{
    stdio_init_all();
    xTaskCreate(Task1, "Task1",2048,NULL,4,NULL);
    xTaskCreate(Task2, "Task2",2048,NULL,5,NULL);
    vTaskStartScheduler();
    for(;;)
    return 0;
}

void Task1(void* param)
{
    for(;;)
    {
        printf("Task1 :  Hey Task2, I'm running\n");
        vTaskDelay(100 / portTICK_PERIOD_MS );
    }
}

void Task2(void* param)
{
    for(;;)
    {
        printf("Task2 :  Hmmm, It's my Turn now, See I've Preempted, I won't allow you to run\n");
        vTaskDelay(10 / portTICK_PERIOD_MS );
    }
}