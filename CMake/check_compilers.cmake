#    Copyright (c) 2017,2018 Norbert Rühl
#    
#    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
#    
#    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
#    
#        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
#    
#        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
#    
#        3. This notice may not be removed or altered from any source distribution.
########################################################################################################################
# Verifying Compiler Compability                                                                                       #
########################################################################################################################
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++1z" COMPILER_SUPPORTS_CXX1Z)

########################################################################################################################
# Verifying Compiler Compability C++17                                                                                 #
########################################################################################################################
if(COMPILER_SUPPORTS_CXX17)
    set(CMAKE_CXX_FLAGS "-std=c++17")
    message(STATUS "The Compiler ${CMAKE_CXX_COMPILER} has C++17 support. It is now enabled.")
elseif(COMPILER_SUPPORTS_CXX1Z)
    set(CMAKE_CXX_FLAGS "-std=c++1z")
    message(STATUS "The Compiler ${CMAKE_CXX_COMPILER} has experimental C++17 support. It is now enabled.")
else()
    message(FATAL_ERROR "The Compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ Compiler")
endif()
