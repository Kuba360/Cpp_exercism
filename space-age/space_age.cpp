#include "space_age.h"


namespace{
    constexpr double s_in_year=31'557'600;
    constexpr double mercury=0.2408467;
    constexpr double venus=0.61519726;
    constexpr double earth=1;
    constexpr double mars=1.8808158;
    constexpr double jupiter=11.862615;
    constexpr double saturn=29.447498;
    constexpr double uran=84.016846;
    constexpr double neptun=164.79132;
}

namespace space_age {

    long long space_age::seconds()const {
        return this->sec;
    }
    double space_age::on_mercury()const {
        return this->sec/s_in_year/mercury;
    }
    double space_age::on_venus()const {
        return this->sec/s_in_year/venus;
    }
    double space_age::on_earth()const {
        return this->sec/s_in_year/earth;
    }
    double space_age::on_mars()const {
        return this->sec/s_in_year/mars;
    }
    double space_age::on_jupiter()const {
        return this->sec/s_in_year/jupiter;
    }
    double space_age::on_saturn()const {
        return this->sec/s_in_year/saturn;
    }
    double space_age::on_uranus()const {
        return this->sec/s_in_year/uran;
    }
    double space_age::on_neptune()const {
        return this->sec/s_in_year/neptun;
    }

}  // namespace space_age
