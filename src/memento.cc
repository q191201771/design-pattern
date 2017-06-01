/**
 * @file   memento.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 13:25:25
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <string>

namespace dp {

  class Memento {
    friend class Originator;

    private:
      Memento(int a, const std::string &b) : a_(a), b_(b) {}

    private:
      int         a_;
      std::string b_;
  };

  class Originator {
    public:
      Originator(int a, const std::string &b, bool c) : a_(a), b_(b), c_(c) {}

      Memento *save() { return new Memento(a_, b_); }

      void load(Memento *m) {
        a_ = m->a_;
        b_ = m->b_;
      }

      void set_a(int a) { a_ = a; }
      void set_b(const std::string &b) { b_ = b; }
      void set_c(bool c) { c_ = c; }

      void display() { printf("%d %s %s\n", a_, b_.c_str(), c_ ? "true" : "false"); }

    private:
      int         a_;
      std::string b_;
      bool        c_;
  };

} // namespace dp

int main() {
  using namespace dp;

  Originator o(0, "initial", false);
  o.display();
  Memento *m = o.save();
  o.set_a(10);
  o.set_b("mod");
  o.set_c(true);
  o.display();
  o.load(m);
  o.display();

  delete m;

  return 0;
}

