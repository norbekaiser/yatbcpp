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
# Verifying Additional Library Requirments which should be there for linking later on                                  #
########################################################################################################################

########################################################################################################################
# LibCurl for Obtaining the Json Objects                                                                               #
########################################################################################################################
find_package(CURL REQUIRED)
if(CURL_FOUND)
    message(STATUS "CURL found")
    message(STATUS "CURL Include DIR" ${CURL_INCLUDE_DIRS})
    include_directories( ${CURL_INCLUDE_DIRS})
endif()


########################################################################################################################
# LibJsonCPP for Parsing JsonObjects                                                                                   #
########################################################################################################################
find_package(jsoncpp REQUIRED)
if(jsoncpp_FOUND)
    message(STATUS "jsoncpp found")
#    message(STATUS "jsoncpp Include DIR" ${jsoncpp_INCLUDE_DIR})
#    include_directories( ${JSONCPP_INCLUDE_DIR})
endif()
