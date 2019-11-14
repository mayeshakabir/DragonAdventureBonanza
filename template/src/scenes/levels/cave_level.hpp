#ifndef DAB_CAVE_LEVEL_HPP
#define DAB_CAVE_LEVEL_HPP

#include "level.hpp"

class CaveLevel: public Level {
public:
    explicit CaveLevel(bool unlocked);

    const char * get_bg_texture_path() override {
        return textures_path("cave/background.png");
    }
    bool use_vertical_camera() override {
        return true;
    }

private:
    bool init_walking_enemy(int type, vec2 initial_pos) override;
    
    const MapVector get_map() const override {
        return m_tile_vec;
    }
    
    const TexturePathMapping get_mapping() const override {
        return m_texture_map;
    }
    
    const TilePropertyMapping get_property_map() const override {
        return m_property_map;
    }
    
    const MapVector m_tile_vec = {
        {10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 0},
        {40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 38, 36, 10, 3, 3, 40, 32, 32, 2, 32, 32, 38, 40, 32, 2, 2, 32, 32, 32, 32, 2, 32, 38, 40, 32, 38, 3, 3, 3, 32, 32, 32, 32, 38, 3, 40, 38, 3, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 38, 36, 10, 3, 3, 40, 32, 32, 32, 32, 32, 32, 32, 32, 38, 36, 10, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 38, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 38, 40, 32, 33, 0, 0, 0, 0, 0, 29, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 3, 0, 0, 38, 3, 40, 0, 0, 0, 0, 34, 38, 36, 10, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 0},
        {1, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 41, 0, 0, 0, 0, 0, 0, 0, 37, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 3, 3, 0, 0, 0, 0, 0, 37, 3, 40, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 40, 20, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 0},
        {1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 32, 38, 40, 38, 36, 0, 0, 0, 0, 0, 0, 0, 0, 37, 38, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 3, 0},
        {36, 8, 8, 8, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 36, 10, 3, 8, 8, 35, 8, 31, 0, 0, 0, 0, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 3, 0},
        {3, 3, 3, 3, 3, 3, 36, 8, 31, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 40, 32, 32, 32, 38, 40, 41, 0, 0, 0, 0, 38, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 3, 0},
        {40, 32, 32, 32, 32, 32, 32, 32, 36, 8, 8, 8, 31, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 21, 0, 0, 3, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 8, 8, 8, 35, 0, 0, 0, 0, 30, 8, 35, 8, 8, 8, 10, 3, 36, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 3, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 28, 13, 0, 0, 0, 1, 35, 8, 31, 0, 0, 0, 0, 30, 35, 8, 8, 35, 8, 35, 10, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 31, 0, 0, 0, 37, 38, 40, 38, 3, 3, 36, 31, 0, 0, 0, 29, 40, 38, 3, 3, 3, 3, 40, 38, 3, 36, 31, 0, 0, 0, 0, 30, 8, 35, 10, 3, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 21, 8, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 1, 0, 0, 0, 0, 10, 40, 38, 3, 3, 3, 3, 3, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 10, 40, 38, 1, 0, 0, 0, 0, 29, 36, 10, 3, 3, 3, 36, 35, 0, 0, 29, 36, 10, 3, 3, 3, 3, 36, 10, 3, 3, 1, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 3, 3, 40, 38, 36, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 8, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 3, 36, 0, 0, 0, 0, 3, 36, 10, 3, 40, 38, 3, 3, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 10, 3, 3, 36, 10, 1, 21, 0, 0, 0, 34, 32, 32, 2, 38, 3, 3, 3, -1, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 33, 0, 0, 0, 0, 29, 36, 10, 3, 40, 38, 3, 3, 36, 10, 3, 3, 3, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 28, 13, 0, 0, 0, 30, 8, 8, 8, 35, 8, 8, 3, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 29, 40, 28, 13, 0, 0, 38, 3, 3, 3, 36, 10, 3, 3, 3, 0},
        {1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 3, 3, 36, 8, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 8, 8, 10, 3, 32, 2, 2, 32, 32, 2, 32, 2, 32, 0, 0, 0, 0, 0, 29, 3, 3, 3, 36, 10, 3, 40, 32, 32, 32, 32, 3, 36, 8, 35, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 36, 0, 0, 0, 0, 34, 38, 40, 38, 2, 2, 2, 38, 3, 0},
        {36, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 30, 8, 8, 8, 10, 36, 10, 3, 3, 3, 3, 40, 38, 3, 31, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 29, 3, 3, 3, 3, 40, 32, 33, 0, 0, 0, 0, 32, 32, 32, 32, 38, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 0},
        {40, 38, 36, 31, 0, 0, 0, 0, 0, 0, 0, 8, 8, 10, 3, 40, 38, 3, 3, 3, 40, 38, 3, 3, 36, 10, 3, 1, 0, -1, 0, 0, 0, 0, 29, 36, 10, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 8, 35, 8, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 29, 1, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 29, 3, 0},
        {36, 10, 3, 36, 31, 0, 0, 0, 0, 0, 30, 10, 3, 3, 3, 36, 10, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 36, 35, 35, 31, 0, 0, 0, 34, 38, 3, 38, 40, 38, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 36, 20, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 36, 35, 8, 8, 8, 35, 8, 35, 8, 35, 8, 8, 10, 3, 0},
        {3, 40, 38, 3, 36, 31, 0, 0, -3, 0, 34, 32, 2, 32, 2, 2, 2, 2, 32, 2, 2, 32, 32, 2, 32, 2, 2, 2, 32, 32, 33, 0, 0, 0, 0, 0, 0, 29, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 3, 3, 40, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 29, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 30, 35, 35, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0},
        {3, 36, 10, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 1, 0, 0, -3, 0, 0, 30, 35, 35, 35, 0, -1, 0, 0, 38, 3, 3, 36, 0, 0, 0, -1, 0, 3, 3, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 29, 3, 3, 40, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 32, 2, 2, 2, 32, 32, 2, 2, 32, 2, 32, 2, 32, 0},
        {40, 38, 3, 36, 10, 36, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 1, 0, 0, 0, 0, 0, 34, 32, 32, 3, 8, 8, 8, 8, 10, 3, 3, 3, 8, 35, 35, 8, 8, 3, 3, 35, 35, 3, 0, 0, 0, 29, 40, 38, 3, 36, 10, 1, 0, 0, 0, 0, 0, 29, 40, 38, 36, 35, 8, 8, 35, 8, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {36, 10, 3, 3, 3, 3, 36, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 38, 3, 3, 36, 35, 35, 0, 0, 0, 0, 0, 0, 2, 32, 2, 32, 32, 32, 32, 32, 2, 32, 32, 2, 32, 32, 2, 32, 2, 32, 33, 0, 0, 0, 29, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 29, 36, 10, 3, 3, 3, 40, 38, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 32, 2, 32, 2, 32, 2, 33, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 10, 3, 3, 3, 3, 36, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 40, 38, 3, 1, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 36, 10, 3, 36, 35, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 2, 32, 38, 3, 3, 36, 31, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 36, 10, 3, 36, 8, 0, 0, 0, 0, 37, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 36, 35, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 35, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 29, 3, 3, 3, 3, 40, 38, 3, 0, 0, 0, 0, 0, 34, 3, 3, 36, 10, 3, 3, 3, 3, 40, 38, 3, 36, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 32, 32, 32, 32, 32, 3, 35, 35, 0, 0, -1, 0, 0, 0, 0, 0, -2, 0, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 30, 35, 10, 3, 3, 3, 3, 36, 10, 40, 0, 0, 0, 0, 0, 0, 37, 32, 32, 32, 32, 3, 3, 3, 36, 10, 3, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 35, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 10, 3, 0, -2, 0, 0, 30, 35, 10, 40, 38, 3, 40, 38, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 35, 8, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 8, 10, 3, 40, 38, 36, 8, 35, 31, 0, 0, 0, -3, 0, 0, 30, 10, 3, 3, 36, 31, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 2, 32, 32, 2, 32, 32, 32, 32, 32, 32, 2, 32, 32, 3, 3, 8, 8, 8, 8, 3, 3, 3, 36, 10, 3, 36, 10, 3, 40, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 1, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 38, 3, 3, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 40, 38, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 2, 2, 32, 2, 32, 32, 32, 32, 32, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 30, 8, 10, 3, 3, 3, 3, 3, 3, 3, 36, 8, 8, 0, 0, 0, 0, 38, 3, 3, 36, 10, 36, 8, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 37, 2, 2, 32, 38, 3, 3, 3, 3, 40, 38, 3, 3, 0, 0, 0, 0, 34, 32, 3, 3, 3, 3, 3, 3, 0, 0, 0, 30, 8, 35, 8, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 35, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 38, 3, 3, 36, 10, 3, 40, 0, 0, 0, 0, 0, 0, 37, 3, 3, 3, 3, 40, 0, 0, 0, 29, 3, 3, 40, 38, 3, 36, 8, 35, 8, 35, 35, 35, 8, 35, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 38, 3, 3, 3, 3, 36, 31, 0, 0, 0, 0, 0, 0, 34, 2, 3, 3, 1, 0, 0, 0, 29, 3, 3, 36, 10, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 35, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 38, 3, 3, 3, 36, 8, 0, 0, 0, 0, 0, 0, 0, 37, 32, 33, 0, 0, 0, 34, 32, 2, 2, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 36, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 35, 35, 35, 0, 0, 0, 0, 30, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 38, 3, 3, 3, 40, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 2, 2, 2, 32, 32, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 36, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 38, 3, 3, 40, 0, 0, 0, 0, 29, 3, 35, 35, 8, 0, -1, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 3, 3, 3, 36, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 36, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 35, 10, 3, 21, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 30, 8, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 30, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 38, 3, 32, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 32, 2, 3, 36, 10, 3, 40, 38, 3, 1, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 1, 0, 0, 0, 0, 29, 36, 10, 3, 40, 38, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 10, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 2, 3, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 36, 10, 40, 38, 3, 36, 0, 0, 0, 0, 29, 3, 3, 3, 36, 10, 3, 3, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 10, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 30, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, -1, 0, 29, 3, 3, 36, 10, 3, 40, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 36, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 30, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 1, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 35, 8, 31, 0, 0, 0, 30, 8, 8, 0, -1, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 37, 2, 3, 3, 3, 3, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 35, 35, 10, 3, 3, 3, 3, 3, 36, 0, 0, 0, 0, 37, 32, 38, 40, 38, 3, 3, 3, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 1, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 35, 35, 8, 3, 3, 40, 38, 1, 0, 0, 0, 29, 3, 3, 8, 8, 31, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 1, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 3, 3, 3, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 37, 40, 38, 3, 3, 36, 8, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 1, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 30, 8, 10, 40, 38, 3, 3, 3, 36, 10, 1, 0, 0, 0, 29, 40, 38, 3, 3, 3, 8, 35, 8, 35, 8, 8, 8, 35, 8, 31, 0, 0, 0, 0, 0, 29, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 10, 36, 10, 3, 40, 38, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 40, 38, 3, 3, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 8, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 40, 1, 0, 0, 29, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 8, 10, 3, 3, 36, 10, 3, 3, 40, 38, 3, 1, 0, -5, 0, 29, 36, 10, 3, 3, 3, 3, 40, 38, 40, 38, 3, 3, 3, 32, 33, 0, 0, 0, 0, 0, 29, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 3, 3, 3, 3, 36, 10, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 10, 3, 3, 3, 40, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 36, 1, 0, 0, 29, 36, 8, 8, 35, 8, 35, 8, 35, 35, 8, 10, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 1, 0, 0, 0, 29, 3, 3, 3, 40, 38, 3, 36, 10, 36, 10, 3, 32, 2, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 3, 40, 38, 3, 3, 3, 3, 36, 10, 36, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 36, 8, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 40, 38, 3, 3, 40, 38, 3, 3, 3, 40, 38, 3, 3, 3, 40, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 29, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 3, 36, 10, 3, 3, 3, 3, 3, 3, 40, 21, 0, 0, 0, 29, 35, 8, 0, 0, 0, 0, 0, 38, 40, 38, 3, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 36, 10, 3, 3, 36, 10, 3, 3, 3, 36, 10, 3, 3, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 32, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 8, 35, 8, 10, 3, 3, 3, 3, 3, 40, 38, 3, 3, 1, 28, 13, 0, 0, 29, 3, 3, 8, 8, 8, 8, 8, 10, 36, 10, 3, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 40, 38, 3, 3, 33, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 33, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 38, 3, 3, 3, 3, 3, 3, 40, 38, 3, 36, 10, 3, 3, 1, 0, 0, 0, 0, 29, 3, 40, 38, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 3, 3, 3, 3, 3, 3, 40, 38, 3, 40, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 36, 10, 3, 3, 36, 10, 3, 2, 0, 0, 0, 0, 0, 0, 0, 30, 8, 10, 3, 40, 38, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 40, 38, 3, 3, 36, 10, 3, 3, 3, 3, 40, 33, 0, 0, 0, 0, 29, 3, 36, 10, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 3, 40, 38, 3, 3, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 32, 0, 0, 0, 0, 0, 0, 0, 21, 3, 3, 3, 3, 36, 10, 3, 3, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 41, 0, 0, 0, 0, 0, 29, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 30, 35, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 29, 3, 1, 0, 0, 29, 3, 36, 10, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 32, 3, 3, 3, 32, 33, 0, 0, 0, 0, 0, 0, 0, 30, 8, 10, 3, 32, 2, 2, 2, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 40, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 29, 3, 36, 10, 40, 38, 3, 3, 40, 38, 3, 3, 36, 10, 3, 3, 36, 8, 35, 35, 31, 0, 0, 0, 0, 0, 10, 3, 3, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 34, 2, 33, 0, 0, 34, 32, 2, 32, 2, 32, 2, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 2, 32, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 35, 10, 36, 10, 40, 38, 3, 3, 3, 3, 3, 3, 3, 41, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 36, 10, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 38, 3, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 3, 3, 3, 3, 36, 10, 3, 3, 3, 40, 38, 3, 40, 0, 0, 0, 0, 0, 0, 0, 34, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 29, 3, 3, 3, 40, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 10, 40, 38, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 35, 8, 10, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 36, 10, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 35, 10, 3, 3, 3, 40, 38, 3, 36, 10, 3, 3, 3, 40, 38, 3, 40, 41, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 29, 40, 38, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, P, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 3, 3, 40, 38, 3, 36, 10, 3, 3, 3, 40, 38, 3, 36, 10, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 10, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 10, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 10, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 8, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 3, 3, 3, 3, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 3, 3, 3, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 40, 32, 32, 32, 32, 38, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 30, 8, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 40, 38, 3, 40, 38, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 29, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, -1, 0, 0, 29, 36, 10, 3, 3, 3, 41, 0, 0, 0, 0, 34, 2, 38, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 10, 36, 10, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 35, 8, 8, 35, 8, 10, 3, 40, 38, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 13, 0, 0, 0, 0, 29, 40, 38, 3, 3, 40, 38, 0, 0, 0, 0, 30, 8, 8, 8, 8, 10, 3, 3, 40, 2, 33, 0, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 40, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 10, 3, 36, 10, 3, 36, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 40, 38, 3, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 36, 10, 3, 3, 36, 10, 0, 0, 0, 0, 29, 40, 38, 3, 40, 38, 3, 3, 1, 20, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 10, 3, 3, 3, 3, 3, 3, 3, 3, 35, 0, 0, 0, 0, 0, 0, 0, -1, 0, 8, 35, 3, 3, 40, 38, 3, 3, 3, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, P, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 29, 36, 10, 3, 3, 36, 10, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 29, 36, 10, 3, 36, 10, 3, 3, 1, 0, 0, -3, 0, 0, 0, 0, 0, 0, 29, 3, 3, 2, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 10, 40, 38, 3, 3, 3, 3, 40, 38, 3, 3, 35, 8, 31, 0, 0, 8, 35, 35, 8, 10, 3, 3, 3, 36, 10, 3, 40, 38, 3, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 29, 3, 3, 3, 3, 40, 38, 3, 3, 8, 0, 0, 0, 0, 0, 0, -3, 0, 34, 2, 33, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 35, 10, 3, 36, 10, 3, 3, 3, 3, 36, 10, 3, 3, 3, 40, 33, 0, 0, 38, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 40, 38, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {36, 8, 35, 8, 8, 31, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 40, 38, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 35, 3, 3, 40, 38, 3, 3, 3, 0, 0, 0, 0, 29, 3, 3, 3, 3, 36, 10, 3, 3, 3, 35, 8, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 10, 40, 38, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 3, 36, 0, 0, 0, 34, 32, 32, 38, 3, 3, 3, 3, 40, 38, 3, 3, 3, 36, 10, 36, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {40, 38, 3, 40, 38, 1, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 36, 10, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 36, 10, 3, 3, 3, 0, 0, 0, 0, 29, 3, 40, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 35, 10, 3, 36, 10, 3, 3, 36, 10, 3, 3, 3, 40, 38, 3, 3, 40, 0, 0, 0, 0, 0, 0, 29, 3, 40, 38, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 40, 38, 3, 3, 40, 38, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {36, 10, 3, 36, 10, 1, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 36, 10, 3, 3, 3, 3, 3, 3, 3, 40, 38, 1, 0, 0, 0, 0, 0, 30, 8, 31, 0, 0, 0, -1, 0, 0, 29, 36, 10, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 29, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 35, 35, 35, 10, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 36, 8, 0, 0, 0, 0, 0, 29, 3, 36, 10, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 36, 10, 9, 9, 36, 10, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 3, 3, 3, 3, 1, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 1, 0, 0, 0, 0, 0, 29, 3, 3, 8, 35, 35, 8, 35, 8, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 0, 0, 0, 0, 29, 3, 1, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 3, 3, 3, 3, 40, 38, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 0, -2, 0, 0, 21, 29, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 3, 40, 38, 3, 1, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 3, 3, 40, 38, 3, 40, 38, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 29, 40, 38, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 40, 38, 3, 36, 10, 3, 0, 0, 0, 0, 29, 3, 1, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 8, 8, 31, 0, 0, -1, 0, 0, 30, 35, 35, 10, 40, 38, 3, 3, 36, 10, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 36, 10, 3, 3, 3, 8, 35, 8, 35, 35, 10, 3, 3, 3, 3, 40, 38, 3, 3, 3, 3, 3, 40, 38, 3, 3, 3, 40, 38, 3, 3, 3, 3, 40, 38, 3, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 3, 36, 10, 3, 1, 0, 0, 0, 29, 1, 0, 0, 0, 0, 29, 3, 3, 36, 10, 3, 36, 10, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 29, 36, 10, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 0, 0, 0, 0, 29, 3, 36, 8, 35, 8, 8, 35, 8, 8, 8, 35, 8, 8, 10, 3, 3, 36, 8, 35, 8, 35, 8, 10, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 40, 38, 3, 3, 36, 10, 3, 3, 3, 3, 3, 36, 10, 3, 3, 3, 36, 10, 3, 3, 3, 3, 36, 10, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    const TexturePathMapping m_texture_map = {
        { -7, textures_path("fire.png")},
        { -6, textures_path("cave/projectiles/ice.png")},
        { -5, textures_path("bat/bat_spritesheet1.png")},
        { -4, textures_path("bat/bat_spritesheet1.png")},
        { -3, textures_path("bat/bat_spritesheet1.png")},
        { -2, textures_path("cave/enemies/glob.png")},
        { -1, textures_path("cave/enemies/spider.png")},
        
        { 1, textures_path("cave/tiles/right_side.png")},
        { 2, textures_path("cave/tiles/bottom_l.png")},
        { 3, textures_path("cave/tiles/fill.png")},
        { 8, textures_path("cave/tiles/middle_r.png")},
        { 9, textures_path("cave/tiles/bottom_l.png")},
        { 10, textures_path("cave/tiles/corner_TL.png")},
        { 13, textures_path("cave/tiles/rock_right.png")},
        { 20, textures_path("cave/torch.png")},
        { 21, textures_path("cave/enemies/littleppl/littleppl.png")},
        { 23, textures_path("cave/enemies/littleppl/littleppl3.png")},
        { 28, textures_path("cave/tiles/rock_L.png")},
        { 29, textures_path("cave/tiles/left-wall.png")},
        { 30, textures_path("cave/tiles/floor_left.png")},
        { 31, textures_path("cave/tiles/floor_right.png")},
        { 32, textures_path("cave/tiles/bottom_r.png")},
        { 33, textures_path("cave/tiles/right_curve.png")},
        { 34, textures_path("cave/tiles/left_curve.png")},
        { 35, textures_path("cave/tiles/middle2.png")},
        { 36, textures_path("cave/tiles/corner_TR.png")},
        { 37, textures_path("cave/tiles/floor_BL.png")},
        { 38, textures_path("cave/tiles/corner_BL.png")},
        { 40, textures_path("cave/tiles/corner_BR.png")},
        { 41, textures_path("cave/tiles/floor_BR.png")}
    };
    
    const TilePropertyMapping m_property_map = {};
};

#endif //DAB_FOREST_LEVEL_HPP
