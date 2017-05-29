/**
 * @file   simple_factory.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 08:40:51
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class Product {
    public:
      virtual ~Product() {}
      virtual void func() = 0;
  };

  class ConcreteProductA : public Product {
    public:
      void func() { printf("ConcreteProductA::func()\n"); }
  };

  class ConcreteProductB : public Product {
    public:
      void func() { printf("ConcreteProductB::func()\n"); }
  };

  class Factory {
    public:
      enum Type {
        TYPE_A = 1,
        TYPE_B
      };

      static Product *createProduct(Type type) {
        switch (type) {
          case TYPE_A: return new ConcreteProductA();
          case TYPE_B: return new ConcreteProductB();
        }
        return NULL;
      }
  };

}

int main() {
  using namespace dp;
  Product *pa = Factory::createProduct(Factory::TYPE_A);
  Product *pb = Factory::createProduct(Factory::TYPE_B);
  pa->func();
  pb->func();
  delete pa;
  delete pb;

  return 0;
}
