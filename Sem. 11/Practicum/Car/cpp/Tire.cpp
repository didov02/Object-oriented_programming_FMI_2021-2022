#include "../h/Tire.h"

Tire::Tire() : CarPart() {
    width = -1;
    diameter = -1;
    profile = -1;
}

Tire::Tire(double width, double profile, double diameter, unsigned long id, const String &producer,
           const String &description) : CarPart(id, producer, description) {

    if (width <= MAX_WIDTH && width >= MIN_WIDTH)
        this->width = width;
    else
        throw std::logic_error("Invalid width data!");

    if (profile <= MAX_PROFILE && profile >= MIN_PROFILE)
        this->profile = profile;
    else
        throw std::logic_error("Invalid profile data!");


    if (diameter <= MAX_DIAMETER && diameter >= MIN_DIAMETER)
        this->diameter = diameter;
    else
        throw std::logic_error("Invalid diameter data!");
}

std::ostream &operator<<(std::ostream &out, const Tire &other) {
    out << (const CarPart &) other;

    out << other.width << "/"
        << other.profile << "R"
        << other.diameter << std::endl;

    return out;
}
