#include <iostream>
#include<string>
#include<stdlib.h>

class Book
{

private:

	std::string  m_Author =  "Unknown Author";
	std::string  m_Title=    "Unknown Title";
	std::string  m_Publisher="Unknown Publisher";
	
	float m_Price=999.0f;
	unsigned int m_Stock=0;

public:

	//constractors
	// default constractor 
	Book()
	{};
	// Intialised constractor
	Book(std::string const& author, std::string const& title, std::string const& publisher, float const& price, int const& stock) :
		m_Author(author), m_Title(title), m_Publisher(publisher), m_Price(price), m_Stock(stock)
	{};
	// Copy constractor not allowed
	Book(const Book& other)=delete;
	
	//Move constractor not allowed 
	Book(Book&& other) = delete;

	//Deconstructor 
	~Book() {};

public:
	//setters

	void const setAuthorName(std::string const& author) { m_Author = author; }
	void const setBookTitle (std::string const& title) { m_Title = title; }
	void const setBookPublisher(std::string const& publisher) { m_Publisher = publisher; }
	
	void const setBookPrice(float const& price) { m_Price = price; }
	void const setStockLevel(int const& stock) { m_Stock = stock; }

	//getters

	std::string getAuthorName()  { return m_Author;}
	std::string getBookTitle()   { return m_Title;}
	std::string getBookPublisher() { return m_Publisher;}

	auto   getBookPrice() { return m_Price;}
	auto   getStockLevel() { return m_Stock; }


public:
	void bookDataIn()
	{
		std::string temp;
		float tempdegit;

		std::cin.ignore();

		std::cout << "\nEnter Author Name: "; 
		std::cin>> temp;
		setAuthorName(temp);

		std::cout << "\nEnter Title Name: ";
		std::cin >> temp;
		setBookTitle(temp);

		std::cout << "\nEnter Publisher Name: ";
		std::cin >> temp;
		setBookPublisher(temp);

		std::cout << "\nEnter Price: "; 
		std::cin >> tempdegit;
		setBookPrice(tempdegit);

		std::cout << "\nEnter Stock Position: ";
		std::cin >> tempdegit;
		setStockLevel((int)tempdegit);
	}


	
	void editBookData()
	{

		std::string temp;
		float tempdegit;

		std::cout << "\nEnter Author Name: ";
		std::cin >> temp;
		setAuthorName(temp);

		std::cout << "Enter Title Name: ";
		std::cin >> temp;
		setBookTitle(temp);

		std::cout << "Enter Publisher Name: ";
		std::cin >> temp;
		setBookPublisher(temp);

		std::cout << "Enter Price: ";
		std::cin >> tempdegit;
		setBookPrice(tempdegit);

		std::cout << "Enter Stock Position: ";
		std::cin >> tempdegit;
		setStockLevel((int)tempdegit);
	}

	void const bookDataDisplay ()
	{
		std::cout << "\nAuthor name: "		<< getAuthorName();
		std::cout << "\nTitle name: "		<< getBookTitle();
		std::cout << "\nPublisher name: "	<< getBookPublisher();
		std::cout << "\nPrice: "			<< getBookPrice();
		std::cout << "\nStock level: "   << getStockLevel() << std::endl; 
	}


	int bookSearch(std::string const& searchBookTitle, std::string const searchBookAuthor)
	{
		auto titleCompare= searchBookTitle.compare(getBookTitle());
		auto authorCompare = searchBookAuthor.compare(getBookTitle());

		//if (titleCompare != 0 || authorCompare != 0) return 1;

		if (titleCompare == 0 && authorCompare == 0)
			return 1;
		else return 0;
	}

	void buyBook()
	{
		int count;
		std::cout << "\nEnter Number Of Books to buy: ";
		std::cin >> count;

		if (count <= getStockLevel())
		{
			setStockLevel(m_Stock - count);

			std::cout << "\nBooks Bought Sucessfully";
			std::cout << "\nTotal cost is: $. " << getBookPrice() * count << std::endl;
		}
		else
		{
			std::cout << "\nRequired Copies not in Stock" << std::endl;
		}
	}
};

int main() {
	Book *book[10];
	std::string  titlebuy, authorbuy;


	int i = 0, r, t, choice;
	
	while (1) 
	{
		std::cout << "\n\n\t\tMENU"
			<< "\n1. Entry of New Book"
			<< "\n2. Buy Book"
			<< "\n3. Search For Book"
			<< "\n4. Edit Details Of Book"
			<< "\n5. Exit"
			<< "\n\nEnter your Choice: ";
		std::cin >> choice;

		switch (choice) 
		{
		case 1:
			book[i] = new Book;
			book[i]->bookDataIn();
			++i;
			break;

		case 2: 
			std::cin.ignore();
			std::cout << "\nEnter Title Of Book: "; 
			std::cin>>titlebuy;

			std::cout << "Enter Author Of Book: ";
			std::cin>>authorbuy;

			for (t = 0; t < i; t++)
			{
				if (book[t]->bookSearch(titlebuy, authorbuy))
				{
					book[t]->buyBook();
					break;
				}
			}
			if (t == 1)
				std::cout << "\nThis Book is Not in Stock";

			break;
		case 3: 
			std::cin.ignore();
			std::cout << "\nEnter Title Of Book: ";
			std::cin >> titlebuy;

			std::cout << "Enter Author Of Book: ";
			std::cin >> authorbuy;

			for (t = 0; t < i; t++) 
			{
				if (book[t]->bookSearch(titlebuy, authorbuy))
				{
					std::cout << "\nBook Found Successfully";
					book[t]->bookDataDisplay();
					break;
				}
				
			}
			if (t == i)
				std::cout << "\nThis Book is Not in Stock";
			break;

		case 4: 
			std::cin.ignore();
			std::cout << "\nEnter Title Of Book: ";
			std::cin >> titlebuy;

			std::cout << "Enter Author Of Book: ";
			std::cin >> authorbuy;

			for (t = 0; t < i; t++) {
				if (book[t]->bookSearch(titlebuy, authorbuy))
				{
					std::cout << "\nBook Found Successfully";
					book[t]->editBookData();
					break;
				}
			}
			if (t == i)
				std::cout << "\nThis Book is Not in Stock";
			break;

		case 5: exit(0);
		default: std::cout << "\nInvalid Choice Entered";

		}
	}




	return 0;
}
