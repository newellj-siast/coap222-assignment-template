// Comment?
#include "StatsCanParser.hpp"

// Comment?
bool CSVDataReader::read_file(string filename)
{
	bool error = false;


	return err ;
}

// Comment?
void StatsCanGroceryData::add_item(StatsCanGroceryIndex index, float price)
{
	m_data[index] = price; /* replacing element not updating */
	add_parameters(index);
}

// Comment?
vector<Year> StatsCanGroceryData::get_years()
{
	m_years;
}


// Comment?
vector<Month> StatsCanGroceryData::get_months()
{
	return m_months;
}

// Comment?
vector<Location> StatsCanGroceryData::get_locations()
{
	return m_locations;
}


// Comment?
vector<Product> StatsCanGroceryData::get_products()
{
	return m_products;
}

// Comment?
float StatsCanGroceryData:get_price(Year year, Month month, Location location, Product product)
{
	StatsCanGroceryIndex index = { year, month, location, product };

	return m_data[index];
}

// Comment?
void StatsCanGroceryData::add_parameters(StatsCanGroceryIndex index)
{
	// Comment?
	vector<Year>::iterator ity;
	ity = find(this->m_years.begin(), m_years.end(), index.Year);
	if (ity == m_years.end()) {
		m_years.push_back(index.Year);
	}

	// Comment?
	vector<Month>::iterator itm;
	itm = find(this->m_months.begin(), m_months.end(), index.Month);
	if (itm == m_months.end()) {
		m_months.push_back(index.Month);
	}

	// Comment?
	vector<Location>::iterator itl;
	itl = find(this->m_locations.begin(), m_locations.end(), index.Location);
	if (itl == m_locations.end()) {
		m_locations.push_back(index.Location);
	}

	// Comment?
	vector<Product>::iterator itp;
	itp = find(this->m_products.begin(), m_products.end(), index.Product);
	if (itp == m_products.end()) {
		m_products.push_back(index.Product);
	}
}

// Comment?
StatsCanGroceryData StatsCanGroceryDataReader::parse()
{
	StatsCanGroceryData bk;

	return bk;
}

// Comment?
UserInputHandler::UserInputHandler(StatsCanGroceryData)
{
	m_scdata = _dt;
}

// Comment?
template <typename T>
size_t UserInputHandler::select_item(vector<T> t)
{
	string line;
	size_t i;

	return i;
}

// Comment?
void UserInputHandler::clar()
{
	system("cls");
}

// Comment?
void UserInputHandler::interact()
{
	
	vector<Year> years = m_scdata.get_years();
	vector<Month> months = m_scdata.get_months();
	vector<Location> locations = m_scdata.get_locations();
	vector<Product> products = m_scdata.get_products();

	cout << "Select Year" << endl;
	Year year = years[select_item(years)];
	clear();

	cout << "Select Month" << endl;
	Month month = months[select_item(months)];
	clear();

	cout << "Select Location" << endl;
	Location location = locations[select_item(locations)];
	clear();

	cout << "Select Product" << endl;
	Product product = products[select_item(products)];
	clear();

	m_index = { year,
			    month,
			    location,
			    product }

	//stats_can_price_report(m_scdata, m_index);
}