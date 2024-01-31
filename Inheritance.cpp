#include <iostream>
#include<string>
#include<cassert>
#include<vector>
using namespace std;


class Engine {
	int _engine_no;
	string _company;
	int _volume;

public:
	Engine() : _engine_no(0), _volume(0) {}

	Engine(int engine, string company, int volume) {
		SetCompany(company);
		SetEngineNo(engine);
		SetVolume(volume);
	}

	int GetEngineNo() const { return _engine_no; }
	const string& GetCompany() const { return _company; }
	int GetVolume() const { return _volume; }

	void SetEngineNo(int engine) {
		if (engine > 5 && engine < 200)
			_engine_no = engine;
		else {
			assert("Engine Error!");
		}
	}

	void SetCompany(const string& company) {
		if (company.size() > 3 && company.size() < 100)
			_company = company;
		else {
			assert("Company Error");
		}
	}

	void SetVolume(int volume) {
		if (volume >= 5 && volume <= 300)
			_volume = volume;
		else {
			assert("Volume minimum 5 maximum 300 allowed.");
		}
	}

	void Print() const {
		cout << "Engine number: " << _engine_no << endl;
		cout << "Company: " << _company << endl;
		cout << "Volume: " << _volume;
	}
};

class Vehicle {
	static int _StaticId;
	int _id;
	string* _model;
	string* _vendor;
	Engine* _engine;
public:
	Vehicle() {
		_id = _StaticId++;
		_model = nullptr;
		_vendor = nullptr;
		_engine = nullptr;
	}
	Vehicle(string model, string vendor, Engine* engine) {
		SetModel(model);
		SetVendor(vendor);
		SetEngine(engine);
		_id = _StaticId++;
	}

	static int GetStaticId() { return _StaticId; }
	int GetId() { return _id; }
	string* GetModel() { return _model; }
	string* GetVendor() { return _vendor; }
	Engine* GetEngine() { return _engine; }

	static void SetStaticId(int value) {
		_StaticId = value;
	}
	void SetModel(string model) {
		if (model.size() > 4 && model.size() < 120)
			_model = new string(model);
		else { assert(!"Model minumum 4 maksimum 120 ola biler"); }
	}
	void SetVendor(string vendor) {
		if (vendor.size() >= 6 && vendor.size() < 200)
			_vendor = new string(vendor);
		else { assert(!"Vendor minumum 6 maksimum 200 ola biler"); }
	}
	void SetEngine(Engine* engine) {
		if (engine != nullptr)
			_engine = new Engine(*engine);
		else { assert(!"Engine is a Free"); }
	}
	void Print() {
		cout << "Id: " << _id << endl;
		cout << "Model: " << *_model << endl;
		cout << "Vendor: " << *_vendor << endl;
		if (_engine != nullptr) {
			_engine->Print();
		}
	}

	~Vehicle() {

		if (_model != nullptr) delete _model;
		if (_vendor != nullptr) delete _vendor;
		if (_engine != nullptr) delete _engine;

		_model = nullptr;
		_vendor = nullptr;
		_engine = nullptr;
	}
};

int Vehicle::_StaticId = 1;

class Car : public Vehicle {
	bool* _hasSpoiler;
public:
	Car() {
		_hasSpoiler = nullptr;
	}
	Car(string model, string vendor, Engine* engine, bool hasSpoiler) :Vehicle(model, vendor, engine) {
		SetHasSpoiler(hasSpoiler);
	}

	bool* GetHasSpoiler() { return _hasSpoiler; }
	void SetHasSpoiler(bool hasSpoiler) {
		if (hasSpoiler == true || hasSpoiler == false)
			_hasSpoiler = new bool(hasSpoiler);
		else { assert(!"Error!"); }
	}

	bool HasSpoiler(bool hasSpoiler) {
		return hasSpoiler;
	}

	void Print() {
		Vehicle::Print();
		cout << endl;
		cout << "HasSpoiler: " << (_hasSpoiler != nullptr ? (*_hasSpoiler ? "true" : "false") : "nullptr") << endl;
	}

	~Car() {
		if (_hasSpoiler != nullptr) delete _hasSpoiler;
		_hasSpoiler = nullptr;
	}
};

class Ship : public Vehicle {
	bool* _hasSail;
public:
	Ship() {
		_hasSail = nullptr;
	}
	Ship(string model, string vendor, Engine* engine, bool hasSail) :Vehicle(model, vendor, engine) {
		SetHasSail(hasSail);
	}

	bool* GetHasSail() { return _hasSail; }
	void SetHasSail(bool hasSail) {
		if (hasSail == true || hasSail == false)
			_hasSail = new bool(hasSail);
		else { assert(!"Error!"); }
	}

	bool HasSpoiler(bool hasSail) {
		return hasSail;
	}

	void Print() {
		Vehicle::Print();
		cout << endl;
		cout << "HasSail: " << (_hasSail != nullptr ? (*_hasSail ? "true" : "false") : "nullptr") << endl;
	}

	~Ship() {
		if (_hasSail != nullptr) delete _hasSail;
		_hasSail = nullptr;
	}
};

class Airplane : public Vehicle {
	int* _engineCount;
	int* _passengersCapacity;
public:
	Airplane() {
		_engineCount = nullptr;
		_passengersCapacity = nullptr;
	}
	Airplane(int engineCount, int passengersCapacity) {
		SetEngineCount(engineCount);
		SetPassengersCapacity(passengersCapacity);
	}

