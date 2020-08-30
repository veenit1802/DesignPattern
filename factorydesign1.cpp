#include<bits/stdc++.h>
using namespace std;
// question -> why we use the vitual keyword
// answer if we do not use the virtual key then destructor of the derived class invoked so using the virtual we achieve the run time binding or late binding

//question -> why we use enum
//answer enum is integer type so we can map the variables with the value the benefit of using enum is we don't have to write to much of the code 





class Pizza
{
	public:
		virtual int getPrice() const=0;
		virtual ~Pizza(){};
};


class HamAndMushroomPizza :public Pizza
{
	public:
		virtual int getPrice() const {return 850;};
		virtual ~HamAndMushroomPizza(){};
};


class DeluxePizza :public Pizza
{
	public:
		virtual int getPrice() const {return 1050;};
		virtual ~DeluxePizza(){};
};

class HawaiianPizza:public Pizza
{
	public:
		virtual int getPrice() const {return 1150;};
		virtual ~HawaiianPizza(){};
};

class PizzaFactory
{
	public:
		enum PizzaType
		{
			HamAndMushroom,
			Deluxe,
			Hawaiian
		};

		static unique_ptr<Pizza> createPizza(PizzaType pizzaType)
		{
			
			switch(pizzaType)
			{
				case HamAndMushroom: return make_unique<HamAndMushroomPizza>();
				case Deluxe: return make_unique<DeluxePizza>();
				case Hawaiian: return make_unique<HawaiianPizza>();
			}
			throw "invalid pizza type.";
		}
};

void pizza_information(PizzaFactory::PizzaType pizzatype)
{
	unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
	cout << "Price of " << pizzatype << " is " << pizza->getPrice() << std::endl;
}

int main()
{
	pizza_information(PizzaFactory::HamAndMushroom);
	pizza_information(PizzaFactory::Deluxe);
	pizza_information(PizzaFactory::Hawaiian);
}
