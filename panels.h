#include <bits/stdc++.h>

using namespace std;

const vector <string>
				helloMessage = {
					"Hi!",
					"Please choose panel(Just type number of command for usage):",
					"0. Admin panel",
					"1. User panel"
				},
				helpPage[] = {
					{
						"This is a help page of Admin Panel!",
						"List of commands(Just type number of command for usage):",
						"0. Add category",
						"1. Delete category",
						"2. Edit category",
						"3. Add product",
						"4. Delete product",
						"5. Edit product",
						"6. View offers",
						"-1. Exit",
						"-2. Help page"
					},
					{
						"This is a help page of User panel!",
						"List of commands(Just type number of command for usage):"
						"0. View products",
						"1. Make offer",
						"-1. Exit",
						"-2. Help page"
					}
				},
				addCategoryPage = {
					"Enter name for new category: "
				},
				deleteCategoryPage = {
					"Enter id of deleting category: "
				},
				editCategoryPage = {
					"Enter id of editing category, then enter attributes in following type:"
					"	[name]"
					"	[N = number of adding subcategories]"
					"	[N ids of adding subcategories]"
				},
				addProductPage = {
					"Enter [name, price, category id] for new product: "
				},
				deleteProductPage = {
					"Enter id of deleting product: "
				},
				editProductPage = {
					"Enter [id, new name, new price, new categoryId] of editing category:"
				},
				makeOfferPage = {
					"Enter [N = number of product], then N [id, count] of products:"
				};

struct Category;
struct Product;
struct Offer;

vector <Category> cs;
vector <Product> ps;
vector <Offer> os;

inline void addCategory();
inline void deleteCategory();
inline void editCategory();
inline void addProduct();
inline void deleteProduct();
inline void editProduct();
inline void viewOffers();
inline void viewProducts();
inline void makeOffer();
inline void printMessage(const vector <string>&s);
inline void WI();
inline void backend(int);
inline void frontend(int);
inline void loadData();
inline void saveData();
