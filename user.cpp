#include <iostream>
//#include "laptop.h"
#include "user.h"
#include <string>

User::User(std::string uzytkownik)
{
    user_name = uzytkownik;
	std::cout << "kostruktor przeciazony user"<<std::endl;
}
User::User()
{
	#ifdef _DEBUG
	std::cout << "konstruktor domyslny user" << std::endl;
	#endif
}

std::string User::get_user2()
{
return user_name;
}

void User::setUser2(std::string uzytkownik)
{
    user_name = uzytkownik;
}


void User::print_user()
{
    std::cout << "identyfikator uzytkownika: " << user_name << std::endl;
}

std::ostream& operator << (std::ostream &out, const User &U)
{
    out << "Uzytkownik: "<< U.user_name << std::endl;
    return out;
}

