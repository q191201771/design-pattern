/**
 * @file   adapter.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-30 08:06:24
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  /// 资料上把target作为adapter的接口类，我觉得是种过度设计没必要就省略掉了
  //class target {};

  /// 来自第三方的代码，你必须得用却又无法对其进行修改。
  class Adaptee {
    public:
      void niHao() { printf("Adaptee::niHao()\n"); }
  };

  class Adapter {
    public:
      Adapter(Adaptee *core) : core_(core) {}

      void sayHi() { core_->niHao(); }

    private:
      Adaptee *core_;
  };

} // namespace dp

int main() {
  using namespace dp;

  Adaptee adaptee;
  Adapter adapter(&adaptee);
  adapter.sayHi();

  return 0;
}
