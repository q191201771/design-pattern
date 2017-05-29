/**
 * @file   builder.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 21:52:05
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <string>

namespace dp {

  class Meal {
    public:
      void set_drink(const std::string &drink) { drink_ = drink; }
      void set_food(const std::string &food) { food_ = food; }
      std::string drink() { return drink_; }
      std::string food() { return food_; }

    private:
      std::string drink_;
      std::string food_;
  };

  class MealBuilder {
    public:
      MealBuilder() : meal_(new Meal()) {}
      virtual ~MealBuilder() {}
      virtual void buildDrink() = 0;
      virtual void buildFood() = 0;

    public:
      Meal *getResult() { return meal_; }

    protected:
      Meal *meal_;
  };

  class SubMealBuilderA : public MealBuilder {
    public:
      virtual void buildDrink() { meal_->set_drink("cola"); }
      virtual void buildFood() { meal_->set_food("hamburger"); }
  };

  class SubMealBuilderB : public MealBuilder {
    public:
      virtual void buildDrink() { meal_->set_drink("tea"); }
      virtual void buildFood() { meal_->set_food("noodle"); }
  };

  class Director {
    public:
      void setBuilder(MealBuilder *builder) {
        builder_ = builder;
      }

      Meal *create() {
        builder_->buildDrink();
        builder_->buildFood();
        return builder_->getResult();
      }

    private:
      MealBuilder *builder_;
  };

} // namespace dp

int main() {
  using namespace dp;

  {
    Director director;
    MealBuilder *builder = new SubMealBuilderA(); ///
    director.setBuilder(builder);
    Meal *meal = director.create();
    printf("SubMealA: %s,%s\n", meal->drink().c_str(), meal->food().c_str());
    delete builder;
    delete meal;
  }

  {
    Director director;
    MealBuilder *builder = new SubMealBuilderB();
    director.setBuilder(builder);
    Meal *meal = director.create();
    printf("SubMealB: %s,%s\n", meal->drink().c_str(), meal->food().c_str());
    delete builder;
    delete meal;
  }

  return 0;
}
