cmake_minimum_required(VERSION 2.6)

project("Argentum Online Client")

# include folder
include_directories(include)

set(ProjectName Client)

# C++11
add_compile_options(-std=c++11)

set(SourceObj 
    src/Main.cpp 
    src/Debug.cpp
    src/Engine.cpp
    src/Transform.cpp
    src/GameObject.cpp
    src/GameObjectManager.cpp
    src/RenderManager.cpp
    src/Bounds.cpp
    )

# Glew Library
find_package(GLEW REQUIRED)
if(GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# glfw3
find_package(glfw3 REQUIRED)

add_executable(${ProjectName} ${SourceObj})

target_include_directories(${ProjectName} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${ProjectName} glfw ${OPENGL_gl_LIBRARY})
