#include "Parusnik.h"

Parusnik::Parusnik(const char* _country, const char* _name, int weight, bool add_to_list) : Ship(_country, _name, weight, add_to_list), sails_raised(false) {

}

Parusnik::Parusnik(const Parusnik& p) : Ship(p) {
	sails_raised = p.sails_raised;
}

void Parusnik::raise_the_sails() {
	if (sails_raised)
		cout << "Паруса уже подняты!\n";
	else {
		cout << "Поднять паруса!\n";
		sails_raised = true;
	}
}

void Parusnik::lower_the_sails() {
	if (!sails_raised)
		cout << "Паруса уже опущены!\n";
	else {
		cout << "Спустить паруса!\n";
		sails_raised = false;
	}
}

void Parusnik::print_data() const {
	cout << "Steamer's characteristics:\n"
		<< "Name: " << name << '\n'
		<< "Country: " << country << '\n'
		<< "Weight: " << weight << '\n'
		<< "Number of people: " << number_of_people << '\n'
		<< "Sails status: " << (sails_raised ? "raised\n" : "lowered\n");
}
