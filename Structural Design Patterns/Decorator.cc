//
// Created by admin on 2020/1/19.
//

#include <string>

class Coffee {
 public:
  virtual int getCost() = 0;
  virtual std::string getDescription() = 0;
};

class SimpleCoffee : public Coffee {
 public:
  int getCost() override {
    return 10;
  }

  std::string getDescription() override {
    return "Simple coffee";
  }
};

class MilkCoffee : public Coffee {
 protected:
  Coffee *coffee_;
 public:
  explicit MilkCoffee(Coffee *coffee) : coffee_(coffee) {};

  int getCost() override {
    return coffee_->getCost() + 2;
  }

  std::string getDescription() override {
    return coffee_->getDescription() + ", milk";
  }
};

class WhipCoffee : public Coffee {
 protected:
  Coffee *coffee_;

 public:
  explicit WhipCoffee(Coffee *coffee) : coffee_(coffee) {};

  int getCost() override {
    return coffee_->getCost() + 5;
  }

  std::string getDescription() override {
    return coffee_->getDescription() + ", whip";
  }
};
class VanillaCoffe : public Coffee {
 protected:
  Coffee *coffee_;

 public:
  explicit VanillaCoffe(Coffee *coffee) : coffee_(coffee) {};

  int getCost() override {
    return coffee_->getCost() + 3;
  }

  std::string getDescription() override {
    return coffee_->getDescription() + ", vanilla";
  }
};
