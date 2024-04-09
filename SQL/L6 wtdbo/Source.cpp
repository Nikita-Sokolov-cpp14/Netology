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
		Wt::Dbo::belongsTo(a, idPublisher, "idPublisher");
		Wt::Dbo::field(a, title, "title");
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
	Wt::Dbo::ptr<Shop> idShop;
	Wt::Dbo::ptr<Book> idBook;
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
	std::string dataSale = "";
	Wt::Dbo::ptr<Stock> idStock;
	int count = 0;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, dataSale, "dataSale");
		Wt::Dbo::belongsTo(a, idStock, "id_stock");
		Wt::Dbo::field(a, count, "count");
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
		std::unique_ptr<Publisher> p1(new Publisher);
		p1->name = "Александр";
		Wt::Dbo::ptr<Publisher> p1Db1 = s.add(std::move(p1));

		std::unique_ptr<Publisher> p2(new Publisher);
		p2->name = "Михаил";
		Wt::Dbo::ptr<Publisher> p1Db2 = s.add(std::move(p2));

		Wt::Dbo::ptr<Publisher> pub1 = s.find<Publisher>().where("id = ?").bind("1");
		if (pub1) {
			std::unique_ptr<Book> book(new Book);
			book->title = "Капитанская дочка";
			Wt::Dbo::ptr<Book> bDb = s.add(std::move(book));
			pub1.modify()->books.insert(bDb);
		}

		Wt::Dbo::ptr<Publisher> pub2 = s.find<Publisher>().where("id = ?").bind("2");
		if (pub1) {
			std::unique_ptr<Book> book(new Book);
			book->title = "Герой нашего времени";
			Wt::Dbo::ptr<Book> bDb = s.add(std::move(book));
			pub2.modify()->books.insert(bDb);
		}

		Wt::Dbo::ptr<Book> book2 = s.find<Book>().where("id = ?").bind("2");
		if (book2) {
			std::unique_ptr<Stock> stock(new Stock);
			stock->count = 17;
			Wt::Dbo::ptr<Stock> stockDb = s.add(std::move(stock));
			book2.modify()->stocks.insert(stockDb);
		}

		Wt::Dbo::ptr<Book> book1 = s.find<Book>().where("id = ?").bind("1");
		if (book1) {
			std::unique_ptr<Stock> stock(new Stock);
			stock->count = 11;
			Wt::Dbo::ptr<Stock> stockDb = s.add(std::move(stock));
			book1.modify()->stocks.insert(stockDb);
		}

		std::unique_ptr<Shop> shop2(new Shop);
		shop2->name = "Произведения Лермонтова";
		Wt::Dbo::ptr<Shop> shopDb2 = s.add(std::move(shop2));

		std::unique_ptr<Shop> shop1(new Shop);
		shop1->name = "Произведения Пушкина";
		Wt::Dbo::ptr<Shop> shopDb1 = s.add(std::move(shop1));

		Wt::Dbo::ptr<Stock> stock1 = s.find<Stock>().where("id = ?").bind("1");
		if (stock1) {
			stock1.modify()->idShop = shopDb1;
		}

		Wt::Dbo::ptr<Stock> stock2 = s.find<Stock>().where("id = ?").bind("2");
		if (stock2) {
			stock2.modify()->idShop = shopDb2;
		}

		Wt::Dbo::ptr<Stock> stock_sale_1 = s.find<Stock>().where("id = ?").bind("1");
		if (stock_sale_1) {
			std::unique_ptr<Sale> sale(new Sale);
			sale->count = 114;
			sale->dataSale = "2024-05-01";
			sale->price = 111;
			Wt::Dbo::ptr<Sale> saleDb = s.add(std::move(sale));
			stock_sale_1.modify()->sales.insert(saleDb);
		}

		Wt::Dbo::ptr<Stock> stock_sale_2 = s.find<Stock>().where("id = ?").bind("2");
		if (stock_sale_2) {
			std::unique_ptr<Sale> sale(new Sale);
			sale->count = 109;
			sale->dataSale = "2024-07-11";
			sale->price = 117;
			Wt::Dbo::ptr<Sale> saleDb = s.add(std::move(sale));
			stock_sale_2.modify()->sales.insert(saleDb);
		}
		tr1.commit();

		Wt::Dbo::Transaction tr2(s);

		std::string name;
		std::cout << "Введите имя издателя:" << std::endl;
		std::cin >> name;

		Wt::Dbo::ptr<Publisher> find_publisher = s.find<Publisher>().where("name = ?").bind(name);
		//???
		Wt::Dbo::ptr<Publisher> find_publisher__ = s.find<Publisher>().where("name = ?").bind("Александр");

		if (find_publisher__) {
			for (const auto& book : find_publisher->books) {
				for (const auto& stock : book->stocks) {
					std::cout << stock->idShop->name << std::endl;
				}
			}
		}

		tr2.commit();
	}
	catch (std::exception& err) {
		std::cout << "Error: " << err.what() << std::endl;
	}
	return 0;
}