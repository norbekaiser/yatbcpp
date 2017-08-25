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
#include "types/Video.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Video::Video(std::string file_id, int width, int height,int duration) : file_id(file_id), width(width), height(height), duration(duration)
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generation Section                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Returns A Video based on a Json Object
 * @param Data   a Json Object Containing the necessary and Optional Fields
 * @return Parsed Video
 */
Video Video::fromJson(Json::Value Data) {
    if(!Data.isMember("file_id")){
        throw essential_key_missing("Video::file_id is missing");
    }
    if(!Data.isMember("width")){
        throw essential_key_missing("Video::width is missing");
    }
    if(!Data.isMember("height")){
        throw essential_key_missing("Video::height is missing");
    }
    if(!Data.isMember("duration")){
        throw essential_key_missing("Video::duration is missing");
    }

    std::string file_id = Data["file_id"].asString();
    int width = Data["width"].asInt();
    int height = Data["height"].asInt();
    int duration = Data["duration"].asInt();

    Video ret(file_id,width,height,duration);

    if(Data.isMember("thumb")){
        ret.setThumb(PhotoSize::fromJson(Data["thumb"]));
    }
    if(Data.isMember("mime_type")){
        ret.setMime_type(Data["mime_type"].asString());
    }
    if(Data.isMember("file_size")){
        ret.setFile_size(Data["file_size"].asInt());
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Video::setThumb(const optional<PhotoSize> &thumb) {
    Video::thumb = thumb;
}

void Video::setMime_type(const optional<string> &mime_type) {
    Video::mime_type = mime_type;
}

void Video::setFile_size(const optional<int> &file_size) {
    Video::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Video::getFile_id() const {
    return file_id;
}

int Video::getWidth() const {
    return width;
}

int Video::getHeight() const {
    return height;
}

int Video::getDuration() const {
    return duration;
}

const optional<PhotoSize> &Video::getThumb() const {
    return thumb;
}

const optional<string> &Video::getMime_type() const {
    return mime_type;
}

const optional<int> &Video::getFile_size() const {
    return file_size;
}

