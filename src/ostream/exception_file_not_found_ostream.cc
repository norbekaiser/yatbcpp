//    Copyright (c) 2017,2018 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.
//
// Created by norbert on 21.08.17.
//

#include <ostream>
#include <exceptions/file_not_found.h>
namespace yatbcpp {

    std::ostream& operator<< (std::ostream &o,const file_not_found& fileNotFound) {
        using namespace std;
        return o << "FILE_NOT_FOUND EXCEPTION<<" << fileNotFound.message << ">>";
    }
    std::ostream& operator<< (std::ostream &o,const file_not_found* fileNotFound) {
        return o<<*fileNotFound;
    }

}
