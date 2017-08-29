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
#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/VideoNote.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VideoNote::VideoNote(std::string file_id, int length, int duration) : file_id(file_id), length(length), duration(duration)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VideoNote::setThumb(const optional<PhotoSize> &thumb) {
    VideoNote::thumb = thumb;
}

void VideoNote::setFile_size(const optional<int> &file_size) {
    VideoNote::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &VideoNote::getFile_id() const {
    return file_id;
}

int VideoNote::getLength() const {
    return length;
}

int VideoNote::getDuration() const {
    return duration;
}

const optional<PhotoSize> &VideoNote::getThumb() const {
    return thumb;
}

const optional<int> &VideoNote::getFile_size() const {
    return file_size;
}
