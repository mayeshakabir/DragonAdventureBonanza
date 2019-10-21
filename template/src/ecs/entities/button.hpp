#ifndef DAB_BUTTON_H
#define DAB_BUTTON_H

#include "entity.hpp"

struct Button : public Entity {

    Button(const char* texture_path) : Entity(){
        scale = {1.f, 1.f};

        drawable = new Drawable();
        drawable->texture_path = texture_path;
        drawable->fs_shader = shader_path("textured.fs.glsl");
        drawable->vs_shader = shader_path("textured.vs.glsl");

		input = new Input();
    }
};

#endif //DAB_BUTTON_H

