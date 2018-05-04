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
#include <iostream>
#include "types/InlineQueryResultCachedAudio.h"

using namespace yatbcpp;
using namespace std;

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(std::string id, std::string audio_file_id):
        InlineQueryResult("audio",id),
        audio_file_id(audio_file_id)
{

}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(const InlineQueryResultCachedAudio& InlineQueryResultCachedAudio): 
    InlineQueryResult(InlineQueryResultCachedAudio.type,InlineQueryResultCachedAudio.id), 
    audio_file_id(InlineQueryResultCachedAudio.audio_file_id)
{
    caption = InlineQueryResultCachedAudio.caption;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Outgoing Section                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Json::Value InlineQueryResultCachedAudio::toJson(){
    std::cout << "VoiceJSON" << std::endl;
    Json::Value Outgoing;
    Outgoing["type"] = getType();//since this is inherited, get it from above?
    Outgoing["id"] = getId();
    Outgoing["audio_file_id"] = getAudio_file_id();
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

const string &InlineQueryResultCachedAudio::getAudio_file_id() const {
    return audio_file_id;
}

const optional<string> &InlineQueryResultCachedAudio::getCaption() const {
    return caption;
}
