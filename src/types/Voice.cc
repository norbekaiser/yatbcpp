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
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/Voice.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Voice::Voice(std::string file_id, int duration):
        file_id(file_id), duration(duration)
{

}

Voice::Voice(const Voice& Voice):
        file_id(Voice.file_id), duration(Voice.duration)
{
    mime_type = Voice.mime_type;
    file_size = Voice.file_size;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Voice::setMime_type(const optional<string> &mime_type) {
    Voice::mime_type = mime_type;
}

void Voice::setFile_size(const optional<int> &file_size) {
    Voice::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Voice::getFile_id() const {
    return file_id;
}

int Voice::getDuration() const {
    return duration;
}

const optional<string> &Voice::getMime_type() const {
    return mime_type;
}

const optional<int> &Voice::getFile_size() const {
    return file_size;
}

