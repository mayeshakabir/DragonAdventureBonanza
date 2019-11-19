#include <ecs/entities/cloud.hpp>
#include <sstream>
#include <ecs/systems/flying_physics_system.hpp>
#include <ecs/entities/final_boss.hpp>
#include "night_sky.hpp"

NightSky::NightSky(bool unlocked) :
        Level(unlocked) {
}

bool NightSky::init() {
    bool init = Level::init();

    m_rng = std::default_random_engine(std::random_device()());
    m_screen = {1200, 800};

    if(!m_final_boss_spawning_system.init(&m_entities, m_screen))
        return false;

    //=================================
    // Change to Flying Physics System
    //=================================
    m_physics_system = new FlyingPhysicsSystem();
    m_physics_system->init(&m_entities, m_screen);
    auto *flying_physics = dynamic_cast<FlyingPhysicsSystem *>(m_physics_system);
    flying_physics->set_spawning_system(&m_final_boss_spawning_system);

    //=================================
    // Cloud Spawning
    //=================================
    m_spawn_cloud_frequency = 5500;
    m_spawn_cloud_timer = m_spawn_cloud_frequency;

    for (float x = 0; x <= m_screen.x - 100; x += 150) {
        float y = 20 + dist(m_rng) * (m_screen.y - 20);
        m_final_boss_spawning_system.spawn_cloud(round(1 + dist(m_rng)), {x, y});
    }

    //=================================
    // Update Player Variables
    //=================================
    m_player->physics->gravity = 0;
    m_player->physics->velocity = {0, 0};
    m_player->physics->acceleration = {0, 0};
    m_player->position = {100, 400};
    m_player->shooting->time = 500;


    //=================================
    // Spawn Final Boss
    //=================================
    if(!m_final_boss_spawning_system.spawn_final_boss())
        return false;
    m_final_boss = &m_entities.back();

    return init && m_final_boss_system.init(*m_final_boss, &m_entities, m_screen, &m_final_boss_spawning_system);
}


void NightSky::update(float elapsed_ms, vec2 screen_size) {
    m_player->input->space = true;

    m_final_boss_system.update(*m_final_boss, elapsed_ms);
    Level::update(elapsed_ms, screen_size);

    m_spawn_cloud_timer += elapsed_ms;
    if (m_spawn_cloud_timer >= m_spawn_cloud_frequency) {
        spawn_cloud();
        m_spawn_cloud_timer = 0;
    }
}


void NightSky::spawn_cloud() {
    float y = 20 + dist(m_rng) * (m_screen.y - 20);
    float x = m_screen.x + 50;
    m_final_boss_spawning_system.spawn_cloud(round(1 + dist(m_rng)), {x, y});
}