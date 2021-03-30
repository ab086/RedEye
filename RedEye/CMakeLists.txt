cmake_minimum_required(VERISON 2.6)

set(PROJECT_NAME RedEye)
project(${PROJECT_NAME})

set(HAVE_LIBC TRUE)
set(src
    main.cpp
)

set(headers

)

add_executable(${PROJECT_NAME} ${src} ${headers})

find_package(Vulkan)

if(Vulkan_FOUND)
    TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE Vulakn::Vulkan)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} Vulkan::Vulkan)
endif()