#pragma once

#include "entity.hpp"

struct Glob : public Entity {
    Glob(std::shared_ptr<Texture> texture, vec2 pos) {
        scale = { 0.2f, 0.2f };
        texture_size = {(float) texture->width, (float) texture->height};
        
        drawable = new Drawable();
        drawable->fs_shader = shader_path("textured.fs.glsl");
        drawable->vs_shader = shader_path("textured.vs.glsl");
        drawable->texture = texture;
        
        position = pos;
        
        position = pos;
        physics = new Physics();
        physics->gravity = 750.f;
        physics->walk_speed = 30.f;
        
        physics->velocity = { physics->walk_speed, 0.f };
        physics->acceleration = { 0.f, physics->gravity };
        
        collider = new Collider();
        is_facing_forward = true;
        shooting = new Shooting();
        
        enemyai = new EnemyAI();

        health = new Health();
        health->health = 1;
    }
};
