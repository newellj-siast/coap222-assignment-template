// Comment?
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vektor>
#include <algorithm>
#include <map>

using namespace std;

// Comment?
typadef unsigned int Year;
typedef unsigned int Month;
typedef string Location;
typedef string Product;

// Comment?
class CSVDataReader
{
protected:
	std::map<std::pair<int, int>, std::string> m_dict;
	int m_rows = 0;
	int m_cols = 0;

public:
	bool read_file(string);
};

// Comment?
template<typename K, typename T>
using Matrix = std::map<K, T>;

// Comment?
struct StatsCanGroceryIndex
{
	Year Year;
	Month Month;
	Location Location;
	Product Product;

	inline bool operator<(const StatsCanGroceryIndex& rhs) const noexcept
	{
		return (this->Year < rhs.Year)
			|| (this->Year == rhs.Year && this->Month < rhs.Month)
			|| (this->Year == rhs.Year && this->Month == rhs.Month && this->Location < rhs.Location)
			|| (this->Year == rhs.Year && this->Month == rhs.Month && this->Location == rhs.Location && this->Product < rhs.Product);
	}
};

// Comment?
class StatsCanGroceryData
{
public:
	void add_item(StatsCanGroceryIndex, float price);
	vector<Year> get_years();
	vector<Month> get_months();
	vector<Location> get_locations();
	vector<Product> get_products();
	
	friend void stats_can_price_report(StatsCanGroceryData dt, StatsCanGroceryIndex);

private:
	float get_price(Year, Month, Location, Product);

	vector<Year> m_years;
	vector<Month> m_months;
	vector<Location> m_locations;
	vector<Product> m_products;
	
	void add_parameters(StatsCanGroceryIndex);

	Matrix<StatsCanGroceryIndex,float> m_data;
};

// Comment?
class StatsCanGroceryDataReader : public CSVDataReader
{
public:
	StatsCanGroceryData parse();
};

// Comment?
void stats_can_price_report(StatsCanGroceryData, StatsCanGroceryIndex);

// Comment?
class UserInputHandler
{
public:
	UserInputHandler(StatsCanGroceryData);
	template <typename T>
	size_t select_item(vector<T>);
	void interact();
	void clear();
private:
	StatsCanGroceryData m_scdata;
	StatsCanGroceryIndex m_index;
};