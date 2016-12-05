#include <bits/stdc++.h>
#include "panels.h"

using namespace std;

struct Category {
	string name;
	int id;
	bool deleted;
	vector <int> ps, cs;
	Category(string name = "", int id = 0) : name(name), id(id), deleted(deleted) {}
};

struct Product {
	string name;
	double price;
	bool deleted;
	int cId, id;
	Product(string name = "", double price = 0, int cId = 0, int id = 0) 
		: name(name), price(price), cId(cId), id(id), deleted(false) {}
};

struct Offer {
	int id;
	double price;
	vector <pair <int, int> > ps;
	Offer(int id = 0, double price = 0) : id(id), price(price) {}
	inline void calc() {
		price = 0;
		for (auto it : ps) {
			price += it.second * :: ps[it.first].price;
		}
	}
};

inline void printMessage(const vector <string> &s) {
	for (auto it : s)
		cout << it << endl;
	cout << endl;
}

inline void WI() {
	cout << "Wrong input!\n";
}

inline void backend(int _type) {
	int type;
	while (true) {
		printMessage(helpPage[_type]);
		cin >> type;
		if (type == -1) {
			break;
		}
		if (type == -2) {
			printMessage(helpPage[_type]);
			continue;
		}
		if (!type) {
			addCategory();
		} else {
			if (type == 1) {
				deleteCategory();
			} else {
				if (type == 2) {
					editCategory();
				} else {
					if (type == 3) {
						addProduct();
					} else {
						if (type == 4) {
							deleteProduct();
						} else {
							if (type == 5) {
								editProduct();
							} else {
								if (type == 6) {
									viewOffers();
								} else {
									WI();
									continue;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "See you soon!\n";
	saveData();
}

inline void frontend(int _type) {
	int type;
	while (true) {
		printMessage(helpPage[_type]);
		cin >> type;
		if (type == -1) {
			break;
		}
		if (type == -2) {
			printMessage(helpPage[_type]);
		}
		if (!type) {
			viewProducts();
		} else {
			if (type == 1) {
				makeOffer();
			} else {
				WI();
				continue;
			}
		}
	}
	cout << "See you soon!\n";
	saveData();
}

inline void addCategory() {
	printMessage(addCategoryPage);
	string name; cin >> name;
	cs.push_back(Category(name, cs.size()));
	printf("Id of new category is %d\n", cs.back().id);
}

inline void deleteCategory() {
	printMessage(deleteCategoryPage);
	int id; cin >> id;
	for (auto &it : cs) {
		if (it.id == id) {
			it.deleted = (true);
			break;
		}
	}
	printf("Done!\n");
}

inline void editCategory() {
	printMessage(editCategoryPage);
	int id; cin >> id;
	for (auto &it : cs) {
		if (id == it.id) {
			string name; cin >> name;
			it.name = name;
			int n; cin >> n;
			for (int i = 0; i < n; ++i) {
				int x; cin >> x;
				it.cs.push_back(x);
			}
			break;
		}
	}
	puts("Done!");
}

inline void addProduct() {
	printMessage(addProductPage); // TODO: addProductPage
	string name; cin >> name;
	double price; cin >> price;
	int cId; cin >> cId;
	ps.push_back(Product(name, price, cId, ps.size()));
	int id = ps.back().id;
	for (auto &it : cs) {
		if (it.id == cId) {
			it.ps.push_back(id);
		}
	}
	printf("Id of new product is %d\n", id);
}

inline void deleteProduct() {
	printMessage(deleteProductPage);
	int id; cin >> id;
	for (auto &it : ps) {
		if (it.id == id) {
			it.deleted = (true);
			break;
		}
	}
	printf("Done!\n");
}

inline void editProduct() {
	printMessage(editProductPage);
	int id; cin >> id;
	for (auto &it : ps) {
		if (id == it.id) {
			string name; cin >> name;
			it.name = name;
			double price; cin >> price;
			it.price = price;
			int cId; cin >> cId;
			it.cId = cId;
			break;
		}
	}
	puts("Done!");
}

inline void viewOffers() {
	for (auto &it : os) {
		printf(
			"Offer id: %d\n"
			"Total price: %lf\n",
			it.id, it.price
			);
		for (auto &jt : it.ps) {
			printf(
				"Name: %s\n"
				"Id: %d\n"
				"Count: %d\n",
				ps[jt.first].name.c_str(), ps[jt.first].id, jt.second);
		}
	}
}

inline void viewProducts() {
	for (auto &it : ps) {
		if (it.deleted) continue;
		printf(
			"Name: %s\n"
			"Id: %d\n"
			"Price: %lf\n"
			"Category: %s\n",
			it.name.c_str(), 
			it.id, 
			it.price, 
			cs[it.cId].name.c_str());
	}
}

inline void makeOffer() {
	printMessage(makeOfferPage);
	int n; cin >> n;
	Offer o = Offer(os.size());
	for (int i = 0; i < n; ++i) {
		int id, cnt; cin >> id >> cnt;
		o.ps.push_back(make_pair(id, cnt));
	}
	o.calc();
	os.push_back(o);
	printf(
		"Id: %d\n"
		"Total price: %lf\n", 
		o.id, o.price);
}

inline void loadData() {
	ifstream fin("pseudoDataBase");
	if (!fin) return;
	cerr << "fin is not empty\n";
	int n; fin >> n; // number of categories
	cerr << n << endl;
	for (int i = 0; i < n; ++i) {
		Category c = Category();
		fin >> c.name >> c.id >> c.deleted;
		cerr << c.name << " " << c.id << " " << c.deleted << endl; 
		int psSize; fin >> psSize;
		cerr << psSize << endl;
		while (psSize--) {
			int x; fin >> x;
			cerr << x << " ";
			c.ps.push_back(x);
		}
		int csSize; fin >> csSize;
		cerr << csSize << endl;
		while (csSize--) {
			int x; fin >> x;
			c.cs.push_back(x);
		}
		cs.push_back(c);
	}
	fin >> n; // number of products
	cerr << n << endl;
	for (int i = 0; i < n; ++i) {
		Product p = Product();
		fin >> p.name >> p.price >> p.deleted >> p.cId >> p.id;
		cerr << p.name << " " << p.price << " " << p.deleted << " " << p.cId << " " << p.id << endl;
		ps.push_back(p);
	}
	fin >> n; // number of offers
	for (int i = 0; i < n; ++i) {
		Offer o = Offer();
		fin >> o.id >> o.price;
		int pSz; fin >> pSz;
		while (pSz--) {
			int id, cnt;
			o.ps.push_back(make_pair(id, cnt));
		}
		os.push_back(o);
	}
	fin.close();
}

inline void saveData() {
	ofstream fout("pseudoDataBase");
	fout << cs.size() << endl;
	for (auto it : cs) {
		fout << it.name << "\n" << it.id << "\n" << (bool)(it.deleted) << endl;
		fout << it.ps.size() << endl;
		for (auto jt : it.ps)
			fout << jt << "\n";
		fout << endl;
		fout << it.cs.size() << endl;
		for (auto jt : it.cs)
			fout << jt << "\n";
		fout << endl;
	}
	fout << ps.size() << endl;
	for (auto it : ps) {
		fout << it.name << "\n" << it.price << "\n" << it.deleted << "\n" << it.cId << "\n" << it.id << endl;
	}
	fout << os.size() << endl;
	for (auto it : os) {
		fout << it.id << "\n" << it.price << endl;
		fout << it.ps.size() << endl;
		for (auto jt : it.ps) {
			fout << jt.first << "\n" << jt.second << endl;
		}
	}
	fout.close();
}
