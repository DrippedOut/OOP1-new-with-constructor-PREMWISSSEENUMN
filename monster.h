#ifndef monster_h
#define monster_h

class monster {
private:
  string name;
  int hp, age, potion;

public:
  bool operator==(monster);
  void operator++() { hp++; }
  void operator+=(int healthPoint) {
    hp += healthPoint;
    cout << name << "'s HP is increased by " << healthPoint << endl;
  }
  void operator-=(int healthPoint) {
    hp -= healthPoint;
    cout << name << "'s HP is decreased by " << healthPoint << endl;
  }
  void Attack(monster &target); // Decrease &'s hp
  void print();                 // to print all data

  monster(string = "Bot", int = 0, int = 0);
  // Alt+126
  ~monster();
};

// Compare monsters by hp
bool monster::operator==(monster x) { return hp == x.hp; }

monster::monster(string n, int a, int h, int p) {
  name = n;
  age = a;
  hp = h;
  potion = p;

  printf("/===========================================\\ \n");
  cout << "New monster is summoned! Its name is " << name << endl;
  cout << "HP: " << hp << " Potion: " << potion << endl;
  printf("\\===========================================/ \n \n");
}
void monster::Attack(monster &target) {
  int damage = 10;
  target -= damage;
  cout << name << " attacked " << target.name << " and dealt " << damage
       << " damage!" << endl;

  if (target.hp < 0) {
    cout << target.name << " is knocked out by" << name << endl;
  }
}
monster::~monster() {
  cout << name << " is brutally killed in a vehicular manslaughter \n" << endl;
}
void monster::print() {
  cout << "Name: " << name << endl;
  cout << "HP: " << hp << endl;
  cout << "Potion: " << potion << endl;
  cout << "Age: " << age << endl;
}
#endif