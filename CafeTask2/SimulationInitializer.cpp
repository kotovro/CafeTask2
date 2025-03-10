#include "SimulationInitializer.h"


std::map<std::string, Ingredient*>* SimuationInitializer::initializeIngredients(std::map<std::string, Ingredient*>* ingredients)
{
    (*ingredients)["Milk"] = new Ingredient(10);
    (*ingredients)["Egg"] = new Ingredient(20.23);
    (*ingredients)["Bacon"] = new Ingredient(20.27);
    (*ingredients)["Bread"] = new Ingredient(25.4);
    (*ingredients)["Water"] = new Ingredient(10.4);
    (*ingredients)["Fish"] = new Ingredient(30.4);
    (*ingredients)["Chicken"] = new Ingredient(26.6);
    (*ingredients)["Cucumber"] = new Ingredient(10.5);
    (*ingredients)["Tomato"] = new Ingredient(26.67);
    (*ingredients)["Lemon"] = new Ingredient(15.4);
    (*ingredients)["Tea"] = new Ingredient(9.4);
    (*ingredients)["Cofe"] = new Ingredient(11.4);
    (*ingredients)["Vodka"] = new Ingredient(44);
    (*ingredients)["Rum"] = new Ingredient(50);

    return ingredients;
}


std::map<std::string, Dish*>* SimuationInitializer::initializeDishes(std::map<std::string, Dish*>*  dishes, std::map<std::string, Ingredient*>* ingredients)
{   
    (*dishes)["Omelette"] = new Dish();
    (*dishes)["Omelette"]->setCookingTime(0.1);
    std::vector<Ingredient*>* omeletteIngredients = (*dishes)["Omelette"]->getIngeredients();
    omeletteIngredients->push_back((*ingredients)["Egg"]);
    omeletteIngredients->push_back((*ingredients)["Egg"]);
    omeletteIngredients->push_back((*ingredients)["Egg"]);
    omeletteIngredients->push_back((*ingredients)["Bacon"]);
    omeletteIngredients->push_back((*ingredients)["Bacon"]);


    (*dishes)["Soup"] = new Dish();
    (*dishes)["Soup"]->setCookingTime(0.30);
    std::vector<Ingredient*>* soupIngredients;
    soupIngredients = (*dishes)["Soup"]->getIngeredients();
    soupIngredients->push_back((*ingredients)["Chicken"]);
    soupIngredients->push_back((*ingredients)["Chicken"]);
    soupIngredients->push_back((*ingredients)["Water"]);
    soupIngredients->push_back((*ingredients)["Water"]);

    (*dishes)["LemonTea"] = new Dish();
    std::vector<Ingredient*>* teaIngredients;
    (*dishes)["LemonTea"]->setCookingTime(0.05);
    teaIngredients = (*dishes)["LemonTea"]->getIngeredients();
    teaIngredients->push_back((*ingredients)["Tea"]);
    teaIngredients->push_back((*ingredients)["Lemon"]);
    teaIngredients->push_back((*ingredients)["Water"]);

    (*dishes)["Espresso"] = new Dish();
    std::vector<Ingredient*>* espressoIngredients;
    (*dishes)["Espresso"]->setCookingTime(0.05);
    espressoIngredients = (*dishes)["Espresso"]->getIngeredients();
    espressoIngredients->push_back((*ingredients)["Cofe"]);
    espressoIngredients->push_back((*ingredients)["Water"]);

    (*dishes)["CoolFishb"] = new Dish();
    std::vector<Ingredient*>* fishbIngredients;
    (*dishes)["CoolFishb"]->setCookingTime(0.30);
    fishbIngredients = (*dishes)["CoolFishb"]->getIngeredients();
    fishbIngredients->push_back((*ingredients)["Fish"]);
    fishbIngredients->push_back((*ingredients)["Tomato"]);
    fishbIngredients->push_back((*ingredients)["Water"]);

    (*dishes)["CocktailSample"] = new Dish();
    (*dishes)["CocktailSample"]->setCookingTime(0.1);
    std::vector<Ingredient*>* cocktailIngredients;
    cocktailIngredients = (*dishes)["CocktailSample"]->getIngeredients();
    cocktailIngredients->push_back((*ingredients)["Rum"]);
    cocktailIngredients->push_back((*ingredients)["Water"]);

    return dishes;
}

Menu* SimuationInitializer::initializeMenu(Menu* menu, std::map<std::string, Dish*>* dishes)
{
    std::vector<Dish*>* breakfast = menu->getBreakfastMenu();
    breakfast->push_back((*dishes)["Omelette"]);

    std::vector<Dish*>* lunch = menu->getLunchMenu();
    lunch->push_back((*dishes)["Soup"]);

    std::vector<Dish*>* dinner = menu->getDinnerMenu();
    dinner->push_back((*dishes)["CoolFishb"]);

    std::vector<Dish*>* drinks = menu->getDrinksMenu();
    drinks->push_back((*dishes)["LemonTea"]);
    drinks->push_back((*dishes)["Espresso"]);

    std::vector<Dish*>* cocktails = menu->getCocktailsMenu();
    cocktails->push_back((*dishes)["CocktailSample"]);

    return menu;
}

void SimuationInitializer::clearMenu(std::map<std::string, Dish*>* dishes, std::map < std::string, Ingredient*>* ingredients)
{
    std::unordered_set<Dish*> uniqueDishes; // Store only unique pointers

    for (auto const& dish : *dishes)
    {
        uniqueDishes.insert(dish.second);
    }
    dishes->clear();

    for (Dish* dish : uniqueDishes) // Delete each unique pointer only once
    {
        delete dish;
    }

    std::unordered_set<Ingredient*> uniqueIngredients; // Store only unique pointers

    for (auto const& ingredient : *ingredients)
    {
        uniqueIngredients.insert(ingredient.second);
    }
    ingredients->clear();

    for (Ingredient* ingredient : uniqueIngredients) // Delete each unique pointer only once
    {
        delete ingredient;
    }
}
