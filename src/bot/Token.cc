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
// Created by norbert on 12.08.17.
//

#include <cstring>
#include <fstream>
#include <iostream>
#include <exceptions/file_not_found.h>

#include "inc/bot/Token.h"
//Namespace for Library
using namespace yatbcpp;
using namespace std;
/////////////////////////////////////////////////
// TODOS: EXCEPTIONS AND STUFF
// Token is only 0-45 long _>  46
////////////////////////////////////////////////

/**
 * returns the token as string
 * @return the Token
 */
const std::string Token::getToken() const {
    string s = token;
    return s;
}

/**
 * Sets the Token, additional verification is done
 * @param s
 */
void Token::setToken(string s){
    if(s.size()<=0){
        //Token May not be less or zero
    }
    if(s.size()>=__TELEGRAM_TOKEN_LENGTH){
        //Token too big
    }
    token = s;
}

/**
 * Limited to the max char length of 45 characters, from then on it is stl
 * @param ttoken
 */
Token::Token(const char ttoken[__TELEGRAM_TOKEN_LENGTH]) {
    this->setToken(ttoken);
}

/**
 * Reads file and gets the token from the file
 * @param filelocation, the file location of the token
 * @return
 */
Token Token::FromFile(const char *filelocation) {
    char token[__TELEGRAM_TOKEN_LENGTH];
    ifstream file (filelocation, ios::in);
    if(file.is_open()){
        int readTokens=0;
        for(readTokens=0;readTokens<__TELEGRAM_TOKEN_LENGTH;readTokens++){
            file.get(token[readTokens]);
        }
        if(readTokens!=__TELEGRAM_TOKEN_LENGTH){
            std::cerr << "Telegram Token Size Missmatch::" << readTokens << " instead of " << __TELEGRAM_TOKEN_LENGTH << std::endl;
            //An Error has occured, we did not stop where we thougt to stop
        }
        file.close();
    }
    else {
        throw file_not_found("Supplied File Location does not contain a file");
    }
    return Token(token);

}
