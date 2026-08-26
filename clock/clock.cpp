#include "clock.h"

namespace date_independent {
            

        clock::clock(int h, int m): hours(h),minutes(m){}

    clock clock::at(int ho, int mi){
        int h=ho%24;
        int minutes_overflow=mi/60;
        minutes_overflow=minutes_overflow%24;
        int m=mi%60;
        h+=minutes_overflow;
        h=h%24;
        if(m<0){
            h-=1;
            m+=60;
        } 
        if(h<0)h+=24;
        return clock(h,m);
    }

    clock::operator std::string()const{
        return std::to_string(this->hours/10)+
               std::to_string(this->hours%10)+
               ':'+
               std::to_string(this->minutes/10)+
               std::to_string(this->minutes%10);
    }

    clock clock::plus(int min)const{
        return clock::at(this->hours,min+this->minutes);
    }
    bool clock::operator==(const clock& other)const{
        return this->hours==other.hours&&this->minutes==other.minutes;
    }
    bool clock::operator!=(const clock& other)const{
        return !(*this==other);
    }
}  // namespace date_independent
