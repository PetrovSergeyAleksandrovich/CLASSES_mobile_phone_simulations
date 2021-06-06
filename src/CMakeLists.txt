cmake_minimum_required(VERSION 3.19)

add_executable(
        CLASSES_mobile_phone_simulations
        main.cpp
        Phone_t.cpp)

target_include_directories(CLASSES_mobile_phone_simulations PUBLIC ${MY_INCLUDE_DIR})