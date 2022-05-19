#include "../h/Battery.h"

Battery::Battery() : CarPart() {
    batteryId = 0;
    capacity = -1;
}

Battery::Battery(unsigned long batteryId, double capacity, unsigned long id, const String &producer,
                 const String &description) : CarPart(id, producer, description) {
    this->batteryId = batteryId;
    this->capacity = capacity;
}

std::ostream &operator<<(std::ostream &out, const Battery &other) {
    out << (const CarPart &) other;

    out << " - " << other.capacity << " Ah" << std::endl;

    return out;
}
