/**
 * @file   visitor.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 14:53:14
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <vector>

namespace dp {

  class ElementA;
  class ElementB;

  class Visitor {
    public:
      virtual ~Visitor() {}
      virtual void visit(ElementA *) = 0;
      virtual void visit(ElementB *) = 0;
  };

  class Element {
    public:
      virtual ~Element() {}
      virtual void accept(Visitor *) = 0;
  };

  class ElementA : public Element {
    public:
      void accept(Visitor *v) { v->visit(this); }
  };

  class ElementB : public Element {
    public:
      void accept(Visitor *v) { v->visit(this); }
  };

  class VisitorA: public Visitor {
    public:
      virtual void visit(ElementA *element) {
        /// 这里可以对ElementA的数据做针对性的业务操作，我省略了，以下的visit函数都一样~
        (void)element;
        printf("visit element A @ visitor A\n");
      }
      virtual void visit(ElementB *) { printf("visit element B @ visitor A\n"); }
  };

  class VisitorB: public Visitor {
    public:
      virtual void visit(ElementA *) { printf("visit element A @ visitor B\n"); }
      virtual void visit(ElementB *) { printf("visit element B @ visitor B\n"); }
  };

} // namespace dp

int main() {
  using namespace dp;

  std::vector<Element *> element_vector;
  element_vector.push_back(new ElementA());
  element_vector.push_back(new ElementB());
  std::vector<Element *>::iterator iter = element_vector.begin();
  for (; iter != element_vector.end(); iter++) {
    VisitorA visitor;
    (*iter)->accept(&visitor);
  }
  iter = element_vector.begin();
  for (; iter != element_vector.end(); iter++) {
    VisitorB visitor;
    (*iter)->accept(&visitor);
  }

  iter = element_vector.begin();
  for (; iter != element_vector.end(); iter++) {
    delete *iter;
  }

  return 0;
}
