#include "Ship.h"

class Parusnik : public Ship {
public:
	explicit Parusnik(const char* _country, const char* _name, int weight, bool add_to_list = false);
	explicit Parusnik(const Parusnik& p);

	virtual void raise_the_sails();
	virtual void lower_the_sails();

	virtual void print_data() const override;

private:
	bool sails_raised;
};