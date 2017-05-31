/**
 * @file   mediator.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 12:55:47
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <string>
#include <map>

namespace dp {

  class Colleague {
    public:
      Colleague(const std::string &id) : id_(id) {}
      virtual ~Colleague() {}

      virtual void recv(const std::string &msg) = 0;
      virtual void send(const std::string &id, const std::string &msg) = 0;

      std::string id() const { return id_; }

    protected:
      std::string id_;
  };

  class Mediator {
    public:
      void registerColleague(Colleague *c) {
        /// TODO if id exist aready
        colleague_map_[c->id()] = c;
      }
      void send(const std::string &id, const std::string &msg) {
        std::map<std::string, Colleague *>::iterator iter = colleague_map_.find(id);
        if (iter == colleague_map_.end()) { return; }
        iter->second->recv(msg);
      }

    private:
      std::map<std::string, Colleague *> colleague_map_;
  };

  class ColleagueA : public Colleague {
    public:
      ColleagueA(const std::string &id, Mediator *m) : Colleague(id), m_(m) {}

      void recv(const std::string &msg) { printf("%s recv %s\n", id_.c_str(), msg.c_str()); }

      void send(const std::string &id, const std::string &msg) { m_->send(id, msg); }

    private:
      Mediator *m_;
  };

  /// TODO
  // class ColleagueB;

} // namespace dp

int main() {
  using namespace dp;

  Mediator m;
  ColleagueA ca1("1", &m);
  ColleagueA ca2("2", &m);
  m.registerColleague(&ca1);
  m.registerColleague(&ca2);
  ca1.send("2", "hello");
  ca2.send("1", "hi");

  return 0;
}

