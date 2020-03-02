	#pragma once
	#include <iostream>

	class User
	{
        std::string user_name;
	public:
        User(std::string);
		User();
        void setUser2(std::string);
		void print_user();
        std::string get_user2();
        friend std::ostream &operator << (std::ostream &out, const User &U);
	};
