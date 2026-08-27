#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

    class scheduler{
        public:
            scheduler(boost::gregorian::greg_month m,int y): d(y,m,1){};

            boost::gregorian::date wday(boost::gregorian::greg_weekday d,int w)const;
            boost::gregorian::date last_wday(boost::gregorian::greg_weekday d)const;
            boost::gregorian::date teenth_wday(boost::gregorian::greg_weekday d)const;

            boost::gregorian::date monteenth()const{
                return teenth_wday(boost::gregorian::Monday);
            }
            boost::gregorian::date tuesteenth()const{
                return teenth_wday(boost::gregorian::Tuesday);
            }
            boost::gregorian::date wednesteenth()const{
                return teenth_wday(boost::gregorian::Wednesday);
            }
            boost::gregorian::date thursteenth()const{
                return teenth_wday(boost::gregorian::Thursday);
            }
            boost::gregorian::date friteenth()const{
                return teenth_wday(boost::gregorian::Friday);
            }
            boost::gregorian::date saturteenth()const{
                return teenth_wday(boost::gregorian::Saturday);
            }
            boost::gregorian::date sunteenth()const{
                return teenth_wday(boost::gregorian::Sunday);
            }


            boost::gregorian::date first_monday()const{
                return wday(boost::gregorian::Monday, 1);
            }
            boost::gregorian::date first_tuesday()const{
                return wday(boost::gregorian::Tuesday, 1);
            }
            boost::gregorian::date first_wednesday()const{
                return wday(boost::gregorian::Wednesday, 1);
            }
            boost::gregorian::date first_thursday()const{
                return wday(boost::gregorian::Thursday, 1);
            }
            boost::gregorian::date first_friday()const{
                return wday(boost::gregorian::Friday, 1);
            }
            boost::gregorian::date first_saturday()const{
                return wday(boost::gregorian::Saturday, 1);
            }
            boost::gregorian::date first_sunday()const{
                return wday(boost::gregorian::Sunday, 1);
            }


            boost::gregorian::date second_monday()const{
                return wday(boost::gregorian::Monday, 2);
            }
            boost::gregorian::date second_tuesday()const{
                return wday(boost::gregorian::Tuesday, 2);
            }
            boost::gregorian::date second_wednesday()const{
                return wday(boost::gregorian::Wednesday, 2);
            }
            boost::gregorian::date second_thursday()const{
                return wday(boost::gregorian::Thursday, 2);
            }
            boost::gregorian::date second_friday()const{
                return wday(boost::gregorian::Friday, 2);
            }
            boost::gregorian::date second_saturday()const{
                return wday(boost::gregorian::Saturday, 2);
            }
            boost::gregorian::date second_sunday()const{
                return wday(boost::gregorian::Sunday, 2);
            }


            boost::gregorian::date third_monday()const{
                return wday(boost::gregorian::Monday, 3);
            }
            boost::gregorian::date third_tuesday()const{
                return wday(boost::gregorian::Tuesday, 3);
            }
            boost::gregorian::date third_wednesday()const{
                return wday(boost::gregorian::Wednesday, 3);
            }
            boost::gregorian::date third_thursday()const{
                return wday(boost::gregorian::Thursday, 3);
            }
            boost::gregorian::date third_friday()const{
                return wday(boost::gregorian::Friday, 3);
            }
            boost::gregorian::date third_saturday()const{
                return wday(boost::gregorian::Saturday, 3);
            }
            boost::gregorian::date third_sunday()const{
                return wday(boost::gregorian::Sunday, 3);
            }


            boost::gregorian::date fourth_monday()const{
                return wday(boost::gregorian::Monday, 4);
            }
            boost::gregorian::date fourth_tuesday()const{
                return wday(boost::gregorian::Tuesday, 4);
            }
            boost::gregorian::date fourth_wednesday()const{
                return wday(boost::gregorian::Wednesday, 4);
            }
            boost::gregorian::date fourth_thursday()const{
                return wday(boost::gregorian::Thursday, 4);
            }
            boost::gregorian::date fourth_friday()const{
                return wday(boost::gregorian::Friday, 4);
            }
            boost::gregorian::date fourth_saturday()const{
                return wday(boost::gregorian::Saturday, 4);
            }
            boost::gregorian::date fourth_sunday()const{
                return wday(boost::gregorian::Sunday, 4);
            }
            


            boost::gregorian::date last_monday()const{
                return last_wday(boost::gregorian::Monday);
            }
            boost::gregorian::date last_tuesday()const{
                return last_wday(boost::gregorian::Tuesday);
            }
            boost::gregorian::date last_wednesday()const{
                return last_wday(boost::gregorian::Wednesday);
            }
            boost::gregorian::date last_thursday()const{
                return last_wday(boost::gregorian::Thursday);
            }
            boost::gregorian::date last_friday()const{
                return last_wday(boost::gregorian::Friday);
            }
            boost::gregorian::date last_saturday()const{
                return last_wday(boost::gregorian::Saturday);
            }
            boost::gregorian::date last_sunday()const{
                return last_wday(boost::gregorian::Sunday);
            }

        private:
            boost::gregorian::date d;
    };

}  // namespace meetup
