struct AirDash {
	AirDash() :
		base_airdash_speed(1000.f),
		cur_airdash_speed(0.f),
		airdash_friction(20.f),
		airdashing(false),
		can_airdash(false) {
	}

	float base_airdash_speed;
	float cur_airdash_speed;
	float airdash_friction;
	bool airdashing;
	bool can_airdash;
};