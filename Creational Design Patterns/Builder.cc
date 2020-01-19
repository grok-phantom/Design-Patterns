//
// Created by admin on 2020/1/19.
//
class Burger;
class BurgerBuilder;

class Burger {
 protected:
  int size;
  bool cheese = false;
  bool pepperoni = false;
  bool lettuce = false;
  bool tomato = false;
 public:
  explicit Burger(BurgerBuilder *builder);
};

class BurgerBuilder {
 public:
  int size;
  bool cheese = false;
  bool pepperoni = false;
  bool lettuce = false;
  bool tomato = false;
  explicit BurgerBuilder(int size_) : size(size_) {};
  BurgerBuilder *addPepperoni() {
    this->pepperoni = true;
    return this;
  }
  BurgerBuilder *addLettuce() {
    this->lettuce = true;
    return this;
  }
  BurgerBuilder *addCheese() {
    this->cheese = true;
    return this;
  }
  BurgerBuilder *addTomato() {
    this->tomato = true;
    return this;
  }

  Burger *build() {
    return new Burger(this);
  }
};

Burger::Burger(BurgerBuilder *builder) {
  this->size = builder->size;
  this->cheese = builder->cheese;
  this->pepperoni = builder->pepperoni;
  this->lettuce = builder->lettuce;
  this->tomato = builder->tomato;
}

int main() {
  auto burger = (new BurgerBuilder(14))
      ->addPepperoni()
      ->addLettuce()
      ->addTomato()
      ->build();
}


