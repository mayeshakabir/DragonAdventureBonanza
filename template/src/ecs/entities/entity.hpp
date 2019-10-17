#pragma once

#include "../components/drawable.hpp"
#include "../components/physics.hpp"
#include "common.hpp"

struct Entity {
    // pointers to all components go here
	Physics *physics = nullptr;
	Drawable* drawable = nullptr;

	float radians = 0.f;
	vec2 position = {0,0};
	vec2 scale = {0,0};
};