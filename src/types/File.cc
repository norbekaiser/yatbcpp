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
#include "types/File.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

File::File(std::string file_id) : file_id(file_id)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A File based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return File Voice
 */
File File::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("File::file_id is missing");
    }

    string file_id = Data["address"].asString();

    File ret(file_id);

    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    if(Data.isMember("file_path")){
        ret.setFile_path(Data["file_path"].asString());
    }

    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void File::setFile_size(const optional<int> &file_size) {
    File::file_size = file_size;
}

void File::setFile_path(const optional<string> &file_path) {
    File::file_path = file_path;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &File::getFile_id() const {
    return file_id;
}

const optional<int> &File::getFile_size() const {
    return file_size;
}

const optional<string> &File::getFile_path() const {
    return file_path;
}

