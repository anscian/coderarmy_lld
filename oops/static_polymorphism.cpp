#include <string>
#include <iostream>


class
ManualCar {
private:
  std::string brand;
  std::string model;
  bool isEngineOn;
  int currentSpeed;
  char currentGear;

public:
  ManualCar(std::string brand, std::string model) {
    this->brand  = brand;
    this->model  = model;
    isEngineOn   = false;
    currentSpeed = 0;
    currentGear = 'N';
  }

  void startEngine() {
    isEngineOn = true;
    std::cout << brand << " " << model << " : Engine starts\n";
  }

  void stopEngine() {
    isEngineOn = false;
    currentSpeed = 0;
    std::cout << brand << " " << model << " : Engine turned off\n";
  }

  void shiftGear(char gear) {
    if (!isEngineOn) {
      std::cout << brand << " " << model << " : Engine is off\n";
      return;
    }
    currentGear = gear;
    std::cout << brand << " " << model << " : Shifted to gear " << currentGear << '\n';
  }

  void accelerate(int speed) {
    if (!isEngineOn) {
      std::cout << brand << " " << model <<  " : Engine is off\n";
      return;
    }
    currentSpeed += speed;
    std::cout << brand << " " << model << " : Accelerating to " << currentSpeed << '\n';
  }

  void accelerate() {
    this->accelerate(20);
  }

  void brake() {
    currentSpeed -= 20;
    if (currentSpeed < 0) currentSpeed = 0;
    std::cout << brand << " " << model << " : Braking to " << currentSpeed << '\n';
  }
};


int
main(void) {
  ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
  myManualCar->startEngine();
  myManualCar->shiftGear('1');
  myManualCar->accelerate();
  myManualCar->shiftGear('2');
  myManualCar->accelerate(40);
  myManualCar->brake();
  myManualCar->stopEngine();
  delete myManualCar;

  return 0;
}
