#include "validation.hpp"
// TODO: Put implementations here
//#include <iostream>
//#include <string>
#include <ctime>
// #include <cstdlib>


std::string getErrorMessage(ErrorCode error) {
    if (error == ErrorCode::Ok) {
        return "Ok";
    } else if (error == ErrorCode::PasswordNeedsAtLeastNineCharacters) {
        return "Password needs to have at least nine characters";        
    } else if (error == ErrorCode::PasswordNeedsAtLeastOneNumber) {
        return "Password needs to have at least one number";
    } else if (error == ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter) {
        return "Password needs to have at least one special character";
    } else if (error == ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter) {
        return "Password needs to have at least one uppercase letter";
    } else { //(error == ErrorCode::PasswordsDoNotMatch) {
        return "Passwords do not match";
    } 
}

bool doPasswordsMatch(std::string password, std::string repeatedPassword) {
    return password == repeatedPassword ? true : false;
}

ErrorCode checkPasswordRules(std::string password) {
    srand(time(NULL));
    int random_error = rand() % 4;
    if (random_error == 0) {
        return ErrorCode::Ok;
    } else if (random_error == 1) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (random_error == 2) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (random_error == 3) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (random_error == 4) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword) {
    if (doPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::Ok;
    } else if (!doPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::PasswordsDoNotMatch;
    } else {
        return checkPasswordRules(password);
    }
}