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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Message Object , represents an incoming message according to bot api definition as close as possible                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#if __has_include(<optional>) 
#include <optional> 
#else 
#include <experimental/optional> 
#define optional experimental::optional 
#endif 
#include "types/User.h"
#include "types/Chat.h"
#include "types/MessageEntity.h"
#include "types/Audio.h"
#include "types/Document.h"
#include "types/Video.h"
#include "types/Voice.h"
#include "types/VideoNote.h"
#include "types/Contact.h"
#include "types/Location.h"
#include "types/Venue.h"
#include "types/Message.h"

using namespace yatbcpp;
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor Section                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message::Message(int32_t message_id, int32_t date, Chat chat):
        message_id(message_id), date(date), chat(chat)
{

}

Message::Message(const Message& Message):
        message_id(Message.message_id), date(Message.date), chat(Message.chat)
{
    from = Message.from;
    forward_from = Message.forward_from;
    forward_from_chat = Message.forward_from_chat;
    forward_from_message_id = Message.forward_from_message_id;
    forward_signature = Message.forward_signature;
    forward_date = Message.forward_date;
    edit_date = Message.edit_date;
    author_signature = Message.author_signature;
    text = Message.text;
    entities = Message.entities;
    audio = Message.audio;
    document = Message.document;
    photo = Message.photo;
    video = Message.video;
    voice = Message.voice;
    video_note = Message.video_note;
    //TODO complete
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Message::setFrom(const optional<User> &from) {
    Message::from = from;
}

void Message::setForward_from(const optional<User> &forward_from) {
    Message::forward_from = forward_from;
}

void Message::setForward_from_chat(const optional<Chat> &forward_from_chat) {
    Message::forward_from_chat = forward_from_chat;
}

void Message::setForward_from_message_id(const optional<int32_t> &forward_from_message_id) {
    Message::forward_from_message_id = forward_from_message_id;
}

void Message::setForward_signature(const optional<string> &forward_signature) {
    Message::forward_signature = forward_signature;
}

void Message::setForward_date(const optional<int32_t> &forward_date) {
    Message::forward_date = forward_date;
}

//void Message::setReply_to_message(const optional<Message *> &reply_to_message) {
//    Message::reply_to_message = reply_to_message;
//}

void Message::setEdit_date(const optional<int32_t> &edit_date) {
    Message::edit_date = edit_date;
}

void Message::setAuthor_signature(const optional<string> &author_signature) {
    Message::author_signature = author_signature;
}

void Message::setText(const optional<string> &text) {
    Message::text = text;
}

void Message::addEntity(const MessageEntity &messageEntity){
    entities.push_back(messageEntity);
}

void Message::setAudio(const optional<Audio> &audio) {
    Message::audio = audio;
}

void Message::setDocument(const optional<Document> &document) {
    Message::document = document;
}

//todo game

void Message::addPhoto(const PhotoSize &Photo) {
    photo.push_back(Photo);
}

//todo sticker

void Message::setVideo(const optional<Video> &video) {
    Message::video = video;
}

void Message::setVoice(const optional<Voice> &voice) {
    Message::voice = voice;
}

void Message::setVideo_note(const optional<VideoNote> &video_note) {
    Message::video_note = video_note;
}

void Message::addNew_chat_members(const User &new_chat_member) {
    new_chat_members.push_back(new_chat_member);
}

void Message::setCaption(const optional<string> &caption) {
    Message::caption = caption;
}

void Message::setContact(const optional<Contact> &contact) {
    Message::contact = contact;
}

void Message::setLocation(const optional<Location> &location) {
    Message::location = location;
}

void Message::setVenue(const optional<Venue> &venue) {
    Message::venue = venue;
}

void Message::setNew_chat_member(const optional<User> &new_chat_member) {
    Message::new_chat_member = new_chat_member;
}

void Message::setLeft_chat_member(const optional<User> &left_chat_member) {
    Message::left_chat_member = left_chat_member;
}

void Message::setNew_chat_title(const optional<string> &new_chat_title) {
    Message::new_chat_title = new_chat_title;
}

void Message::addNew_chat_photo(const PhotoSize &newchatphoto) {
    new_chat_photo.push_back(newchatphoto);
}

void Message::setDelete_chat_photo(const optional<bool> &delete_chat_photo) {
    Message::delete_chat_photo = delete_chat_photo;
}

void Message::setGroup_chat_created(const optional<bool> &group_chat_created) {
    Message::group_chat_created = group_chat_created;
}

void Message::setSupergroup_chat_created(const optional<bool> &supergroup_chat_created) {
    Message::supergroup_chat_created = supergroup_chat_created;
}

void Message::setChannel_chat_created(const optional<bool> &channel_chat_created) {
    Message::channel_chat_created = channel_chat_created;
}

void Message::setMigrate_to_chat_id(const optional<long> &migrate_to_chat_id) {
    Message::migrate_to_chat_id = migrate_to_chat_id;
}

void Message::setMigrate_from_chat_id(const optional<long> &migrate_from_chat_id) {
    Message::migrate_from_chat_id = migrate_from_chat_id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter Section                                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int32_t Message::getMessage_id() const {
    return message_id;
}

const optional<User> &Message::getFrom() const {
    return from;
}

int32_t Message::getDate() const {
    return date;
}

const Chat &Message::getChat() const {
    return chat;
}

const optional<User> &Message::getForward_from() const {
    return forward_from;
}

const optional<Chat> &Message::getForward_from_chat() const {
    return forward_from_chat;
}

const optional<int32_t> &Message::getForward_from_message_id() const {
    return forward_from_message_id;
}

const optional<string> &Message::getForward_signature() const {
    return forward_signature;
}

const optional<int32_t> &Message::getForward_date() const {
    return forward_date;
}

//const optional<Message *> &Message::getReply_to_message() const {
//    return reply_to_message;
//}

const optional<int32_t> &Message::getEdit_date() const {
    return edit_date;
}

const optional<string> &Message::getAuthor_signature() const {
    return author_signature;
}

const optional<string> &Message::getText() const {
    return text;
}

const vector<MessageEntity> &Message::getEntities() const {
    return entities;
}

const optional<Audio> &Message::getAudio() const {
    return audio;
}

const optional<Document> &Message::getDocument() const {
    return document;
}

const vector<PhotoSize> &Message::getPhoto() const {
    return photo;
}

const optional<Video> &Message::getVideo() const {
    return video;
}

const optional<Voice> &Message::getVoice() const {
    return voice;
}

const optional<VideoNote> &Message::getVideo_note() const {
    return video_note;
}

const vector<User> &Message::getNew_chat_members() const {
    return new_chat_members;
}

const optional<string> &Message::getCaption() const {
    return caption;
}

const optional<Contact> &Message::getContact() const {
    return contact;
}

const optional<Location> &Message::getLocation() const {
    return location;
}

const optional<Venue> &Message::getVenue() const {
    return venue;
}

const optional<User> &Message::getNew_chat_member() const {
    return new_chat_member;
}

const optional<User> &Message::getLeft_chat_member() const {
    return left_chat_member;
}

const optional<string> &Message::getNew_chat_title() const {
    return new_chat_title;
}

const vector<PhotoSize> &Message::getNew_chat_photo() const {
    return new_chat_photo;
}

const optional<bool> &Message::getDelete_chat_photo() const {
    return delete_chat_photo;
}

const optional<bool> &Message::getGroup_chat_created() const {
    return group_chat_created;
}

const optional<bool> &Message::getSupergroup_chat_created() const {
    return supergroup_chat_created;
}

const optional<bool> &Message::getChannel_chat_created() const {
    return channel_chat_created;
}

const optional<long> &Message::getMigrate_to_chat_id() const {
    return migrate_to_chat_id;
}

const optional<long> &Message::getMigrate_from_chat_id() const {
    return migrate_from_chat_id;
}





