#    Copyright (c) 2017 Norbert Rühl
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
# Install Target                                                                                                        #
########################################################################################################################
include(GenerateExportHeader)
generate_export_header(yatbcpp)
set_property(TARGET yatbcpp PROPERTY VERSION ${yatbcpp_VERSION})
set_property(TARGET yatbcpp PROPERTY SOVERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp PROPERTY INTERFACE_yatbcpp_MAJOR_VERSION ${yatbcpp_MAJOR_VERSION})
set_property(TARGET yatbcpp APPEND PROPERTY COMPATIBLE_INTERFACE_STRING yatbcpp_MAJOR_VERSION)


install(TARGETS yatbcpp EXPORT yatbcppTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)

########################################################################################################################
# Main Headers from root and main include header                                                                       #
########################################################################################################################

install(
        FILES
        yatbcpp.h
        ${yatbcppHeadersList}
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp_export.h"
        DESTINATION
        include/yatbcpp
        COMPONENT
        Devel
)

########################################################################################################################
# Type Headers                                                                                                         #
########################################################################################################################

install(
        FILES
        ${yatbcppTypesHeadersList}
        DESTINATION
        include/yatbcpp/types/
        COMPONENT
        Devel
)

########################################################################################################################
# Exception Headers                                                                                                    #
########################################################################################################################

install(
        FILES
        ${yatbcppExceptionsHeadersList}
        DESTINATION
        include/yatbcpp/exceptions/
        COMPONENT
        Devel
)



install(EXPORT yatbcppTargets
        FILE
#        yatbcpp.cmake
        yatbcppTargets.cmake
        NAMESPACE
        yatbcpp::
        DESTINATION
        ${ConfigPackageLocation}
        )

install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfigVersion.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/yatbcpp/yatbcppTargets.cmake"
        DESTINATION
        ${ConfigPackageLocation}
        COMPONENT
        Devel
)
