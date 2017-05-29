/**
 * @file   factory_method.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-05-29 09:38:51
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
      virtual ~LoggerFactory() {}
      virtual Logger *createLogger() = 0;
  };

  class DBLoggerFactory : public LoggerFactory {
    public:
      virtual Logger *createLogger() {
        return new DBLogger();
      }
  };

  class FileLoggerFactory : public LoggerFactory {
    public:
      virtual Logger *createLogger() {
        return new FileLogger();
      }
  };

} // namespace dp

int main() {
  using namespace dp;

  {
    LoggerFactory *logger_factory = new DBLoggerFactory(); ///
    Logger *logger = logger_factory->createLogger();
    logger->trace();
    delete logger_factory;
    delete logger;
  }

  {
    LoggerFactory *logger_factory = new FileLoggerFactory();
    Logger *logger = logger_factory->createLogger();
    logger->trace();
    delete logger_factory;
    delete logger;
  }

  return 0;
}
