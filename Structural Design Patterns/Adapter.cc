//
// Created by admin on 2020/1/19.
//


class Lion {
 public:
  virtual void roar() = 0;
};

class AfricanLion : public Lion {
 public:
  void roar() override {}
};

class AsianLion : public Lion {
 public:
  void roar() override {}
};
class Hunter {
 public:
  static void hunt(Lion *lion) {
    lion->roar();
  }
};

class WildDog {
 public:
  void bark() {};
};

class WildDogAdapter : public Lion {
 protected:
  WildDog *dog;
 public:
  explicit WildDogAdapter(WildDog *dog) {
    this->dog = dog;
  }

  void roar() override {
    this->dog->bark();
  }
};

int main() {
  auto wildDog = new WildDog();
  auto wildDogAdapter = new WildDogAdapter(wildDog);

  auto hunter = new Hunter();
//  Hunter::hunt(wildDogAdapter);
  hunter->hunt(wildDogAdapter);
}