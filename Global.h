#pragma once
#include <iostream>
#include "clsUser.h"

class UserSession {
public:
    static clsUser& getCurrentUser() {
        static clsUser currentUser = clsUser::Find("", "");
        return currentUser;
    }

    static void setCurrentUser(const string& username,const string& password) {
        getCurrentUser() = clsUser::Find(username, password);
    }

};
