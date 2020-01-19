//
// Created by admin on 2020/1/19.
//

#include <iostream>
#include <memory>

class Door {
 public:
  virtual void getDescription() = 0;
};

class WoodenDoor : public Door {
 public:
  void getDescription() override {
    std::cout << "I am a wooden door" << std::endl;
  }
};

class IronDoor : public Door {
 public:
  void getDescription() override {
    std::cout << "I am a iron door" << std::endl;
  }
};

class DoorFittingExpert {
 public:
  virtual void getDescription() = 0;
};

class Welder : public DoorFittingExpert {
 public:
  void getDescription() override {
    std::cout << "I can only fit iron doors" << std::endl;
  }
};

class Carpenter : public DoorFittingExpert {
 public:
  void getDescription() override {
    std::cout << "I can only fit wooden doors" << std::endl;
  }
};

class DoorFactory {
 public:
  virtual std::unique_ptr<Door> makeDoor() = 0;
  virtual std::unique_ptr<DoorFittingExpert> makeFittingExpert() = 0;
};

class WoodenDoorFactory : public DoorFactory {
 public:
  std::unique_ptr<Door> makeDoor() override {
    return std::make_unique<WoodenDoor>();
  }

  std::unique_ptr<DoorFittingExpert> makeFittingExpert() override {
    return std::make_unique<Carpenter>();
  }
};

class IronDoorFactory : public DoorFactory {
 public:
  std::unique_ptr<Door> makeDoor() override {
    return std::make_unique<IronDoor>();
  }

  std::unique_ptr<DoorFittingExpert> makeFittingExpert() override {
    return std::make_unique<Welder>();
  }
};

int main() {
  auto woodenFactory = new WoodenDoorFactory();
  auto wooden_door = woodenFactory->makeDoor();
  auto wooden_expert = woodenFactory->makeFittingExpert();

  wooden_door->getDescription();
  wooden_expert->getDescription();

  auto ironFactory = new IronDoorFactory();
  auto iron_door = ironFactory->makeDoor();
  auto iron_expert = ironFactory->makeFittingExpert();

  iron_door->getDescription();
  iron_expert->getDescription();
}