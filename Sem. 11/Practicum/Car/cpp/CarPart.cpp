#include "../h/CarPart.h"

std::ostream &operator<<(std::ostream &out, const CarPart &other) {
    out << "(" << other.id << ") by " << other.producer << " - " << other.description;
    return out;
}

CarPart::CarPart(unsigned long id, const String &producer, const String &description) {
    this->id = id;
    this->producer = producer;
    this->description = description;
}
