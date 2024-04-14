#include <iostream>
#include <wt/Dbo/backend/Postgres.h>
#include <wt/Dbo/Dbo.h>
#include <windows.h>

#pragma execution_character_set("utf-8")

class Book;
class Stock;
class Sale;

class Publisher {
public:
	std::string name = "";

	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "idPublisher");
	}
};

class Book {
public:
	std::string title = "";
	Wt::Dbo::ptr<Publisher> idPublisher;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, idPublisher, "idPublisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "idBook");
	}
};

class Shop {
public:
	std::string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "idShop");
	}
};

class Stock {
public:
	int count = 0;
	Wt::Dbo::ptr<Book> idBook;
	Wt::Dbo::ptr<Shop> idShop;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;


	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, idBook, "idBook");
		Wt::Dbo::belongsTo(a, idShop, "idShop");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "id_stock");
	}
};

class Sale {
public:
	int price = 0;
	int count = 0;
	std::string dataSale = "";
	Wt::Dbo::ptr<Stock> idStock;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, dataSale, "dataSale");
		Wt::Dbo::belongsTo(a, idStock, "id_stock");
	}
};

int main() {

	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {
		std::string conStr =
			"host=localhost "
			"port=5432 "
			"dbname=L6_SQL_WT "
			"user=postgres "
			"password=8880648";

		std::unique_ptr<Wt::Dbo::backend::Postgres> conn = std::make_unique<Wt::Dbo::backend::Postgres>(conStr);

		Wt::Dbo::Session s;
		s.setConnection(std::move(conn));
		s.mapClass<Publisher>("Publisher");
		s.mapClass<Book>("Book");
		s.mapClass<Shop>("Shop");
		s.mapClass<Stock>("Stock");
		s.mapClass<Sale>("Sale");

		s.createTables();

		//заполнение таблиц
		Wt::Dbo::Transaction tr1(s);
		std::unique_ptr<Publisher> p1(new Publisher{ "Publisher_Alexander's", {} });
		std::unique_ptr<Publisher> p2(new Publisher{ "Publisher_Mihail's", {} });


		Wt::Dbo::ptr<Publisher> pupDb1 = s.add(std::move(p1));
		Wt::Dbo::ptr<Publisher> pubDb2 = s.add(std::move(p2));

		std::unique_ptr<Book> book1(new Book{ "The Daughter of The Commandant", pupDb1, {} });
		Wt::Dbo::ptr<Book> bDb1 = s.add(std::move(book1));
		std::unique_ptr<Book> book2(new Book{ "Queen of Spades", pupDb1, {} });
		Wt::Dbo::ptr<Book> bDb2 = s.add(std::move(book2));
		std::unique_ptr<Book> book3(new Book{ "A Hero of Our Time", pubDb2, {} });
		Wt::Dbo::ptr<Book> bDb3 = s.add(std::move(book3));
		std::unique_ptr<Book> book4(new Book{ "The Cemetery", pubDb2, {} });
		Wt::Dbo::ptr<Book> bDb4 = s.add(std::move(book4));

		std::unique_ptr<Shop> shop2(new Shop{ "Shop 2", {} });
		Wt::Dbo::ptr<Shop> shopDb2 = s.add(std::move(shop2));
		std::unique_ptr<Shop> shop1(new Shop{ "Shop 1", {} });
		Wt::Dbo::ptr<Shop> shopDb1 = s.add(std::move(shop1));

		std::unique_ptr<Stock> stock1(new Stock{11, bDb1, shopDb1, {} });
		Wt::Dbo::ptr<Stock> stockDb1 = s.add(std::move(stock1));
		std::unique_ptr<Stock> stock2(new Stock{ 17, bDb2, shopDb1, {} });
		Wt::Dbo::ptr<Stock> stockDb2 = s.add(std::move(stock2));
		std::unique_ptr<Stock> stock3(new Stock{ 19, bDb3, shopDb2, {} });
		Wt::Dbo::ptr<Stock> stockDb3 = s.add(std::move(stock3));
		std::unique_ptr<Stock> stock4(new Stock{ 23, bDb4, shopDb2, {} });
		Wt::Dbo::ptr<Stock> stockDb4 = s.add(std::move(stock4));

		std::unique_ptr<Sale> sale1(new Sale{ 85, 27, "2024-02-14", stockDb1});
		Wt::Dbo::ptr<Sale> saleDb1 = s.add(std::move(sale1));
		std::unique_ptr<Sale> sale2(new Sale{ 104, 39, "2024-01-18", stockDb2 });
		Wt::Dbo::ptr<Sale> saleDb2 = s.add(std::move(sale2));

		tr1.commit();

		Wt::Dbo::Transaction tr2(s);

		std::string find_val;
		std::cout << "¬ведите по какому параметру искать: name или id:" << std::endl;
		std::cin >> find_val;

		Wt::Dbo::ptr<Publisher> find_publisher = nullptr;

		if (find_val == "name") {
			std::string name;
			std::cout << "¬ведите название издател€:" << std::endl;
			std::cin >> name;

			find_publisher = s.find<Publisher>().where("name = ?").bind(name);
		}
		else if (find_val == "id") {
			int id;
			std::cout << "¬ведите id издател€:" << std::endl;
			std::cin >> id;

			find_publisher = s.find<Publisher>().where("id = ?").bind(id);
		}
		else {
			std::cout << "¬веден неверный параметр!" << std::endl;
		}

		if (find_publisher) {
			std::cout << "»здатель найден! " << find_publisher->name << std::endl;
			std::cout << "—писок магазинов, в которых продаютс€ его книги:" << std::endl;

			std::set<std::string> shops;
			for (const auto& book : find_publisher->books) {
				for (const auto& stock : book->stocks) {
					shops.insert(stock->idShop->name);
				}
			}

			for (const auto& shop_name : shops) {
				std::cout << shop_name << ", ";
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "»здатель не найден!" << std::endl;
		}

		tr2.commit();
	}
	catch (std::exception& err) {
		std::cout << "Error: " << err.what() << std::endl;
	}

	return 0;
}