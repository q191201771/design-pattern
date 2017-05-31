/**
 * @file   proxy.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 10:12:40
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <memory>

namespace dp {

  class Foo {};

} // namespace dp

int main() {
  using namespace dp;

  std::shared_ptr<Foo> foo = std::make_shared<Foo>();

  return 0;
}

