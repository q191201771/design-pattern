/**
 * @file   template_method.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 10:33:56
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class AbstractClass {
    public:
      virtual ~AbstractClass() {}
      virtual void step1() { printf("step1\n"); }
      virtual void step2() { printf("step2\n"); }
      virtual void step3() = 0;
      virtual void step4() { printf("step4\n"); }
      virtual void op() {
        step1();
        step2();
        step3();
        step4();
      }
  };

  class ConcreteClassA : public AbstractClass {
    public:
      virtual void step3() { printf("A step3\n"); }
  };

  class ConcreteClassB : public AbstractClass {
    public:
      virtual void step3() { printf("B step3\n"); }
  };

} // namespace dp

int main() {
  using namespace dp;

  AbstractClass *obj = new ConcreteClassA();
  obj->op();
  delete obj;
  obj = new ConcreteClassB();
  obj->op();
  delete obj;

  return 0;
}

