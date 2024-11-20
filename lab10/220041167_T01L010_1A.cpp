 #include <iostream>
#include <string>
using namespace std;

class CharacterActions {
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() = 0;
    virtual ~CharacterActions() {}
};
class BaseCharacter : public CharacterActions {
protected:
    string name;
    int health;
    int mana;
    int attackPower;

public:
    BaseCharacter(string n, int h, int ap) : name(n), health(h), mana(0), attackPower(ap) {}

    virtual void attack() override {
        cout << name << " attacks with power " << attackPower << "!" << endl;
        mana += 50;
    }

    virtual void defend() override {
        cout << name << " defends! Attack blocked!" << endl;
    }

    virtual void useSpecialAbility() override = 0;

    virtual void displayStats() override {
        cout << name << " | Health: " << health << " | Mana: " << mana << endl;
    }

    int getHealth() const { return health; }
    void reduceHealth(int damage) { health -= damage; }

    string getName() const { return name; }
    int getMana() const { return mana; }
    void resetMana() { mana = 0; }
};

class Warrior : public BaseCharacter {
private:
    int specialPower;

public:
    Warrior() : BaseCharacter("Warrior", 100, 25), specialPower(35) {}

    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses Berserk Rage with power " << specialPower << "!" << endl;
            mana = 0;
        } else {
            cout << name << " doesn't have enough mana for Berserk Rage!" << endl;
        }
    }
};

class Mage : public BaseCharacter {
private:
    int specialPower;

public:
    Mage() : BaseCharacter("Mage", 120, 20), specialPower(30) {}

    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses Arcane Blast with power " << specialPower << "!" << endl;
            mana = 0;
        } else {
            cout << name << " doesn't have enough mana for Arcane Blast!" << endl;
        }
    }
};

class Archer : public BaseCharacter {
private:
    int specialPower;

public:
    Archer() : BaseCharacter("Archer", 90, 20), specialPower(35) {}

    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses Fire Arrow with power " << specialPower << "!" << endl;
            mana = 0;
        } else {
            cout << name << " doesn't have enough mana for Fire Arrow!" << endl;
        }
    }
};

class BossEnemy {
private:
    string name;
    int health;
    int attackPower;

public:
    BossEnemy() : name("Boss"), health(150), attackPower(30) {}

    void attack(BaseCharacter &target) {
        cout << name << " attacks " << target.getName() << " with power " << attackPower << "!" << endl;
        target.reduceHealth(attackPower);
    }

    void reduceHealth(int damage) { health -= damage; }
    int getHealth() const { return health; }
};


class GameEngine {
private:
    BaseCharacter *players[3];
    BossEnemy boss;

public:
    GameEngine() {
        players[0] = new Warrior();
        players[1] = new Mage();
        players[2] = new Archer();
    }

    ~GameEngine() {
        for (int i = 0; i < 3; i++) {
            delete players[i];
        }
    }

    void startGame() {
        cout << "Game begins! Players vs. Boss" << endl;

        while (boss.getHealth() > 0) {

            for (int i = 0; i < 3; i++) {
                if (players[i]->getHealth() > 0) {
                    players[i]->attack();
                    boss.reduceHealth(players[i]->getMana() >= 100 ? players[i]->getMana() : players[i]->getMana());
                }
            }

            for (int i = 0; i < 3; i++) {
                if (players[i]->getHealth() > 0) {
                    boss.attack(*players[i]);
                }
            }

            for (int i = 0; i < 3; i++) {
                if (players[i]->getMana() >= 100) {
                    players[i]->useSpecialAbility();
                    boss.reduceHealth(35);
                }
            }

            for (int i = 0; i < 3; i++) {
                players[i]->displayStats();
            }
            cout << "Boss Health: " << boss.getHealth() << endl;

            for (int i = 0; i < 3; i++) {
                if (players[i]->getHealth() <= 0) {
                    cout << players[i]->getName() << " has been defeated! Game over!" << endl;
                    return;
                }
            }
        }

        cout << "Boss defeated! Players win!" << endl;
    }
};

int main() {
    GameEngine game;
    game.startGame();
    return 0;
}
