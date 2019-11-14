#pragma once
#include "common.hpp"
#include <list>
#include <map>
#include <ecs/entities/modal.hpp>
#include <ecs/entities/tile.hpp>
#include "../entities/entity.hpp"

class RenderSystem {
public:
	RenderSystem();
	~RenderSystem();

    bool init(std::list<Entity>* entities, const std::map<int, Tile*>& tiles);
    bool initEntity(Entity& entity);
    
	void destroy();
    
	void draw_all(mat3 projection);
	void draw(Entity &entity, mat3 projection);
	void drawModal(mat3 projection, Modal& entity);
	void update(float ms);

private:
    bool load_from_file(Drawable::Effect& effect, const char* vs_path, const char* fs_path);

    void transform(Entity &entity);
    void rotate(mat3 &out, float radians);
    void translate(mat3 &out, vec2 offset);
    void scale(mat3 &out, vec2 scale);

    void release(Drawable::Effect& effect);
    std::list<Entity>* m_entities;
    std::map<int, Tile*> m_tiles;
    std::map<const char*, Drawable::Effect> m_effects;
    mat3 out;
};
