/**
 * @file   simple_factory.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 08:40:51
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>

namespace dp {

  class Logger {
    public:
      virtual ~Logger() {}
      virtual void trace() = 0;
  };

  class DBLogger : public Logger {
    public:
      virtual void trace() { printf("DBLogger::trace()\n"); }
  };

  class FileLogger : public Logger {
    public:
      virtual void trace() { printf("FileLogger::trace()\n"); }
  };

  /////////////////////////////////////////////////////

  class LoggerFactory {
    public:
      enum Type {
        TYPE_DB = 1,
        TYPE_File
      };

      static Logger *createLogger(Type type) {
        switch (type) {
          case TYPE_DB: return new DBLogger();
          case TYPE_File: return new FileLogger();
        }
        return NULL;
      }
  };

} // namespace dp

int main() {
  using namespace dp;
  Logger *db_logger = LoggerFactory::createLogger(LoggerFactory::TYPE_DB);
  Logger *file_logger = LoggerFactory::createLogger(LoggerFactory::TYPE_File);
  db_logger->trace();
  file_logger->trace();
  delete db_logger;
  delete file_logger;

  return 0;
}
