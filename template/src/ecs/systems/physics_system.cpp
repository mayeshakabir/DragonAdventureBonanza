#include "physics_system.hpp"

void PhysicsSystem::update(float ms) {
    for (auto entity : m_entities) {
        if (!entity.physics) {
            continue;
        }

        float x_step = entity.physics->velocity.x * (ms / 1000);
        float y_step = entity.physics->velocity.y * (ms / 1000);

        entity.position.x += x_step;
        entity.position.y += y_step;
    }
}

bool PhysicsSystem::init(const std::vector<Entity> &entities, std::map<int, Tile *> tiles) {
    m_entities = entities;
    m_tiles = tiles;
    return true;
}
