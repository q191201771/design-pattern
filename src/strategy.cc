/**
 * @file   strategy.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 07:20:33
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

namespace dp {

  class Strategy {
    public:
      virtual ~Strategy() {}
      virtual void sort(std::vector<int> &) = 0;
  };

  class Context {
    public:
      Context() : strategy_(NULL) {}

      void setStrategy(Strategy *strategy) { strategy_ = strategy; }
      void sort(std::vector<int> &vec) {
        assert(strategy_ != NULL);
        strategy_->sort(vec);
      }

    private:
      Strategy *strategy_;
  };

  class StableSortStrategy : public Strategy {
    public:
      virtual void sort(std::vector<int> &vec) { std::stable_sort(vec.begin(), vec.end()); }
  };

  class UnstableSortStrategy : public Strategy {
    public:
      virtual void sort(std::vector<int> &vec) { std::sort(vec.begin(), vec.end()); }
  };

  void print(const std::vector<int> &vec) {
    std::vector<int>::const_iterator iter = vec.begin();
    for (; iter != vec.end(); iter++) {
      printf("%d ", *iter);
    }
    printf("\n");
  }

} // namespace dp

int main() {
  using namespace dp;

  int arr[] = { 2, 0, 1, 7, 0, 3, 0, 3 };
  std::vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
  printf("-----before stable sort\n");
  print(vec);

  Context context;
  Strategy *strategy = new StableSortStrategy();
  context.setStrategy(strategy);
  context.sort(vec);
  printf("-----after stable sort\n");
  print(vec);
  delete strategy;

  vec.assign(arr, arr+sizeof(arr)/sizeof(int));
  printf("-----before sort\n");
  print(vec);
  strategy = new UnstableSortStrategy();
  context.setStrategy(strategy);
  context.sort(vec);
  printf("-----after sort\n");
  print(vec);
  delete strategy;

  return 0;
}
