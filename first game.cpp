#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


struct new_player {
	float health;
	int level;
	float damage;
	float stamina;
	float armor;

	new_player();

	void takeDamage(float T_damage);
	void updateLevel(int newLevel);

};

new_player::new_player() {
	health = 100.f;
	armor = 50.f;
	damage = 30.f;
	level = 1;
	stamina = 200;

}

void new_player::updateLevel(int newLevel) {
	level += newLevel;
}

void new_player::takeDamage(float T_damage) {
	if (T_damage <= armor) {
		armor -= T_damage;
	}
	else if (T_damage > armor) {
		cout << " the armor of you is broken!" << endl;
		health -= T_damage - armor;
		armor = 0;
	}
}

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
			health -= T_damage - armor;
			armor = 0;
		}
	}


};

int main() {

	new_player qwq;
	monster_1 bad;

	cout << " the health of qwq is " << qwq.health << " now " << endl;
	cout << " the armor of qwq is " << qwq.armor << " now " << endl;
	cout << " the level of qwq is " << qwq.level << " now " << endl;
	cout << endl;

	do {
		cout << " you make " << qwq.damage << " damage on monster " << endl;
		bad.takeDamage(qwq.damage);
		cout << " monster have " << bad.health << " health remain " << endl;
		cout << " you have " << qwq.health << " health remain " << endl;
		cout << "\n";
		cout << " monster make " << bad.damage << " damage on you" << endl;
		qwq.takeDamage(bad.damage);
		cout << " monster have " << bad.health << " health remain " << endl;
		cout << " you have " << qwq.health << " health remain " << endl;
		cout << "\n";
	} while ((qwq.health > -10) && (bad.health > -3));

	if (qwq.health <= 0) {
		cout << " you lose " << endl;
	}
	else if (bad.health <= 0) {
		cout << " you win! " << endl;
		qwq.updateLevel(1);
		cout << " now your level is " << qwq.level << " ! " << endl;
	}

}

