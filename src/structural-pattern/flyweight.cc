/**
 * @file   flyweight.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 09:54:22
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <assert.h>
#include <string>
#include <map>

namespace dp {

  class Flyweight {
    public:
      Flyweight(const std::string &intrinsic_state) : intrinsic_state_(intrinsic_state) {}

      void op(const std::string &extrinsic_state) { printf("%s %s\n", intrinsic_state_.c_str(), extrinsic_state.c_str()); }

    private:
      std::string intrinsic_state_;
  };

  class FlyweightFactory {
    public:
      /// TODO release `flyweight_map_` memory

      Flyweight *get(const std::string &key) {
        std::map<std::string, Flyweight *>::iterator iter = flyweight_map_.find(key);
        if (iter != flyweight_map_.end()) {
          return iter->second;
        }
        Flyweight *fw = new Flyweight(key);
        flyweight_map_[key] = fw;
        return fw;
      }

    private:
      std::map<std::string, Flyweight *> flyweight_map_;
  };

} // namespace dp

int main() {
  using namespace dp;

  FlyweightFactory ff;
  Flyweight *fw1 = ff.get("chef");
  fw1->op("eat");
  fw1->op("work");
  Flyweight *fw2 = ff.get("chef");
  assert(fw1 == fw2);
  fw2->op("sleep");
  Flyweight *fw3 = ff.get("yoko");
  fw3->op("eat");

  return 0;
}

