#include "Steamer.h"

class Corvette : public Steamer {
public:
	explicit Corvette(const char* _country, const char* _name, int weight, double max_speed, int ammo, bool plane_landing, bool add_to_list = false);
	explicit Corvette(const Corvette& c);

	virtual void shoot(double northern_latitude, double eastern_longitude);
	virtual void print_data() const override;
private:
	bool plane_landing;
	int ammo;
};