#pragma once

#include "common.hpp"
#include <vector>

class Ground;

class Player : public Entity
{
public:
	// Creates all the associated render resources and default transform
	bool init(vec2 x_bounds, vec2 y_bounds);

	// Releases all associated resources
	void destroy();
	
	// Update player position based on direction
	// ms represents the number of milliseconds elapsed from the previous update() call
	void update(float ms);
	
	// Renders the player
	void draw(const mat3& projection)override;

// ========================================
// TODO: collision code
// ========================================
	// Collision routine
//	bool collides_with(const Turtle& turtle);

	// Returns the current player position
	vec2 get_position() const;
	bool is_facing_forwards() {
	    return m_is_facing_forwards;
	}

	// Moves the player's position by the specified offset
	void move(vec2 off);

	// True if the player is alive
	bool is_alive()const;

	// Kills the player, changing its alive state and triggering on death events
	void kill();
    
    // Set player direction
    void walk(bool forward);
    void stop();
    void jump();

	// Check if player is landed
	void land(const Ground& ground);
	bool can_jump();

	// TODO: use vector when we change to use mesh file
	void compute_world_coordinate();
		
private:
	bool m_is_alive; // True if the player is alive
    bool m_on_ground; // True if player is on ground/platform
	
	bool m_unlocked_double_jump;
	int m_jump_count;
	
    bool m_is_facing_forwards; // True if player is facing forward

    float walking_speed;
    float jumping_speed;
    float gravity;

	vec2 m_x_world_bounds;
	vec2 m_y_world_bounds;
	
    Texture player_texture;
	std::vector<vec2> player_world_coord;
	TexturedVertex vertices[4];
};
