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
#include "types/PhotoSize.h"
#include "types/Document.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Document::Document(std::string file_id):
        file_id(file_id)
{

}

Document::Document(const Document& Document):
        file_id(Document.file_id)
{
    thumb = Document.thumb;
    file_name = Document.file_name;
    mime_type = Document.mime_type;
    file_size = Document.file_size;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Document::setThumb(const optional<PhotoSize> &thumb) {
    Document::thumb = thumb;
}

void Document::setFile_name(const optional<string> &file_name) {
    Document::file_name = file_name;
}

void Document::setMime_type(const optional<string> &mime_type) {
    Document::mime_type = mime_type;
}

void Document::setFile_size(const optional<int> &file_size) {
    Document::file_size = file_size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &Document::getFile_id() const {
    return file_id;
}

const optional<PhotoSize> &Document::getThumb() const {
    return thumb;
}

const optional<string> &Document::getFile_name() const {
    return file_name;
}

const optional<string> &Document::getMime_type() const {
    return mime_type;
}

const optional<int> &Document::getFile_size() const {
    return file_size;
}
