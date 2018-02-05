#include "configuration.h"
#include "omicron_api.h"
#include <iostream>

#include "log4cpp/Appender.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"

int main(int argc, char, const char *argv[]) {

  // Read in parameters
  // TODO: parse params using boost.program_options

  // Initiate and prepare a logger object
  log4cpp::Appender *appender1 =
      new log4cpp::OstreamAppender("console", &std::cout);
  appender1->setLayout(new log4cpp::BasicLayout());

  log4cpp::Category &root = log4cpp::Category::getRoot();
  root.setPriority(log4cpp::Priority::INFO);
  root.addAppender(appender1);

  // Read in the configuration file
  Configuration config("/home/bryson/github/persei8/etc/sample-config.yaml");

  // Create the object to interface with the Omicron daemon
  OmicronAPI api(config.omicron_address, config.omicron_port, config.omicron_user, config.omicron_password);

  if (api.CheckStatus()) {
    root.info("Successfully contacted OmicronD on " + api.ToString());
  }

  return 0;
}
