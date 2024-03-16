#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class gold_armor {
public:
	float* armor_ptr;
	float* new_speed;
	string* name_armor;

	gold_armor();
	~gold_armor();
};

class new_player {
public:
	float health;
	int level;
	float damage;
	float speed;
	float armor;
	float ex_armor;
	float real_armor;

	new_player();

	void takeDamage(float T_damage);
	void updateLevel(int newLevel);
	void getArmor(float newArmor, float newSpeed);
	void property();
};

class monster_1 {
public:
	float health;
	float armor;
	float damage;

	monster_1() {
		health = 50.f;
		armor = 50.f;
		damage = 20.f;
	}

	void takeDamage(float T_damage) {
		if (T_damage <= armor) {
			armor -= T_damage;
		}
		else if (T_damage > armor) {
			cout << " the armor of monster is broken!" << endl;
			health -= T_damage;
			armor = 0;
		}
	}
};

gold_armor::gold_armor() {

	armor_ptr = new float;
	*armor_ptr = 50.f;

	new_speed = new float(0.75);

	name_armor = new string(" gold armor ");

	cout << " I got a " << *name_armor << " now " << endl;
}

gold_armor::~gold_armor() {

	cout << " The " << *name_armor << " is broken now ! " << endl;

	delete armor_ptr;
	delete new_speed;
	delete name_armor;
}

new_player::new_player() {
	health = 100.f;
	damage = 10.f;
	level = 1;
	speed = 200;
	ex_armor = 0;
	real_armor = 50.f;
	armor = real_armor + ex_armor;

}

void new_player::updateLevel(int newLevel) {
	level += newLevel;
}

void new_player::takeDamage(float T_damage) {
	if (T_damage <= armor) {
		if ((ex_armor >= T_damage) && (ex_armor != 0)) {
			ex_armor -= T_damage;
		}
		else if (0 < ex_armor < T_damage) {
			cout << " the first armor of is brokrn " << endl;
			ex_armor -= T_damage;
			if (ex_armor < 0) {
				ex_armor = 0;
			}
		}
	} if ((real_armor > 0) && (ex_armor == 0)) {
		real_armor -= T_damage;
		if (real_armor <= 0) {
			cout << " the second armor is broken " << endl;
			real_armor = 0;
		}

	}
	else if (T_damage > armor) {
		cout << " all the armor of you is broken!" << endl;
		health -= T_damage;
		armor = 0;
	}
	armor = real_armor + ex_armor;
}

void new_player::getArmor(float newArmor, float newSpeed) {
	ex_armor = newArmor;
	armor = real_armor + ex_armor;
	speed = newSpeed * speed;

	cout << " Get a new armor ! " << endl;
}

void new_player::property() {
	cout << " My health is " << health << " now " << endl;
	cout << " My armor is " << armor << " now " << endl;
	cout << " My damage is " << damage << " now " << endl;
	cout << " My level is " << level << " now " << endl;
	cout << " My speed is " << speed << " now " << endl;
	cout << endl;
}


int main() {
	new_player qwq;
	monster_1 bad;
	qwq.property();
	gold_armor* Garmor = new gold_armor();
	qwq.getArmor(*(Garmor->armor_ptr), *(Garmor->new_speed));
	qwq.property();

	do {
		cout << " you make " << qwq.damage << " damage on monster " << endl;
		bad.takeDamage(qwq.damage);
		if (bad.health <= 0) {
			cout << endl;
			break;
		}
		cout << " monster have " << bad.health << " health remain " << endl;
		cout << " you have " << qwq.health << " health remain " << endl;
		cout << " your first and second armor have " << qwq.ex_armor << "   " << qwq.real_armor << " remain " << endl;
		cout << "\n";
		cout << " monster make " << bad.damage << " damage on you" << endl;
		qwq.takeDamage(bad.damage);
		if (qwq.health <= 0) {
			cout << endl;
			break;
		}
		cout << " monster have " << bad.health << " health remain " << endl;
		cout << " you have " << qwq.health << " health remain " << endl;
		cout << " your first and second armor have " << qwq.ex_armor << "   " << qwq.real_armor << " remain " << endl;
		cout << "\n";

	} while ((qwq.health > 0) && (bad.health > 0));

	if (qwq.health <= 0) {
		cout << " you lose " << endl;
	}
	else if (bad.health <= 0) {
		cout << " you win! " << endl;
		qwq.updateLevel(1);
		cout << " now your level is " << qwq.level << " ! " << endl;
	}
}
