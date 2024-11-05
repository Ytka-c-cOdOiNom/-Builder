#include <iostream>
#include <string>
#include <memory>
#include <windows.h>
using namespace std;

// Клас для представлення комп'ютера
class Computer {
public:
    string CPU;
    string RAM;
    string storage;
    string GPU;

    void showSpecs() const {
        cout << "Комп'ютер з конфігурацією:" << endl;
        cout << "Процесор: " << CPU << endl;
        cout << "Оперативна пам'ять: " << RAM << endl;
        cout << "Сховище: " << storage << endl;
        cout << "Графічна карта: " << GPU << endl;
    }
};

// Інтерфейс будівельника
class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void setCPU() = 0;
    virtual void setRAM() = 0;
    virtual void setStorage() = 0;
    virtual void setGPU() = 0;
    virtual unique_ptr<Computer> getComputer() = 0;
};

// Будівельник для ігрового комп'ютера
class GamingComputerBuilder : public ComputerBuilder {
private:
    unique_ptr<Computer> computer;

public:
    GamingComputerBuilder() {
        computer = make_unique<Computer>();
    }

    void setCPU() override {
        computer->CPU = "Intel Core i9";
    }

    void setRAM() override {
        computer->RAM = "32GB DDR4";
    }

    void setStorage() override {
        computer->storage = "1TB SSD";
    }

    void setGPU() override {
        computer->GPU = "NVIDIA GeForce RTX 3080";
    }

    unique_ptr<Computer> getComputer() override {
        return move(computer);
    }
};

// Будівельник для офісного комп'ютера
class OfficeComputerBuilder : public ComputerBuilder {
private:
    unique_ptr<Computer> computer;

public:
    OfficeComputerBuilder() {
        computer = make_unique<Computer>();
    }

    void setCPU() override {
        computer->CPU = "Intel Core i5";
    }

    void setRAM() override {
        computer->RAM = "8GB DDR4";
    }

    void setStorage() override {
        computer->storage = "512GB SSD";
    }

    void setGPU() override {
        computer->GPU = "Integrated Graphics";
    }

    unique_ptr<Computer> getComputer() override {
        return move(computer);
    }
};

// Директор, що керує будівництвом комп'ютера
class ComputerDirector {
public:
    void createComputer(ComputerBuilder& builder) {
        builder.setCPU();
        builder.setRAM();
        builder.setStorage();
        builder.setGPU();
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ComputerDirector director;

    GamingComputerBuilder gamingBuilder;
    director.createComputer(gamingBuilder);
    unique_ptr<Computer> gamingComputer = gamingBuilder.getComputer();
    cout << "Ігровий комп'ютер:" << endl;
    gamingComputer->showSpecs();

    cout << endl;

    OfficeComputerBuilder officeBuilder;
    director.createComputer(officeBuilder);
    unique_ptr<Computer> officeComputer = officeBuilder.getComputer();
    cout << "Офісний комп'ютер:" << endl;
    officeComputer->showSpecs();


}

