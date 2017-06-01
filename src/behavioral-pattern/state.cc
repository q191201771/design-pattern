/**
 * @file   state.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 06:50:00
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <assert.h>

/// 把业务放入具体的状态类中，至于状态转化的逻辑以及状态的生命周期依具体场景而定。

namespace dp {

  class Context;

  class State {
    public:
      virtual ~State() {}
      virtual void handle(Context *) = 0;
  };

  class Context {
    public:
      Context(State *state) : state_(state) { assert(state != NULL); }
      ~Context() { if (state_ != NULL) { delete state_; } }

      void changeState(State *state) {
        assert(state != NULL && state_ != NULL);
        delete state_;
        state_ = state;
      }

      void request() { state_->handle(this); }

    private:
      State *state_;
  };

  // forward declaration
  class ConcreteStateB : public State {
    public:
      virtual void handle(Context *context);
  };

  class ConcreteStateA : public State {
    public:
      virtual void handle(Context *context) {
        assert(context != NULL);
        printf("do something while in state A\n");
        context->changeState(new ConcreteStateB());
      }
  };

  void ConcreteStateB::handle(Context *context) {
    assert(context != NULL);
    printf("do something while in state B\n");
    context->changeState(new ConcreteStateA());
  }

} // namespace dp

int main() {
  using namespace dp;

  State *state = new ConcreteStateA();
  Context context(state);
  context.request();
  context.request();
  context.request();

  return 0;
}

