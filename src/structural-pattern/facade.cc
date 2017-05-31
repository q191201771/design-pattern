/**
 * @file   facade.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 08:36:34
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class SystemA {
    public:
      void opA() { printf("SystemA::opA\n"); }
  };

  class SystemB {
    public:
      void opB() { printf("SystemB::opB\n"); }
  };

  class SystemC {
    public:
      void opC() { printf("SystemC::opC\n"); }
  };

  class Facade {
    public:
      Facade(SystemA *a, SystemB *b, SystemC *c) : a_(a), b_(b), c_(c) {}

      void op() {
        a_->opA();
        b_->opB();
        c_->opC();
      }

    private:
      SystemA *a_;
      SystemB *b_;
      SystemC *c_;
  };

} // namespace dp

int main() {
  using namespace dp;

  SystemA *a = new SystemA();
  SystemB *b = new SystemB();
  SystemC *c = new SystemC();
  Facade facade(a, b, c);
  facade.op();
  delete a; delete b; delete c;

  return 0;
}

