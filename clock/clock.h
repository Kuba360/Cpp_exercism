#pragma once
#include <string>
namespace date_independent {

    class clock{
        public:
            clock(int h, int m);
            static clock at(int h,int m);
            operator std::string ()const;
            clock plus(int min)const;
            bool operator != (const clock& other)const;
            bool operator == (const clock& other)const;
        private:
            int hours;
            int minutes;
    };

}  // namespace date_independent
