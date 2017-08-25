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
#include "types/PhotoSize.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PhotoSize::PhotoSize(std::string file_id, int width, int height) : file_id(file_id), width(width), height(height)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A PhotoSize based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed PhotoSize
 */
PhotoSize PhotoSize::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("PhotoSize::file_id is missing");
    }
    if(!Data.isMember("width")){
        throw essential_key_missing("PhotoSize::width is missing");
    }
    if(!Data.isMember("height")){
        throw essential_key_missing("PhotoSize::height is missing");
    }

    std::string file_id = Data["file_id"].asString();
    int width = Data["width"].asInt();
    int height = Data["height"].asInt();

    PhotoSize ret(file_id,width,height);

    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    return ret;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PhotoSize::setFile_size(const optional<int> &file_size) {
    PhotoSize::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &PhotoSize::getFile_id() const {
    return file_id;
}

int PhotoSize::getWidth() const {
    return width;
}

int PhotoSize::getHeight() const {
    return height;
}

const optional<int> &PhotoSize::getFile_size() const {
    return file_size;
}

