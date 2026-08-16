#include <string>
#include <iostream>


class
Car {
protected:
  std::string brand;
  std::string model;
  bool isEngineOn;
  int currentSpeed;

public:
  Car(std::string brand, std::string model) {
    this->brand  = brand;
    this->model  = model;
    isEngineOn   = false;
    currentSpeed = 0;
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

  virtual void accelerate() = 0;
  virtual void brake() = 0;
  virtual ~Car() {}
};


class
ManualCar: public Car {
private:
  char currentGear;

public:
  ManualCar(std::string brand, std::string model): Car(brand, model) {
    currentGear = 'N';
  }

  void shiftGear(char gear) {
    if (!isEngineOn) {
      std::cout << brand << " " << model << " : Engine is off\n";
      return;
    }
    currentGear = gear;
    std::cout << brand << " " << model << " : Shifted to gear " << currentGear << '\n';
  }

  void accelerate() override {
    if (!isEngineOn) {
      std::cout << brand << " " << model <<  " : Engine is off\n";
      return;
    }
    currentSpeed += 20;
    std::cout << brand << " " << model << " : Accelerating to " << currentSpeed << '\n';
  }

  void brake() override {
    currentSpeed -= 20;
    if (currentSpeed < 0) currentSpeed = 0;
    std::cout << brand << " " << model << " : Braking to " << currentSpeed << '\n';
  }
};


class
ElectricCar: public Car {
private:
  int batteryLevel;

public:
  ElectricCar(std::string brand, std::string model): Car(brand, model) {
    batteryLevel = 100;
  }

  void chargeBattery() {
    batteryLevel = 100;
    std::cout << brand << " " << model << " : Battery fully charged\n";
  }

  int getBatteryLevel() {
    return batteryLevel;
  }

  void accelerate() override {
    if (!isEngineOn) {
      std::cout << brand << " " << model << " : Engine is off\n";
      return;
    }
    if (batteryLevel <= 0) {
      std::cout << brand << " " << model << " : Battery dead\n";
      return;
    }
    batteryLevel -= 10;
    currentSpeed += 15;
    std::cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h. Battery at " << batteryLevel << "%.\n";
  }

  void brake() override {
    currentSpeed -= 15;
    if (currentSpeed < 0) currentSpeed = 0;
    std::cout << brand << " " << model << " : Regenerative braking, speed is now " << currentSpeed << "km/h. Battery at " << batteryLevel << "%.\n";
  }
};


int
main(void) {
  ManualCar *myManualCar = new ManualCar("Suzuki", "WagonR");
  myManualCar->startEngine();
  myManualCar->shiftGear('1');
  myManualCar->accelerate();
  myManualCar->shiftGear('2');
  myManualCar->accelerate();
  myManualCar->brake();
  myManualCar->stopEngine();
  delete myManualCar;

  std::cout << "------------------------------\n";

  ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model S");
  myElectricCar->chargeBattery();
  myElectricCar->startEngine();
  myElectricCar->accelerate();
  myElectricCar->accelerate();
  myElectricCar->brake();
  myElectricCar->stopEngine();
  delete myElectricCar;

  return 0;
}
