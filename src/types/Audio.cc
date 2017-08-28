//    Copyright (c) 2017 Norbert Rühl
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
// Created by norbert on 23.08.17.
//

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include <jsoncpp/json/json.h>
#include "exceptions/essential_key_missing.h"
#include "types/Audio.h"


using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Audio::Audio(std::string file_id, int duration) : file_id(file_id), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Audio::setPerformer(const optional<string> &performer) {
    Audio::performer = performer;
}

void Audio::setTitle(const optional<string> &title) {
    Audio::title = title;
}

void Audio::setMime_type(const optional<string> &mime_type) {
    Audio::mime_type = mime_type;
}

void Audio::setFile_size(const optional<int> &file_size) {
    Audio::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Audio::getFile_id() const {
    return file_id;
}

int Audio::getDuration() const {
    return duration;
}

const optional<string> &Audio::getPerformer() const {
    return performer;
}

const optional<string> &Audio::getTitle() const {
    return title;
}

const optional<string> &Audio::getMime_type() const {
    return mime_type;
}

const optional<int> &Audio::getFile_size() const {
    return file_size;
}
