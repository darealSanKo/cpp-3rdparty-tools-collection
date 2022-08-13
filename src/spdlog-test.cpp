// File: spdlog-test.cpp
// Project: src
// Created Date: 13/08/2022
// Author: Shun Suzuki
// -----
// Last Modified: 13/08/2022
// Modified By: Shun Suzuki (suzuki@hapis.k.u-tokyo.ac.jp)
// -----
// Copyright (c) 2022 Shun Suzuki. All rights reserved.
//

#include "spdlog/spdlog.h"

int main() {
  spdlog::set_level(spdlog::level::debug);  // off < critical < error < warn < info < debug < trace

  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");

  spdlog::debug("This message should be displayed..");
  spdlog::trace("This message should not be displayed..");
}
