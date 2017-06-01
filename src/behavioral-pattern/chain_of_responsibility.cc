/**
 * @file   chain_of_responsibility.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 09:05:09
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <assert.h>

namespace dp {

  class Handler {
    public:
      Handler(Handler *h) : handler_(h) {}

      virtual ~Handler() {}
      virtual void handleRequest(int num) = 0;

    protected:
      Handler *handler_;
  };

  class ConcreteHandlerA : public Handler {
    public:
      ConcreteHandlerA(Handler *h) : Handler(h) {}

      virtual void handleRequest(int num) {
        if (num < 100) {
          printf("A can handle %d\n", num);
          return;
        }
        if (handler_ != NULL) {
          handler_->handleRequest(num);
        }
      }
  };

  class ConcreteHandlerB : public Handler {
    public:
      ConcreteHandlerB(Handler *h) : Handler(h) {}

      virtual void handleRequest(int num) {
        if (num < 200) {
          printf("B can handle %d\n", num);
          return;
        }
        if (handler_ != NULL) {
          handler_->handleRequest(num);
        }
      }
  };

  class ConcreteHandlerC : public Handler {
    public:
      ConcreteHandlerC(Handler *h) : Handler(h) {}

      virtual void handleRequest(int num) {
        if (num < 300) {
          printf("C can handle %d\n", num);
          return;
        }
        if (handler_ != NULL) {
          handler_->handleRequest(num);
        }
      }
  };

} // namespace dp

int main() {
  using namespace dp;

  Handler *hc = new ConcreteHandlerC(NULL);
  Handler *hb = new ConcreteHandlerB(hc);
  Handler *ha = new ConcreteHandlerA(hb);

  printf("request 50\n");
  ha->handleRequest(50);
  printf("request 150\n");
  ha->handleRequest(150);
  printf("request 250\n");
  ha->handleRequest(250);
  printf("request 350\n");
  ha->handleRequest(350);

  delete hc; delete hb; delete ha;

  return 0;
}

