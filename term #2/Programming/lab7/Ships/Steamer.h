#include "Ship.h"

class Steamer : public Ship {
public:
	explicit Steamer(const char* _country, const char* _name, int weight, double max_speed, bool add_to_list=false);
	explicit Steamer(const Steamer& s);

	void turn_on_the_engine();
	void turn_of_the_engine();

	void set_speed(double val);

	virtual void print_data() const override;

protected:
	double max_speed;
	double curr_speed;
private:
	bool is_engine_running;
};