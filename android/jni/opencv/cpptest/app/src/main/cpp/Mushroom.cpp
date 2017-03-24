//
// Created by Christian Aberger on 21.03.2017.
//

#include "Mushroom.h"

Mushroom::Mushroom()
: round(false)
{
}
Mushroom::Mushroom(const Mushroom& other) {
    *this = other;
}
Mushroom& Mushroom::operator=(const Mushroom& other) {
    color = other.color;
    round = other.round;
    mushRoomName = other.mushRoomName;
    return *this;
}
