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
		string company;
		int shares;
		double share_val;
		double total_val;
		void set_tot()
		{
			total_val = shares * share_val; 
		}
		
	public:
		void acquire(const string co, int n, double pr);
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
};	// notice the 


int main()
{	
	Stock stock1, stock2;	// Objects of class Stock // Stock is like a type  " int "
	// We cant call any of the variable or function in private class because we can't access it. This is why we cant print the information in Private.
	
	stock1.acquire("NanoSmart", 20, 12.50); 
	stock1.display();
	stock1.buy(1, 3.99);
	stock1.sell(1, 5.99);
	stock1.update(24.00);
	stock1.display();
	
	cout << "********* Negative Share ***********"<<endl;
	stock2.acquire("Amazon", -1, 100);
	stock2.display();
	stock2.buy(1, 2.00);
	stock2.sell(1, 8.99);
	stock2.update(30.00);
	stock2.display();
	
	cout << "\nDone..." << endl;

	return 0;
}

// Body of acquire method. "::" is the scope operator (acquire is a member of Stock)
// This function only belongs to the object Stock
void Stock::acquire(const string co, int n, double pr)
{
	company = co;
	
	if(n < 0)
	{
		cerr << "Number of shares can't be negative; " // if share is negative cerr sets it to Zero
			 << company << " shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
		cout << "Updated shares for " << company << endl;
	}
	
	share_val = pr;
	set_tot();
}
void Stock::buy(int num, double price)
{
	if(num < 0) // if the number of shares are less than 0
	{
		shares = shares + 0;
		cout << "Number of shares can't be negative." << endl;
		cout << "Buying 0 shares." << endl;
	}
	else
	{
		shares = shares + num;
		share_val += (price * num); // multiply the number of shares with the price 
		cout << "Bought " << num << " shares of " << company << " for $" << price << " per share." << endl;
	}
	set_tot();
}
void Stock::sell(int num, double price)
{
	if(num < 0)// We can't sell 0 shares
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
