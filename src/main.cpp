#include "omicron_api.h"
#include <iostream>

#include "log4cpp/Appender.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"

// main() is where program execution begins.
int main() {
  OmicronAPI api("127.0.0.1", 12221);

  log4cpp::Appender *appender1 =
      new log4cpp::OstreamAppender("console", &std::cout);
  appender1->setLayout(new log4cpp::BasicLayout());

  log4cpp::Category &root = log4cpp::Category::getRoot();
  root.setPriority(log4cpp::Priority::INFO);
  root.addAppender(appender1);

  if (api.CheckStatus()) {
    root.info("Successfully contacted OmicronD on " + api.ToString());
  }

  return 0;
}
