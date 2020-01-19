//
// Created by admin on 2020/1/19.
//

#include <iostream>
#include <memory>

class Door {
 public:
  virtual float getWidth() = 0;
  virtual float getHeight() = 0;
};

class WoodenDoor : public Door {
 protected:
  float width;
  float height;

 public:
  WoodenDoor(float _width, float _height) : width(_width), height(_height) {}
  float getWidth() override {
    return this->width;
  }
  float getHeight() override {
    return this->height;
  }
};

class DoorFactory {
 public:
  static std::unique_ptr<Door> makeDoor(float width, float height) {
    return std::make_unique<WoodenDoor>(width, height);
  }
};

int main() {
  auto door = DoorFactory::makeDoor(100, 200);
  std::cout << door->getWidth() << std::endl;
  std::cout << door->getHeight() << std::endl;
}
