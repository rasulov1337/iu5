#include "Corvette.h"

Corvette::Corvette(const char* _country, const char* _name, int weight, double max_speed, int ammo, bool plane_landing, bool add_to_list) :
	Steamer(_country, _name, weight, max_speed, add_to_list), ammo(ammo), plane_landing(plane_landing) {

}

Corvette::Corvette(const Corvette& c) : Steamer(c) {
	ammo = c.ammo;
	plane_landing = c.plane_landing;
}

void Corvette::shoot(double northern_latitude, double eastern_longitude) {
	if (ammo <= 0) {
		cout << "Can't shoot! No ammo!\n";
		return;
	}

	cout << "Shots fired at " << northern_latitude << ' ' << eastern_longitude << '\n';
	--ammo;
	if (ammo > 0)
		cout << "Ammo left: " << --ammo << '\n';
	else
		cout << "No ammo left!\n";
}

void Corvette::print_data() const {
	this->Steamer::print_data();
	cout << "Ammo left: " << ammo << '\n'
		<< "Is plane landing supported: " << plane_landing << '\n';
}
