/**
 * @file   bridge.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-30 08:39:40
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

/// 核心思想是从不同维度去做抽象，不同维度间也可以有指向关系，依实际场景而定。

namespace dp {

  class Platform {
    public:
      virtual ~Platform() {}
      virtual void func() = 0;
  };

  class Windows : public Platform {
    public:
      virtual void func() { printf("Windows\n"); }
  };

  class Linux : public Platform {
    public:
      virtual void func() { printf("Linux\n"); }
  };

  class MacOS : public Platform {
    public:
      virtual void func() { printf("MacOS\n"); }
  };

  class AVFile {
    public:
      virtual ~AVFile() {}
      virtual void func() = 0;
  };

  class RMVBFile : public AVFile {
    public:
      virtual void func() { printf("RMVBFile\n"); }
  };

  class MP4File : public AVFile {
    public:
      virtual void func() { printf("MP4File\n"); }
  };

  class MKVFile : public AVFile {
    public:
      virtual void func() { printf("MKVFile\n"); }
  };

  class Player {
    public:
      Player(Platform *platform, AVFile *avfile) : platform_(platform), avfile_(avfile) {}
      void func() {
        platform_->func();
        avfile_->func();
      }

    private:
      Platform *platform_;
      AVFile   *avfile_;
  };

} // namespace dp

int main() {
  using namespace dp;

  Platform *platform = new MacOS();
  AVFile *avfile = new MKVFile();
  Player player(platform, avfile);
  player.func();
  delete platform;
  delete avfile;

  return 0;
}
