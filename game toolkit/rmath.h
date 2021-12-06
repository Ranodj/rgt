#pragma once

#include "core.h"

inline float lerp(float a, float b, float t) {

    return (b - (b - a) * (1.0 - t)) * (t > 0.5) + (a + (b - a) * t) * (t <= 0.5);
}

inline vector2 lerp(vector2 a, vector2 b, float t) {

    return vector2(lerp(a.x, b.x, t), lerp(a.y, b.y, t));
}