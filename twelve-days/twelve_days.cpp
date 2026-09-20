#include "twelve_days.h"
#include <array>
namespace twelve_days {

    std::array<std::string,12> ar{" a Partridge in a Pear Tree.\n"," two Turtle Doves,"," three French Hens,",
                                    " four Calling Birds,"," five Gold Rings,"," six Geese-a-Laying,",
                                    " seven Swans-a-Swimming,"," eight Maids-a-Milking,"," nine Ladies Dancing,",
                                    " ten Lords-a-Leaping,"," eleven Pipers Piping,"," twelve Drummers Drumming,"};
    std::array<std::string,12> num{"first","second","third","fourth","fifth","sixth","seventh",
                                    "eighth","ninth","tenth","eleventh","twelfth"};
    std::string recite(int begin, int end){
        std::string r;
        int tmp=begin;
        while(begin<=end){
            if(tmp!=begin)r+='\n';
            r+="On the "+num[begin-1]+" day of Christmas my true love gave to me:";
            tmp=begin;
            while(tmp>1){
                r+=ar[tmp-1];
                tmp--;
            }
            if(tmp!=begin && tmp==1)r+=" and";
            r+=ar[0];
            begin++;
        }
        return r;
    }

}  // namespace twelve_days
