#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class creature {
public:
	string type;
	float strong;
	float weight;

	creature();
	creature(string new_type, float new_strong, float new_weight);

	void property() {
		cout << " I am a " << type << " now " << endl;
		cout << " My strength is " << strong << " now " << endl;
		cout << " My weight is " << weight << " kg now " << endl;
		cout << endl;
	}

	virtual void class_level();
};

creature::creature() {
	//type = "default_name";
	//strong = 50.f;
	//weight = 100.f;
}

creature::creature(string new_type, float new_strong, float new_weight) {
	type = new_type;
	strong = new_strong;
	weight = new_weight;
}

void creature::class_level() {
	cout << " This is the first later class " << endl;
	cout << endl;
}

class human : public creature {
public:
	human();
	human(string new_type, float new_strong, float new_weight) :creature(new_type, new_strong, new_weight) {}

	virtual void class_level() override {
		cout << " This is the second later class " << endl;
		cout << endl;
	}
};

human::human() {

}

class black_people : public human {
public:
	black_people();
	black_people(string new_type, float new_strong, float new_weight) :human(new_type, new_strong, new_weight) {}

	virtual void class_level() override {
		cout << " This is the third later class " << endl;
		cout << endl;
	}
};

black_people::black_people() {
	type = "black_people";
	strong = 75.f;
	weight = 70.f;

}

class yellow_people : public human {
public:
	yellow_people();
	yellow_people(string new_type, float new_strong, float new_weight) :human(new_type, new_strong, new_weight) {}

	virtual void class_level() override {
		cout << " This is the third later class " << endl;
		cout << endl;
	}
};

yellow_people::yellow_people() {
	type = "yellow_people";
	strong = 50.f;
	weight = 80.f;
}

int main() {
	human a("zombie", 20, 60);
	a.property();
	a.class_level();
	human b;
	b.property();
	b.class_level();
	yellow_people c("zombie", 30, 25);
	c.property();
	c.class_level();
	yellow_people d;
	d.property();
	d.class_level();
	black_people e("zombie", 10, 30);
	e.property();
	e.class_level();
	black_people f;
	f.property();
	f.class_level();

	creature* ptr_creature = new creature();
	creature* ptr_human = new human();
	creature* ptr_black_people = new black_people();
	creature* ptr_yellow_people = new yellow_people();

	ptr_creature->class_level();
	ptr_human->class_level();
	ptr_black_people->class_level();
	ptr_yellow_people->class_level();

	creature* array_of_ptr[] = { ptr_creature, ptr_human, ptr_black_people, ptr_yellow_people };
	for (int i = 0; i < 4; i++) {
		array_of_ptr[i]->class_level();
	}
}