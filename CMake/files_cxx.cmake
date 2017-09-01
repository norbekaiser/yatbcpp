#    Copyright (c) 2017 Norbert Rühl
#    
#    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
#    
#    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
#    
#        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
#    
#        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
#    
#        3. This notice may not be removed or altered from any source distribution.
########################################################################################################################
# Telegram Bot Source Files                                                                                            #
########################################################################################################################
set(SOURCE_FILES_OSTREAM_OPERATOR
        src/ostream/curl_error_ostream.cc
        src/ostream/exception_essential_key_missing_ostream.cc
        src/ostream/exception_file_not_found_ostream.cc
        src/ostream/telegram_api_error_ostream.cc
        src/ostream/User_ostream.cc
        )
set(SOURCE_FILES_EXCEPTIONS ${yatbcppExceptionsHeadersList}
        src/exceptions/essential_key_missing.cc
        src/exceptions/file_not_found.cc
        src/exceptions/telegram_api_error.cc
        src/exceptions/curl_error.cc
        )

set(SOURCE_FILES_TYPES ${yatbcppTypesHeadersList}
        src/types/Audio.cc
        src/types/Chat.cc
        src/types/ChatMember.cc
        src/types/ChatPhoto.cc
        src/types/Contact.cc
        src/types/Document.cc
        src/types/KeyboardButton.cc
        src/types/File.cc
        src/types/ForceReply.cc
        src/types/Location.cc
        src/types/Message.cc
        src/types/MessageEntity.cc
        src/types/PhotoSize.cc
        src/types/ReplyKeyboardMarkup.cc
        src/types/ReplyKeyboardRemove.cc
        src/types/Update.cc
        src/types/User.cc
        src/types/UserProfilePhotos.cc
        src/types/Venue.cc
        src/types/Video.cc
        src/types/VideoNote.cc
        src/types/Voice.cc
        )

set(SOURCE_FILE_TYPES_FROMJSON ${yatbcppTypesHeadersList}
        src/types_fromJson/Audio_fromJson.cc
        src/types_fromJson/Chat_fromJson.cc
        src/types_fromJson/ChatMember_fromJson.cc
        src/types_fromJson/ChatPhoto_fromJson.cc
        src/types_fromJson/Contact_fromJson.cc
        src/types_fromJson/Document_fromJson.cc
        src/types_fromJson/File_fromJson.cc
        src/types_fromJson/KeyboardButton_fromJson.cc
        src/types_fromJson/Location_fromJson.cc
        src/types_fromJson/Message_fromJson.cc
        src/types_fromJson/MessageEntity_fromJson.cc
        src/types_fromJson/PhotoSize_fromJson.cc
        src/types_fromJson/ReplyKeyboardMarkup_fromJson.cc
        src/types_fromJson/Update_fromJson.cc
        src/types_fromJson/User_fromJson.cc
        src/types_fromJson/UserProfilePhotos_fromJson.cc
        src/types_fromJson/Venue_fromJson.cc
        src/types_fromJson/Video_fromJson.cc
        src/types_fromJson/VideoNote_fromJson.cc
        src/types_fromJson/Voice_fromJson.cc
        )

set(SOURCE_FILES_METHODS ${yatbcppMethodsHeadersList}
        src/methods/forwardMessage.cc
        src/methods/getMe.cc
        src/methods/sendAudio.cc
        src/methods/sendMessage.cc
        src/methods/sendPhoto.cc
        )

set(SOURCE_FILES_BOT ${yatbcppBotHeadersList}
        src/bot/Token.cc
        src/bot/Bot.cc
        )