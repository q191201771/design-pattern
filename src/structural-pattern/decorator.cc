/**
 * @file   decorator.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-30 20:33:30
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class Component {
    public:
      void func() { printf("Component::func()\n"); }
  };

  class Decorator {
    public:
      Decorator() : component_(NULL) {}
      void setComponent(Component *component) { component_ = component; }
      void func() {
        printf("do something before call Component::func()\n");
        component_->func();
        printf("do something after call Component::func()\n");
      }

    private:
      Component *component_;
  };

} // namespace dp

int main() {
  using namespace dp;

  Component component;
  Decorator decorator;
  decorator.setComponent(&component);
  decorator.func();

  return 0;
}
