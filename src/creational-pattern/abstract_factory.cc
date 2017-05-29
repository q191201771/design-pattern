/**
 * @file   abstract_factory.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 13:46:52
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class Button {
    public:
      virtual ~Button() {}
      virtual void display() = 0;
  };

  class TextField {
    public:
      virtual ~TextField() {}
      virtual void display() = 0;
  };

  class SpringButton : public Button {
    public:
      virtual void display() { printf("SpringButton::display()\n"); }
  };

  class SummerButton : public Button {
    public:
      virtual void display() { printf("SummerButton::display()\n"); }
  };

  class SpringTextField : public TextField {
    public:
      virtual void display() { printf("SpringTextField::display()\n"); }
  };

  class SummerTextField : public TextField {
    public:
      virtual void display() { printf("SummerTextField::display()\n"); }
  };

  //////////////////////////////////////////////////////////////////////

  class SkinFactory {
    public:
      virtual ~SkinFactory() {}
      virtual Button *createButton() = 0;
      virtual TextField *createTextField() = 0;
  };

  class SpringSkinFactory : public SkinFactory {
    public:
      virtual Button *createButton() { return new SpringButton(); }
      virtual TextField *createTextField() { return new SpringTextField(); }
  };

  class SummerSkinFactory : public SkinFactory {
    public:
      virtual Button *createButton() { return new SummerButton(); }
      virtual TextField *createTextField() { return new SummerTextField(); }
  };

} // namespace dp

int main() {
  using namespace dp;

  {
    SkinFactory *skin_factory = new SpringSkinFactory(); ///
    Button *button = skin_factory->createButton();
    TextField *text_field = skin_factory->createTextField();
    button->display();
    text_field->display();
    delete skin_factory; delete button; delete text_field;
  }

  {
    SkinFactory *skin_factory = new SummerSkinFactory();
    Button *button = skin_factory->createButton();
    TextField *text_field = skin_factory->createTextField();
    button->display();
    text_field->display();
    delete skin_factory; delete button; delete text_field;
  }

  return 0;
}
