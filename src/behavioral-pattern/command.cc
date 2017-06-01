/**
 * @file   command.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-31 12:36:53
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class Television {
    public:
      void turnOn()  { printf("turn on tv.\n"); }
      void turnOff() { printf("turn off tv.\n"); }
  };

  class Command {
    public:
      Command(Television *tv) : tv_(tv) {}
      virtual ~Command() {}

      virtual void execute() {}

    protected:
      Television *tv_;
  };

  class TurnOnCommand : public Command{
    public:
      TurnOnCommand(Television *tv) : Command(tv) {}

      virtual void execute() { tv_->turnOn(); }
  };

  class TurnOffCommand : public Command{
    public:
      TurnOffCommand(Television *tv) : Command(tv) {}

      virtual void execute() { tv_->turnOff(); }
  };

  class Controller {
    public:
      void execute(Command *cmd) { cmd->execute(); }
  };

} // namespace dp

int main() {
  using namespace dp;

  Television tv;
  Controller controller;
  TurnOnCommand on_cmd(&tv);
  controller.execute(&on_cmd);
  TurnOffCommand off_cmd(&tv);
  controller.execute(&off_cmd);

  return 0;
}

