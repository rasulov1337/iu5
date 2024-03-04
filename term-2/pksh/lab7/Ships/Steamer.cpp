#include "Steamer.h"


Steamer::Steamer(const char* _country, const char* _name, int weight, double max_speed, bool add_to_list) : Ship(_country, _name, weight, add_to_list),
			max_speed(max_speed), is_engine_running(false), curr_speed(0) { }

Steamer::Steamer(const Steamer& s) : Ship(s) {
	max_speed = s.max_speed;
	is_engine_running = s.is_engine_running;
	curr_speed = s.curr_speed;
}

void Steamer::turn_on_the_engine()
{
	is_engine_running = true;
}

void Steamer::turn_of_the_engine()
{
	is_engine_running = false;
	curr_speed = 0;
}

void Steamer::set_speed(double val)
{
	if (!is_engine_running) {
		cout << "Please turn on the engine first!\n";
		return;
	}
	else if (val < 0 || val > max_speed) {
		cout << "Couldn't change steamer's velocity: Invalid range!\n";
		return;
	}
	curr_speed = val;
	cout << "Set engine speed to " << val << '\n';
}

void Steamer::print_data() const
{
	cout << "Steamer's characteristics:\n"
		<< "Name: " << name << '\n'
		<< "Country: " << country << '\n'
		<< "Weight: " << weight << '\n'
		<< "Number of people: " << number_of_people << '\n'
		<< "Is engine running: " << is_engine_running << '\n'
		<< "Max speed: " << max_speed << '\n'
		<< "Current speed: " << curr_speed << '\n';
}
