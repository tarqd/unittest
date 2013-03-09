#ifndef UNITTEST_TASK_HPP
#define UNITTEST_TASK_HPP
#pragma once

#include <functional>
#include <string>

namespace unittest {
inline namespace v1 {

class task final {
  using step = std::pair<std::string, std::function<void()>>;
  using function = std::function<void()>;
  const char* label;

public:
  task& operator = (task const&) noexcept = delete;
  task& operator = (task&&) noexcept = delete;

  task (task const&) noexcept = delete;
  task (task&&) noexcept = delete;
  task () noexcept = delete;

  explicit task (const char*) noexcept;
  ~task () noexcept;

  step operator = (function&&) const noexcept;
};

}} /* namespace unittest::v1 */

#endif /* UNITTEST_TASK_HPP */
