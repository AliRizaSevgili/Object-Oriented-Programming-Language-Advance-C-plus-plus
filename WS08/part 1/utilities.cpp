#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    
                    Product* product = new Product(desc[i].desc, price[j].price);
                    try {
                        product->validate(); 
                        priceList += product;
                    }
                    catch (...) {
                        delete product; 
                        throw;
                    }
                }
            }
        }


		return priceList;
	}

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> productList;

        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    // Use smart pointer for Product
                    std::unique_ptr<Product> product(new Product(desc[i].desc, price[j].price));
                    product->validate(); // Validate the product
                    productList += std::move(product); // Move semantics transfer ownership to the list
                }
            }
        }
        return productList;
    }
}