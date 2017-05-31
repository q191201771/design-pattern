/**
 * @file   composite.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-30 13:19:06
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <vector>
#include <string>

namespace dp {

  class Component {
    public:
      virtual ~Component() {}
      virtual void add(Component *) { printf("warn:add not impl in this component!\n"); }
      virtual void display() = 0;
  };

  class Container : public Component {
    public:
      /// haven't check dup
      virtual void add(Component *component) { components_.push_back(component); }

      virtual void display() {
        std::vector<Component *>::iterator iter = components_.begin();
        for (; iter !=components_.end(); iter++) {
          (*iter)->display();
        }
      }
    private:
      std::vector<Component *> components_;
  };

  class Button : public Component {
    public:
      virtual void display() { printf("Button\n"); }
  };

  class TextField: public Component {
    public:
      virtual void display() { printf("TextField\n"); }
  };

} // namespace dp

int main() {
  using namespace dp;

  Container global_container;
  Button button1;
  Button button2;
  TextField text_field1;
  global_container.add(&button1);
  global_container.add(&button2);
  global_container.add(&text_field1);

  Container sub_container;
  Button button3;
  sub_container.add(&button3);
  global_container.add(&sub_container);

  printf("----------\n");
  button1.add(&button2); /// oops
  printf("----------\n");
  text_field1.display();
  printf("----------\n");
  button3.display();
  printf("----------\n");
  global_container.display();
  printf("----------\n");

  return 0;
}
