//
// Created by admin on 2020/1/19.
//
#include <iostream>
#include <memory>

class Interviewer {
 public:
  virtual void askQuestions() = 0;
};

class Developer : public Interviewer {
 public:
  void askQuestions() override {
    std::cout << "Asking about design patterns!" << std::endl;
  }
};

class CommunityExecutive : public Interviewer {
  void askQuestions() override {
    std::cout << "Asking about community building" << std::endl;
  }
};

class HiringManager {
 protected:
  virtual std::unique_ptr<Interviewer> makeInterviewer() = 0;
 public:
  void takeInterview() {
    auto interviewer = this->makeInterviewer();
    interviewer->askQuestions();
  }
};

class DevelopmentManager : public HiringManager {
 protected:
  std::unique_ptr<Interviewer> makeInterviewer() override {
    return std::make_unique<Developer>();
  }
};
class MarketingManager : public HiringManager {
 protected:
  std::unique_ptr<Interviewer> makeInterviewer() override {
    return std::make_unique<CommunityExecutive>();
  }
};

int main() {
  auto devManager = new DevelopmentManager();
  devManager->takeInterview();

  auto marketingManager = new MarketingManager();
  marketingManager->takeInterview();
}
