cmake_minimum_required(VERSION 3.18)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

  

project(picoFreertos LANGUAGES C CXX ASM)

set( FREERTOS_PORT "GCC_ARM_CM0" CACHE STRING "" FORCE)
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config INTERFACE ./include) # The config file directory
target_compile_definitions(freertos_config PUBLIC)
add_subdirectory(./FreeRTOS-Kernel)


add_executable(main src/main.c 
    
    FreeRTOS-Kernel/event_groups.c
    FreeRTOS-Kernel/list.c
    FreeRTOS-Kernel/queue.c
    FreeRTOS-Kernel/stream_buffer.c
    FreeRTOS-Kernel/tasks.c 
    FreeRTOS-Kernel/timers.c
    FreeRTOS-Kernel/portable/MemMang/heap_3.c
    FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/port.c
    #FreeRTOS-Kernel/portable/GCC/ARM_CM0/portasm.c 
    )
    
  

target_link_libraries(main pico_stdlib hardware_exception freertos_config)
include(~/picoFreeRtos/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
target_include_directories(main PUBLIC FreeRTOS-Kernel/include FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/include )

pico_sdk_init()

pico_add_extra_outputs(main)

pico_enable_stdio_usb(main 1)