	int* GetEngineCount() { return _engineCount; }
	int* GetPassengersCapacity() { return _passengersCapacity; }

	void SetEngineCount(int engineCount) {
		if (engineCount >= 5 && engineCount <= 100) {
			_engineCount = new int(engineCount);
		}
		else { assert(!"Engine count minumum 5 maksimum 100 ola biler"); }
	}
	void SetPassengersCapacity(int passengersCapacity) {
		if (passengersCapacity >= 20 && passengersCapacity <= 100) {
			_passengersCapacity = new int(passengersCapacity);
		}
		else { assert(!"Passengers Capacity minumum 20 maksimum 100 ola biler"); }
	}


	void Print() {
		Vehicle::Print();
		cout << "Engine Count: " << (*_engineCount) << endl;
		cout << "Passengers Capacity: " << (*_passengersCapacity) << endl;
	}

	~Airplane() {
		if (_engineCount != nullptr) delete _engineCount;
		if (_passengersCapacity != nullptr) delete _passengersCapacity;
		_engineCount = nullptr;
		_passengersCapacity = nullptr;
	}
};

class VehicleDepo {
	vector<Car>cars;
	vector<Ship>ships;
	vector<Airplane>airplanes;
public:
	vector<Car>& GetCars() { return cars; }
	void SetCars(Car** cars, int count) {
		if (cars != nullptr && count > 0) {
			this->cars.clear();

			for (int i = 0; i < count; i++) {
				this->cars.push_back(*cars[i]);
			}
		}
		else {
			assert(!"Invalid input: cars is nullptr or count is not greater than 0");
		}
	}
	void AddCar(const Car& car) {
		cars.push_back(car);
	}
	void RemoveCar() {
		if (!cars.empty()) {
			cars.pop_back();
		}
		else { assert(!"Depo is empty!"); }
	}
	Car* RemoveCarsById(int id) {
		for (size_t i = 0; i < cars.size(); i++)
			if (cars[i].GetId() == id)
				return &cars[i];
		return NULL;
	}

	vector<Ship>& GetShips() { return ships; }

	void SetShips(Ship** ships, int count) {
		if (ships != nullptr && count > 0) {
			this->ships.clear();

			for (int i = 0; i < count; i++) {
				this->ships.push_back(*ships[i]);
			}
		}
		else {
			assert(!"Invalid input: ships is nullptr or count is not greater than 0");
		}
	}

	void AddShip(const Ship& ship) {
		ships.push_back(ship);
	}

	void RemoveShip() {
		if (!ships.empty()) {
			ships.pop_back();
		}
		else {
			assert(!"Depo is empty!");
		}
	}

	Ship* RemoveShipsById(int id) {
		for (size_t i = 0; i < ships.size(); i++)
			if (ships[i].GetId() == id)
				return &ships[i];
		return nullptr;
	}

	vector<Airplane>& GetAirplanes() { return airplanes; }

	void SetAirplanes(Airplane** airplanes, int count) {
		if (airplanes != nullptr && count > 0) {
			this->airplanes.clear();

			for (int i = 0; i < count; i++) {
				this->airplanes.push_back(*airplanes[i]);
			}
		}
		else {
			assert(!"Invalid input: airplanes is nullptr or count is not greater than 0");
		}
	}

	void AddAirplane(const Airplane& airplane) {
		airplanes.push_back(airplane);
	}

	void RemoveAirplane() {
		if (!airplanes.empty()) {
			airplanes.pop_back();
		}
		else {
			assert(!"Depo is empty!");
		}
	}

	Airplane* RemoveAirplanesById(int id) {
		for (size_t i = 0; i < airplanes.size(); i++)
			if (airplanes[i].GetId() == id)
				return &airplanes[i];
		return nullptr;
	}
	void ShowAllVehicles() const {
		cout << "Cars:\n";
		Car car;
		car.Print();

		cout << "\nShips:\n";
		Ship ship;
		ship.Print();

		cout << "\nAirplanes:\n";
		Airplane airplane;
		airplane.Print();
	}
};

void main() {
	Engine* engine = new Engine(97, "BAKU", 260);

	Car bmw("Bmw-X3", "E63 BMW M6", engine, true);
	Car prado("Prado", "Toyota", engine, false);

	cout << "Car Information:\n";
	cout << endl;
	bmw.Print();
	cout << endl;

	prado.Print();
	cout << endl;

	Ship titanic("Titanic", "White Star Line", engine, true);
	Ship queenMary("Queen Mary", "Cunard Line", engine, false);

	Airplane boeing747(6, 70);
	Airplane airbusA380(5, 90);

	cout << "Ships Information:\n " << endl;
	titanic.Print();
	cout << endl;
	queenMary.Print();

	/*VehicleDepo depo;

	depo.AddCar(bmw);
	depo.AddCar(prado);

	depo.AddShip(titanic);
	depo.AddShip(queenMary);

	depo.AddAirplane(boeing747);
	depo.AddAirplane(airbusA380);*/

	/*int carIdToRemove = 2;
	Car* removedCar = depo.RemoveCarsById(carIdToRemove);
	if (removedCar != nullptr) 
	{
		cout << endl;
		cout << "Removed Car with ID " << carIdToRemove << endl;
		removedCar->Print();
	}
	else {
		cout << "Car with ID " << carIdToRemove << " not found in the depo.";
	}

	depo.ShowAllVehicles();*/

	delete engine;
}