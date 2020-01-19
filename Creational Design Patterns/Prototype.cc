//
// Created by admin on 2020/1/19.
//

#include <iostream>
#include <string>

class Sheep {
 protected:
  std::string name;
  std::string category;

 public:
  explicit Sheep(std::string name_, std::string category_ = "Mountain Sheep") {
    name = std::move(name_);
    category = std::move(category_);
  };

  void setName(std::string name_) {
    name = std::move(name_);
  }
  std::string getName() {
    return name;
  }

  void setCategory(std::string category_) {
    category = std::move(category_);
  }

  std::string getCategory() {
    return category;
  }

  Sheep *clone() const {
    return new Sheep(*this);
  }
};

int main() {
  auto original = new Sheep("Jolly");
  std::cout << original->getName() << std::endl;
  std::cout << original->getCategory() << std::endl;

  auto cloned = original->clone();
  cloned->setName("Dolly");
  std::cout << cloned->getName() << std::endl;
  std::cout << cloned->getCategory() << std::endl;
}


