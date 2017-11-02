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
#include <iostream>
#include "types/InlineQueryResultCachedVoice.h"

using namespace yatbcpp;
using namespace std;

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(std::string id,std::string voice_file_id,std::string title):
        InlineQueryResult("voice",id),
        voice_file_id(voice_file_id), title(title)
{

}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(const InlineQueryResultCachedVoice& InlineQueryResultCachedVoice):
    InlineQueryResult(InlineQueryResultCachedVoice.type,InlineQueryResultCachedVoice.id),
    voice_file_id(InlineQueryResultCachedVoice.voice_file_id), title(InlineQueryResultCachedVoice.title)
{
    caption = InlineQueryResultCachedVoice.caption;
}


Json::Value InlineQueryResultCachedVoice::toJson(){
    std::cout << "VoiceJSON" << std::endl;
    Json::Value Outgoing;
    Outgoing["type"] = getType();//since this is inherited, get it from above?
    Outgoing["id"] = getId();
    Outgoing["voice_file_id"] = getVoice_file_id();
    Outgoing["title"] = getTitle();
    if(getCaption()){
        Outgoing["caption"] = getCaption().value();
    }
    //TODO reply markup and input message content
    return  Outgoing;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string &InlineQueryResultCachedVoice::getVoice_file_id() const {
    return voice_file_id;
}

const string &InlineQueryResultCachedVoice::getTitle() const {
    return title;
}

const optional<string> &InlineQueryResultCachedVoice::getCaption() const {
    return caption;
}
