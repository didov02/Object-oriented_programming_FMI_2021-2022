#include "../h/Tire.h"

Tire::Tire(double width, double profile, double diameter, unsigned long id, const String &producer,
           const String &description) : CarPart(id, producer, description) {

    setWidth(width);

    setProfile(profile);

    setDiameter(diameter);
}

std::ostream &operator<<(std::ostream &out, const Tire &other) {
    out << (const CarPart &) other << " - " << other.width << "/" << other.profile << "R" << other.diameter << std::endl;
    return out;
}

void Tire::setWidth(double width) {
    if (width <= MAX_WIDTH && width >= MIN_WIDTH)
        this->width = width;
    else
        throw std::logic_error("Invalid width data!");
}

void Tire::setProfile(double profile) {
    if (profile <= MAX_PROFILE && profile >= MIN_PROFILE)
        this->profile = profile;
    else
        throw std::logic_error("Invalid profile data!");
}

void Tire::setDiameter(double diameter) {
    if (diameter <= MAX_DIAMETER && diameter >= MIN_DIAMETER)
        this->diameter = diameter;
    else
        throw std::logic_error("Invalid diameter data!");
}
