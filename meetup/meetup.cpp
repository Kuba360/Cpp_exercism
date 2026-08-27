#include "meetup.h"
namespace meetup {

    boost::gregorian::date scheduler::wday(boost::gregorian::greg_weekday day, int w)const{
        boost::gregorian::date nd=this->d;
        while(w!=0){
            if(nd.day_of_week()==day)w--;
            
            if(w!=0){
                nd+= boost::gregorian::days(1);
            }
        }
        return nd;
    }

    boost::gregorian::date scheduler::last_wday(boost::gregorian::greg_weekday day)const{
        boost::gregorian::date nd=this->d.end_of_month();
        while(nd.day_of_week()!=day){
                nd-= boost::gregorian::days(1);
        }
        return nd;
    }

    boost::gregorian::date scheduler::teenth_wday(boost::gregorian::greg_weekday day)const{
        boost::gregorian::date nd=this->d+boost::gregorian::days(12);;
        while(nd.day_of_week()!=day){
                nd+= boost::gregorian::days(1);
        }
        return nd;
    }
}  

