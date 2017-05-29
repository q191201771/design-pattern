/**
 * @file   singleton.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 15:34:36
 *     -initial release xxxx-xx-xx
 *
 */

#include <mutex>
#include <stdio.h>
#include <assert.h>

namespace dp {

  class Singleton {
    public:
      static Singleton &instance() {
        if (core_ == NULL) {
          std::lock_guard<std::mutex> lock(mutex_);
          if (core_ == NULL) {
            core_ = new Singleton();
          }
        }
        return *core_;
      }

      void set_a(int a) { a_ = a; }
      int get_a() const { return a_; }

    private:
      Singleton() : a_(0) {}
      ~Singleton() {}
      Singleton(const Singleton &);
      Singleton &operator=(const Singleton &);

    private:
      static Singleton  *core_;
      static std::mutex  mutex_;

    private:
      int a_;
  };

  Singleton *Singleton::core_ = NULL;
  std::mutex Singleton::mutex_;

} // namespace dp

int main() {
  using namespace dp;

  assert(&Singleton::instance() == &Singleton::instance());
  Singleton::instance().set_a(7);
  assert(Singleton::instance().get_a() == 7);

  return 0;
}
