#pragma once

#include <vector>

#include "entity.hpp"

struct Tile : public Entity {

    Tile(std::shared_ptr<Texture> texture, vec2 pos, vec2 scale, vec2 size) {
        this->scale = scale;

        drawable = new Drawable();
        drawable->fs_shader = shader_path("textured.fs.glsl");
        drawable->vs_shader = shader_path("textured.vs.glsl");
        drawable->texture = texture;

        texture->height = size.y;
        texture->width = size.x;
        position = pos;
        if (!torchTex->is_valid()) {
            if (!torchTex->load_from_file(textures_path("cave/torch.png"))) {
                fprintf(stderr, "Failed to load %s texture!", textures_path("cave/torch.png"));
                return;
            }
        }
    }

    Tile(vec2 pos, vec2 size, vec2 tile_scale, std::shared_ptr<Properties> prop) {
        position = pos;
        texture_size = mul(size, tile_scale);
        properties = prop;
    }

    Tile(std::shared_ptr<Texture> texture, vec2 pos, vec2 scale, vec2 size, std::shared_ptr<Properties> prop)
            : Tile(texture, pos, scale, size) {
        properties = prop;
    }

public:
    std::shared_ptr<Texture> torchTex = std::make_shared<Texture>();
};
