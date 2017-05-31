/**
 * @file   observer.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 18:41:30
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <string>
#include <set>

namespace dp {

  class Observer {
    public:
      virtual ~Observer() {}
      virtual void update(const std::string &) = 0;
  };

  class Subject {
    public:
      void attach(Observer *obs) { obs_set_.insert(obs); }
      void detach(Observer *obs) { obs_set_.erase(obs); }

      void notify(const std::string &msg) {
        std::set<Observer *>::iterator iter = obs_set_.begin();
        for (; iter != obs_set_.end(); iter++) {
          (*iter)->update(msg);
        }
      }

    private:
      std::set<Observer *> obs_set_;
  };

  class ConcreteObserver : public Observer {
    public:
      virtual void update(const std::string &msg) { printf("%s\n", msg.c_str()); }
  };

} // namespace dp

int main() {
  using namespace dp;

  Subject sub1;
  Subject sub2;
  ConcreteObserver co1;
  ConcreteObserver co2;
  sub1.attach(&co1);
  sub1.attach(&co2);
  sub2.attach(&co1);
  sub2.attach(&co2);
  sub2.detach(&co1);
  sub1.notify("msg from sub1");
  sub2.notify("msg from sub2");
  sub1.notify("msg from sub1 again");

  return 0;
}
