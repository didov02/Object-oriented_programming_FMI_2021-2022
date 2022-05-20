#include "../h/Engine.h"

Engine::Engine(double hp, unsigned long id, const String &producer, const String &description) : CarPart(id, producer, description) {
    this->hp = hp;
}

std::ostream &operator<<(std::ostream &out, const Engine &other) {
    out << (const CarPart &) other;

    out << " - " << other.hp << "hp" << std::endl;

    return out;
}

double Engine::getHp() const {
    return hp;
}
