#include "level.hpp"

#include <utility>
#include <ecs/entities/player.hpp>

Level::Level(bool unlocked) :
    m_unlocked(unlocked),
    m_tile_map(nullptr),
    m_x_boundaries{-200.f, 0},
    m_y_boundaries{0, 0},
    m_physics_system(nullptr) {
}

Level::~Level() = default;

/** destroys resources not needed when the scene is not active **/
void Level::destroy() {
    Scene::destroy();
    m_entities.clear();
    delete m_tile_map;
}

bool Level::init_scene(MapVector map, TexturePathMapping mapping, const char * texturePath) {
    Scene::init();
    m_tile_map = new TileMap(this);
    for (auto & iter : mapping) {
        auto* texture = new Texture();
        if (!texture->is_valid()) {
            if (!texture->load_from_file(iter.second)) {
                fprintf(stderr, "Failed to load tile texture!");
                return false;
            }
        }
        m_texture_mapping.insert(TextureMapping::value_type(iter.first, texture));
    }
    if (!m_tile_map->init(std::move(map), m_texture_mapping)) {
        fprintf(stderr, "Failed to initialize tile map!");
        return false;
    }
    std::shared_ptr<Player> player = std::make_shared<Player>();
    player->init(get_x_boundaries(), get_y_boundaries());
    m_entities.emplace_back(player);
    m_x_boundaries.y = m_tile_map->get_map_dim().x;
    m_y_boundaries.y = m_tile_map->get_map_dim().y;
    m_physics_system = new PhysicsSystem(m_tile_map->get_tiles());
    return true;
}

bool Level::init_enemy(int type, vec2 initial_pos) {
    if (type == -1) {
        return init_walking_enemy(type, initial_pos);
    }
    return false;
}

void Level::update(float elapsed_ms) {
    m_physics_system->update(elapsed_ms);
}

void Level::draw(const mat3 &projection) {
    Scene::draw(projection);
    m_tile_map->draw(projection);
    for (auto& enemy : m_entities) {
        enemy.get()->draw(projection);
    }
}
