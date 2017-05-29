/**
 * @file   prototype.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 17:32:22
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <assert.h>

namespace dp {

  class Foo {
    public:
      Foo() : a_(-1), p_(NULL) {}

      Foo(int a, int *p) : a_(a), p_(p) {}

      ~Foo() { if (p_ != NULL) { delete p_; } }

      Foo(const Foo &f) {
        a_ = f.a_;
        if (f.p_ != NULL) {
          p_ = new int(*(f.p_));
        }
      }

      Foo *clone() const {
        Foo *f = new Foo();
        f->a_ = a_;
        if (p_ != NULL) {
          f->p_ = new int(*p_);
        }
        return f;
      }

      int a() const { return a_; }
      int *p() const { return p_; }

    private:
      int a_;
      int *p_;
  };

} // namespace dp

int main() {
  using namespace dp;

  Foo f1(10, new int(20));
  Foo f2(f1);
  Foo *f3 = f2.clone();

  assert(f1.a() == f2.a() && f2.a() == f3->a() && f1.a() == 10);
  assert(f1.p() != f2.p() && f2.p() != f3->p() &&
         *f1.p() == *f2.p() && *f2.p() == *(f3->p()) && *f1.p() == 20);

  return 0;
}

