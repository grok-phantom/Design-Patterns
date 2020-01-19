//
// Created by admin on 2020/1/19.
//

#include <string>
#include <vector>
#include <iostream>

class Employee {
 public:
  Employee(const std::string& name, float salary){};
  virtual std::string getName() = 0;
  virtual void setSalary(float salary) = 0;
  virtual float getSalary() = 0;
  virtual std::vector<int> getRoles() = 0;
};

class Developer : public Employee {
 protected:
  float salary;
  std::string name;
  std::vector<int> roles;

 public:
  Developer(std::string name_, float salary_) : Employee(name_, salary_) {
    name = std::move(name_);
    salary = salary_;
  }

  std::string getName() override {
    return this->name;
  }

  void setSalary(float salary_) override {
    this->salary = salary_;
  }

  float getSalary() override {
    return this->salary;
  }

  std::vector<int> getRoles() override {
    return this->roles;
  }
};

class Designer : public Employee {
 protected:
  float salary;
  std::string name;
  std::vector<int> roles;

 public:
  Designer(std::string name_, float salary_) : Employee(name_, salary_) {
    name = std::move(name_);
    salary = salary_;
  }

  std::string getName() override {
    return this->name;
  }

  void setSalary(float salary_) override {
    this->salary = salary_;
  }

  float getSalary() override {
    return this->salary;
  }

  std::vector<int> getRoles() override {
    return this->roles;
  }
};

class Organization {
 protected:
  std::vector<Employee *> employees;
 public:
  void addEmployee(Employee *employee) {
    employees.push_back(employee);
  }
  float getNetSalaries() {
    float netSalary = 0;
    for (const auto &employee : employees) {
      netSalary += employee->getSalary();
    }
    return netSalary;
  }
};

int main() {
  auto john = new Developer("John Doe", 12000);
  auto jane = new Designer("Jane Doe", 15000);

  auto organization = new Organization();
  organization->addEmployee(john);
  organization->addEmployee(jane);

  std::cout << organization->getNetSalaries() << std::endl;
}