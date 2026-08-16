#include <string>
#include <iostream>


class
SportsCar {
private:
  std::string brand;
  std::string model;
  bool isEngineOn;
  int currentSpeed;
  char currentGear;
  std::string tyreCompany;

public:
  SportsCar(std::string brand, std::string model) {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 'N';
    tyreCompany = "MRF";
  }

  int speedOmeter() {
    return currentSpeed;
  }

  std::string getTyreCompany() {
    return tyreCompany;
  }

  void setTyreCompany(std::string tyreCompany) {
    this->tyreCompany = tyreCompany;
  }

  void startEngine() {
    isEngineOn = true;
    std::cout << brand << " " << model << " : Engine starts\n";
  }

  void shiftGear(char gear) {
    if (!isEngineOn) {
      std::cout << brand << " " << model << " : Engine is off\n";
      return;
    }
    currentGear = gear;
    std::cout << brand << " " << model << " : Shifted to gear " << currentGear << '\n';
  }

  void accelerate() {
    if (!isEngineOn) {
      std::cout << brand << " " << model << " : Engine is off\n";
      return;
    }
    currentSpeed += 20;
    std::cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h\n";
  }

  void brake() {
    currentSpeed -= 20;
    if (currentSpeed < 0) currentSpeed = 0;
    std::cout << brand << " " << model << " : Braked to " << currentSpeed << "km/h\n";
  }

  void stopEngine() {
    isEngineOn = false;
    currentGear = 'N';
    currentSpeed = 0;
    std::cout << brand << " " << model << " : Engine turned off\n";
  }
};


int
main(void) {
  SportsCar *myCar = new SportsCar("Ford", "Mustang");

  myCar->startEngine();
  myCar->shiftGear('1');
  myCar->accelerate();
  myCar->shiftGear('2');
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();

  // myCar->currentSpeed = 500;
  std::cout << "Current Speed: " << myCar->speedOmeter() << '\n';

  delete myCar;

  return 0;
}
