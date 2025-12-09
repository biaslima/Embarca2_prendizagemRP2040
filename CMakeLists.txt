# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Tarefa_Aprendizagem_09-12 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Adicionar TensorFlow Lite Micro
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/pico-tflmicro/CMakeLists.txt")
    message(STATUS "✓ pico-tflmicro encontrado!")
    add_subdirectory(pico-tflmicro EXCLUDE_FROM_ALL)
else()
    message(FATAL_ERROR "✗ pico-tflmicro não encontrado! Execute: git clone https://github.com/raspberrypi/pico-tflmicro.git")
endif()

# Add executable. Default name is the project name, version 0.1
add_executable(Tarefa_Aprendizagem_09-12 
    main.c
    tflm_wrapper.cpp
)

pico_set_program_name(Tarefa_Aprendizagem_09-12 "Tarefa_Aprendizagem_09-12")
pico_set_program_version(Tarefa_Aprendizagem_09-12 "0.1")

# IMPORTANTE: Habilitar USB para ver mensagens no serial
pico_enable_stdio_uart(Tarefa_Aprendizagem_09-12 0)
pico_enable_stdio_usb(Tarefa_Aprendizagem_09-12 1)

# Add the standard library to the build
target_link_libraries(Tarefa_Aprendizagem_09-12
    pico_stdlib
    pico-tflmicro
)

# Add the standard include files to the build
target_include_directories(Tarefa_Aprendizagem_09-12 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Tarefa_Aprendizagem_09-12)
