//
// Created by admin on 2020/1/19.
//
#include <string>
#include <iostream>
class Theme {
 public:
  virtual std::string getColor() = 0;
};

class WebPage {
 public:
  explicit WebPage(Theme *theme) {};
  virtual std::string getContent() = 0;
};

class About : public WebPage {
 protected:
  Theme *theme_;
 public:
  explicit About(Theme *theme) : WebPage(theme) {
    this->theme_ = theme;
  }
  std::string getContent() override {
    return "About page in " + this->theme_->getColor();
  }
};

class Careers : public WebPage {
 protected:
  Theme *theme_;
 public:
  explicit Careers(Theme *theme) : WebPage(theme) {
    this->theme_ = theme;
  }
  std::string getContent() override {
    return "Careers page in " + this->theme_->getColor();
  }
};

class DarkTheme : public Theme {
 public:
  std::string getColor() override {
    return "Dark Black";
  }
};
class LightTheme : public Theme {
 public:
  std::string getColor() override {
    return "Off white";
  }
};
class AquaTheme : public Theme {
 public:
  std::string getColor() override {
    return "Light blue";
  }
};

int main() {
  auto darkTheme = new DarkTheme();

  auto about = new About(darkTheme);
  auto careers = new Careers(darkTheme);

  std::cout << about->getContent() << std::endl;
  std::cout << careers->getContent() << std::endl;
}
