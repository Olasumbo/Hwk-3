// L9_Ex1_Stocks.cpp

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

// Class definition. Notice the data members and function members (methods).
class Stock
{
	private:
		//string company;
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot()
		{
			total_val = shares * share_val; 
		}
		Stock acquire(const char * co, int n, double pr);
		Stock acquire(const char * company );
		
	public:
		//void acquire(const string co, int n, double pr);
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();

		//Constructors
		Stock();   // default, no arguments.
		Stock(const char* string, int n, double pr); // parametric constructor
		Stock( char *company );

};	// notice the 


int main()
{	
	//Stock stock1, stock2;	// Objects of class Stock // Stock is like a type  " int "
	
	//stock1.acquire("NanoSmart", 20, 12.50); // We cant call acquire anymore since it is private
	Stock stock1;
	stock1.display();
	stock1.buy(1, 3.99);
	cout << endl;
	
	Stock stock2("Amazon", 13, 100);
	stock2.display();
	stock2.buy(1, 2.00);
	stock2.sell(1, 8.99);
	cout << endl;

	Stock stock3("Ameren", 20, 12.50);
	stock3.buy(1, 4.09);
	stock3.sell(1, 5.99);
	stock3.update(24.00);
	stock3.display();
	
	cout << "\nDone..." << endl;

	return 0;
}

Stock::Stock()
{
	shares = 0;
	share_val = 0;
	set_tot();
}

Stock::Stock( char *company )
{
	shares = 0;
	share_val = 0;
	set_tot();
	acquire( company );
}

Stock::Stock(const char* string, int n, double pr)
{
	acquire(string, n, pr);
}

Stock Stock::acquire(const char *co, int n, double pr)
{
	strncpy(company, co, 29); ///(Dest, Source, Size)
	company[29] = '\0';
	if(n < 0)
	{
		cerr << "Number of shares can't be negative; "<< company << " shares set to 0.\n";
		shares = 0;			
	}
	else
	{
		shares = n;
		cout << "Updated shares." << endl;

	}
	share_val = pr;
	set_tot();

}
Stock Stock::acquire(const char *co) 
{
	strncpy(company, co, 29);
	company[29] = '\0';
	shares = 0;
	share_val = 0.0;
	set_tot();
}
void Stock::buy(int num, double price)
{
	if(num < 0)
	{
		shares = shares + 0;
		cout << "Number of shares can't be negative." << endl;
		cout << "Buying 0 shares." << endl;
	}
	else
	{
		shares = shares + num;
		share_val += (price * num); 
		cout << "Bought " << num << " shares of " << company << " for $" << price << " per share." << endl;
	}
	set_tot();
}
void Stock::sell(int num, double price)
{
	if(num < 0)
	{
		shares = shares - 0;
		std::cout << "Number of shares can't be negative." << endl;
		std::cout << "Selling 0 shares." << endl;
	}
	else
	{
		shares = shares - num;
		share_val -= (price * num); 
		cout << "Sold " << num << " share(s) "" of " << company << " for $" << price << " per share." << std::endl;
	}
	set_tot();
}
void Stock::update(double price)
{
	if( price < 0.0)
	{
		share_val = 0.0;
		cout << "Share price can't be negative." << endl;
		cout << "Setting share value to $0.00" << endl;
	}
	else
	{
		share_val = price;
		cout << "Setting share price to $" << price << endl;
	}
	set_tot();
}
void Stock::display()
{
	cout << "Company: " << company << endl;
	cout << "Number of Shares: " << shares << endl;
	cout << "Share Value: " << share_val << endl;
	cout << "Total Value: " << total_val << endl;
}
