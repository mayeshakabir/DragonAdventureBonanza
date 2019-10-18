#pragma once

#include <vector>

#include "common.hpp"
#include "entity.hpp"

struct Tile : public Entity {
    Tile(Texture* texture, vec2 pos, vec2 scale, vec2 size) {
        this->scale = scale;

        drawable = new Drawable();
        drawable->fs_shader = shader_path("textured.fs.glsl");
        drawable->vs_shader = shader_path("textured.vs.glsl");
        drawable->texture = texture;  

        texture->height = size.x;
        texture->width = size.y;
        position = pos;
    }
};
